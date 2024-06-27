#pragma once
#include "AstNode.h"
class StmtNode : public AstNode
{
public:
    StmtType SubNodeType;
    StmtNode(StmtType type, int32_t line = -1);
    std::string ToString() override;
};