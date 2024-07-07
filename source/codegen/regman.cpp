#include "regman.h"
#include <cassert>
void RegMan::Init()
{
    for (int i = 0; i < 32; i++)
    {
        ABI abi = static_cast<ABI>(i);
        PhyRegs[abi] = new Register(abi);
    }
}
Var *&RegMan::operator[](int idx)
{
    return Vars[idx];
}

Register *&RegMan::operator()(ABI idx)
{
    return PhyRegs[idx];
}

void RegMan::CreateAddVar(int assignedNo, int offset, int *sp)
{
    assert(Vars.find(assignedNo) == Vars.end());
    Vars[assignedNo] = new Var(offset, sp);
}

void RegMan::CreateAddVar(int assignedNo, Register *reg)
{
    assert(Vars.find(assignedNo) == Vars.end());
    Vars[assignedNo] = new Var(reg);
}

void RegMan::CreateAddVar(int assignedNo, ABI regABI)
{
    assert(Vars.find(assignedNo) == Vars.end());
    Vars[assignedNo] = new Var(PhyRegs[regABI]);
}

void RegMan::AddVar(int assignedNo, Var *v)
{
    Vars[assignedNo] = v;
}

void RegMan::AddVarInRegInfo(int assignedNo, ABI idx)
{
    assert(Vars.find(assignedNo) != Vars.end());
    RegToVar[idx][assignedNo] = Vars[assignedNo];
}

void RegMan::RemoveVarInRegInfo(int assignedNo, ABI idx)
{
    assert(Vars.find(assignedNo) != Vars.end());
    assert(RegToVar[idx].erase(assignedNo));
}

bool RegMan::IsVarInReg(int assignedNo, ABI &abiOut)
{
    if (Vars[assignedNo]->InReg)
    {
        abiOut = Vars[assignedNo]->Reg->ABINo;
        return true;
    }
    return false;
}

void RegMan::AutoSetVarInRegInfo(int assignedNo, ABI idx)
{
    auto var = Vars[assignedNo];
    if (var->InReg)
    {
        ABI oldAbi = var->Reg->ABINo;
        var->SetInReg(PhyRegs[idx]);
        var->OnlyInReg();
        RemoveVarInRegInfo(assignedNo, oldAbi);
        AddVarInRegInfo(assignedNo, idx);
        return;
    }
    var->SetInReg(PhyRegs[idx]);
    var->OnlyInReg();
    AddVarInRegInfo(assignedNo, idx);
}

Register *RegMan::GetReg()
{
    return nullptr;
}

Register *RegMan::SP()
{
    return PhyRegs[ABI::sp];
}

void RegMan::Reset()
{
    Vars.clear();
    RegToVar.clear();
    PhyRegs.clear();
    Init();
}

RegMan::RegMan()
{
    Init();
}

RegMan::~RegMan() {}
