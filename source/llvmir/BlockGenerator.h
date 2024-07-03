#pragma once
#include <vector>
#include "VarSybTable.h"
#include "FuncSybTable.h"
#include "IRInstruction.h"
#include "OperatorNode.h"
#include "StmtNode.h"
class BlockGenerator
{
public:
    VarSybTable VarIDTable;
    FuncSybTable &FuncTable;

    ir::Label *LoopStart;
    ir::Label *LoopEnd;
    ir::Label *FuncEnd;
    ID *RetPtr;
    ID *CurrentArray;
    BlockGenerator(FuncSybTable &funcTable, VarSybTable *parentVarTable = nullptr);

    void SetLoopLabel(ir::Label *lStart, ir::Label *lEnd);
    void SetFuncEndLabel(ir::Label *label, ID *retVal);
    void ReplaceLoopStart(ir::Label *&target);
    void ReplaceLoopEnd(ir::Label *&target);
    ir::IRInsts *MakeBlock(AstNode *block);
    ir::IRInsts *GenReturn(bool isVoid = false);
    ir::IRInsts *LoadReturn(bool isVoid = false);
    int HotCalculation(ir::IRInsts *&expr);

protected:
    ID *MakeID();
    ID *MakeID(std::string name, int32_t value, BasicType type);
    ID *MakeID(std::string name, BasicType type);
    ID *MakeID(BasicType type);
    ID *MakeNum(int32_t value);

    ir::IRInsts *MakeDecl(AstNode *decl);
    ir::IRInsts *MakeConstDecl(AstNode *constDecl);

    ir::IRInsts *MakeIDDecl(AstNode *idDecl);
    ir::IRInsts *MakeArrDecl(AstNode *arrDecl);

    ir::IRInsts *MakeIDConstDecl(AstNode *idConstDecl);
    ir::IRInsts *MakeArrConstDecl(AstNode *arrConstDecl);

    ir::IRInsts *MakeRightRef(AstNode *ref, ID *&idValueOut);
    ir::IRInsts *MakeIDRRef(AstNode *idRef, ID *&idValueOut);
    ir::IRInsts *MakeArrRRef(AstNode *arrayRef, ID *&idValueOut);
    ir::IRInsts *MakePtrRRef(AstNode *arrayRef, ID *&idPtrOut);

    ir::IRInsts *MakeLeftRef(AstNode *ref, ID *&idPtrOut);
    ir::IRInsts *MakeIDLRef(AstNode *idRef, ID *&idPtrOut);
    ir::IRInsts *MakeArrLRef(AstNode *arrayRef, ID *&idPtrOut);
    ir::IRInsts *MakePtrLRef(AstNode *arrayRef, ID *&idPtrOut);

    /// @brief a set of functions that initialize array
    Dim IdxToDim(int idx);
    int GetInitCount(int level);
    int GetLevel(int currIdx);
    ir::IRInsts *MakeArrInitLRef(int idx, ID *&idPtrOut);
    ir::IRInsts *MakeArrInitLRef(Dim &dim, ID *&idPtrOut);
    /// @brief for standard array initialization
    ir::IRInsts *MakeArrInit(AstNode *arrInit);
    ir::IRInsts *MakeArrInitLevel(AstNode *arrInitLevel, int level, int &currIdx);
    /// @brief for const array initialization
    ir::IRInsts *MakeArrConstInit(AstNode *arrConstInit);
    ir::IRInsts *MakeArrCInitLevel(AstNode *arrCInitLevel, int level, int &currIdx);
    int MakeConstExpr(AstNode *son);

    ir::IRInsts *MakeExpr(AstNode *son, ID *&resultOut);
    ir::IRInsts *MakeExprInner(AstNode *node, ID *&resultOut);
    ir::IRInsts *MakeExprOperator(OperatorNode *op, ID *&resultOut);

    ir::IRInsts *MakeFuncCall(AstNode *func, ID *&resultOut);
    ir::IRInsts *MakeRealParams(AstNode *params, IDArgs *&paramOut);

    /// @brief functions that make binary numeric IRs
    ir::IRInsts *MakeBinaryOperator(OperatorNode *op, ID *&resultOut);
    ir::IRInsts *MakeUnaryOperator(OperatorNode *op, ID *&resultOut);

    ir::IRInsts *MakeStatement(StmtNode *stmt);
    ir::IRInsts *MakeExprStmt(StmtNode *exprStmt);
    ir::IRInsts *MakeBlockStmt(StmtNode *blockStmt);
    ir::IRInsts *MakeAssignStmt(StmtNode *assignStmt);
    ir::IRInsts *MakeIfStmt(StmtNode *ifStmt);
    ir::IRInsts *MakeWhileStmt(StmtNode *whileStmt);
    ir::IRInsts *MakeBreakStmt(StmtNode *breakStmt);
    ir::IRInsts *MakeContinueStmt(StmtNode *continueStmt);
    ir::IRInsts *MakeReturnStmt(StmtNode *returnStmt);

    ir::IRInsts *MakeShortAnd(OperatorNode *andNode, ir::Label *trueLabel, ir::Label *falseLabel);
    ir::IRInsts *MakeShortOr(OperatorNode *orNode, ir::Label *trueLabel, ir::Label *falseLabel);
    ir::IRInsts *MakeCond(AstNode *cond, ir::Label *trueLabel, ir::Label *falseLabel);
    ir::IRInsts *MakeCondInner(AstNode *boolExpr, ir::Label *trueLabel, ir::Label *falseLabel);
    ir::IRInsts *MakeCondOperator(OperatorNode *op, ir::Label *trueLabel, ir::Label *falseLabel);
    ir::IRInsts *MakeRelationInner(AstNode *son, ID *&resultOut);
    ir::IRInsts *MakeRelationOperator(OperatorNode *op, ID *&resultOut);

    ir::ZExt *TryZExt(ID *id, ID *&result);
    ir::IRInsts *MakeExprToBr(ID *judge, ir::Label *trueLabel, ir::Label *falseLabel);
    ir::Alloca *MakeAlloca(ID *&ptr);
    ir::Alloca *MakeAlloca(ID *&ptr, Dim &dim);
    ir::Alloca *MakeAlloca(ID *&ptr, Dim &dim, bool isPtr);
    ir::Load *MakeLoad(ID *orign, ID *&resultOut);
    ir::Store *MakeStore(ID *value, ID *target);
    ir::ICmp *MakeICmp(ID *left, ICmpType cmpType, ID *right, ID *&resultOut);
    ir::Br *MakeBr(ID *cond, ir::Label *trueLabel, ir::Label *falseLabel);
    ir::Br *MakeBr(ir::Label *target);
    ir::Add *MakeAdd(ID *left, ID *right, ID *&resultOut);
    ir::Sub *MakeSub(ID *left, ID *right, ID *&resultOut);
    ir::Mul *MakeMul(ID *left, ID *right, ID *&resultOut);
    ir::SDiv *MakeSDiv(ID *left, ID *right, ID *&resultOut);
    ir::SRem *MakeSRem(ID *left, ID *right, ID *&resultOut);
    ir::Label *MakeLabel(ID *labelNo);
    ir::Ret *MakeRet(ID *ret = nullptr);
    ir::GetElementPtr *MakeGetElementPtr(ID *ptr, ID *&resultPtr, ID *offset);
    ir::GetPtr *MakeGetPtr(ID *ptr, ID *&resultPtr, ID *offset);
};
