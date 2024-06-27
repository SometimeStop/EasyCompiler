#include "IRInstruction.h"

IRInstruction::IRInstruction(IRInsType type, Var *result)
{
    Type = type;
    Result = result;
    Align = 4;
}

IRInstruction::~IRInstruction() {}

Var &IRInstruction::GetResultVar() { return *Result; }

std::string IRInstruction::ToString()
{
    std::string ret = "";
    return ret;
}

IRInstBlock::IRInstBlock() {}

Alloca::Alloca(Var *ptrVar)
    : IRInstruction(IRInsType::Alloca, ptrVar) {}

Var &Alloca::GetPtrVar()
{
    return *Result;
}

std::string Alloca::ToString()
{
    return std::format("{0} = alloca {1}, align {2}", Result->ToNameString(), Result->Type.ToString(), std::to_string(Align));
}

Alloca::~Alloca() {}

Load::Load(Var *var, Var *ptrVar)
    : IRInstruction(IRInsType::Load, var)
{
    Args.push_back(ptrVar);
}

Var &Load::GetVar()
{
    return *Result;
}

Var &Load::GetPtrVar()
{
    assert(!Args.empty());
    return *Args[0];
}

std::string Load::ToString()
{
    return std::format("{0} = load {1}, {2} {3}, align {4}", Result->ToNameString(), Result->Type.ToString(), Args[0]->Type.ToString(), Args[0]->ToNameString(), std::to_string(Align));
}

Load::~Load() {}

Store::Store(Var *var, Var *ptrVar)
    : IRInstruction(IRInsType::Store)
{
    Args.push_back(var);
    Args.push_back(ptrVar);
}

Var &Store::GetVar()
{
    assert(!Args.empty());
    return *Args[0];
}

Var &Store::GetPtrVar()
{
    assert(!Args.empty());
    return *Args[1];
}

std::string Store::ToString()
{
    return std::format("store {0} {1}, {2} {3}, align {4}", Args[0]->Type.ToString(), Args[0]->ToNameString(), Args[1]->Type.ToString(), Args[1]->ToNameString(), std::to_string(Align));
}

Store::~Store() {}

Call::Call(Var *var, std::string name, std::vector<Var *> &args)
    : IRInstruction(IRInsType::Call, var)
{
    FName = name;
    Args = args;
}

Var &Call::GetVar()
{
    return *Result;
}

std::string &Call::FuncName()
{
    return FName;
}

std::vector<Var *> &Call::Params()
{
    return Args;
}

std::string Call::ToString()
{
    std::string ret = std::format("{0} = call {1} @{2}(", Result->ToNameString(), FName, Result->Type.ToString());
    for (int i = 0; i < Args.size(); i++)
    {
        auto arg = Args[i];
        ret += arg->Type.ToString();
        ret += " ";
        ret += arg->ToNameString();
        if (i != Args.size() - 1)
        {
            ret += ", ";
        }
    }
    ret += ")";
    return ret;
}

Ret::Ret(Var *var)
    : IRInstruction(IRInsType::Ret)
{
    Args.push_back(var);
}

Var &Ret::GetVar()
{
    assert(!Args.empty());
    return *Args[0];
}

bool Ret::IsVoid()
{
    if (Args[0]->Type.Type == BasicType::TYPE_VOID)
    {
        return true;
    }
    return false;
}

std::string Ret::ToString()
{
    if (IsVoid())
    {
        return "ret void";
    }
    return std::format("ret {0} {1}", Args[0]->Type.ToString(), Args[0]->ToNameString());
}

Add::Add(Var *res, Var *lVar, Var *rVar)
    : IRInstruction(IRInsType::Add, res)
{
    Args.push_back(lVar);
    Args.push_back(rVar);
}

Var &Add::LVar()
{
    assert(!Args.empty());
    return *Args[0];
}

Var &Add::RVar()
{
    assert(!Args.empty());
    return *Args[1];
}

std::string Add::ToString()
{
    return std::format("{0} = add nsw {1} {2}, {3}", Result->ToNameString(), Result->Type.ToString(), Args[0]->ToNameString(), Args[1]->ToNameString());
}

Sub::Sub(Var *res, Var *lVar, Var *rVar)
    : IRInstruction(IRInsType::Sub, res)
{
    Args.push_back(lVar);
    Args.push_back(rVar);
}

Var &Sub::LVar()
{
    assert(!Args.empty());
    return *Args[0];
}

Var &Sub::RVar()
{
    assert(!Args.empty());
    return *Args[1];
}

std::string Sub::ToString()
{
    return std::format("{0} = sub nsw {1} {2}, {3}", Result->ToNameString(), Result->Type.ToString(), Args[0]->ToNameString(), Args[1]->ToNameString());
}

Mul::Mul(Var *res, Var *lVar, Var *rVar)
    : IRInstruction(IRInsType::Mul, res)
{
    Args.push_back(lVar);
    Args.push_back(rVar);
}

Var &Mul::LVar()
{
    assert(!Args.empty());
    return *Args[0];
}

Var &Mul::RVar()
{
    assert(!Args.empty());
    return *Args[1];
}

std::string Mul::ToString()
{
    return std::format("{0} = mul nsw {1} {2}, {3}", Result->ToNameString(), Result->Type.ToString(), Args[0]->ToNameString(), Args[1]->ToNameString());
}

SDiv::SDiv(Var *res, Var *lVar, Var *rVar)
    : IRInstruction(IRInsType::SDiv, res)
{
    Args.push_back(lVar);
    Args.push_back(rVar);
}

Var &SDiv::LVar()
{
    assert(!Args.empty());
    return *Args[0];
}

Var &SDiv::RVar()
{
    assert(!Args.empty());
    return *Args[1];
}

std::string SDiv::ToString()
{
    return std::format("{0} = sdiv {1} {2}, {3}", Result->ToNameString(), Result->Type.ToString(), Args[0]->ToNameString(), Args[1]->ToNameString());
}

SRem::SRem(Var *res, Var *lVar, Var *rVar)
    : IRInstruction(IRInsType::SRem, res)
{
    Args.push_back(lVar);
    Args.push_back(rVar);
}

Var &SRem::LVar()
{
    assert(!Args.empty());
    return *Args[0];
}

Var &SRem::RVar()
{
    assert(!Args.empty());
    return *Args[1];
}

std::string SRem::ToString()
{
    return std::format("{0} = srem {1} {2}, {3}", Result->ToNameString(), Result->Type.ToString(), Args[0]->ToNameString(), Args[1]->ToNameString());
}
