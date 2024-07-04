#pragma once
#include "VarType.h"
#include <cassert>
class ID
{

public:
    std::string Name;
    VarType Type;
    int32_t Value;
    int32_t PtrTarVal;
    bool IsConst;
    bool IsPtr;
    bool IsGlobal;
    bool HasValue;
    bool LRefed;
    bool IsNumber;
    int AssignedNumber;

    ID();
    ID(VarType type);
    ID(BasicType type);
    ID(std::string name, VarType type);
    ID(std::string name, BasicType type);
    ID(std::string name, int32_t value, VarType type = BasicType::TYPE_INT32);
    ID(std::string name, int32_t value, BasicType type = BasicType::TYPE_INT32);
    ID(int32_t value);
    bool Equals(const ID *other);
    bool Equals(const ID &other);
    void SetConst();
    void AddPtr();
    void SetValue(int32_t value);
    int32_t GetValue();
    void SetGlobal();
    void SetLRefed();
    ID *TryReplace();
    ID *ToSameDimPtr();
    ID *ToLowDimPtr();
    ID *ToLowDimArr();
    std::string ToString();
    ~ID();
};
typedef std::vector<ID *> IDArgs;
