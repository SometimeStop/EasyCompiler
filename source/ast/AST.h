#pragma once

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include "type.h"

enum class AstNodeType
{
    CompileUnitType,

    /// @brief operator types
    /// @brief operator "+"
    OperatorAdd,
    OperatorPos,

    /// @brief operator "-"
    OperatorSub,
    OperatorNeg,

    /// @brief operator "*"
    OperatorMul,

    /// @brief operator "/"
    OperatorDiv,

    /// @brief operator "%"
    OperatorMod,

    /// @brief operator "!"
    OperatorNot,

    /// @brief operator "<"
    OperatorLT,

    /// @brief operator ">"
    OperatorGT,

    /// @brief operator "<="
    OperatorLE,

    /// @brief operator ">="
    OperatorGE,

    /// @brief operator "=="
    OperatorEQ,

    /// @brief operator "!="
    OperatorNE,

    /// @brief operator "&&"
    OperatorAnd,

    /// @brief operator "||"
    OperatorOr,

    /// @brief id type
    IdentifierType,

    /// @brief int const type (value)
    IntConstType,

    /// @brief int type (saved keyword)
    IntType,

    ConstDeclType,
    DeclType,

    FuncDefType,
    FuncFormParamsType,
    FuncFormParamType,

    FuncCallType,
    FuncRealParamsType,
    FuncRealParamType,

    BlockType,
    AssignType,

    ExprType,
    ConstExprType,
    CondExprType,

    IfType,
    WhileType,
    BreakType,
    ContinueType,
    ReturnType,

    ComplexType,
    UnknownType,
};

enum class IntConstType
{
    DecConst,
    OctConst,
    HexConst,
};

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

    /// @brief use variable type to create node
    AstNode(VarType type, int32_t line);

    /// @brief create an int value node
    AstNode(uint32_t value);
    AstNode(char *id, int32_t line);
    AstNode(AstNodeType type, int32_t line = -1);

    std::string ToString();
};

namespace ast
{
    AstNode *CreateDeclNode(int32_t line, BasicType btype, bool isConst = true);
    AstNode *CreateFuncDefNode(int32_t line, BasicType btype, const char *name, AstNode *blk, AstNode *fpn = nullptr);
    AstNode *CreateFuncCallNode(int32_t line, const char *name, AstNode *params = nullptr);
    AstNode *CreateFuncBasicParamsNode(int32_t line, BasicType btype, const char *name);
    AstNode *CreateAssignNode(AstNode *lVal, AstNode *expr);
    AstNode *CreateExprEntryNode(AstNodeType type = AstNodeType::ExprType, AstNode *expr = nullptr);
    AstNode *CreateReturnNode(AstNode *expr = nullptr);
    AstNode *CreateExprNode(AstNodeType type, AstNode *leftOperator, AstNode *rightOperator = nullptr);
    void InsertAstNode(AstNode *parent, AstNode *child);
}
