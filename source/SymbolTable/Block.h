#pragma once
#include <vector>
#include "VarSybTable.h"
#include "IRInstruction.h"
#include "OperatorNode.h"
#include "StmtNode.h"
class Block
{
public:
    VarSybTable SybTable;
    std::vector<IRInstruction *> BuildStmt(AstNode *stmt);
    std::vector<IRInstruction *> BuildAssign(AstNode *assign);
    std::vector<IRInstruction *> BuildDecl(AstNode *decl);
    Block(VarSybTable& parent);
};
