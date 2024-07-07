#include "riscvasm.h"
#include <cassert>
Oprd::Oprd() {}

Imm::Imm()
{
    IsImm12 = true;
    Sp = nullptr;
}

Imm::Imm(int immVal, bool isImm12, int *sp)
{
    IsImm12 = isImm12;
    if (IsImm12)
    {
        assert(immVal >= -2048 && immVal <= 2047);
    }

    ImmVal = immVal;
    Sp = sp;
}

ABI Register::ToABI()
{
    return ABINo;
}

int Register::ToInt()
{
    return (int)ABINo;
}

Register::Register(ABI abi)
{
    ABINo = abi;
}

Register::Register(int abi)
{
    ABINo = static_cast<ABI>(abi);
}

std::string Register::ToString()
{
    switch (ABINo)
    {

    case ABI::zero:
        return "zero";
        break;
    case ABI::ra:
        return "ra";
        break;
    case ABI::sp:
        return "sp";
        break;
    case ABI::gp:
        return "gp";
        break;
    case ABI::tp:
        return "tp";
        break;
    case ABI::t0:
        return "t0";
        break;
    case ABI::t1:
        return "t1";
        break;
    case ABI::t2:
        return "t2";
        break;
    case ABI::s0:
        return "s0";
        break;
    case ABI::s1:
        return "s1";
        break;
    case ABI::a0:
        return "a0";
        break;
    case ABI::a1:
        return "a1";
        break;
    case ABI::a2:
        return "a2";
        break;
    case ABI::a3:
        return "a3";
        break;
    case ABI::a4:
        return "a4";
        break;
    case ABI::a5:
        return "a5";
        break;
    case ABI::a6:
        return "a6";
        break;
    case ABI::a7:
        return "a7";
        break;
    case ABI::s2:
        return "s2";
        break;
    case ABI::s3:
        return "s3";
        break;
    case ABI::s4:
        return "s4";
        break;
    case ABI::s5:
        return "s5";
        break;
    case ABI::s6:
        return "s6";
        break;
    case ABI::s7:
        return "s7";
        break;
    case ABI::s8:
        return "s8";
        break;
    case ABI::s9:
        return "s9";
        break;
    case ABI::s10:
        return "s10";
        break;
    case ABI::s11:
        return "s11";
        break;
    case ABI::t3:
        return "t3";
        break;
    case ABI::t4:
        return "t4";
        break;
    case ABI::t5:
        return "t5";
        break;
    case ABI::t6:
        return "t6";
        break;
    case ABI::TOP:
        return "ERROR";
        break;
    default:
        return "ERROR";
        break;
    }
    return "ERROR";
}

rv::riscvasm::riscvasm()
{
    Type = AsmType::TAB;
}

rv::riscvasm::riscvasm(AsmType t) : Type(t) {}

Register *&rv::riscvasm::rd()
{
    return DstReg;
}

Register *&rv::riscvasm::rs1()
{
    return Srcs[0];
}

Register *&rv::riscvasm::rs2()
{
    return Srcs[1];
}

Imm *&rv::riscvasm::imm()
{
    return ImmVal;
}

std::string rv::riscvasm::ToString()
{
    return std::string();
}

rv::riscvasm *rv::riscvasm::Cmt(std::string in)
{
    Comment = in;
    return this;
}

// stack location = [sp offset] + sp
int Var::GetOffset()
{
    return *ImmOffset.Sp - ImmOffset.ImmVal;
}

Imm *Var::GetImm12Offset()
{
    return new Imm(*(ImmOffset.Sp) - ImmOffset.ImmVal);
}

void Var::SetInReg(Register *reg)
{
    InReg = true;
    Reg = reg;
}

void Var::OnlyInReg()
{
    InReg = true;
    InStack = false;
}

void Var::SetInStack(int offset, int *sp)
{
    assert(!StackSet);
    StackSet = true;
    InStack = true;
    ImmOffset.Sp = sp;
    assert(offset >= -2048 && offset <= 2047);
    ImmOffset.ImmVal = offset;
}

