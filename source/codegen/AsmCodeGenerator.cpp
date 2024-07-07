#include "AsmCodeGenerator.h"
#include <fstream>
rv::RVAsms *AsmCodeGenerator::GenFunction()
{
    auto asms = rv::GenAsms();
    int prologue = 0;
    int argoffset = 0;
    sp = new int;
    *sp = 0;
    for (auto inst : func->AllIR.Insts)
    {
        prologue += inst->Prologue();
        if (inst->Result != nullptr)
        {
            regman.CreateAddVar(inst->Result->AssignedNumber, prologue, sp);
        }
    }
    assert(prologue % 4 == 0 && "prologue failed, align error!");
    while (prologue % 16 != 0)
    {
        prologue += 4;
    }
    *sp = prologue;
    while (prologue > 2048)
    {
        asms->Append(new rv::addi(regman.SP(), regman.SP(), new Imm(-2048)));
        prologue -= 2048;
    }
    asms->Append(new rv::addi(regman.SP(), regman.SP(), new Imm(-prologue)));
    int iter = 0;
    for (iter = 0; iter < func->Args.size(); iter++)
    {
        auto arg = func->Args[iter];
        auto inst = dynamic_cast<ir::Store *>(func->StdIR[iter]);
        int assignNo = inst->GetPtrVar().AssignedNumber;
        assert(inst->Result->AssignedNumber == arg->AssignedNumber && "Foward IR error! <E:error-ir-assign>");
        assert(inst != nullptr && "Foward IR error! <E:error-ir-type>");
        if (iter < 8)
        {
            ABI abi = static_cast<ABI>(iter + 10);
            // FIXME: stack location > 2047 ?
            regman[assignNo]->SetInReg(regman(abi));
            regman.AddVarInRegInfo(assignNo, abi);
            asms->Append(new rv::sd(regman(abi), regman.SP(), regman[assignNo]->GetImm12Offset()));
            regman[assignNo]->SetInStack();
            continue;
        }
        // FIXME: stack location > 2047 ?
        int readLoc = *sp - argoffset;
        asms->Append(new rv::ld(regman(ABI::t0), regman.SP(), new Imm(readLoc)));
        asms->Append(new rv::sd(regman(ABI::t0), regman.SP(), regman[assignNo]->GetImm12Offset()));
        regman[assignNo]->SetInStack();
        argoffset -= 4;
    }
    for (; iter < func->StdIR.size(); iter++)
    {
        auto inst = func->StdIR[iter];
        switch (inst->Type)
        {
        case IRInsType::Load:
            asms->Append(TransLoad(inst));
            break;
        case IRInsType::Store:
            asms->Append(TransStore(inst));
        default:
            break;
        }
    }

    return nullptr;
}

rv::RVAsms *AsmCodeGenerator::TransLoad(ir::IRInstruction *inst)
{
    auto ins = dynamic_cast<ir::Load *>(inst);
    auto asms = rv::GenAsms();
    int sourceNo = ins->GetPtrVar().AssignedNumber;
    int dstNo = ins->GetVar().AssignedNumber;
    ABI abi = ABI::TOP;
    asms->Append(FindReg(abi));
    auto imm12 = regman[sourceNo]->GetImm12Offset();
    asms->Append(new rv::ld(regman(abi), regman.SP(), imm12));
    regman.AddVarInRegInfo(dstNo, abi);
    regman[dstNo]->OnlyInReg();
    return asms;
}

rv::RVAsms *AsmCodeGenerator::TransStore(ir::IRInstruction *inst)
{
    auto ins = dynamic_cast<ir::Store *>(inst);
    auto asms = rv::GenAsms();
    int dstNo = ins->GetPtrVar().AssignedNumber;
    auto imm12 = regman[dstNo]->GetImm12Offset();
    int srcNo = ins->GetVar().AssignedNumber;
    ABI abi = ABI::TOP;
    asms->Append(TryLoadToReg(srcNo, abi));
    asms->Append(new rv::sd(regman(abi), regman.SP(), imm12));
    return asms;
}

rv::RVAsms *AsmCodeGenerator::TransCall(ir::IRInstruction *inst)
{
    return nullptr;
}

