#pragma once
#include <vector>
enum class BasicType
{
    TYPE_NULL,
    TYPE_VOID,
    TYPE_INT32,
    TYPE_INT1,
    TYPE_PTR,
    TYPE_UNKNOW,
};

enum class AstNodeType
{
    CompileUnitType,

    OperatorType,

    /// @brief id type
    IdentifierType,

    /// @brief int const type (value)
    NumValueType,

    DeclType,
    ConstDeclType,

    FuncDefType,
    FuncFormParamsType,
    FuncFormParamType,

    FuncCallType,
    FuncRealParamsType,

    BlockType,
    ExprType,
    ConstExprType,
    CondExprType,

    StatementType,
    ArrayDimType,
    ArrayInitValType,
    ArrayInitLevelType,

    UnknownType,
};

enum class StmtType
{
    StmtAssign,
    StmtExpr,
    StmtIf,
    StmtBlock,
    StmtWhile,
    StmtBreak,
    StmtContinue,
    StmtReturn,
};

enum class OperatorType
{
    /// @brief operator types
    /// @brief operator "+"
    OperatorAdd,

    /// @brief operator "-"
    OperatorSub,

    /// @brief operator "*"
    OperatorMul,

    /// @brief operator "/"
    OperatorDiv,

    /// @brief operator "%"
    OperatorMod,

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

    /// @brief Unary operators
    /// @brief operator "!"
    OperatorNot,
    OperatorPos,
    OperatorNeg,
};

typedef std::vector<int> Dim;
typedef std::vector<int> InitList;