#include "visualization.h"
#include <iostream>
void viz::PrintAst(AstNode *root)
{
    std::cout << "Printing ast" << std::endl;
    GVC_t *gvc = gvContext();
    Agraph_t *g = agopen((char *)"ast", Agdirected, NULL);
    agsafeset(g, (char *)"dpi", (char *)"150", (char *)"");
    VisitAstNode(g, root, 0);
    gvLayout(gvc, g, "dot");
    std::string filePath = "/home/william/compiler/MyCompiler/out/ast.png";
    gvRenderFilename(gvc, g, "png", filePath.c_str());
    std::cout << "Graph generated" << std::endl;
    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);
}

Agnode_t *viz::VisitAstNode(Agraph_t *g, AstNode *node, int depth)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    Agnode_t *graphNode;
    Agnode_t *parentNode = agnode(g, (char *)nullptr, 1);
    if (parentNode != nullptr)
    {
        std::string parentName = node->ToString();
        std::cout << TabCtrl(depth) << parentName << std::endl;
        agsafeset(parentNode, (char *)"label", (char *)parentName.c_str(), (char *)"");
        agsafeset(parentNode, (char *)"shape", (char *)"ellipse", (char *)"");
        for (AstNode *it : node->Children)
        {
            Agnode_t *childNode = VisitAstNode(g, it, depth + 1);
            agedge(g, parentNode, childNode, nullptr, 1);
        }
    }
    return parentNode;
}

std::string viz::TabCtrl(int depth)
{
    std::string tabs = "";
    for (int i = 0; i < depth; i++)
    {
        tabs += "    ";
    }
    return tabs;
}
