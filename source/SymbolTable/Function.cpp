#include "Function.h"
#include <iostream>
#include <fstream>
Function::Function(std::string name, BasicType retType, bool isBuildIn)
{
    Name = name;
    RetType.Type = retType;
    IsBuildIn = isBuildIn;
    CallExist = false;
    NameNo = 0;
}

void Function::AddArg(ID *arg)
{
    if (arg == nullptr)
    {
        return;
    }
    Args.push_back(arg);
}

void Function::AddArg(IDArgs &args)
{
    Args = args;
    for (auto arg : Args)
    {
        Args.push_back(arg);
    }
}

void Function::AddIR(ir::IRInsts &insts)
{
    for (int i = 0; i < insts.size(); i++)
    {
        if (insts[i]->Type == IRInsType::Alloca)
        {
            AllocaIR.Append(insts[i]);
        }
        else
        {
            StdIR.Append(insts[i]);
        }
    }
}

int Function::GetNameNo()
{
    return NameNo++;
}

int Function::GetArgCount()
{
    return Args.size();
}

void Function::Print()
{
    AssignAllNo();
    std::string argName;
    for (int i = 0; i < Args.size(); i++)
    {
        argName += Args[i]->Type.ToString() + " " + Args[i]->ToString();
        if (i != Args.size() - 1)
        {
            argName += ", ";
        }
    }
    std::string file = "/home/william/compiler/MyCompiler/out/1_self.ll";
    std::ofstream ofs(file, std::ios::app);
    ofs << std::format("define {0} @{1}({2})", RetType.ToString(), Name, argName) << std::endl;
    ofs << "{" << std::endl;
    for (int i = 0; i < AllocaIR.size(); i++)
    {
        ofs << "    " << AllocaIR[i]->ToString() << AllocaIR[i]->CmtString() << std::endl;
    }
    for (int i = 0; i < StdIR.size(); i++)
    {
        if (StdIR[i]->Type == IRInsType::Label)
        {
            ofs << std::endl
                << StdIR[i]->ToString()
                << StdIR[i]->CmtString() << std::endl;
            continue;
        }
        ofs << "    " << StdIR[i]->ToString() << StdIR[i]->CmtString() << std::endl;
    }
    ofs << "}" << std::endl;
    ofs.close();
}

void Function::AssignAllNo()
{
    for (int i = 0; i < Args.size(); i++)
    {
        Args[i]->AssignedNumber = GetNameNo();
    }
    for (int i = 0; i < AllocaIR.size(); i++)
    {
        AllocaIR[i]->Result->AssignedNumber = GetNameNo();
    }
    for (int i = 0; i < StdIR.size(); i++)
    {
        if (StdIR[i]->Result != nullptr)
        {
            StdIR[i]->Result->AssignedNumber = GetNameNo();
        }
    }
}

Function::~Function() {}
