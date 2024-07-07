#include "ID.h"

ID::ID()
{
    Type = BasicType::TYPE_UNKNOW;
    IsConst = false;
    IsPtr = false;
    IsGlobal = false;
    IsNumber = false;
    HasValue = false;
    LRefed = false;
    Value = 0;
}

ID::ID(VarType Type)
{
    IsConst = false;
    IsPtr = false;
    IsGlobal = false;
    IsNumber = false;
    HasValue = false;
    Type.Type = Type;
    LRefed = false;
    Value = 0;
}

ID::ID(BasicType type)
{
    IsConst = false;
    IsPtr = false;
    IsGlobal = false;
    IsNumber = false;
    HasValue = false;
    Type.Type = type;
    LRefed = false;
    Value = 0;
}

ID::ID(std::string name, VarType type) : ID(type)
{
    Name = name;
}

ID::ID(std::string name, BasicType type) : ID(type)
{
    Name = name;
}

ID::ID(std::string name, int32_t value, VarType type) : ID(name, type)
{
    Value = value;
    HasValue = true;
}

ID::ID(std::string name, int32_t value, BasicType type) : ID(name, type)
{
    Value = value;
    HasValue = true;
}

ID::ID(int32_t value)
{
    IsConst = true;
    IsPtr = false;
    IsGlobal = false;
    IsNumber = true;
    HasValue = true;
    Type = BasicType::TYPE_INT32;
    LRefed = false;
    Value = value;
}

bool ID::Equals(const ID *other)
{
    if (this->Name == other->Name)
    {
        return true;
    }
    return false;
}

bool ID::Equals(const ID &other)
{
    if (this->Name == other.Name)
    {
        return true;
    }
    return false;
}

void ID::SetConst()
{
    IsConst = true;
}

void ID::AddPtr()
{
    IsPtr = true;
    Type.Dims.push_back(0);
}

void ID::SetValue(int32_t value)
{
    Value = value;
    HasValue = true;
}

int32_t ID::GetValue()
{
    return Value;
}

void ID::SetGlobal()
{
    IsGlobal = true;
}

void ID::SetLRefed()
{
    LRefed = true;
}

ID *ID::TryReplace()
{
    if (HasValue)
    {
        if (LRefed)
        {
            return this;
        }
        else
        {
            return new ID(Value);
        }
    }
    return this;
}

ID *ID::ToLowDimPtr()
{
    assert(Type.Dims.size() > 0);
    ID *lower = new ID(BasicType::TYPE_PTR);
    Dim tmp = Type.Dims;
    tmp.erase(tmp.begin(), tmp.begin() + 1);
    assert(tmp.size() == Type.Dims.size() - 1);
    lower->Type.AppendArray(tmp);
    // if (lower->Type.Dims.size() == 1)
    // {
    //     lower->Type.Dims[0] = 0;
    // }
    return lower;
}

ID *ID::ToLowDimArr()
{
    assert(Type.Dims.size() >= 2);
    ID *lower = new ID(BasicType::TYPE_PTR);
    Dim tmp = Type.Dims;
    tmp.erase(tmp.begin() + 1, tmp.begin() + 2);
    assert(tmp.size() == Type.Dims.size() - 1);
    lower->Type.AppendArray(tmp);
    if (lower->Type.Dims.size() == 1)
    {
        lower->Type.Dims[0] = 0;
    }
    return lower;
}

ID *ID::ToSameDimPtr()
{
    ID *same = new ID(BasicType::TYPE_PTR);
    Dim tmp = Type.Dims;
    same->Type.AppendArray(tmp);
    return same;
}

std::string ID::ToString()
{
    if (IsNumber)
    {
        return std::to_string(Value);
    }
    else if (!IsGlobal)
    {
        return "%" + std::to_string(AssignedNumber);
    }
    return "@" + Name;
}

ID::~ID()
{
}
