#include "IRInstruction.h"
namespace ir
{
    IRInstruction::IRInstruction(IRInsType type, ID *result)
    {
        Type = type;
        Result = result;
        HasComment = false;
    }

    IRInstruction::~IRInstruction() {}

    ID &IRInstruction::GetResultVar() { return *Result; }

    std::string IRInstruction::ToString()
    {
        std::string ret = "";
        return ret;
    }

    std::string &IRInstruction::GetComment()
    {
        return Comment;
    }

    std::string IRInstruction::CmtString()
    {
        if (HasComment)
        {
            return "    ;" + Comment;
        }
        else
        {
            return "";
        }
    }

    bool IRInstruction::HotCalculation()
    {
        assert(false && "Hot calculation NOT supported");
    }

    IRInstruction *IRInstruction::MakeComment(std::string cmt)
    {
        Comment = cmt;
        HasComment = true;
        return this;
    }

    IRInsts::IRInsts() {}

    void IRInsts::Append(IRInsts *block)
    {
        if (block == nullptr)
        {
            return;
        }
        for (auto inst : block->Insts)
        {
            Insts.push_back(inst);
        }
        delete block;
    }

    void IRInsts::Append(IRInstruction *ins)
    {
        if (ins == nullptr)
        {
            return;
        }
        Insts.push_back(ins);
    }

    void IRInsts::Insert(IRInsts *block)
    {
        if (block == nullptr)
        {
            return;
        }
        Insts.insert(Insts.begin(), block->Insts.begin(), block->Insts.end());
    }

    void IRInsts::Insert(IRInstruction *ins)
    {
        if (ins == nullptr)
        {
            return;
        }
        Insts.insert(Insts.begin(), ins);
    }

    bool IRInsts::HotCalculation(int &value)
    {
        assert(!Insts.empty() && "No instructions to be calculated!");
        for (int i = 0; i < Insts.size(); i++)
        {
            if (!Insts[i]->HotCalculation())
            {
                return false;
            }
        }
        value = Insts[Insts.size() - 1]->Result->Value;
        return true;
    }

    bool IRInsts::Empty()
    {
        return Insts.empty();
    }

    int IRInsts::size() const
    {
        return Insts.size();
    }

    IRInstruction *&IRInsts::operator[](int index)
    {
        return Insts[index];
    }

    Alloca::Alloca(ID *ptrVar)
        : IRInstruction(IRInsType::Alloca, ptrVar) {}

    ID &Alloca::GetPtrVar()
    {
        return *Result;
    }

    std::string Alloca::ToString()
    {
        return std::format("{0} = alloca {1}", Result->ToString(), Result->Type.ToLowDimString());
    }

    Alloca::~Alloca() {}

    Load::Load(ID *var, ID *ptrVar)
        : IRInstruction(IRInsType::Load, var)
    {
        Args.push_back(ptrVar);
    }

    ID &Load::GetVar()
    {
        return *Result;
    }

    ID &Load::GetPtrVar()
    {
        assert(!Args.empty());
        return *Args[0];
    }

    std::string Load::ToString()
    {
        return std::format("{0} = load {1}, {2} {3}", Result->ToString(), Result->Type.ToString(), Args[0]->Type.ToString(), Args[0]->ToString());
    }

    bool Load::HotCalculation()
    {
        if (GetPtrVar().Type == BasicType::TYPE_PTR)
        {
            assert(false && "illegal reference to array");
        }
        if (GetPtrVar().IsConst || (GetPtrVar().IsGlobal && !GetPtrVar().LRefed))
        {
            GetVar().HasValue = true;
            GetVar().Value = GetPtrVar().PtrTarVal;
            return true;
        }
        return false;
    }

    Load::~Load() {}

    Store::Store(ID *var, ID *ptrVar)
        : IRInstruction(IRInsType::Store)
    {
        Args.push_back(var);
        Args.push_back(ptrVar);
    }

