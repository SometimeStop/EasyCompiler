#pragma once
#include "StmtNode.h"
#include "OperatorNode.h"
#include "FuncSybTable.h"
#include "VarSybTable.h"
#include "Block.h"
class IRGen
{
private:
    VarSybTable VarTable;
    FuncSybTable FuncTable;
    AstNode *Root;
    void VisitCompileUnit(AstNode *unit);
    void DefineFunction(AstNode *func);
    std::vector<Var *> DefineFormParams(AstNode *param);
    Var *DefineVar(AstNode *var);

    std::vector<IRInstruction *> BuildGlobDecl();
    std::vector<IRInstruction *> BuildBlock(AstNode *block);


public:
    IRGen(AstNode *root);
    void GenerateIR();
    ~IRGen();
};