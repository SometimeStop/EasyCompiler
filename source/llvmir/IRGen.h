#include "GlobalGenerator.h"
class IRGen
{
public:
    GlobalGenerator *Generator;
    AstNode *Root;

    IRGen(AstNode *root);
    void GenerateIR();
    ~IRGen();
};