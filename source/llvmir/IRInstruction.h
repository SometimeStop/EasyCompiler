#pragma once
#include "irtype.h"
#include "ID.h"
#include <vector>
#include <format>
#include <cassert>

namespace ir
{
    class IRInstruction
    {
    private:
        std::string Comment;
        bool HasComment;

    public:
        IRInsType Type;
        IDArgs Args;
        ID *Result;
        IRInstruction(IRInsType type, ID *result = nullptr);
        ~IRInstruction();
        ID &GetResultVar();
        virtual std::string ToString();
        std::string &GetComment();
        std::string CmtString();
        virtual bool HotCalculation();
        IRInstruction *MakeComment(std::string cmt);
    };

    class IRInsts
    {
    public:
        IRInsts();
        std::vector<IRInstruction *> Insts;
        void Append(IRInsts *block);
        void Append(IRInstruction *ins);
        void Insert(IRInsts *block);
        void Insert(IRInstruction *ins);
        bool HotCalculation(int &value);
        bool Empty();
        int size() const;
        IRInstruction *&operator[](int index);
    };

    IRInsts *GenInsts();

    class Alloca : public IRInstruction
    {
    public:
        Alloca(ID *ptrVar);
        ID &GetPtrVar();
        std::string ToString() override;
        ~Alloca();
    };

    class Load : public IRInstruction
    {
    public:
        Load(ID *var, ID *ptrVar);
        ID &GetVar();
        ID &GetPtrVar();
        std::string ToString() override;
        bool HotCalculation() override;
        ~Load();
    };

    class Store : public IRInstruction
    {
    public:
        Store(ID *var, ID *ptrVar);
        ID &GetVar();
        ID &GetPtrVar();
        std::string ToString() override;
        ~Store();
    };

    class Call : public IRInstruction
    {
    public:
        std::string Func;
        Call(ID *result, std::string func, IDArgs *&args);
        ID &GetVar();
        std::string &GetFunc();
        IDArgs &Params();
        bool IsVoid();
        std::string ToString() override;
    };

    class Ret : public IRInstruction
    {
    public:
        Ret(ID *var = nullptr);
        ID &GetVar();
        bool IsVoid();
        std::string ToString() override;
    };

    class Add : public IRInstruction
    {
    public:
        Add(ID *res, ID *lVar, ID *rVar);
        ID &GetLVar();
        ID &GetRVar();
        std::string ToString() override;
        bool HotCalculation() override;
    };

    class Sub : public IRInstruction
    {
    public:
        Sub(ID *res, ID *lVar, ID *rVar);
        ID &GetLVar();
        ID &GetRVar();
        std::string ToString() override;
        bool HotCalculation() override;
    };

    class Mul : public IRInstruction
    {
    public:
        Mul(ID *res, ID *lVar, ID *rVar);
        ID &GetLVar();
        ID &GetRVar();
        std::string ToString() override;
        bool HotCalculation() override;
    };

    class SDiv : public IRInstruction
    {
    public:
        SDiv(ID *res, ID *lVar, ID *rVar);
        ID &GetLVar();
        ID &GetRVar();
        std::string ToString() override;
        bool HotCalculation() override;
    };

    class SRem : public IRInstruction
    {
    public:
        SRem(ID *res, ID *lVar, ID *rVar);
        ID &GetLVar();
        ID &GetRVar();
        std::string ToString() override;
        bool HotCalculation() override;
    };

    class ICmp : public IRInstruction
    {
    public:
        ICmpType CmpType;
        ICmp(ID *res, ICmpType cmpType, ID *lVar, ID *rVar);
        std::string ToString() override;
    };

    class Label : public IRInstruction
    {
    public:
        ID &GetLabelNo();
        Label(ID *labelNo);
        std::string ToString() override;
    };

    class Br : public IRInstruction
    {
    public:
        Label *NonCondLabel;
        Label *TrueLabel;
        Label *FalseLabel;
        ID &GetCond();
        Label &GetNonCondLabel();
        Label &GetTrueLabel();
        Label &GetFalseLabel();
        Br(Label *label);
        Br(ID *condVar, Label *trueLabel, Label *falseLabel);
        std::string ToString() override;
    };

    class ZExt : public IRInstruction
    {
    public:
        ZExt(ID *res, ID *src);
        std::string ToString() override;
    };

    class GetElementPtr : public IRInstruction
    {
    public:
        GetElementPtr(ID *ptr, ID *resultPtr, ID *offset);
        std::string ToString() override;
    };

    class GetPtr : public IRInstruction
    {
    public:
        GetPtr(ID *ptr, ID *resultVar, ID *offset);
        std::string ToString() override;
    };

    class Global : public IRInstruction
    {
    public:
        InitList *Inits;
        Global(ID *result, ID *initVal);
        Global(ID *result, InitList *initVal);
        std::string ToString() override;
    };
}