rv::RVAsms *AsmCodeGenerator::TransRet(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    if (!inst->Args.empty())
    {
        ABI retAbi = ABI::a0;
        int ret = inst->Args[0]->AssignedNumber;
        asms->Append(TryLoadToReg(ret, retAbi));
        regman.AddVarInRegInfo(ret, retAbi);
        assert(retAbi == ABI::a0);
    }
    asms->Append(RecoverRegs());
    while (*sp > 2032)
    {
        asms->Append(new rv::addi(regman.SP(), regman.SP(), new Imm(2047)));
        *sp = *sp - 2032;
    }
    asms->Append(new rv::addi(regman.SP(), regman.SP(), new Imm(*sp)));
    asms->Append(new rv::ret());
    return asms;
}

rv::RVAsms *AsmCodeGenerator::TransBinOp(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    Imm *imm = nullptr;
    ID *lVar = inst->Args[0];
    ID *rVar = inst->Args[1];
    ID *oprd = nullptr;
    ID *result = inst->Result;
    IRInsType type = inst->Type;
    ABI rdAbi = ABI::TOP;
    if (lVar->IsNumber && rVar->IsNumber)
    {
        int l = lVar->Value;
        int r = rVar->Value;
        switch (inst->Type)
        {
        case IRInsType::Add:
            imm = new Imm(l + r, false);
            break;
        case IRInsType::Sub:
            imm = new Imm(l - r, false);
            break;
        case IRInsType::Mul:
            imm = new Imm(l * r, false);
            break;
        case IRInsType::SDiv:
            imm = new Imm(l / r, false);
            break;
        case IRInsType::SRem:
            imm = new Imm(l % r, false);
            break;
        default:
            assert(false && "unreachable");
            break;
        }
        asms->Append(FindReg(rdAbi));
        asms->Append(new rv::li(regman(rdAbi), imm));
        regman.AutoSetVarInRegInfo(result->AssignedNumber, rdAbi);
        return asms;
    }
    if (type == IRInsType::Add)
    {
        if (lVar->IsNumber && FitImm12(lVar->Value))
        {
            imm = new Imm(lVar->Value);
            oprd = rVar;
        }
        if (rVar->IsNumber && FitImm12(rVar->Value))
        {
            imm = new Imm(rVar->Value);
            oprd = lVar;
        }
        if (imm != nullptr)
        {
            auto rs = regman[oprd->AssignedNumber];
            ABI rsAbi = ABI::TOP;
            asms->Append(TryLoadToReg(rs, rsAbi));
            asms->Append(FindReg(rdAbi, rsAbi));
            regman.AutoSetVarInRegInfo(result->AssignedNumber, rdAbi);
            asms->Append(new rv::addi(regman(rdAbi), regman(rsAbi), imm));
            return asms;
        }
    }
    ABI rs1Abi = ABI::TOP;
    ABI rs2Abi = ABI::TOP;
    asms->Append(TryLoadToReg(lVar->AssignedNumber, rs1Abi));
    asms->Append(TryLoadToReg(rVar->AssignedNumber, rs2Abi, rs1Abi));
    asms->Append(FindReg(rdAbi, rs1Abi, rs2Abi));
    regman.AutoSetVarInRegInfo(result->AssignedNumber, rdAbi);
    auto rd = regman(rdAbi);
    auto rs1 = regman(rs1Abi);
    auto rs2 = regman(rs2Abi);
    switch (inst->Type)
    {
    case IRInsType::Add:
        asms->Append(new rv::add(rd, rs1, rs2));
        break;
    case IRInsType::Sub:
        asms->Append(new rv::sub(rd, rs1, rs2));
        break;
    case IRInsType::Mul:
        asms->Append(new rv::mul(rd, rs1, rs2));
        break;
    case IRInsType::SDiv:
        asms->Append(new rv::div(rd, rs1, rs2));
        break;
    case IRInsType::SRem:
        asms->Append(new rv::rem(rd, rs1, rs2));
        break;
    default:
        assert(false && "unreachable");
        break;
    }
    return asms;
}

