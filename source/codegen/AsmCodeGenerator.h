#include "GlobalGenerator.h"
#include "riscvasm.h"
class AsmCodeGenerator
{
private:
    GlobalGenerator* irGen;
    rv::Asms *GenFunction(Function *func);
public:
    AsmCodeGenerator(GlobalGenerator* ir);
    ~AsmCodeGenerator();
};