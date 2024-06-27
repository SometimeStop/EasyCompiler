#pragma once

enum class BasicType{
    TYPE_NULL,
    TYPE_VOID,
    TYPE_INT,
    TYPE_ARRAY,
    TYPE_UKNOWN,
};

enum class AstNodeType
{
    CompileUnitType,

    OperatorType,

    /// @brief id type
    IdentifierType,

    /// @brief int const type (value)
    IntConstType,

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
};