rv::RVAsms *AsmCodeGenerator::TransICmp(ir::IRInstruction *inst)
{
    auto ins = dynamic_cast<ir::ICmp *>(inst);
    auto asms = rv::GenAsms();
    auto var1 = regman[ins->Args[0]->AssignedNumber];
    auto var2 = regman[ins->Args[1]->AssignedNumber];
    ABI rs1Abi = ABI::TOP;
    ABI rs2Abi = ABI::TOP;
    ABI rdAbi = ABI::TOP;
    asms->Append(TryLoadToReg(var1, rs1Abi));
    asms->Append(TryLoadToReg(var2, rs2Abi, rs1Abi));
    asms->Append(FindReg(rdAbi, rs1Abi, rs2Abi));
    regman.AutoSetVarInRegInfo(inst->Result->AssignedNumber, rdAbi);
    auto rd = regman(rdAbi);
    auto rs1 = regman(rs1Abi);
    auto rs2 = regman(rs2Abi);
    switch (ins->CmpType)
    {
    case ICmpType::EQ:
        asms->Append(new rv::sub(rd, rs1, rs2));
        asms->Append(new rv::seqz(rd, rd));
        break;
    case ICmpType::NE:
        asms->Append(new rv::sub(rd, rs1, rs2));
        asms->Append(new rv::snez(rd, rd));
        break;
    case ICmpType::SGE:
        asms->Append(new rv::slt(rd, rs1, rs2));
        asms->Append(new rv::seqz(rd, rd));
        break;
    case ICmpType::SLE:
        asms->Append(new rv::sgt(rd, rs1, rs2));
        asms->Append(new rv::seqz(rd, rd));
        break;
    case ICmpType::SGT:
        asms->Append(new rv::sgt(rd, rs1, rs2));
        break;
    case ICmpType::SLT:
        asms->Append(new rv::slt(rd, rs1, rs2));
        break;
    default:
        assert(false && "unreachable");
        break;
    }
    return asms;
}

rv::RVAsms *AsmCodeGenerator::TransBr(ir::IRInstruction *inst)
{
    auto ins = dynamic_cast<ir::Br *>(inst);
    if (inst->Type == IRInsType::BrDirect)
    {
        rv::Label target = func->Name + std::to_string(ins->NonCondLabel->GetLabelNo().AssignedNumber);
        auto asms = rv::GenAsms();
        asms->Append(new rv::j(target));
        return asms;
    }
    else
    {
        rv::Label trueL = func->Name + std::to_string(ins->TrueLabel->GetLabelNo().AssignedNumber);
        rv::Label falseL = func->Name + std::to_string(ins->FalseLabel->GetLabelNo().AssignedNumber);
        auto asms = rv::GenAsms();
        ABI rsAbi = ABI::TOP;
        auto var = regman[ins->Args[0]->AssignedNumber];
        asms->Append(TryLoadToReg(var, rsAbi));
        auto rs = regman(rsAbi);
        asms->Append(new rv::bnez(rs, trueL));
        asms->Append(new rv::j(falseL));
        return asms;
    }
}

rv::RVAsms *AsmCodeGenerator::TransLabel(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    rv::Label l = func->Name + std::to_string(inst->Args[0]->AssignedNumber);
    asms->Append(new rv::label(l));
    return asms;
}

rv::RVAsms *AsmCodeGenerator::TransGetelementptr(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    ABI op0 = ABI::TOP;
    ABI op1 = ABI::TOP;
    ABI op2 = ABI::TOP;
    auto baseVar = regman[inst->Args[0]->AssignedNumber];
    auto offsetID = inst->Args[1];

    asms->Append(FindReg(op0));
    asms->Append(FindReg(op1, op0));
    asms->Append(FindReg(op2, op1, op0));
    regman.AutoSetVarInRegInfo(inst->Result->AssignedNumber, op2);

    if (offsetID->IsNumber)
    {
        Imm *offset = new Imm(offsetID->Value, false);
    }
    return asms;
}

rv::RVAsms *AsmCodeGenerator::TransGetptr(ir::IRInstruction *inst)
{
    return nullptr;
}

rv::RVAsms *AsmCodeGenerator::ImmSafeAdd(ABI rdAbi, ABI rsAbi, Imm *imm)
{
    assert(rdAbi != rsAbi);
    auto asms = rv::GenAsms();
    auto rd = regman(rdAbi);
    auto rs = regman(rsAbi);
    if (imm->IsImm12)
    {
        asms->Append(new rv::addi(rd, rs, imm));
        return asms;
    }
    asms->Append(new rv::li(rd, imm));
    asms->Append(new rv::add(rd, rd, rs));
    return asms;
}

