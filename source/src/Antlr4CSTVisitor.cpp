#include "Antlr4CSTVisitor.h"

#define Instanceof(res, type, var) auto res = dynamic_cast<type>(var)

sysyCSTVisitor::sysyCSTVisitor()
{
}

sysyCSTVisitor::~sysyCSTVisitor()
{
}

AstNode *sysyCSTVisitor::run(sysyParser::CompileUnitContext *root)
{
    return std::any_cast<AstNode *>(visitCompileUnit(root));
}

std::any sysyCSTVisitor::visitCompileUnit(sysyParser::CompileUnitContext *ctx)
{
    auto compileUnitNode = new AstNode(AstNodeType::CompileUnitType);
    for (auto &item : ctx->children)
    {
        if (Instanceof(decl, sysyParser::DeclContext *, item))
        {
            auto tmpNode = visitDecl(decl);
            ast::InsertAstNode(compileUnitNode, std::any_cast<AstNode *>(tmpNode));
        }
        else if (Instanceof(funcDef, sysyParser::FuncDefContext *, item))
        {
            auto tmpNode = visitFuncDef(funcDef);
            ast::InsertAstNode(compileUnitNode, std::any_cast<AstNode *>(tmpNode));
        }
        else
        {
            assert(false);
        }
    }
    return compileUnitNode;
}

