#pragma once
#include "AstNode.h"
class OperatorNode : public AstNode
{
public:
    OperatorType SubNodeType;
    OperatorNode(OperatorType type, int32_t line = -1);
    std::string ToString() override;
};