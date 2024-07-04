#include "GlobalGenerator.h"
#include <fstream>
#include <iostream>
bool GlobalGenerator::Generate()
{
    AddBuildInFunc();
    for (auto node : Root->Children)
    {
        switch (node->NodeType)
        {
        case AstNodeType::FuncDefType:
            MakeFuncDef(node);
            break;
        case AstNodeType::DeclType:
            MakeGlobalDecl(node);
            break;
        case AstNodeType::ConstDeclType:
            MakeGlobalConstDecl(node);
            break;
        default:
            assert(false && "Unexpected node type in Compile-Unit node");
            break;
        }
    }

    std::cout << "[IRGen] Complete!" << std::endl;
    return true;
}

void GlobalGenerator::Print()
{
    std::string file = "/home/william/compiler/MyCompiler/out/1_self.ll";
    std::ofstream ofs(file, std::ios::out);
    for (int i = 0; i < GlobalDeclIRs.size(); i++)
    {
        ofs << GlobalDeclIRs[i]->ToString() << GlobalDeclIRs[i]->CmtString() << std::endl;
    }
    ofs.close();
    FuncTable.Print();
}

void GlobalGenerator::MakeFuncDef(AstNode *funcDef)
{
    auto funcFPs = funcDef->Children[0];
    auto funcBlock = funcDef->Children[1];
    bool isVoid = false;
    CurrentFunc = new Function(funcDef->VarId, funcDef->VType);
    switch (funcDef->VType)
    {
    case BasicType::TYPE_INT32:
        isVoid = false;
        break;
    case BasicType::TYPE_VOID:
        isVoid = true;
        break;
    default:
        assert(false && "Invalid function def type");
        break;
    }
    assert(FuncTable.AddFunc(funcDef->VarId, CurrentFunc) && "Function redefinition!");
    BlockGenerator *block = new BlockGenerator(FuncTable, &VarIDTable);
    CurrentFunc->AddIR(*block->GenReturn(isVoid));
    CurrentFunc->AddIR(*MakeFuncFormParams(funcFPs, *block));
    CurrentFunc->AddIR(*(block->MakeBlock(funcBlock)));
    CurrentFunc->AddIR(*block->LoadReturn(isVoid));
    CurrentFunc = nullptr;
    delete block;
}

ir::IRInsts *GlobalGenerator::MakeFuncFormParams(AstNode *funcFPs, BlockGenerator &funcBlock)
{
    auto insts = ir::GenInsts();
    for (auto decl : funcFPs->Children)
    {
        if (decl->Children.empty())
        {
            ID *val = MakeID(BasicType::TYPE_INT32);
            CurrentFunc->AddArg(val);
            ID *ptr = nullptr;
            insts->Append(MakeAlloca(ptr));
            insts->Append(MakeStore(val, ptr));
            assert(funcBlock.VarIDTable.AddVar(decl->VarId, ptr));
        }
        else
        {
            Dim arrDim;
            ID *fp = MakeID(BasicType::TYPE_PTR);
            fp->AddPtr();
            CurrentFunc->AddArg(fp);
            for (auto dim : decl->Children[0]->Children)
            {
                arrDim.push_back(MakeConstExpr(dim));
            }
            fp->Type.AppendArray(arrDim);
            // FIXME: not a good implement
            ID *ptr = nullptr;
            insts->Append(MakeAlloca(ptr, arrDim, true));
            insts->Append(MakeStore(fp, ptr));
            assert(funcBlock.VarIDTable.AddVar(decl->VarId, ptr));
        }
    }
    return insts;
}

void GlobalGenerator::MakeGlobalDecl(AstNode *decl)
{
    for (auto son : decl->Children)
    {
        if (son->Children.size() == 0 || son->Children[0]->NodeType == AstNodeType::ExprType)
        {
            MakeGIDDecl(son);
        }
        else
        {
            MakeGArrDecl(son);
        }
    }
}

void GlobalGenerator::MakeGlobalConstDecl(AstNode *constDecl)
{
    for (auto son : constDecl->Children)
    {
        if (son->Children[0]->NodeType == AstNodeType::ConstExprType)
        {
            MakeGIDConstDecl(son);
        }
        else
        {
            MakeGArrConstDecl(son);
        }
    }
}

void GlobalGenerator::MakeGIDConstDecl(AstNode *idConstDecl)
{
    ID *ptr = nullptr;
    ID *initVal = nullptr;
    if (!idConstDecl->Children.empty())
    {
        initVal = MakeNum(MakeConstExpr(idConstDecl->Children[0]));
    }
    else
    {
        initVal = MakeNum(0);
    }
    auto uselessDecl = MakeGlobalAlloca(idConstDecl->VarId, ptr, initVal, true);
    assert(VarIDTable.AddVar(idConstDecl->VarId, ptr));
}

