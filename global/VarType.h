#pragma once
#include "type.h"
#include <string>
#include <vector>
class VarType
{
public:
    BasicType Type;
    std::vector<int> Dimensions;
    VarType();
    VarType(BasicType t);
    operator BasicType&();
    std::string ToString();
};