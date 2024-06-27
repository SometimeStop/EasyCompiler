#include "FuncSybTable.h"

bool FuncSybTable::GetFunc(std::string name, Function *&result)
{
    if (HasFunc(name))
    {
        result = Functions[name];
        return true;
    }
    result = nullptr;
    return false;
}

bool FuncSybTable::GetFuncType(std::string name, BasicType &result)
{
    if (HasFunc(name))
    {
        result = Functions[name]->RetType;
        return true;
    }
    result = BasicType::TYPE_UKNOWN;
    return false;
}

bool FuncSybTable::AddFunc(std::string name, Function *func)
{
    if (HasFunc(name))
    {
        return false;
    }
    Functions[name] = func;
    return true;
}

bool FuncSybTable::HasFunc(std::string name)
{
    if (Functions.find(name) != Functions.end())
    {
        return true;
    }
    return false;
}

FuncSybTable::FuncSybTable()
{
}

FuncSybTable::~FuncSybTable() {}
