#include "VarType.h"
VarType::VarType()
{
    Type = BasicType::TYPE_NULL;
}

VarType::VarType(BasicType t)
{
    Type = t;
}

VarType::operator BasicType &()
{
    return Type;
}

void VarType::AppendArray(Dim &dim)
{
    Type = BasicType::TYPE_PTR;
    Dims.insert(Dims.end(), dim.begin(), dim.end());
}

std::string VarType::ToString()
{
    std::string str;
    switch (Type)
    {
    case BasicType::TYPE_INT32:
        str = "i32";
        break;
    case BasicType::TYPE_VOID:
        str = "void";
        break;
    case BasicType::TYPE_NULL:
        str = "Null";
        break;
    case BasicType::TYPE_PTR:
        str = GenPtr(0);
        break;
    case BasicType::TYPE_INT1:
        str = "i1";
        break;
    default:
        str = "Unknown";
        break;
    }
    return str;
}

std::string VarType::ToLowDimString()
{
    std::string str;
    switch (Type)
    {
    case BasicType::TYPE_PTR:
        str = GenPtr(1);
        break;
    default:
        str = "Unknown";
        break;
    }
    return str;
}

int VarType::PtrDim()
{
    int cnt = 0;
    for (int i = 0; i < Dims.size(); i++)
    {
        if (Dims[i] == 0)
        {
            cnt++;
        }
    }
    return cnt;
}

std::string VarType::GenPtr(int level)
{
    if (level == Dims.size())
    {
        return "i32";
    }
    if (Dims[level] == 0)
    {
        return GenPtr(level + 1) + "*";
    }
    std::string str = "[";
    str += std::to_string(Dims[level]) + " x ";
    str += GenPtr(level + 1);
    str += "]";
    return str;
}
