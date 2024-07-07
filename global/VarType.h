#pragma once
#include "type.h"
#include <string>
#include <vector>

class VarType
{
public:
    BasicType Type;
    Dim Dims;
    VarType();
    VarType(BasicType t);
    operator BasicType &();
    void AppendArray(Dim &dim);
    std::string ToString();
    std::string ToLowDimString();
    int PtrDim();
    int GetPtrDim();
    int GetElePtrDim();
private:
    std::string GenPtr(int level);
};