#include "Var.h"
#include "IRInstruction.h"
#include "VarSybTable.h"
#include <vector>
class Function
{
public:
    std::string Name;
    VarType RetType;
    std::vector<Var *> Args;
    std::vector<Alloca *> AllocaIns;
    int NameNo;
    bool IsBuildIn;
    bool CallExist;
    Function(std::string name, BasicType retType, bool isBuildIn = false);
    void AddArg(std::vector<Var *>& args);
    int AssignNameNo();
    int GetArgCount();
    ~Function();
};