rv::RVAsms *AsmCodeGenerator::RecoverRegs()
{
    return nullptr;
}

rv::RVAsms *AsmCodeGenerator::SaveRegs()
{
    return nullptr;
}

rv::RVAsms *AsmCodeGenerator::FindReg(ABI &out, ABI no1, ABI no2)
{
    return nullptr;
}

rv::RVAsms *AsmCodeGenerator::TryLoadToReg(Imm *imm, ABI &out, ABI no1, ABI no2)
{
    return nullptr;
}

rv::RVAsms *AsmCodeGenerator::TryLoadToReg(int sourceNo, ABI &out, ABI no1, ABI no2)
{
    return TryLoadToReg(regman[sourceNo], out, no1, no2);
}

rv::RVAsms *AsmCodeGenerator::TryLoadToReg(Var *source, ABI &out, ABI no1, ABI no2)
{
    auto asms = rv::GenAsms();
    if (source->InReg)
    {
        out = source->Reg->ABINo;
        return asms;
    }
    assert(!source->InReg);
    assert(source->InStack);
    asms->Append(FindReg(out, no1, no2));
    auto imm12 = source->GetImm12Offset();
    asms->Append(new rv::ld(regman(out), regman.SP(), imm12));
    return asms;
}

bool AsmCodeGenerator::FitImm12(int value)
{
    if (value >= -2048 && value <= 2047)
    {
        return true;
    }
    return false;
}

rv::RVAsms *AsmCodeGenerator::EasyStore()
{
    return nullptr;
}

AsmCodeGenerator::AsmCodeGenerator(GlobalGenerator *ir)
{
    assert(ir != nullptr);
    irGen = ir;
}

AsmCodeGenerator::~AsmCodeGenerator() {}

AsmPlainCodeGenerator::AsmPlainCodeGenerator(GlobalGenerator *Gen)
{
    irGen = Gen;
}

