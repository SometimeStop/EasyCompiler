#include "VarType.h"
class Var
{

public:
    std::string Name;
    VarType Type;
    int32_t Value;
    bool IsConst;
    bool IsPtr;
    bool IsGlobal;
    bool HasValue;
    int PointerDim;
    Var();
    Var(VarType type);
    Var(BasicType type);
    Var(std::string name, VarType type);
    Var(std::string name, BasicType type);
    Var(std::string name, int32_t value, VarType type = BasicType::TYPE_INT);
    Var(std::string name, int32_t value, BasicType type = BasicType::TYPE_INT);
    bool Equals(const Var *other);
    bool Equals(const Var &other);
    void SetConst();
    void SetPtr();
    void SetValue(int32_t value);
    int32_t GetValue();
    void SetPtrTo(Var* target);
    void SetGlobal();
    std::string ToNameString();
    std::string ToValueString();
    ~Var();
};
