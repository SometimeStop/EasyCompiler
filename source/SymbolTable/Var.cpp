#include "Var.h"

Var::Var()
{
    Type = BasicType::TYPE_UKNOWN;
    IsConst = false;
    IsPtr = false;
    IsGlobal = false;
    HasValue = false;
    Value = 0;
}

Var::Var(VarType Type)
{
    IsConst = false;
    IsPtr = false;
    IsGlobal = false;
    HasValue = false;
    Type = Type;
    Value = 0;
}

Var::Var(BasicType type)
{
    IsConst = false;
    IsPtr = false;
    IsGlobal = false;
    HasValue = false;
    Type = type;
    Value = 0;
}

Var::Var(std::string name, VarType type) : Var(type)
{
    Name = name;
}

Var::Var(std::string name, BasicType type) : Var(type)
{
    Name = name;
}

Var::Var(std::string name, int32_t value, VarType type) : Var(name, type)
{
    Value = value;
    HasValue = true;
}

Var::Var(std::string name, int32_t value, BasicType type) : Var(name, type)
{
    Value = value;
    HasValue = true;
}

bool Var::Equals(const Var *other)
{
    if (this->Name == other->Name)
    {
        return true;
    }
    return false;
}

bool Var::Equals(const Var &other)
{
    if (this->Name == other.Name)
    {
        return true;
    }
    return false;
}

void Var::SetConst()
{
    IsConst = true;
}

void Var::SetPtr()
{
    PointerDim = 1;
    IsPtr = true;
}

void Var::SetValue(int32_t value)
{
    Value = value;
    HasValue = true;
}

int32_t Var::GetValue()
{
    return Value;
}

void Var::SetPtrTo(Var *target)
{
    Name = target->Name;
    Type = target->Type;
    Value = target->Value;
    IsConst = target->IsConst;
    IsPtr = true;
    if (target->IsPtr)
    {
        PointerDim = target->PointerDim + 1;
    }
    else
    {
        PointerDim = 1;
    }
    HasValue = target->HasValue;
}

void Var::SetGlobal()
{
    IsGlobal = true;
}

std::string Var::ToNameString()
{
    return "%" + Name;
}

std::string Var::ToValueString()
{
    return std::to_string(Value);
}

Var::~Var()
{
}
