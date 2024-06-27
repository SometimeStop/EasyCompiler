#include "Var.h"
#include <unordered_map>
class VarSybTable
{
public:
    std::unordered_map<std::string, Var *> Variables;
    VarSybTable* Parent;
    bool AddVar(std::string name, Var *var);

    bool GetVar(std::string name, Var *&result);
    bool RecursiveGetVar(std::string name, Var *&result);

    bool GetVarType(std::string name, BasicType& result);
    bool RecursiveGetVarType(std::string name, BasicType& result);

    bool HasVar(std::string name);
    bool RecursiveHasVar(std::string name);

    VarSybTable(VarSybTable* parent = nullptr);
    ~VarSybTable();
};