    ID &Store::GetVar()
    {
        assert(!Args.empty());
        return *Args[0];
    }

    ID &Store::GetPtrVar()
    {
        assert(!Args.empty());
        return *Args[1];
    }

    std::string Store::ToString()
    {
        return std::format("store {0} {1}, {2} {3}", Args[0]->Type.ToString(), Args[0]->ToString(), Args[1]->Type.ToString(), Args[1]->ToString());
    }

    Store::~Store() {}

    Call::Call(ID *result, std::string func, IDArgs *&args)
        : IRInstruction(IRInsType::Call, result)
    {
        Func = func;
        if (args != nullptr)
        {
            Args = *args;
        }
    }

    ID &Call::GetVar()
    {
        return *Result;
    }

    std::string &Call::GetFunc()
    {
        return Func;
    }

    IDArgs &Call::Params()
    {
        return Args;
    }

    bool Call::IsVoid()
    {
        return Result == nullptr;
    }

    std::string Call::ToString()
    {
        if (IsVoid())
        {
            std::string ret = std::format("call void @{0}(", Func);
            for (int i = 0; i < Args.size(); i++)
            {
                auto arg = Args[i];
                ret += arg->Type.ToString();
                ret += " ";
                ret += arg->ToString();
                if (i != Args.size() - 1)
                {
                    ret += ", ";
                }
            }
            ret += ")";
            return ret;
        }
        std::string ret = std::format("{0} = call {1} @{2}(", Result->ToString(), Result->Type.ToString(), Func);
        for (int i = 0; i < Args.size(); i++)
        {
            auto arg = Args[i];
            ret += arg->Type.ToString();
            ret += " ";
            ret += arg->ToString();
            if (i != Args.size() - 1)
            {
                ret += ", ";
            }
        }
        ret += ")";
        return ret;
    }

    Ret::Ret(ID *var)
        : IRInstruction(IRInsType::Ret)
    {
        if (var == nullptr)
        {
            return;
        }

        Args.push_back(var);
    }

    ID &Ret::GetVar()
    {
        assert(!Args.empty());
        return *Args[0];
    }

    bool Ret::IsVoid()
    {
        if (Args.size() == 0)
            return true;
        return false;
    }

    std::string Ret::ToString()
    {
        if (IsVoid())
        {
            return "ret void";
        }
        return std::format("ret {0} {1}", Args[0]->Type.ToString(), Args[0]->ToString());
    }

    Add::Add(ID *res, ID *lVar, ID *rVar)
        : IRInstruction(IRInsType::Add, res)
    {
        Args.push_back(lVar);
        Args.push_back(rVar);
    }

    ID &Add::GetLVar()
    {
        assert(!Args.empty());
        return *Args[0];
    }

    ID &Add::GetRVar()
    {
        assert(!Args.empty());
        return *Args[1];
    }

    std::string Add::ToString()
    {
        return std::format("{0} = add nsw {1} {2}, {3}", Result->ToString(), Result->Type.ToString(), Args[0]->ToString(), Args[1]->ToString());
    }

    bool Add::HotCalculation()
    {
        if (GetRVar().HasValue && GetRVar().HasValue)
        {
            GetResultVar().HasValue = true;
            GetResultVar().Value = GetLVar().Value + GetRVar().Value;
            return true;
        }
        return false;
    }

    Sub::Sub(ID *res, ID *lVar, ID *rVar)
        : IRInstruction(IRInsType::Sub, res)
    {
        Args.push_back(lVar);
        Args.push_back(rVar);
    }

    ID &Sub::GetLVar()
    {
        assert(!Args.empty());
        return *Args[0];
    }

    ID &Sub::GetRVar()
    {
        assert(!Args.empty());
        return *Args[1];
    }

    std::string Sub::ToString()
    {
        return std::format("{0} = sub nsw {1} {2}, {3}", Result->ToString(), Result->Type.ToString(), Args[0]->ToString(), Args[1]->ToString());
    }

