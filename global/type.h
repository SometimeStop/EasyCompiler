#pragma once

#include <string>

enum class BasicType{
    TYPE_NULL,
    TYPE_VOID,
    TYPE_INT,
    TYPE_UKNOWN,
};

class VarType {
public:
    BasicType type;
    VarType();
    VarType(BasicType t);
    std::string ToString();
};