void Var::SetInStack()
{
    InStack = true;
}

void Var::AllocInStack(int offset, int *sp)
{
    assert(!StackSet);
    StackSet = true;
    ImmOffset.Sp = sp;
    assert(offset >= -2048 && offset <= 2047);
    ImmOffset.ImmVal = offset;
}

void Var::OnlyInStack()
{
    InStack = true;
    InReg = false;
}

Var::Var()
{
    StackSet = false;
    InStack = false;
    InReg = false;
}

Var::Var(int offset, int *sp) : Var()
{
    assert(!StackSet);
    StackSet = true;
    ImmOffset.ImmVal = offset;
    ImmOffset.Sp = sp;
}

Var::Var(Register *reg) : Var()
{
    InReg = true;
    InStack = false;
    Reg = reg;
}

namespace rv
{
    RVAsms::RVAsms() {}
    void RVAsms::Append(riscvasm *rvasm)
    {
        if (rvasm == nullptr)
        {
            return;
        }
        Asms.push_back(rvasm);
    }

    void RVAsms::Append(RVAsms *rvasms)
    {
        if (rvasms == nullptr)
        {
            return;
        }
        Asms.insert(Asms.end(), rvasms->Asms.begin(), rvasms->Asms.end());
    }

    void RVAsms::Append(RVAsms &rvasms)
    {
        if (rvasms.Asms.empty())
        {
            return;
        }
        Asms.insert(Asms.end(), rvasms.Asms.begin(), rvasms.Asms.end());
    }

    void RVAsms::Insert(riscvasm *rvasm)
    {
        if (rvasm == nullptr)
        {
            return;
        }
        Asms.insert(Asms.begin(), rvasm);
    }

    void RVAsms::Insert(RVAsms *rvasms)
    {
        if (rvasms == nullptr)
        {
            return;
        }
        Asms.insert(Asms.begin(), rvasms->Asms.begin(), rvasms->Asms.end());
    }

    split::split(std::string desc) : riscvasm(AsmType::DESC)
    {
        show = desc;
    }

    std::string split::ToString()
    {
        return show;
    }

    label::label(Label label) : riscvasm(AsmType::LABEL)
    {
        Lbl = label;
    }

    std::string label::ToString()
    {
        return Lbl;
    }
    beqz::beqz(Register *rs, Label lb)
    {
        Srcs.push_back(rs);
        Lbl = lb;
    }
    std::string beqz::ToString()
    {
        return "beqz " + Srcs[0]->ToString() + ", " + Lbl;
    }
    bnez::bnez(Register *rs, Label lb)
    {
        Srcs.push_back(rs);
        Lbl = lb;
    }
    std::string bnez::ToString()
    {
        return "bnez " + Srcs[0]->ToString() + ", " + Lbl;
    }
    j::j(Label lb)
    {
        Lbl = lb;
    }
    std::string j::ToString()
    {
        return "j " + Lbl;
    }
    call::call(Label lb)
    {
        Lbl = lb;
    }
    std::string call::ToString()
    {
        return "call " + Lbl;
    }
    ret::ret()
    {
    }
    std::string ret::ToString()
    {
        return "ret";
    }
    ld::ld(Register *rs, Register *rd, Imm *imm12)
    {
        Srcs.push_back(rs);
        DstReg = rd;
        ImmVal = imm12;
    }
    std::string ld::ToString()
    {
        return "ld " + Srcs[0]->ToString() + ", " + std::to_string(ImmVal->ImmVal) + "(" + DstReg->ToString() + ")";
    }
    sd::sd(Register *rs2, Register *rs1, Imm *imm12)
    {
        Srcs.push_back(rs1);
        Srcs.push_back(rs2);
        ImmVal = imm12;
    }
    std::string sd::ToString()
    {
        return "sd " + Srcs[1]->ToString() + ", " + std::to_string(ImmVal->ImmVal) + "(" + Srcs[0]->ToString() + ")";
    }