    bool Sub::HotCalculation()
    {
        if (GetRVar().HasValue && GetRVar().HasValue)
        {
            GetResultVar().HasValue = true;
            GetResultVar().Value = GetLVar().Value - GetRVar().Value;
            return true;
        }
        return false;
    }

    Mul::Mul(ID *res, ID *lVar, ID *rVar)
        : IRInstruction(IRInsType::Mul, res)
    {
        Args.push_back(lVar);
        Args.push_back(rVar);
    }

    ID &Mul::GetLVar()
    {
        assert(!Args.empty());
        return *Args[0];
    }

    ID &Mul::GetRVar()
    {
        assert(!Args.empty());
        return *Args[1];
    }

    std::string Mul::ToString()
    {
        return std::format("{0} = mul nsw {1} {2}, {3}", Result->ToString(), Result->Type.ToString(), Args[0]->ToString(), Args[1]->ToString());
    }

    bool Mul::HotCalculation()
    {
        if (GetRVar().HasValue && GetRVar().HasValue)
        {
            GetResultVar().HasValue = true;
            GetResultVar().Value = GetLVar().Value * GetRVar().Value;
            return true;
        }
        return false;
    }

    SDiv::SDiv(ID *res, ID *lVar, ID *rVar)
        : IRInstruction(IRInsType::SDiv, res)
    {
        Args.push_back(lVar);
        Args.push_back(rVar);
    }

    ID &SDiv::GetLVar()
    {
        assert(!Args.empty());
        return *Args[0];
    }

    ID &SDiv::GetRVar()
    {
        assert(!Args.empty());
        return *Args[1];
    }

    std::string SDiv::ToString()
    {
        return std::format("{0} = sdiv {1} {2}, {3}", Result->ToString(), Result->Type.ToString(), Args[0]->ToString(), Args[1]->ToString());
    }

    bool SDiv::HotCalculation()
    {
        if (GetRVar().HasValue && GetRVar().HasValue)
        {
            GetResultVar().HasValue = true;
            GetResultVar().Value = GetLVar().Value / GetRVar().Value;
            return true;
        }
        return false;
    }

    SRem::SRem(ID *res, ID *lVar, ID *rVar)
        : IRInstruction(IRInsType::SRem, res)
    {
        Args.push_back(lVar);
        Args.push_back(rVar);
    }

    ID &SRem::GetLVar()
    {
        assert(!Args.empty());
        return *Args[0];
    }

    ID &SRem::GetRVar()
    {
        assert(!Args.empty());
        return *Args[1];
    }

    std::string SRem::ToString()
    {
        return std::format("{0} = srem {1} {2}, {3}", Result->ToString(), Result->Type.ToString(), Args[0]->ToString(), Args[1]->ToString());
    }

    bool SRem::HotCalculation()
    {
        if (GetRVar().HasValue && GetRVar().HasValue)
        {
            GetResultVar().HasValue = true;
            GetResultVar().Value = GetLVar().Value % GetRVar().Value;
            return true;
        }
        return false;
    }

    IRInsts *GenInsts()
    {
        IRInsts *result = new IRInsts();
        return result;
    }

    ID &Label::GetLabelNo()
    {
        return *Result;
    }

    Label::Label(ID *labelNo)
        : IRInstruction(IRInsType::Label, labelNo) {}

    std::string Label::ToString()
    {
        return std::format("{0}:", Result->ToString());
    }

    ID &Br::GetCond()
    {
        return *Args[0];
    }

    Label &Br::GetNonCondLabel()
    {
        return *NonCondLabel;
    }

    Label &Br::GetTrueLabel()
    {
        return *TrueLabel;
    }

    Label &Br::GetFalseLabel()
    {
        return *FalseLabel;
    }

    Br::Br(Label *label)
        : IRInstruction(IRInsType::BrDirect)
    {
        NonCondLabel = label;
    }

