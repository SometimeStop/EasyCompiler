#include "FuncSybTable.h"
#include <fstream>
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
    result = BasicType::TYPE_UNKNOW;
    return false;
}

bool FuncSybTable::AddFunc(std::string name, Function *func)
{
    if (HasFunc(name))
    {
        return false;
    }
    Functions[name] = func;
    FunctionsOrdered.push_back(func);
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

void FuncSybTable::Print()
{
    for (int i = 0; i < FunctionsOrdered.size(); i++)
    {
        FunctionsOrdered[i]->Print();
    }
}

FuncSybTable::FuncSybTable() {}

FuncSybTable::~FuncSybTable() {}