    add::add(Register *rd, Register *rs1, Register *rs2)
    {
        DstReg = rd;
        Srcs.push_back(rs1);
        Srcs.push_back(rs2);
    }

    std::string add::ToString()
    {
        return "add " + DstReg->ToString() + ", " + Srcs[0]->ToString() + ", " + Srcs[1]->ToString();
    }
    addi::addi(Register *rd, Register *rs1, Imm *imm12)
    {
        DstReg = rd;
        Srcs.push_back(rs1);
        ImmVal = imm12;
    }
    std::string addi::ToString()
    {
        return "addi " + DstReg->ToString() + ", " + Srcs[0]->ToString() + ", " + std::to_string(ImmVal->ImmVal);
    }
    sub::sub(Register *rd, Register *rs1, Register *rs2)
    {
        DstReg = rd;
        Srcs.push_back(rs1);
        Srcs.push_back(rs2);
    }
    std::string sub::ToString()
    {
        return "sub " + DstReg->ToString() + ", " + Srcs[0]->ToString() + ", " + Srcs[1]->ToString();
    }
    slt::slt(Register *rd, Register *rs1, Register *rs2)
    {
        DstReg = rd;
        Srcs.push_back(rs1);
        Srcs.push_back(rs2);
    }
    std::string slt::ToString()
    {
        return "slt " + DstReg->ToString() + ", " + Srcs[0]->ToString() + ", " + Srcs[1]->ToString();
    }
    sgt::sgt(Register *rd, Register *rs1, Register *rs2)
    {
        DstReg = rd;
        Srcs.push_back(rs1);
        Srcs.push_back(rs2);
    }
    std::string sgt::ToString()
    {
        return "sgt " + DstReg->ToString() + ", " + Srcs[0]->ToString() + ", " + Srcs[1]->ToString();
    }
    seqz::seqz(Register *rd, Register *rs)
    {
        DstReg = rd;
        Srcs.push_back(rs);
    }
    std::string seqz::ToString()
    {
        return "seqz " + DstReg->ToString() + ", " + Srcs[0]->ToString();
    }
    snez::snez(Register *rd, Register *rs)
    {
        DstReg = rd;
        Srcs.push_back(rs);
    }
    std::string snez::ToString()
    {
        return "snez " + DstReg->ToString() + ", " + Srcs[0]->ToString();
    }
    mul::mul(Register *rd, Register *rs1, Register *rs2)
    {
        DstReg = rd;
        Srcs.push_back(rs1);
        Srcs.push_back(rs2);
    }
    std::string mul::ToString()
    {
        return "mul " + DstReg->ToString() + ", " + Srcs[0]->ToString() + ", " + Srcs[1]->ToString();
    }
    div::div(Register *rd, Register *rs1, Register *rs2)
    {
        DstReg = rd;
        Srcs.push_back(rs1);
        Srcs.push_back(rs2);
    }
    std::string div::ToString()
    {
        return "div " + DstReg->ToString() + ", " + Srcs[0]->ToString() + ", " + Srcs[1]->ToString();
    }
    rem::rem(Register *rd, Register *rs1, Register *rs2)
    {
        DstReg = rd;
        Srcs.push_back(rs1);
        Srcs.push_back(rs2);
    }
    std::string rem::ToString()
    {
        return "rem " + DstReg->ToString() + ", " + Srcs[0]->ToString() + ", " + Srcs[1]->ToString();
    }
    li::li(Register *rd, Imm *imm)
    {
        DstReg = rd;
        ImmVal = imm;
    }
    std::string li::ToString()
    {
        return "li " + DstReg->ToString() + ", " + std::to_string(ImmVal->ImmVal);
    }
    la::la(Register *rd, Label label)
    {
        DstReg = rd;
        Lbl = label;
    }
    std::string la::ToString()
    {
        return "la " + DstReg->ToString() + ", " + Lbl;
    }
    mv::mv(Register *rd, Register *rs)
    {
        DstReg = rd;
        Srcs.push_back(rs);
    }
    std::string mv::ToString()
    {
        assert(false);
        return "";
    }
}
