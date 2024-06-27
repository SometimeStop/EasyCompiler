#pragma once

#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include "OperatorNode.h"
#include "StmtNode.h"
#include "AstNode.h"
namespace ast
{
    AstNode *CreateDeclNode(int32_t line, BasicType btype, bool isConst = true);
    AstNode *CreateFuncDefNode(int32_t line, BasicType btype, std::string name, AstNode *blk, AstNode *fpn = nullptr);
    AstNode *CreateFuncCallNode(int32_t line, std::string name, AstNode *params = nullptr);
    AstNode *CreateFuncParamNode(int32_t line, BasicType btype, std::string name);
    AstNode *CreateAssignNode(AstNode *lVal, AstNode *expr);
    AstNode *CreateExprStmtNode(AstNode *expr = nullptr);
    AstNode *CreateExprEntryNode(AstNodeType type = AstNodeType::ExprType, AstNode *expr = nullptr);
    AstNode *CreateReturnNode(AstNode *expr = nullptr);
    AstNode *CreateExprNode(OperatorType type, AstNode *leftOperator, AstNode *rightOperator = nullptr);
    AstNode *CreateDimNode();
    AstNode *CreateArrayInitValNode();
    AstNode *CreateInitDimNode();
    void InsertAstNode(AstNode *parent, AstNode *child);
}
