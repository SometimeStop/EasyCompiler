#include "IRGen.h"

void IRGen::VisitCompileUnit(AstNode *unit)
{
    if (unit == nullptr)
    {
        return;
    }
    for (auto node : unit->Children)
    {
        switch (node->NodeType)
        {
        case AstNodeType::FuncDefType:
            DefineFunction(node);
            break;
        case AstNodeType::DeclType:
            break;
        case AstNodeType::ConstDeclType:
            break;
        default:
            break;
        }
    }
}

void IRGen::DefineFunction(AstNode *funcNode)
{
    Function *f = new Function(funcNode->VarId, funcNode->VType);
    auto formParams = DefineFormParams(funcNode->Children[0]);
    f->AddArg(formParams);
    FuncTable.AddFunc(f->Name, f);
}

std::vector<Var *> IRGen::DefineFormParams(AstNode *param)
{
    std::vector<Var *> formParams;
    for (auto paramNode : param->Children)
    {
        Var *param = DefineVar(paramNode);
        formParams.push_back(param);
    }
    return formParams;
}

Var *IRGen::DefineVar(AstNode *var)
{
    Var *v = new Var(var->VarId, var->VType);
    // FIXME:Add Array Operation
    return v;
}

std::vector<IRInstruction *> IRGen::BuildBlock(AstNode *blockNode)
{
    std::vector<IRInstruction *> Ins;
    Block block(VarTable);
    for (auto node : blockNode->Children)
    {
        std::vector<IRInstruction *> result;
        switch (node->NodeType)
        {
        case AstNodeType::DeclType:
            result = block.BuildDecl(node);
            Ins.insert(Ins.end(), result.begin(), result.end());
            break;
        case AstNodeType::StatementType:
            result = block.BuildStmt(node);
            Ins.insert(Ins.end(), result.begin(), result.end());
            break;
        default:
            break;
        }
    }
}

IRGen::IRGen(AstNode *root)
{
    Root = root;
}

void IRGen::GenerateIR()
{
}
