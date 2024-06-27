#pragma once
#include "irtype.h"
#include "Var.h"
#include <vector>
#include <format>
#include <cassert>

class IRInstruction
{
public:
    IRInsType Type;
    std::vector<Var *> Args;
    Var *Result;
    int Align;
    IRInstruction(IRInsType type, Var *result = nullptr);
    ~IRInstruction();
    Var &GetResultVar();
    virtual std::string ToString();
};

class IRInstBlock
{
public:
    IRInstBlock();
    std::vector<IRInstruction *> Insts;
};

class Alloca : public IRInstruction
{
public:
    Alloca(Var *ptrVar);
    Var &GetPtrVar();
    std::string ToString() override;
    ~Alloca();
};

class Load : public IRInstruction
{
public:
    Load(Var *var, Var *ptrVar);
    Var &GetVar();
    Var &GetPtrVar();
    std::string ToString() override;
    ~Load();
};

class Store : public IRInstruction
{
public:
    Store(Var *var, Var *ptrVar);
    Var &GetVar();
    Var &GetPtrVar();
    std::string ToString() override;
    ~Store();
};

class Call : public IRInstruction
{
public:
    std::string FName;
    Call(Var *var, std::string name, std::vector<Var *> &args);
    Var &GetVar();
    std::string &FuncName();
    std::vector<Var *> &Params();
    std::string ToString() override;
};

class Ret : public IRInstruction
{
public:
    Ret(Var *var = nullptr);
    Var &GetVar();
    bool IsVoid();
    std::string ToString() override;
};

class Add : public IRInstruction
{
public:
    Add(Var *res, Var *lVar, Var *rVar);
    Var &LVar();
    Var &RVar();
    std::string ToString() override;
};

class Sub : public IRInstruction
{
public:
    Sub(Var *res, Var *lVar, Var *rVar);
    Var &LVar();
    Var &RVar();
    std::string ToString() override;
};

class Mul : public IRInstruction
{
public:
    Mul(Var *res, Var *lVar, Var *rVar);
    Var &LVar();
    Var &RVar();
    std::string ToString() override;
};

class SDiv : public IRInstruction
{
public:
    SDiv(Var *res, Var *lVar, Var *rVar);
    Var &LVar();
    Var &RVar();
    std::string ToString() override;
};

class SRem : public IRInstruction
{
public:
    SRem(Var *res, Var *lVar, Var *rVar);
    Var &LVar();
    Var &RVar();
    std::string ToString() override;
};

class ICmp : public IRInstruction
{
public:
    ICmpType CmpType;

};