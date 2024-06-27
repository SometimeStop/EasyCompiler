#include "AstFunc.h"

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
    node->VType.Type = btype;
    node->LineNo = line;
    return node;
}

AstNode *ast::CreateFuncDefNode(int32_t line, BasicType btype, std::string name, AstNode *blk, AstNode *fpn)
{
    AstNode *node = new AstNode(AstNodeType::FuncDefType, line);
    node->VType.Type = btype;
    node->VarId = name;
    node->IsRef = false;
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

AstNode *ast::CreateFuncCallNode(int32_t line, std::string name, AstNode *params)
{
    AstNode *node = new AstNode(AstNodeType::FuncCallType, line);
    node->IsRef = true;
    node->VarId = name;

    if (params == nullptr)
    {
        params = new AstNode(AstNodeType::FuncRealParamsType);
    }

    node->Children.push_back(params);
    params->Parent = node;

    return node;
}

AstNode *ast::CreateFuncParamNode(int32_t line, BasicType btype, std::string name)
{
    AstNode *node = new AstNode(AstNodeType::FuncFormParamType, line);
    node->VType.Type = btype;
    node->VarId = name;
    return node;
}

AstNode *ast::CreateAssignNode(AstNode *lVal, AstNode *expr)
{
    AstNode *node = new StmtNode(StmtType::StmtAssign);
    node->Children.push_back(lVal);
    node->Children.push_back(expr);
    lVal->Parent = node;
    expr->Parent = node;
    return node;
}

AstNode *ast::CreateExprStmtNode(AstNode *expr)
{
    if (expr == nullptr)
    {
        AstNode *node = new StmtNode(StmtType::StmtExpr);
        return node;
    }
    else
    {
        AstNode *node = new StmtNode(StmtType::StmtExpr);
        node->Children.push_back(expr);
        expr->Parent = node;
        return node;
    }
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
    AstNode *node = new StmtNode(StmtType::StmtReturn);
    InsertAstNode(node, expr);
    return node;
}

AstNode *ast::CreateExprNode(OperatorType type, AstNode *leftOperator, AstNode *rightOperator)
{
    AstNode *node = new OperatorNode(type);
    InsertAstNode(node, leftOperator);
    if (rightOperator != nullptr)
    {
        InsertAstNode(node, rightOperator);
    }
    return node;
}

AstNode *ast::CreateDimNode()
{
    AstNode *node = new AstNode(AstNodeType::ArrayDimType);
    return node;
}

AstNode *ast::CreateArrayInitValNode()
{
    AstNode *node = new AstNode(AstNodeType::ArrayInitValType);
    return node;
}

AstNode *ast::CreateInitDimNode()
{
    AstNode *node = new AstNode(AstNodeType::ArrayInitLevelType);
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
