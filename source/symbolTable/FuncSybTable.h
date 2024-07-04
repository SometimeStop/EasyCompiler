#include "Function.h"
#include <unordered_map>
class FuncSybTable
{
public:
    std::unordered_map<std::string, Function *> Functions;
    std::vector<Function *> FunctionsOrdered;
    bool GetFunc(std::string name, Function *&result);
    bool GetFuncType(std::string name, BasicType &result);
    bool AddFunc(std::string name, Function *func);
    bool HasFunc(std::string name);
    void Print();
    FuncSybTable();
    ~FuncSybTable();
};
