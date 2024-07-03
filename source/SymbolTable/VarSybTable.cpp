#include "VarSybTable.h"

bool VarSybTable::AddVar(std::string name, ID *var)
{
    if (HasVar(name))
    {
        return false;
    }
    assert(var->IsPtr);
    Variables[name] = var;
    return true;
}

bool VarSybTable::GetVar(std::string name, ID *&result)
{
    if (HasVar(name))
    {
        result = Variables[name];
        return true;
    }
    result = nullptr;
    return false;
}

bool VarSybTable::RecursiveGetVar(std::string name, ID *&result)
{
    if (GetVar(name, result))
    {
        return true;
    }
    else if (Parent != nullptr)
    {
        return Parent->RecursiveGetVar(name, result);
    }
    result = nullptr;
    return false;
}

bool VarSybTable::GetVarType(std::string name, BasicType &result)
{
    if (HasVar(name))
    {
        result = Variables[name]->Type;
        return true;
    }
    result = BasicType::TYPE_UNKNOW;
    return false;
}

bool VarSybTable::RecursiveGetVarType(std::string name, BasicType &result)
{
    if (GetVarType(name, result))
    {
        return true;
    }
    else if (Parent != nullptr)
    {
        return Parent->RecursiveGetVarType(name, result);
    }
    result = BasicType::TYPE_UNKNOW;
    return false;
}

bool VarSybTable::HasVar(std::string name)
{
    if (Variables.find(name) != Variables.end())
    {
        return true;
    }
    return false;
}

bool VarSybTable::RecursiveHasVar(std::string name)
{
    if (HasVar(name))
    {
        return true;
    }
    else if (Parent != nullptr)
    {
        return Parent->RecursiveHasVar(name);
    }
    return false;
}

VarSybTable::VarSybTable(VarSybTable *parent)
{
    Parent = parent;
}

VarSybTable::~VarSybTable() {}
