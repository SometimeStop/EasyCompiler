#pragma once

#include "AstNode.h"
#include "sysyBaseVisitor.h"

class sysyCSTVisitor : public sysyBaseVisitor
{
public:
    sysyCSTVisitor();
    virtual ~sysyCSTVisitor();
    AstNode *run(sysyParser::CompileUnitContext *root);

protected:
    std::any visitCompileUnit(sysyParser::CompileUnitContext *ctx) override;
    std::any visitDecl(sysyParser::DeclContext *ctx) override;
    std::any visitConstDecl(sysyParser::ConstDeclContext *ctx) override;
    std::any visitBType(sysyParser::BTypeContext *ctx) override;
    std::any visitConstDef(sysyParser::ConstDefContext *ctx) override;
    std::any visitConstInitVal(sysyParser::ConstInitValContext *ctx) override;
    std::any visitVarDecl(sysyParser::VarDeclContext *ctx) override;
    std::any visitVarDef(sysyParser::VarDefContext *ctx) override;
    std::any visitInitVal(sysyParser::InitValContext *ctx) override;
    std::any visitFuncDef(sysyParser::FuncDefContext *ctx) override;
    std::any visitFuncType(sysyParser::FuncTypeContext *ctx) override;
    std::any visitFuncFormParams(sysyParser::FuncFormParamsContext *ctx) override;
    std::any visitFuncFormParam(sysyParser::FuncFormParamContext *ctx) override;
    std::any visitFuncBasicParam(sysyParser::FuncBasicParamContext *ctx) override;
    std::any visitFuncArrayParam(sysyParser::FuncArrayParamContext *ctx) override;
    std::any visitBlock(sysyParser::BlockContext *ctx) override;
    std::any visitBlockItem(sysyParser::BlockItemContext *ctx) override;
    std::any visitStmt(sysyParser::StmtContext * ctx);
    std::any visitAssignmentStmt(sysyParser::AssignmentStmtContext *ctx) override;
    std::any visitExprStmt(sysyParser::ExprStmtContext *ctx) override;
    std::any visitBlockStmt(sysyParser::BlockStmtContext *ctx) override;
    std::any visitIfStmt(sysyParser::IfStmtContext *ctx) override;
    std::any visitWhileStmt(sysyParser::WhileStmtContext *ctx) override;
    std::any visitBreakStmt(sysyParser::BreakStmtContext *ctx) override;
    std::any visitContinueStmt(sysyParser::ContinueStmtContext *ctx) override;
    std::any visitReturnStmt(sysyParser::ReturnStmtContext *ctx) override;
    std::any visitExpr(sysyParser::ExprContext *ctx) override;
    std::any visitCond(sysyParser::CondContext *ctx) override;
    std::any visitLVal(sysyParser::LValContext *ctx) override;
    std::any visitPrimaryExpr(sysyParser::PrimaryExprContext *ctx) override;
    std::any visitNumber(sysyParser::NumberContext *ctx) override;
    std::any visitUnaryExpr(sysyParser::UnaryExprContext *ctx) override;
    std::any visitUnaryOp(sysyParser::UnaryOpContext *ctx) override;
    std::any visitFuncRealParams(sysyParser::FuncRealParamsContext *ctx) override;
    std::any visitMulExpr(sysyParser::MulExprContext *ctx) override;
    std::any visitMulOp(sysyParser::MulOpContext *ctx) override;
    std::any visitAddExpr(sysyParser::AddExprContext *ctx) override;
    std::any visitAddOp(sysyParser::AddOpContext *ctx) override;
    std::any visitRelationExpr(sysyParser::RelationExprContext *ctx) override;
    std::any visitRelationOp(sysyParser::RelationOpContext *ctx) override;
    std::any visitEqExpr(sysyParser::EqExprContext *ctx) override;
    std::any visitEqOp(sysyParser::EqOpContext *ctx) override;
    std::any visitLAndExpr(sysyParser::LAndExprContext *ctx) override;
    std::any visitLOrExpr(sysyParser::LOrExprContext *ctx) override;
    std::any visitConstExpr(sysyParser::ConstExprContext *ctx) override;
    std::any visitIntConst(sysyParser::IntConstContext *ctx) override;
};
