#include "Block.h"

std::vector<IRInstruction *> Block::BuildStmt(AstNode *stmt)
{
    std::vector<IRInstruction *> instructions;
    // Alloca *alloca = new Alloca();
    return std::vector<IRInstruction *>();
}


std::vector<IRInstruction *> Block::BuildDecl(AstNode *decl)
{
    
}

Block::Block(VarSybTable &parent)
{
    SybTable.Parent = &parent;
}