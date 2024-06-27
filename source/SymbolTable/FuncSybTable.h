#include "Function.h"
#include <unordered_map>
class FuncSybTable
{
public:
    std::unordered_map<std::string, Function *> Functions;
    bool GetFunc(std::string name, Function*& result);
    bool GetFuncType(std::string name, BasicType& result);
    bool AddFunc(std::string name, Function *func);
    bool HasFunc(std::string name);

    FuncSybTable();
    ~FuncSybTable();
};
