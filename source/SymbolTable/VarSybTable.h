#pragma once
#include "ID.h"
#include <unordered_map>
#include <cassert>
class VarSybTable
{
public:
    std::unordered_map<std::string, ID *> Variables;
    VarSybTable *Parent;
    bool AddVar(std::string name, ID *var);

    bool GetVar(std::string name, ID *&result);
    bool RecursiveGetVar(std::string name, ID *&result);

    bool GetVarType(std::string name, BasicType &result);
    bool RecursiveGetVarType(std::string name, BasicType &result);

    bool HasVar(std::string name);
    bool RecursiveHasVar(std::string name);

    VarSybTable(VarSybTable *parent = nullptr);
    ~VarSybTable();
};