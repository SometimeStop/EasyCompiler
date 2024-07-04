#include "riscvasm.h"

Oprd::Oprd() {}

Imm::Imm(int32_t immVal, bool isImm12)
{
    IsImm12 = isImm12;
    ImmVal = immVal;
}

Reg::Reg(int32_t *regNo)
{
    RegNo = regNo;
}

rv::riscvasm::riscvasm(AsmType t) : Type(t) {}

Reg *&rv::riscvasm::rd()
{
    return DstReg;
}

Reg *&rv::riscvasm::rs1()
{
    return Srcs[0];
}

Reg *&rv::riscvasm::rs2()
{
    return Srcs[1];
}

Imm *&rv::riscvasm::imm()
{
    return ImmVal;
}
