#include "Function.h"

Function::Function(std::string name, BasicType retType, bool isBuildIn)
{
    Name = name;
    RetType.Type = retType;
    IsBuildIn = isBuildIn;
    CallExist = false;
    NameNo = 0;
}

void Function::AddArg(std::vector<Var *> &args)
{
    Args = args;
    for (auto arg : Args)
    {
        SybTable.AddVar(arg->Name,arg);
    }
}

int Function::AssignNameNo()
{
    return ++NameNo;
}

int Function::GetArgCount()
{
    return Args.size();
}

Function::~Function() {}
