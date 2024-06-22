#include "type.h"

VarType::VarType()
{
    type = BasicType::TYPE_NULL;
}

VarType::VarType(BasicType t)
{
    type = t;
}

std::string VarType::ToString()
{
    std::string str;
    switch (type)
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