rv::RVAsms *AsmPlainCodeGenerator::GenFunction()
{
    auto asms = rv::GenAsms();

    asms->Append(new rv::split(".text"));
    asms->Append(new rv::split(".globl " + func->Name));
    asms->Append(new rv::label(func->Name));
    int prologue = 8;
    int argoffset = 0;
    sp = new int();
    *sp = 0;
    int funcMax = 0;
    for (auto inst : func->AllIR.Insts)
    {
        if (inst->Result != nullptr)
        {
            prologue += inst->Prologue();
            regman.CreateAddVar(inst->Result->AssignedNumber, prologue, sp);
        }
        if (inst->Type == IRInsType::Call)
        {
            auto ins = dynamic_cast<ir::Call *>(inst);
            funcMax = std::max(funcMax, ins->ArgPrologue());
        }
    }
    prologue += funcMax;
    assert(prologue % 8 == 0 && "prologue failed, align error!");
    while (prologue % 16 != 0)
    {
        prologue += 4;
    }
    *sp = prologue;
    while (prologue > 2048)
    {
        asms->Append(new rv::addi(regman.SP(), regman.SP(), new Imm(-2048)));
        prologue -= 2048;
    }
    asms->Append(new rv::addi(regman.SP(), regman.SP(), new Imm(-prologue)));
    asms->Append(EasySWStack(*sp - 8, ABI::ra));
    for (auto alloca : func->AllocaIR.Insts)
    {
        asms->Append(EasyAlloca(alloca));
    }
    int iter = 0;
    for (iter = 0; iter < func->Args.size(); iter++)
    {
        auto arg = func->Args[iter];
        auto inst = dynamic_cast<ir::Store *>(func->StdIR[iter]);
        asms->Append(EasyStoreParam(inst, iter));
    }
    for (; iter < func->StdIR.size(); iter++)
    {
        auto inst = func->StdIR[iter];
        switch (inst->Type)
        {
        case IRInsType::Load:
            asms->Append(EasyLoad(inst));
            break;
        case IRInsType::Store:
            asms->Append(EasyStore(inst));
            break;
        case IRInsType::Call:
            asms->Append(EasyCall(inst));
            break;
        case IRInsType::Ret:
            asms->Append(EasyRet(inst));
            break;
        case IRInsType::Add:
        case IRInsType::Sub:
        case IRInsType::Mul:
        case IRInsType::SDiv:
        case IRInsType::SRem:
            asms->Append(EasyBinOp(inst));
            break;
        case IRInsType::ICmp:
            asms->Append(EasyICmp(inst));
            break;
        case IRInsType::Br:
        case IRInsType::BrDirect:
            asms->Append(EasyBr(inst));
            break;
        case IRInsType::GetElementPtr:
            asms->Append(EasyGetelementptr(inst));
            break;
        case IRInsType::GetPtr:
            asms->Append(EasyGetptr(inst));
            break;
        case IRInsType::Label:
            asms->Append(EasyLabel(inst));
            break;
        default:
            break;
        }
    }
    regman.Reset();
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyLoad(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    ABI abi = ABI::t0;
    if (inst->Args[0]->IsGlobal)
    {
        asms->Append(EasyGlob(inst->Args[0]->Name, abi));
    }
    else
    {
        asms->Append(EasyLW(inst->Args[0], abi));
        asms->Append(new rv::ld(regman(abi), regman(abi), new Imm(0)));
    }

    asms->Append(EasySWStack(inst->Result, abi));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyAlloca(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    auto ins = dynamic_cast<ir::Alloca *>(inst);
    asms->Append(new rv::li(regman(ABI::t0), new Imm(regman[inst->Result->AssignedNumber]->GetOffset() + 8, false)));
    asms->Append(new rv::add(regman(ABI::t0), regman(ABI::t0), regman.SP()));
    asms->Append(EasySWStack(inst->Result, ABI::t0));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyStoreParam(ir::IRInstruction *inst, int cnt)
{
    auto asms = rv::GenAsms();
    auto ins = dynamic_cast<ir::Store *>(inst);
    ABI abi = ABI::TOP;
    if (cnt < 8)
    {
        abi = static_cast<ABI>(cnt + 10);
        asms->Append(EasyAddr(&ins->GetPtrVar(), ABI::t1));
        asms->Append(new rv::ld(regman(ABI::t1), regman(ABI::t1), new Imm(0)));
        asms->Append(new rv::sd(regman(abi), regman(ABI::t1), new Imm(0)));
    }
    else
    {
        asms->Append(EasyLW(*sp + (cnt - 8) * 8, ABI::t0));
        asms->Append(EasyAddr(&ins->GetPtrVar(), ABI::t1));
        asms->Append(new rv::ld(regman(ABI::t1), regman(ABI::t1), new Imm(0)));
        asms->Append(new rv::sd(regman(ABI::t0), regman(ABI::t1), new Imm(0)));
    }
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyStore(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    auto ins = dynamic_cast<ir::Store *>(inst);
    if (inst->Args[1]->IsGlobal)
    {
        asms->Append(EasyOperand(&ins->GetVar(), ABI::t0));
        asms->Append(EasyAddr(&ins->GetPtrVar(), ABI::t1));
        asms->Append(new rv::sd(regman(ABI::t0), regman(ABI::t1), new Imm(0)));
    }
    else
    {
        asms->Append(EasyOperand(&ins->GetVar(), ABI::t0));
        asms->Append(EasyAddr(&ins->GetPtrVar(), ABI::t1));
        asms->Append(new rv::ld(regman(ABI::t1), regman(ABI::t1), new Imm(0)));
        asms->Append(new rv::sd(regman(ABI::t0), regman(ABI::t1), new Imm(0)));
    }
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyCall(ir::IRInstruction *inst)
{
    auto ins = dynamic_cast<ir::Call *>(inst);
    auto asms = rv::GenAsms();
    int offset = 0;
    for (int i = 0; i < inst->Args.size(); i++)
    {
        if (i < 8)
        {
            asms->Append(EasyOperand(inst->Args[i], static_cast<ABI>(i + 10)));
            continue;
        }
        asms->Append(EasyOperand(inst->Args[i], ABI::t0));
        asms->Append(EasySWStack(offset, ABI::t0));
        offset += 8;
    }
    asms->Append(new rv::call(std::string(ins->Func)));
    if (ins->Result != nullptr)
    {
        asms->Append(EasySWStack(ins->Result, ABI::a0));
    }

    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyRet(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    if (func->RetType == BasicType::TYPE_VOID)
    {
        asms->Append(EasyLW(*sp - 8, ABI::ra));
        asms->Append(EasyEpilogue());
        asms->Append(new rv::ret());
        return asms;
    }
    asms->Append(EasyOperand(inst->Args[0], ABI::a0));
    asms->Append(EasyLW(*sp - 8, ABI::ra));
    asms->Append(EasyEpilogue());
    asms->Append(new rv::ret());
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyBinOp(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    asms->Append(EasyOperand(inst->Args[0], ABI::t1));
    asms->Append(EasyOperand(inst->Args[1], ABI::t2));
    auto rd = regman(ABI::t0);
    auto rs1 = regman(ABI::t1);
    auto rs2 = regman(ABI::t2);
    switch (inst->Type)
    {
    case IRInsType::Add:
        asms->Append(new rv::add(rd, rs1, rs2));
        break;
    case IRInsType::Sub:
        asms->Append(new rv::sub(rd, rs1, rs2));
        break;
    case IRInsType::Mul:
        asms->Append(new rv::mul(rd, rs1, rs2));
        break;
    case IRInsType::SDiv:
        asms->Append(new rv::div(rd, rs1, rs2));
        break;
    case IRInsType::SRem:
        asms->Append(new rv::rem(rd, rs1, rs2));
        break;
    default:
        assert(false && "unreachable");
        break;
    }
    asms->Append(EasySWStack(inst->Result, ABI::t0));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyICmp(ir::IRInstruction *inst)
{
    auto ins = dynamic_cast<ir::ICmp *>(inst);
    auto asms = rv::GenAsms();
    asms->Append(EasyOperand(inst->Result, ABI::t0));
    asms->Append(EasyOperand(inst->Args[0], ABI::t1));
    asms->Append(EasyOperand(inst->Args[1], ABI::t2));
    auto rd = regman(ABI::t0);
    auto rs1 = regman(ABI::t1);
    auto rs2 = regman(ABI::t2);

    switch (ins->CmpType)
    {
    case ICmpType::EQ:
        asms->Append(new rv::sub(rd, rs1, rs2));
        asms->Append(new rv::seqz(rd, rd));
        break;
    case ICmpType::NE:
        asms->Append(new rv::sub(rd, rs1, rs2));
        asms->Append(new rv::snez(rd, rd));
        break;
    case ICmpType::SGE:
        asms->Append(new rv::slt(rd, rs1, rs2));
        asms->Append(new rv::seqz(rd, rd));
        break;
    case ICmpType::SLE:
        asms->Append(new rv::sgt(rd, rs1, rs2));
        asms->Append(new rv::seqz(rd, rd));
        break;
    case ICmpType::SGT:
        asms->Append(new rv::sgt(rd, rs1, rs2));
        break;
    case ICmpType::SLT:
        asms->Append(new rv::slt(rd, rs1, rs2));
        break;
    default:
        assert(false && "unreachable");
        break;
    }
    asms->Append(EasySWStack(inst->Result, ABI::t0));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyBr(ir::IRInstruction *inst)
{
    auto ins = dynamic_cast<ir::Br *>(inst);
    auto asms = rv::GenAsms();

    switch (inst->Type)
    {
    case IRInsType::BrDirect:
    {
        rv::Label dircL;
        dircL.append(func->Name + std::to_string(ins->NonCondLabel->Args[0]->AssignedNumber));
        asms->Append(new rv::j(dircL));
        break;
    }
    case IRInsType::Br:
    {
        rv::Label trueL;
        std::string name = func->Name;
        std::string trueNo = std::to_string(ins->TrueLabel->Args[0]->AssignedNumber);
        trueL = name + trueNo;
        rv::Label falseL;
        falseL.append(func->Name + std::to_string(ins->FalseLabel->Args[0]->AssignedNumber));
        asms->Append(EasyLW(ins->Args[0], ABI::t0));
        asms->Append(new rv::bnez(regman(ABI::t0), trueL));
        asms->Append(new rv::j(falseL));
        break;
    }

    default:
        break;
    }
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyLabel(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    rv::Label L = func->Name + std::to_string(inst->Args[0]->AssignedNumber);
    asms->Append(new rv::label(L));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyGetelementptr(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    if (inst->Args[0]->IsGlobal)
    {
        asms->Append(EasyAddr(inst->Args[0], ABI::t0));
        Imm *base = new Imm(inst->Args[0]->Type.GetElePtrDim(), false);
        asms->Append(EasyOperand(inst->Args[1], ABI::t1));
        asms->Append(new rv::li(regman(ABI::t2), base));
        asms->Append(new rv::mul(regman(ABI::t1), regman(ABI::t1), regman(ABI::t2)));
        asms->Append(new rv::add(regman(ABI::t0), regman(ABI::t0), regman(ABI::t1)));
        asms->Append(EasySWStack(inst->Result, ABI::t0));
        return asms;
    }
    asms->Append(EasyAddr(inst->Args[0], ABI::t0));
    asms->Append(new rv::ld(regman(ABI::t0), regman(ABI::t0), new Imm(0)));
    Imm *base = new Imm(inst->Args[0]->Type.GetElePtrDim(), false);
    asms->Append(EasyOperand(inst->Args[1], ABI::t1));
    asms->Append(new rv::li(regman(ABI::t2), base));
    asms->Append(new rv::mul(regman(ABI::t1), regman(ABI::t1), regman(ABI::t2)));
    asms->Append(new rv::add(regman(ABI::t0), regman(ABI::t0), regman(ABI::t1)));
    asms->Append(EasySWStack(inst->Result, ABI::t0));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyGetptr(ir::IRInstruction *inst)
{
    auto asms = rv::GenAsms();
    if (inst->Args[0]->IsGlobal)
    {
        asms->Append(EasyAddr(inst->Args[0], ABI::t0));
        Imm *base = new Imm(inst->Args[0]->Type.GetElePtrDim(), false);
        asms->Append(EasyOperand(inst->Args[1], ABI::t1));
        asms->Append(new rv::li(regman(ABI::t2), base));
        asms->Append(new rv::mul(regman(ABI::t1), regman(ABI::t1), regman(ABI::t2)));
        asms->Append(new rv::add(regman(ABI::t0), regman(ABI::t0), regman(ABI::t1)));
        asms->Append(EasySWStack(inst->Result, ABI::t0));
        return asms;
    }
    asms->Append(EasyAddr(inst->Args[0], ABI::t0));
    asms->Append(new rv::ld(regman(ABI::t0), regman(ABI::t0), new Imm(0)));
    Imm *base = new Imm(inst->Args[0]->Type.GetPtrDim(), false);
    asms->Append(EasyOperand(inst->Args[1], ABI::t1));
    asms->Append(new rv::li(regman(ABI::t2), base));
    asms->Append(new rv::mul(regman(ABI::t1), regman(ABI::t1), regman(ABI::t2)));
    asms->Append(new rv::add(regman(ABI::t0), regman(ABI::t0), regman(ABI::t1)));
    asms->Append(EasySWStack(inst->Result, ABI::t0));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyAddr(ID *id, ABI dst)
{
    auto asms = rv::GenAsms();
    if (id->IsGlobal)
    {
        asms->Append(new rv::la(regman(dst), id->Name));
        return asms;
    }

    int offset = regman[id->AssignedNumber]->GetOffset();

    if (FitImm12(offset))
    {
        asms->Append(new rv::addi(regman(dst), regman.SP(), new Imm(offset)));
        return asms;
    }
    asms->Append(new rv::li(regman(dst), new Imm(offset, false)));
    asms->Append(new rv::add(regman(dst), regman(dst), regman.SP()));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyLW(int offset, ABI dst)
{
    auto asms = rv::GenAsms();

    if (FitImm12(offset))
    {
        asms->Append(new rv::ld(regman(dst), regman.SP(), new Imm(offset)));
        return asms;
    }
    asms->Append(new rv::li(regman(dst), new Imm(offset, false)));
    asms->Append(new rv::add(regman(dst), regman(dst), regman.SP()));
    asms->Append(new rv::ld(regman(dst), regman(dst), new Imm(0)));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyLW(ID *id, ABI dst)
{
    return EasyLW(regman[id->AssignedNumber]->GetOffset(), dst);
}

rv::RVAsms *AsmPlainCodeGenerator::EasySWStack(int offset, ABI src)
{
    assert(src != ABI::t6);
    auto asms = rv::GenAsms();
    if (FitImm12(offset))
    {
        asms->Append(new rv::sd(regman(src), regman.SP(), new Imm(offset)));
        return asms;
    }
    asms->Append(new rv::li(regman(ABI::t6), new Imm(offset, false)));
    asms->Append(new rv::add(regman(ABI::t6), regman(ABI::t6), regman.SP()));
    asms->Append((new rv::sd(regman(src), regman(ABI::t6), new Imm(0))));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasySWStack(ID *id, ABI src)
{
    return EasySWStack(regman[id->AssignedNumber]->GetOffset(), src);
}

rv::RVAsms *AsmPlainCodeGenerator::EasyGlob(std::string name, ABI dst)
{
    auto asms = rv::GenAsms();
    asms->Append(new rv::la(regman(dst), name));
    asms->Append(new rv::ld(regman(dst), regman(dst), new Imm(0)));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyOperand(ID *arg, ABI dest)
{
    auto asms = rv::GenAsms();
    if (arg->IsNumber)
    {
        asms->Append(new rv::li(regman(dest), new Imm(arg->Value, false)));
        return asms;
    }
    asms->Append(EasyLW(arg, dest));
    return asms;
}

rv::RVAsms *AsmPlainCodeGenerator::EasyEpilogue()
{
    auto asms = rv::GenAsms();
    while (*sp >= 2032)
    {
        asms->Append(new rv::addi(regman.SP(), regman.SP(), new Imm(2032)));
        *sp -= 2032;
    }
    asms->Append(new rv::addi(regman.SP(), regman.SP(), new Imm(*sp)));
    return asms;
}

bool AsmPlainCodeGenerator::FitImm12(int value)
{
    if (value >= -2048 && value <= 2047)
    {
        return true;
    }
    return false;
}

void AsmPlainCodeGenerator::Run()
{
    std::string file = "/home/william/compiler/MyCompiler/out/1_self.s";
    std::ofstream ofs(file, std::ios::out);
    for (auto g : irGen->GlobalDeclIRs.Insts)
    {
        auto asms = rv::GenAsms();
        auto global = dynamic_cast<ir::Global *>(g);
        asms->Append(new rv::split(".data"));
        asms->Append(new rv::split(".globl " + global->Result->Name));
        asms->Append(new rv::label(global->Result->Name));
        int zero = 0;
        for (int i = 0; i < global->Inits->size(); i++)
        {
            int num = global->Inits->at(i);
            if (num == 0)
            {
                zero += 8;
            }
            else if (zero != 0)
            {
                asms->Append(new rv::split(".zero " + std::to_string(zero)));
                zero = 0;
                asms->Append(new rv::split(".dword " + std::to_string(num)));
            }
            else
            {
                asms->Append(new rv::split(".dword " + std::to_string(num)));
            }
        }
        if (zero != 0)
        {
            asms->Append(new rv::split(".zero " + std::to_string(zero)));
            zero = 0;
        }
        for (auto a : asms->Asms)
        {
            if (a->Type == AsmType::TAB)
            {
                ofs << "    " << a->ToString() << std::endl;
            }
            else if (a->Type == AsmType::DESC)
            {
                ofs << "    " << a->ToString() << std::endl;
            }
            else
            {
                ofs << a->ToString() << ":" << std::endl;
            }
        }
        ofs << "\n\n";
    }

    for (auto function : irGen->FuncTable.FunctionsOrdered)
    {
        auto asms = rv::GenAsms();
        if (function->IsBuildIn)
        {
            continue;
        }
        func = function;
        asms->Append(GenFunction());
        for (auto a : asms->Asms)
        {
            if (a->Type == AsmType::TAB)
            {
                ofs << "    " << a->ToString() << std::endl;
            }
            else if (a->Type == AsmType::DESC)
            {
                ofs << "    " << a->ToString() << std::endl;
            }
            else
            {
                ofs << a->ToString() << ":" << std::endl;
            }
        }
        ofs << "\n\n";
    }

    return;
}
