#include "AstNode.h"
#include <graphviz/gvc.h>
#include <string>
namespace viz
{
    void PrintAst(AstNode* node);
    Agnode_t* VisitAstNode(Agraph_t *g,AstNode* node, int depth);
    std::string TabCtrl(int depth);
}
