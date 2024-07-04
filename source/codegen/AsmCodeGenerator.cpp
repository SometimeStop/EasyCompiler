#include "AsmCodeGenerator.h"

rv::Asms *AsmCodeGenerator::GenFunction(Function *func)
{
    int prologue = 0;
    
    return nullptr;
}

AsmCodeGenerator::AsmCodeGenerator(GlobalGenerator *ir)
{
    assert(ir != nullptr);
    irGen = ir;
}

AsmCodeGenerator::~AsmCodeGenerator() {}