std::any sysyCSTVisitor::visitDecl(sysyParser::DeclContext *ctx)
{
    if (ctx->constDecl())
    {
        return visitConstDecl(ctx->constDecl());
    }
    else if (ctx->varDecl())
    {
        return visitVarDecl(ctx->varDecl());
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitConstDecl(sysyParser::ConstDeclContext *ctx)
{
    auto token = ctx->getStart();
    unsigned int lineno = token->getLine();

    BasicType btype = std::any_cast<BasicType>(visitBType(ctx->bType()));
    auto constDeclNode = ast::CreateDeclNode(lineno, btype);
    for (auto &constDefCtx : ctx->constDef())
    {
        auto tmpNode = visitConstDef(constDefCtx);
        ast::InsertAstNode(constDeclNode, std::any_cast<AstNode *>(tmpNode));
    }
    return constDeclNode;
}

/// @brief visit basic type
/// @param ctx
/// @return basic type of this node, only int.
std::any sysyCSTVisitor::visitBType(sysyParser::BTypeContext *ctx)
{
    if (ctx->T_INT())
    {
        return BasicType::TYPE_INT;
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitConstDef(sysyParser::ConstDefContext *ctx)
{
    auto token = ctx->getStart();
    unsigned int lineno = token->getLine();

    AstNode *constDefNode = new AstNode((char *)ctx->T_ID()->getText().c_str(), (int32_t)lineno);
    if (ctx->constExpr().empty())
    {
        auto constVarNode = std::any_cast<AstNode *>(visitConstInitVal(ctx->constInitVal()));
        ast::InsertAstNode(constDefNode, constVarNode);
        return constDefNode;
    }
    else // FIXME:array operation!!!
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitConstInitVal(sysyParser::ConstInitValContext *ctx)
{
    // single expr
    if (ctx->constExpr())
    {
        return visitConstExpr(ctx->constExpr());
    }
    else if (ctx->constInitVal().empty())
    {
        return nullptr;
    }
    else
    {
        assert(false);
        // FIXME:array operation!!!
    }
}

std::any sysyCSTVisitor::visitVarDecl(sysyParser::VarDeclContext *ctx)
{
    auto token = ctx->getStart();
    unsigned int lineno = token->getLine();

    BasicType btype = std::any_cast<BasicType>(visitBType(ctx->bType()));
    auto declNode = ast::CreateDeclNode(lineno, btype, false);
    for (auto &defCtx : ctx->varDef())
    {
        auto tmpNode = visitVarDef(defCtx);
        ast::InsertAstNode(declNode, std::any_cast<AstNode *>(tmpNode));
    }
    return declNode;
}

std::any sysyCSTVisitor::visitVarDef(sysyParser::VarDefContext *ctx)
{
    auto token = ctx->getStart();
    unsigned int lineno = token->getLine();

    AstNode *varDefNode = new AstNode((char *)ctx->T_ID()->getText().c_str(), (int32_t)lineno);
    if (ctx->initVal()) // branch 2: initVal has val
    {
        if (ctx->constExpr().empty())
        {
            auto initValNode = visitInitVal(ctx->initVal());
            ast::InsertAstNode(varDefNode, std::any_cast<AstNode *>(initValNode));
            return varDefNode;
        }
        else // FIXME:array operation!!!
        {
            assert(false);
        }
    }
    else // branch 1: initVal has NO val
    {
        if (ctx->constExpr().empty())
        {
            AstNode *zeroInitValNode = new AstNode((uint32_t)0);
            ast::InsertAstNode(varDefNode, zeroInitValNode);
            return varDefNode;
        }
        else // FIXME:array operation!!!
        {
            assert(false);
        }
    }
}

std::any sysyCSTVisitor::visitInitVal(sysyParser::InitValContext *ctx)
{
    if (ctx->expr())
    {
        return visitExpr(ctx->expr());
    }
    else
    {
        // FIXME:array operation!!!
        assert(false);
    }
}

std::any sysyCSTVisitor::visitFuncDef(sysyParser::FuncDefContext *ctx)
{
    auto token = ctx->getStart();
    unsigned int lineno = token->getLine();

    std::string name = ctx->T_ID()->getText();
    BasicType btype = std::any_cast<BasicType>(visitFuncType(ctx->funcType()));

    AstNode *funcFormParamsNode = nullptr;
    if (ctx->funcFormParams())
    {
        funcFormParamsNode = std::any_cast<AstNode *>(visitFuncFormParams(ctx->funcFormParams()));
    }

    AstNode *blockNode = std::any_cast<AstNode *>(visitBlock(ctx->block()));

    return ast::CreateFuncDefNode(lineno, btype, name.c_str(), blockNode, funcFormParamsNode);
}

std::any sysyCSTVisitor::visitFuncType(sysyParser::FuncTypeContext *ctx)
{
    if (ctx->T_INT())
    {
        return BasicType::TYPE_INT;
    }
    else if (ctx->T_VOID())
    {
        return BasicType::TYPE_VOID;
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitFuncFormParams(sysyParser::FuncFormParamsContext *ctx)
{
    AstNode *formParamsNode = new AstNode(AstNodeType::FuncFormParamsType);
    for (auto &formParamCtx : ctx->funcFormParam())
    {
        auto formParamNode = std::any_cast<AstNode *>(visitFuncFormParam(formParamCtx));
        ast::InsertAstNode(formParamsNode, formParamNode);
    }
    return formParamsNode;
}

std::any sysyCSTVisitor::visitFuncFormParam(sysyParser::FuncFormParamContext *ctx)
{
    if (ctx->funcBasicParam())
    {
        return visitFuncBasicParam(ctx->funcBasicParam());
    }
    else if (ctx->funcArrayParam())
    {
        return visitFuncArrayParam(ctx->funcArrayParam());
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitFuncBasicParam(sysyParser::FuncBasicParamContext *ctx)
{
    auto token = ctx->getStart();
    unsigned int lineno = token->getLine();

    BasicType btype = std::any_cast<BasicType>(visitBType(ctx->bType()));
    std::string name = ctx->T_ID()->getText();

    return ast::CreateFuncBasicParamsNode(lineno, btype, name.c_str());
}

std::any sysyCSTVisitor::visitFuncArrayParam(sysyParser::FuncArrayParamContext *ctx)
{
    // FIXME:array operation!!!
    assert(false);
    return std::any();
}

std::any sysyCSTVisitor::visitBlock(sysyParser::BlockContext *ctx)
{
    auto blockNode = new AstNode(AstNodeType::BlockType);
    for (auto &blockItem : ctx->blockItem())
    {
        auto tmpNode = visitBlockItem(blockItem);
        ast::InsertAstNode(blockNode, std::any_cast<AstNode *>(tmpNode));
    }
    return blockNode;
}

std::any sysyCSTVisitor::visitBlockItem(sysyParser::BlockItemContext *ctx)
{
    if (ctx->decl())
    {
        return visitDecl(ctx->decl());
    }
    else if (ctx->stmt())
    {
        return visitStmt(ctx->stmt());
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitStmt(sysyParser::StmtContext *ctx)
{
    if (Instanceof(assignCtx, sysyParser::AssignmentStmtContext *, ctx))
    {
        return visitAssignmentStmt(assignCtx);
    }
    else if (Instanceof(exprCtx, sysyParser::ExprStmtContext *, ctx))
    {
        return visitExprStmt(exprCtx);
    }
    else if (Instanceof(blockCtx, sysyParser::BlockStmtContext *, ctx))
    {
        return visitBlockStmt(blockCtx);
    }
    else if (Instanceof(ifCtx, sysyParser::IfStmtContext *, ctx))
    {
        return visitIfStmt(ifCtx);
    }
    else if (Instanceof(whileCtx, sysyParser::WhileStmtContext *, ctx))
    {
        return visitWhileStmt(whileCtx);
    }
    else if (Instanceof(breakCtx, sysyParser::BreakStmtContext *, ctx))
    {
        return visitBreakStmt(breakCtx);
    }
    else if (Instanceof(continueCtx, sysyParser::ContinueStmtContext *, ctx))
    {
        return visitContinueStmt(continueCtx);
    }
    else if (Instanceof(returnCtx, sysyParser::ReturnStmtContext *, ctx))
    {
        return visitReturnStmt(returnCtx);
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitAssignmentStmt(sysyParser::AssignmentStmtContext *ctx)
{
    auto lValNode = std::any_cast<AstNode *>(visitLVal(ctx->lVal()));
    auto exprNode = std::any_cast<AstNode *>(visitExpr(ctx->expr()));

    return ast::CreateAssignNode(lValNode, exprNode);
}

std::any sysyCSTVisitor::visitExprStmt(sysyParser::ExprStmtContext *ctx)
{
    if (ctx->expr())
    {
        auto exprNode = std::any_cast<AstNode *>(visitExpr(ctx->expr()));
        return exprNode;
    }
    else
    {
        return ast::CreateExprEntryNode();
    }
}

std::any sysyCSTVisitor::visitBlockStmt(sysyParser::BlockStmtContext *ctx)
{
    return visitBlock(ctx->block());
}

std::any sysyCSTVisitor::visitIfStmt(sysyParser::IfStmtContext *ctx)
{
    AstNode *ifNode = new AstNode(AstNodeType::IfType);
    auto condNode = std::any_cast<AstNode *>(visitCond(ctx->cond()));
    ast::InsertAstNode(ifNode, condNode);
    for (auto &stmtCtx : ctx->stmt())
    {
        auto stmtNode = std::any_cast<AstNode *>(visitStmt(stmtCtx));
        ast::InsertAstNode(ifNode, stmtNode);
    }
    return ifNode;
}

std::any sysyCSTVisitor::visitWhileStmt(sysyParser::WhileStmtContext *ctx)
{
    AstNode *whileNode = new AstNode(AstNodeType::WhileType);
    auto condNode = std::any_cast<AstNode *>(visitCond(ctx->cond()));
    auto stmtNode = std::any_cast<AstNode *>(visitStmt(ctx->stmt()));
    ast::InsertAstNode(whileNode, condNode);
    ast::InsertAstNode(whileNode, stmtNode);
    return whileNode;
}

std::any sysyCSTVisitor::visitBreakStmt(sysyParser::BreakStmtContext *ctx)
{
    AstNode *breakNode = new AstNode(AstNodeType::BreakType);
    return breakNode;
}

std::any sysyCSTVisitor::visitContinueStmt(sysyParser::ContinueStmtContext *ctx)
{
    AstNode *continueNode = new AstNode(AstNodeType::ContinueType);
    return continueNode;
}

std::any sysyCSTVisitor::visitReturnStmt(sysyParser::ReturnStmtContext *ctx)
{
    if (ctx->expr())
    {
        auto exprNode = std::any_cast<AstNode *>(visitExpr(ctx->expr()));
        return ast::CreateReturnNode(exprNode);
    }
    else
    {
        return ast::CreateReturnNode();
    }
}

std::any sysyCSTVisitor::visitExpr(sysyParser::ExprContext *ctx)
{
    auto exprNode = std::any_cast<AstNode *>(visitAddExpr(ctx->addExpr()));
    return ast::CreateExprEntryNode(AstNodeType::ExprType, exprNode);
}

std::any sysyCSTVisitor::visitCond(sysyParser::CondContext *ctx)
{
    auto exprNode = std::any_cast<AstNode *>(visitLOrExpr(ctx->lOrExpr()));
    return ast::CreateExprEntryNode(AstNodeType::CondExprType, exprNode);
}

std::any sysyCSTVisitor::visitLVal(sysyParser::LValContext *ctx)
{
    auto token = ctx->getStart();
    unsigned int lineno = token->getLine();

    std::string name = ctx->T_ID()->getText();

    if (ctx->expr().empty())
    {
        AstNode *node = new AstNode((char *)name.c_str(), lineno);
        return node;
    }
    else
    {
        // FIXME:array operation!!!
        assert(false);
    }
}

std::any sysyCSTVisitor::visitPrimaryExpr(sysyParser::PrimaryExprContext *ctx)
{
    if (ctx->expr())
    {
        return visitExpr(ctx->expr());
    }
    else if (ctx->lVal())
    {
        return visitLVal(ctx->lVal());
    }
    else if (ctx->number())
    {
        return visitNumber(ctx->number());
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitNumber(sysyParser::NumberContext *ctx)
{
    return visitIntConst(ctx->intConst());
}

std::any sysyCSTVisitor::visitUnaryExpr(sysyParser::UnaryExprContext *ctx)
{
    if (ctx->primaryExpr())
    {
        return visitPrimaryExpr(ctx->primaryExpr());
    }
    else if (ctx->unaryOp())
    {
        AstNodeType type = std::any_cast<AstNodeType>(visitUnaryOp(ctx->unaryOp()));
        AstNode *lOperator = std::any_cast<AstNode *>(visitUnaryExpr(ctx->unaryExpr()));
        return ast::CreateExprNode(type, lOperator);
    }
    else
    {
        auto token = ctx->getStart();
        unsigned int lineno = token->getLine();
        std::string name = ctx->T_ID()->getText();
        if (ctx->funcRealParams())
        {
            return ast::CreateFuncCallNode(lineno, name.c_str(), std::any_cast<AstNode *>(visitFuncRealParams(ctx->funcRealParams())));
        }
        else
        {
            return ast::CreateFuncCallNode(lineno, name.c_str());
        }
    }
}

std::any sysyCSTVisitor::visitUnaryOp(sysyParser::UnaryOpContext *ctx)
{
    AstNode *unaryOpNode = nullptr;
    if (ctx->T_ADD())
    {
        return AstNodeType::OperatorPos;
    }
    else if (ctx->T_SUB())
    {
        return AstNodeType::OperatorNeg;
    }
    else if (ctx->T_NOT())
    {
        return AstNodeType::OperatorNot;
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitFuncRealParams(sysyParser::FuncRealParamsContext *ctx)
{
    AstNode *funcRealParamsNode = new AstNode(AstNodeType::FuncRealParamsType);
    for (auto &exprCtx : ctx->expr())
    {
        auto exprNode = std::any_cast<AstNode *>(visitExpr(exprCtx));
        ast::InsertAstNode(funcRealParamsNode, exprNode);
    }
    return funcRealParamsNode;
}

std::any sysyCSTVisitor::visitMulExpr(sysyParser::MulExprContext *ctx)
{
    // mulExpr: unaryExpr | mulExpr mulOp unaryExpr;
    if (ctx->mulOp())
    {
        AstNodeType type = std::any_cast<AstNodeType>(visitMulOp(ctx->mulOp()));
        AstNode *lOperator = std::any_cast<AstNode *>(visitMulExpr(ctx->mulExpr()));
        AstNode *rOperator = std::any_cast<AstNode *>(visitUnaryExpr(ctx->unaryExpr()));
        return ast::CreateExprNode(type, lOperator, rOperator);
    }
    else
    {
        return visitUnaryExpr(ctx->unaryExpr());
    }
}

std::any sysyCSTVisitor::visitMulOp(sysyParser::MulOpContext *ctx)
{
    if (ctx->T_MUL())
    {
        return AstNodeType::OperatorMul;
    }
    else if (ctx->T_DIV())
    {
        return AstNodeType::OperatorDiv;
    }
    else if (ctx->T_MOD())
    {
        return AstNodeType::OperatorMod;
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitAddExpr(sysyParser::AddExprContext *ctx)
{
    if (ctx->addOp())
    {
        AstNodeType type = std::any_cast<AstNodeType>(visitAddOp(ctx->addOp()));
        AstNode *lOperator = std::any_cast<AstNode *>(visitAddExpr(ctx->addExpr()));
        AstNode *rOperator = std::any_cast<AstNode *>(visitMulExpr(ctx->mulExpr()));
        return ast::CreateExprNode(type, lOperator, rOperator);
    }
    else
    {
        return visitMulExpr(ctx->mulExpr());
    }
}

std::any sysyCSTVisitor::visitAddOp(sysyParser::AddOpContext *ctx)
{
    if (ctx->T_ADD())
    {
        return AstNodeType::OperatorAdd;
    }
    else if (ctx->T_SUB())
    {
        return AstNodeType::OperatorSub;
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitRelationExpr(sysyParser::RelationExprContext *ctx)
{
    if (ctx->relationOp())
    {
        AstNodeType type = std::any_cast<AstNodeType>(visitRelationOp(ctx->relationOp()));
        AstNode *lOperator = std::any_cast<AstNode *>(visitRelationExpr(ctx->relationExpr()));
        AstNode *rOperator = std::any_cast<AstNode *>(visitAddExpr(ctx->addExpr()));
        return ast::CreateExprNode(type, lOperator, rOperator);
    }
    else
    {
        return visitAddExpr(ctx->addExpr());
    }
}

std::any sysyCSTVisitor::visitRelationOp(sysyParser::RelationOpContext *ctx)
{
    if (ctx->T_LT())
    {
        return AstNodeType::OperatorLT;
    }
    else if (ctx->T_GT())
    {
        return AstNodeType::OperatorGT;
    }
    else if (ctx->T_LE())
    {
        return AstNodeType::OperatorLE;
    }
    else if (ctx->T_GE())
    {
        return AstNodeType::OperatorGE;
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitEqExpr(sysyParser::EqExprContext *ctx)
{
    if (ctx->eqOp())
    {
        AstNodeType type = std::any_cast<AstNodeType>(visitEqOp(ctx->eqOp()));
        AstNode *lOperator = std::any_cast<AstNode *>(visitEqExpr(ctx->eqExpr()));
        AstNode *rOperator = std::any_cast<AstNode *>(visitRelationExpr(ctx->relationExpr()));
        return ast::CreateExprNode(type, lOperator, rOperator);
    }
    else
    {
        return visitRelationExpr(ctx->relationExpr());
    }
}

std::any sysyCSTVisitor::visitEqOp(sysyParser::EqOpContext *ctx)
{
    if (ctx->T_EQ())
    {
        return AstNodeType::OperatorEQ;
    }
    else if (ctx->T_NE())
    {
        return AstNodeType::OperatorNE;
    }
    else
    {
        assert(false);
    }
}

std::any sysyCSTVisitor::visitLAndExpr(sysyParser::LAndExprContext *ctx)
{
    if (ctx->T_AND())
    {
        AstNodeType type = AstNodeType::OperatorAnd;
        AstNode *lOperator = std::any_cast<AstNode *>(visitLAndExpr(ctx->lAndExpr()));
        AstNode *rOperator = std::any_cast<AstNode *>(visitEqExpr(ctx->eqExpr()));
        return ast::CreateExprNode(type, lOperator, rOperator);
    }
    else
    {
        return visitEqExpr(ctx->eqExpr());
    }
}

std::any sysyCSTVisitor::visitLOrExpr(sysyParser::LOrExprContext *ctx)
{
    if (ctx->T_OR())
    {
        AstNodeType type = AstNodeType::OperatorOr;
        AstNode *lOperator = std::any_cast<AstNode *>(visitLOrExpr(ctx->lOrExpr()));
        AstNode *rOperator = std::any_cast<AstNode *>(visitLAndExpr(ctx->lAndExpr()));
        return ast::CreateExprNode(type, lOperator, rOperator);
    }
    else
    {
        return visitLAndExpr(ctx->lAndExpr());
    }
}

std::any sysyCSTVisitor::visitConstExpr(sysyParser::ConstExprContext *ctx)
{
    auto exprNode = std::any_cast<AstNode *>(visitAddExpr(ctx->addExpr()));
    return ast::CreateExprEntryNode(AstNodeType::ConstExprType, exprNode);
}

std::any sysyCSTVisitor::visitIntConst(sysyParser::IntConstContext *ctx)
{
    if (ctx->T_DEC_CONST())
    {
        AstNode *constNode = new AstNode((uint32_t)stoul(ctx->T_DEC_CONST()->getText(), nullptr, 10));
        return constNode;
    }
    else if (ctx->T_OCT_CONST())
    {
        AstNode *constNode = new AstNode((uint32_t)stoul(ctx->T_OCT_CONST()->getText(), nullptr, 8));
        return constNode;
    }
    else if (ctx->T_HEX_CONST())
    {
        AstNode *constNode = new AstNode((uint32_t)stoul(ctx->T_HEX_CONST()->getText(), nullptr, 16));
        return constNode;
    }
    else
    {
        assert(false);
    }
}
