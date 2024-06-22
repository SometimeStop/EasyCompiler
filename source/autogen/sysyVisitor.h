
// Generated from sysy.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "sysyParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by sysyParser.
 */
class  sysyVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by sysyParser.
   */
    virtual std::any visitCompileUnit(sysyParser::CompileUnitContext *context) = 0;

    virtual std::any visitDecl(sysyParser::DeclContext *context) = 0;

    virtual std::any visitConstDecl(sysyParser::ConstDeclContext *context) = 0;

    virtual std::any visitBType(sysyParser::BTypeContext *context) = 0;

    virtual std::any visitConstDef(sysyParser::ConstDefContext *context) = 0;

    virtual std::any visitConstInitVal(sysyParser::ConstInitValContext *context) = 0;

    virtual std::any visitVarDecl(sysyParser::VarDeclContext *context) = 0;

    virtual std::any visitVarDef(sysyParser::VarDefContext *context) = 0;

    virtual std::any visitInitVal(sysyParser::InitValContext *context) = 0;

    virtual std::any visitFuncDef(sysyParser::FuncDefContext *context) = 0;

    virtual std::any visitFuncType(sysyParser::FuncTypeContext *context) = 0;

    virtual std::any visitFuncFormParams(sysyParser::FuncFormParamsContext *context) = 0;

    virtual std::any visitFuncFormParam(sysyParser::FuncFormParamContext *context) = 0;

    virtual std::any visitFuncBasicParam(sysyParser::FuncBasicParamContext *context) = 0;

    virtual std::any visitFuncArrayParam(sysyParser::FuncArrayParamContext *context) = 0;

    virtual std::any visitBlock(sysyParser::BlockContext *context) = 0;

    virtual std::any visitBlockItem(sysyParser::BlockItemContext *context) = 0;

    virtual std::any visitAssignmentStmt(sysyParser::AssignmentStmtContext *context) = 0;

    virtual std::any visitExprStmt(sysyParser::ExprStmtContext *context) = 0;

    virtual std::any visitBlockStmt(sysyParser::BlockStmtContext *context) = 0;

    virtual std::any visitIfStmt(sysyParser::IfStmtContext *context) = 0;

    virtual std::any visitWhileStmt(sysyParser::WhileStmtContext *context) = 0;

    virtual std::any visitBreakStmt(sysyParser::BreakStmtContext *context) = 0;

    virtual std::any visitContinueStmt(sysyParser::ContinueStmtContext *context) = 0;

    virtual std::any visitReturnStmt(sysyParser::ReturnStmtContext *context) = 0;

    virtual std::any visitExpr(sysyParser::ExprContext *context) = 0;

    virtual std::any visitCond(sysyParser::CondContext *context) = 0;

    virtual std::any visitLVal(sysyParser::LValContext *context) = 0;

    virtual std::any visitPrimaryExpr(sysyParser::PrimaryExprContext *context) = 0;

    virtual std::any visitNumber(sysyParser::NumberContext *context) = 0;

    virtual std::any visitUnaryExpr(sysyParser::UnaryExprContext *context) = 0;

    virtual std::any visitUnaryOp(sysyParser::UnaryOpContext *context) = 0;

    virtual std::any visitFuncRealParams(sysyParser::FuncRealParamsContext *context) = 0;

    virtual std::any visitMulExpr(sysyParser::MulExprContext *context) = 0;

    virtual std::any visitMulOp(sysyParser::MulOpContext *context) = 0;

    virtual std::any visitAddExpr(sysyParser::AddExprContext *context) = 0;

    virtual std::any visitAddOp(sysyParser::AddOpContext *context) = 0;

    virtual std::any visitRelationExpr(sysyParser::RelationExprContext *context) = 0;

    virtual std::any visitRelationOp(sysyParser::RelationOpContext *context) = 0;

    virtual std::any visitEqExpr(sysyParser::EqExprContext *context) = 0;

    virtual std::any visitEqOp(sysyParser::EqOpContext *context) = 0;

    virtual std::any visitLAndExpr(sysyParser::LAndExprContext *context) = 0;

    virtual std::any visitLOrExpr(sysyParser::LOrExprContext *context) = 0;

    virtual std::any visitConstExpr(sysyParser::ConstExprContext *context) = 0;

    virtual std::any visitIntConst(sysyParser::IntConstContext *context) = 0;


};

