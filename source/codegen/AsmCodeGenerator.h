#pragma once
#include "GlobalGenerator.h"
#include "riscvasm.h"
#include "riscvfunc.h"
#include "regman.h"
class AsmCodeGenerator
{
private:
    int *sp;
    RegMan regman;
    Function *func; // Current function
    GlobalGenerator *irGen;
    rv::RVAsms *GenFunction();
    rv::RVAsms *TransLoad(ir::IRInstruction *inst);
    rv::RVAsms *TransStore(ir::IRInstruction *inst);
    rv::RVAsms *TransCall(ir::IRInstruction *inst);
    rv::RVAsms *TransRet(ir::IRInstruction *inst);
    rv::RVAsms *TransBinOp(ir::IRInstruction *inst);
    rv::RVAsms *TransICmp(ir::IRInstruction *inst);
    rv::RVAsms *TransBr(ir::IRInstruction *inst);
    rv::RVAsms *TransLabel(ir::IRInstruction *inst);
    rv::RVAsms *TransGetelementptr(ir::IRInstruction *inst);
    rv::RVAsms *TransGetptr(ir::IRInstruction *inst);

    rv::RVAsms *ImmSafeAdd(ABI rdAbi, ABI rsAbi, Imm *imm);
    rv::RVAsms *RecoverRegs();
    rv::RVAsms *SaveRegs();
    rv::RVAsms *FindReg(ABI &out, ABI no1 = ABI::TOP, ABI no2 = ABI::TOP);
    rv::RVAsms *TryLoadToReg(Imm *imm, ABI &out, ABI no1 = ABI::TOP, ABI no2 = ABI::TOP);
    rv::RVAsms *TryLoadToReg(int sourceNo, ABI &out, ABI no1 = ABI::TOP, ABI no2 = ABI::TOP);
    rv::RVAsms *TryLoadToReg(Var *source, ABI &out, ABI no1 = ABI::TOP, ABI no2 = ABI::TOP);
    bool FitImm12(int value);

    rv::RVAsms *EasyStore();

public:
    AsmCodeGenerator(GlobalGenerator *ir);
    ~AsmCodeGenerator();
};

class AsmPlainCodeGenerator
{
public:
    AsmPlainCodeGenerator(GlobalGenerator *Gen);

    int *sp;
    RegMan regman;
    Function *func; // Current function
    GlobalGenerator *irGen;
    rv::RVAsms *GenFunction();

    rv::RVAsms *EasyLoad(ir::IRInstruction *inst);
    rv::RVAsms *EasyAlloca(ir::IRInstruction *inst);
    rv::RVAsms *EasyStoreParam(ir::IRInstruction *inst, int cnt);
    rv::RVAsms *EasyStore(ir::IRInstruction *inst);
    rv::RVAsms *EasyCall(ir::IRInstruction *inst);
    rv::RVAsms *EasyRet(ir::IRInstruction *inst);
    rv::RVAsms *EasyBinOp(ir::IRInstruction *inst);
    rv::RVAsms *EasyICmp(ir::IRInstruction *inst);
    rv::RVAsms *EasyBr(ir::IRInstruction *inst);
    rv::RVAsms *EasyLabel(ir::IRInstruction *inst);
    rv::RVAsms *EasyGetelementptr(ir::IRInstruction *inst);
    rv::RVAsms *EasyGetptr(ir::IRInstruction *inst);

    rv::RVAsms *EasyAddr(ID *id, ABI dst);
    rv::RVAsms *EasyLW(int offset, ABI dst);
    rv::RVAsms *EasyLW(ID *id, ABI dst);
    rv::RVAsms *EasySWStack(int offset, ABI src);
    rv::RVAsms *EasySWStack(ID *id, ABI src);
    rv::RVAsms *EasyGlob(std::string name, ABI dst);
    rv::RVAsms *EasyOperand(ID *arg, ABI dest);
    rv::RVAsms *EasyEpilogue();
    bool FitImm12(int value);
    void Run();
};