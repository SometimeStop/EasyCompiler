#include "IRGen.h"

IRGen::IRGen(AstNode *root)
{
    Root = root;
    Generator = new GlobalGenerator(root);
}

void IRGen::GenerateIR()
{
    Generator->Generate();
    Generator->Print();
}

IRGen::~IRGen() {}
