#include "AST.h"

AstNode::AstNode(VarType vType, int32_t line)
{
    VType = vType;
    LineNo = line;

    NodeType = AstNodeType::ComplexType;
    Parent = nullptr;
}

AstNode::AstNode(uint32_t value)
{
    IntVal = value;
    LineNo = -1;

    NodeType = AstNodeType::IntConstType;
    VType = BasicType::TYPE_INT;
    Parent = nullptr;
}

AstNode::AstNode(char *id, int32_t line)
{
    VarId = id;
    LineNo = line;

    NodeType = AstNodeType::IdentifierType;
    VType = BasicType::TYPE_INT;
}

AstNode::AstNode(AstNodeType type, int32_t line)
{
    NodeType = type;
    LineNo = line;

    VType = BasicType::TYPE_UKNOWN;
    Parent = nullptr;
}

std::string AstNode::ToString()
{
    std::string ret;
    switch (NodeType)
    {
    case AstNodeType::CompileUnitType:
        ret += "CompileUnit";
        break;
    case AstNodeType::OperatorAdd:
        ret += "+(Binary)";
        break;
    case AstNodeType::OperatorPos:
        ret += "+(Unary)";
        break;
    case AstNodeType::OperatorSub:
        ret += "-(Binary)";
        break;
    case AstNodeType::OperatorNeg:
        ret += "-(Unary)";
        break;
    case AstNodeType::OperatorMul:
        ret += "*";
        break;
    case AstNodeType::OperatorDiv:
        ret += "/";
        break;
    case AstNodeType::OperatorMod:
        ret += "%";
        break;
    case AstNodeType::OperatorNot:
        ret += "!";
        break;
    case AstNodeType::OperatorLT:
        ret += "<";
        break;
    case AstNodeType::OperatorGT:
        ret += ">";
        break;
    case AstNodeType::OperatorLE:
        ret += "<=";
        break;
    case AstNodeType::OperatorGE:
        ret += ">=";
        break;
    case AstNodeType::OperatorEQ:
        ret += "==";
        break;
    case AstNodeType::OperatorNE:
        ret += "!=";
        break;
    case AstNodeType::OperatorAnd:
        ret += "&&";
        break;
    case AstNodeType::OperatorOr:
        ret += "||";
        break;
    case AstNodeType::IdentifierType:
        ret += "id: " + VarId;
        break;
    case AstNodeType::IntConstType:
        ret += "int: " + std::to_string(IntVal);
        break;
    case AstNodeType::IntType:
        ret += "type: int";
        break;
    case AstNodeType::ConstDeclType:
        ret += "const decl";
        break;
    case AstNodeType::DeclType:
        ret += "decl";
        break;
    case AstNodeType::FuncDefType:
        ret += "func def: " + VarId;
        break;
    case AstNodeType::FuncFormParamsType:
        ret += "func form params";
        break;
    case AstNodeType::FuncFormParamType:
        ret += "FP(" + VType.ToString() + "): " + VarId;
        break;
    case AstNodeType::FuncCallType:
        ret += "func call: " + VarId;
        break;
    case AstNodeType::FuncRealParamsType:
        ret += "func real params";
        break;
    case AstNodeType::BlockType:
        ret += "block";
        break;
    case AstNodeType::AssignType:
        ret += "=";
        break;
    case AstNodeType::ExprType:
        ret += "expr";
        break;
    case AstNodeType::CondExprType:
        ret += "cond expr";
        break;
    case AstNodeType::ConstExprType:
        ret += "const expr";
        break;
    case AstNodeType::IfType:
        ret += "if";
        break;
    case AstNodeType::WhileType:
        ret += "while";
        break;
    case AstNodeType::BreakType:
        ret += "break";
        break;
    case AstNodeType::ContinueType:
        ret += "continue";
        break;
    case AstNodeType::ReturnType:
        ret += "return";
        break;
    case AstNodeType::ComplexType:
        ret += "complex";
        break;
    case AstNodeType::UnknownType:
        ret += "unknown";
        break;
    default:
        break;
    }
    return ret;
}

AstNode *ast::CreateDeclNode(int32_t line, BasicType btype, bool isConst)
{
    AstNode *node = nullptr;
    if (isConst)
    {
        node = new AstNode(AstNodeType::ConstDeclType);
    }
    else
    {
        node = new AstNode(AstNodeType::DeclType);
    }
    node->VType.type = btype;
    node->LineNo = line;
    return node;
}

AstNode *ast::CreateFuncDefNode(int32_t line, BasicType btype, const char *name, AstNode *blk, AstNode *fpn)
{
    AstNode *node = new AstNode(AstNodeType::FuncDefType, line);
    node->VType.type = btype;
    node->VarId = name;
    if (!fpn)
    {
        fpn = new AstNode(AstNodeType::FuncFormParamsType);
    }

    if (!blk)
    {
        blk = new AstNode(AstNodeType::BlockType);
    }

    node->Children.push_back(fpn);
    fpn->Parent = node;

    node->Children.push_back(blk);
    blk->Parent = node;

    return node;
}

AstNode *ast::CreateFuncCallNode(int32_t line, const char *name, AstNode *params)
{
    AstNode *node = new AstNode(AstNodeType::FuncCallType, line);
    node->VarId = name;

    if (params == nullptr)
    {
        params = new AstNode(AstNodeType::FuncRealParamType);
    }

    node->Children.push_back(params);
    params->Parent = node;

    return node;
}

AstNode *ast::CreateFuncBasicParamsNode(int32_t line, BasicType btype, const char *name)
{
    AstNode *node = new AstNode(AstNodeType::FuncFormParamType, line);
    node->VType.type = btype;
    node->VarId = name;
    return node;
}

AstNode *ast::CreateAssignNode(AstNode *lVal, AstNode *expr)
{
    AstNode *node = new AstNode(AstNodeType::AssignType);
    node->Children.push_back(lVal);
    node->Children.push_back(expr);
    lVal->Parent = node;
    expr->Parent = node;
    return node;
}

AstNode *ast::CreateExprEntryNode(AstNodeType type, AstNode *expr)
{
    if (expr == nullptr)
    {
        return nullptr;
    }
    else
    {
        AstNode *node = new AstNode(type);
        node->Children.push_back(expr);
        expr->Parent = node;
        return node;
    }
}

AstNode *ast::CreateReturnNode(AstNode *expr)
{
    AstNode *node = new AstNode(AstNodeType::ReturnType);
    if (expr == nullptr)
    {
        return node;
    }
    else
    {
        InsertAstNode(node, expr);
        return node;
    }
}

AstNode *ast::CreateExprNode(AstNodeType type, AstNode *leftOperator, AstNode *rightOperator)
{
    AstNode *node = new AstNode(type);
    InsertAstNode(node, leftOperator);
    if (rightOperator != nullptr)
    {
        InsertAstNode(node, rightOperator);
    }
    return node;
}

void ast::InsertAstNode(AstNode *parent, AstNode *child)
{
    if (child == nullptr)
    {
        return;
    }
    child->Parent = parent;
    parent->Children.push_back(child);
    return;
}
