#pragma once
#include <vector>
#include <utility>
#include <map>
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

enum class ABI : int
{
    zero,
    ra,
    sp,
    gp,
    tp,
    t0,
    t1,
    t2,
    s0,
    s1,
    a0 = 10,
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    s2 = 18,
    s3,
    s4,
    s5,
    s6,
    s7,
    s8,
    s9,
    s10,
    s11,
    t3 = 28,
    t4,
    t5,
    t6,
    TOP = 32,
};

// Var->GetSPOffset <=> [imm12]
// SP                  <=>  (rs1)

typedef std::vector<int> Dim;
typedef std::vector<int> InitList;
typedef std::map<int, std::vector<int>> BlockPairs;