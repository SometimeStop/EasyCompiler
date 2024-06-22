
// Generated from sysy.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "sysyVisitor.h"


/**
 * This class provides an empty implementation of sysyVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  sysyBaseVisitor : public sysyVisitor {
public:

  virtual std::any visitCompileUnit(sysyParser::CompileUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(sysyParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(sysyParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBType(sysyParser::BTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDef(sysyParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstInitVal(sysyParser::ConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(sysyParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(sysyParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitVal(sysyParser::InitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(sysyParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncType(sysyParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFormParams(sysyParser::FuncFormParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFormParam(sysyParser::FuncFormParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncBasicParam(sysyParser::FuncBasicParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncArrayParam(sysyParser::FuncArrayParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(sysyParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItem(sysyParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentStmt(sysyParser::AssignmentStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(sysyParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockStmt(sysyParser::BlockStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(sysyParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(sysyParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(sysyParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStmt(sysyParser::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(sysyParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(sysyParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCond(sysyParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLVal(sysyParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpr(sysyParser::PrimaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(sysyParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(sysyParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOp(sysyParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncRealParams(sysyParser::FuncRealParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulExpr(sysyParser::MulExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulOp(sysyParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExpr(sysyParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddOp(sysyParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationExpr(sysyParser::RelationExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationOp(sysyParser::RelationOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqExpr(sysyParser::EqExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqOp(sysyParser::EqOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLAndExpr(sysyParser::LAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLOrExpr(sysyParser::LOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExpr(sysyParser::ConstExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntConst(sysyParser::IntConstContext *ctx) override {
    return visitChildren(ctx);
  }


};

