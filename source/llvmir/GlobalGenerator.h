#pragma once
#include "BlockGenerator.h"
class GlobalGenerator : public BlockGenerator
{
public:
    FuncSybTable FuncTable;
    Function *CurrentFunc;
    AstNode *Root;
    InitList *CurrentInitList;

    void MakeFuncDef(AstNode *funcDef);
    ir::IRInsts *MakeFuncFormParams(AstNode *funcFPs, BlockGenerator &funcBlock);

    void MakeGlobalDecl(AstNode *decl);
    void MakeGlobalConstDecl(AstNode *constDecl);

    void MakeGIDDecl(AstNode *idDecl);
    void MakeGArrDecl(AstNode *arrDecl);
    void MakeGArrInitLevel(AstNode *arrInitLevel, int level, int &currIdx);
    void MakeGIDConstDecl(AstNode *idConstDecl);
    void MakeGArrConstDecl(AstNode *arrConstDecl);

    void MakeInitList(AstNode *arrInit);

    ir::Global *MakeGlobalAlloca(std::string name, ID *&globSyb, ID *initVal, bool isConst = false);
    ir::Global *MakeGlobalAlloca(std::string name, ID *&globSyb, Dim &dim, InitList *initVal, bool isConst = false);
    void AddBuildInFunc();


    GlobalGenerator(AstNode *compileUnit);
    ir::IRInsts GlobalDeclIRs;
    bool Generate();
    void Print();
};