void GlobalGenerator::MakeGArrConstDecl(AstNode *arrConstDecl)
{
    ID *ptr = nullptr;
    Dim arrDim;
    auto arrDimNode = arrConstDecl->Children[0];
    auto arrInitNode = arrConstDecl->Children[1];
    for (int i = 0; i < arrDimNode->Children.size(); i++)
    {
        auto dimExpr = arrDimNode->Children[i];
        arrDim.push_back(MakeConstExpr(dimExpr));
    }
    CurrentInitList = new InitList();
    GlobalDeclIRs.Append(MakeGlobalAlloca(arrConstDecl->VarId, ptr, arrDim, CurrentInitList, true));
    CurrentArray = ptr;
    MakeInitList(arrInitNode);
    CurrentArray = nullptr;
    CurrentInitList = nullptr;
    assert(VarIDTable.AddVar(arrConstDecl->VarId, ptr));
}

void GlobalGenerator::MakeGIDDecl(AstNode *idDecl)
{
    ID *ptr = nullptr;
    ID *initVal = nullptr;
    if (!idDecl->Children.empty())
    {
        initVal = MakeNum(MakeConstExpr(idDecl->Children[0]));
    }
    else
    {
        initVal = MakeNum(0);
    }
    GlobalDeclIRs.Append(MakeGlobalAlloca(idDecl->VarId, ptr, initVal));
    assert(VarIDTable.AddVar(idDecl->VarId, ptr));
}

void GlobalGenerator::MakeGArrDecl(AstNode *arrDecl)
{
    ID *ptr = nullptr;
    Dim arrDim;
    auto arrDimNode = arrDecl->Children[0];
    auto arrInitNode = arrDecl->Children[1];
    for (int i = 0; i < arrDimNode->Children.size(); i++)
    {
        auto dimExpr = arrDimNode->Children[i];
        arrDim.push_back(MakeConstExpr(dimExpr));
    }
    CurrentInitList = new InitList();
    GlobalDeclIRs.Append(MakeGlobalAlloca(arrDecl->VarId, ptr, arrDim, CurrentInitList));
    CurrentArray = ptr;
    MakeInitList(arrInitNode);
    CurrentArray = nullptr;
    CurrentInitList = nullptr;
    assert(VarIDTable.AddVar(arrDecl->VarId, ptr));
}

void GlobalGenerator::MakeInitList(AstNode *arrInit)
{
    int initCount = GetInitCount(1);
    int actualCount = 0;
    if (arrInit->Children.empty())
    {
        for (; actualCount < initCount; actualCount++)
        {
            CurrentInitList->push_back(0);
        }
        return;
    }
    MakeGArrInitLevel(arrInit->Children[0], 1, actualCount);
    assert(initCount == actualCount && "Init incomplete!");
}

void GlobalGenerator::MakeGArrInitLevel(AstNode *arrInitLevel, int level, int &currIdx)
{
    int totalInit = GetInitCount(level);
    int targetIdx = currIdx + totalInit;
    for (int i = 0; i < arrInitLevel->Children.size(); i++)
    {
        auto child = arrInitLevel->Children[i];
        switch (child->NodeType)
        {
        case AstNodeType::ExprType:
        case AstNodeType::ConstExprType:
        {
            ID *ptr = nullptr;
            CurrentInitList->push_back(MakeConstExpr(child));
            ++currIdx;
            assert(currIdx == CurrentInitList->size());
        }
        break;
        case AstNodeType::ArrayInitLevelType:
            MakeGArrInitLevel(child, GetLevel(currIdx), currIdx);
            break;
        default:
            assert(false && "Unexpected node type in ArrayInitLevel");
            return;
            break;
        }
    }
    for (; currIdx < targetIdx; currIdx++)
    {
        ID *ptr = nullptr;
        CurrentInitList->push_back(0);
        ++currIdx;
    }
}

ir::Global *GlobalGenerator::MakeGlobalAlloca(std::string name, ID *&globSyb, ID *initVal, bool isConst)
{
    globSyb = MakeID(name, BasicType::TYPE_PTR);
    globSyb->AddPtr();
    globSyb->SetGlobal();
    globSyb->PtrTarVal = initVal->Value;
    globSyb->IsConst = isConst;
    return new ir::Global(globSyb, initVal);
}

ir::Global *GlobalGenerator::MakeGlobalAlloca(std::string name, ID *&globSyb, Dim &dim, InitList *initVal, bool isConst)
{
    globSyb = MakeID(name, BasicType::TYPE_PTR);
    globSyb->AddPtr();
    globSyb->SetGlobal();
    globSyb->Type.AppendArray(dim);
    globSyb->IsConst = isConst;
    return new ir::Global(globSyb, initVal);
}

void GlobalGenerator::AddBuildInFunc()
{
    Function *func = nullptr;
    func = new Function("getint", BasicType::TYPE_INT32, true);
    FuncTable.AddFunc("getint", func);
    func = new Function("getch", BasicType::TYPE_INT32, true);
    FuncTable.AddFunc("getch", func);
    func = new Function("getarray", BasicType::TYPE_INT32, true);
    FuncTable.AddFunc("getarray", func);
    func = new Function("putint", BasicType::TYPE_VOID, true);
    FuncTable.AddFunc("putint", func);
    func = new Function("putch", BasicType::TYPE_VOID, true);
    FuncTable.AddFunc("putch", func);
    func = new Function("putarray", BasicType::TYPE_VOID, true);
    FuncTable.AddFunc("putarray", func);
}

GlobalGenerator::GlobalGenerator(AstNode *compileUnit) : BlockGenerator(FuncTable)
{
    Root = compileUnit;
}
