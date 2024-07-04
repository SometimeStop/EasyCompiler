#pragma once
#include "ID.h"
#include "IRInstruction.h"
#include "VarSybTable.h"
#include <vector>
class Function
{
public:
    std::string Name;
    VarType RetType;
    IDArgs Args;
    ir::IRInsts AllocaIR;
    ir::IRInsts StdIR;
    ir::IRInsts AllIR;
    BlockPairs Pairs;
    int NameNo;
    bool IsBuildIn;
    bool CallExist;
    Function(std::string name, BasicType retType, bool isBuildIn = false);
    void AddArg(ID *arg = nullptr);
    void AddArg(IDArgs &args);
    void AddIR(ir::IRInsts &insts);
    int GetArgCount();
    void Print();
    void AssignAllNo();
    int Prologue();
    ~Function();
private:
    int GetNameNo();
};