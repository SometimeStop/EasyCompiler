#pragma once
#include "riscvasm.h"
#include <unordered_map>

class RegMan
{
private:
    void Init();

public:
    // Assigned number -> Variable
    std::unordered_map<int, Var *> Vars;
    // ABI chart number -> Virtual registers (after using register assignment algorithm, should only use the regs listed in enum ABI)

    std::unordered_map<ABI, std::unordered_map<int, Var *>> RegToVar;
    std::unordered_map<ABI, Register *> PhyRegs;
    Var *&operator[](int idx);
    Register *&operator()(ABI idx);
    void CreateAddVar(int assignedNo, int offset, int *sp);
    void CreateAddVar(int assignedNo, Register *reg);
    void CreateAddVar(int assignedNo, ABI regABI);
    void AddVar(int assignedNo, Var *v);
    void AddVarInRegInfo(int assignedNo, ABI idx);
    void RemoveVarInRegInfo(int assignedNo, ABI idx);
    bool IsVarInReg(int assignedNo, ABI &abiOut);
    void AutoSetVarInRegInfo(int assignedNo, ABI idx);
    Register *GetReg();
    Register *SP();
    void Reset();
    RegMan();
    ~RegMan();
};