#include "GlobalGenerator.h"
class IRGen
{
    GlobalGenerator *Generator;
    AstNode *Root;
public:
    IRGen(AstNode *root);
    void GenerateIR();
    ~IRGen();
};