    Br::Br(ID *condVar, Label *trueLabel, Label *falseLabel)
        : IRInstruction(IRInsType::Br)
    {
        Args.push_back(condVar);
        TrueLabel = trueLabel;
        FalseLabel = falseLabel;
    }

    std::string Br::ToString()
    {
        if (Type == IRInsType::BrDirect)
        {
            return std::format("br label {0}", NonCondLabel->Result->ToString());
        }
        else
        {
            return std::format("br i1 {0}, label {1}, label {2}", Args[0]->ToString(), TrueLabel->Result->ToString(), FalseLabel->Result->ToString());
        }
    }

    ICmp::ICmp(ID *res, ICmpType cmpType, ID *lVar, ID *rVar)
        : IRInstruction(IRInsType::ICmp, res)
    {
        Args.push_back(lVar);
        Args.push_back(rVar);
        CmpType = cmpType;
    }

    std::string ICmp::ToString()
    {
        std::string cmpString;
        switch (CmpType)
        {
        case ICmpType::SGT:
            cmpString += "sgt";
            break;
        case ICmpType::SLT:
            cmpString += "slt";
            break;
        case ICmpType::SGE:
            cmpString += "sge";
            break;
        case ICmpType::SLE:
            cmpString += "sle";
            break;
        case ICmpType::EQ:
            cmpString += "eq";
            break;
        case ICmpType::NE:
            cmpString += "ne";
            break;
        default:
            break;
        }
        return std::format("{0} = icmp {1} {2} {3}, {4}", Result->ToString(), cmpString, Args[0]->Type.ToString(), Args[0]->ToString(), Args[1]->ToString());
    }

    ZExt::ZExt(ID *res, ID *src)
        : IRInstruction(IRInsType::ZExt, res)
    {
        Args.push_back(src);
        assert(src->Type == BasicType::TYPE_INT1);
    }

    std::string ZExt::ToString()
    {
        return std::format("{0} = zext {1} {2} to i32", Result->ToString(), Args[0]->Type.ToString(), Args[0]->ToString());
    }

    GetElementPtr::GetElementPtr(ID *ptr, ID *resultPtr, ID *offset)
        : IRInstruction(IRInsType::GetElementPtr, resultPtr)
    {
        Args.push_back(ptr);
        Args.push_back(offset);
    }

    std::string GetElementPtr::ToString()
    {
        return std::format("{0} = getelementptr {1} {2} {3}, i32 0, {4} {5}", Result->ToString(), Args[0]->Type.ToLowDimString(), Args[0]->Type.ToString(), Args[0]->ToString(), Args[1]->Type.ToString(), Args[1]->ToString());
    }

    GetPtr::GetPtr(ID *ptr, ID *resultPtr, ID *offset)
        : IRInstruction(IRInsType::GetPtr, resultPtr)
    {
        Args.push_back(ptr);
        Args.push_back(offset);
    }
    std::string GetPtr::ToString()
    {
        return std::format("{0} = getelementptr {1} {2} {3}, {4} {5}", Result->ToString(), Args[0]->Type.ToLowDimString(), Args[0]->Type.ToString(), Args[0]->ToString(), Args[1]->Type.ToString(), Args[1]->ToString());
    }
    Global::Global(ID *resultPtr, ID *initVal)
        : IRInstruction(IRInsType::Global, resultPtr)
    {
        Inits = new InitList();
        Inits->push_back(initVal->Value);
    }

    Global::Global(ID *resultPtr, InitList *initVal)
        : IRInstruction(IRInsType::Global, resultPtr)
    {
        Inits = initVal;
    }
    std::string Global::ToString()
    {
        std::string initString;
        initString += "[";
        for (int i = 0; i < Inits->size(); i++)
        {

            if (i != Inits->size() - 1)
            {
                initString += std::to_string((*Inits)[i]) + ", ";
                continue;
            }
            initString += std::to_string((*Inits)[i]);
        }
        initString += "]";
        return std::format("{0} = global {1} {2}", Result->ToString(), Result->Type.ToLowDimString(), initString);
    }
}