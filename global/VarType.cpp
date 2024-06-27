#include "VarType.h"
VarType::VarType()
{
    Type = BasicType::TYPE_NULL;
}

VarType::VarType(BasicType t)
{
    Type = t;
}

VarType::operator BasicType&()
{
    return Type;
}

std::string VarType::ToString()
{
    std::string str;
    switch (Type)
    {
        case BasicType::TYPE_INT:
            str = "i32";
            break;
        case BasicType::TYPE_VOID:
            str = "void";
            break;
        case BasicType::TYPE_NULL:
            str = "Null";
            break;
        default:
            str = "Unknown";
            break;
    }
    return str;
}
