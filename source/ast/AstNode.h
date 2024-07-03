#pragma once
#include <vector>
#include <cstdint>
#include <string>
#include "VarType.h"
#include "type.h"
#include "IRInstruction.h"
class AstNode
{
public:
    AstNode *Parent;
    std::vector<AstNode *> Children;
    AstNodeType NodeType;
    int32_t LineNo;
    VarType VType;
    uint32_t IntVal;
    std::string VarId;
    bool IsRef;
    /// @brief use variable type to create node
    AstNode(VarType type, int32_t line);
    /// @brief create an int value node
    AstNode(uint32_t value);
    AstNode(std::string id, int32_t line, bool isRef = false);
    AstNode(AstNodeType type, int32_t line = -1);
    virtual std::string ToString();
};