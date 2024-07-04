#include "AstNode.h"
#include "GlobalGenerator.h"
#include <graphviz/gvc.h>
#include <string>
#include <map>
#include <utility>
namespace viz
{
    void PrintAst(AstNode *node);
    Agnode_t *VisitAstNode(Agraph_t *g, AstNode *node, int depth);
    void PrintBasicBlock(GlobalGenerator *gen);
    BlockPairs VisitBasicBlock(Agraph_t *g, ir::IRInsts *insts);
}
