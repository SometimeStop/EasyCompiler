#include "visualization.h"
#include <iostream>
void viz::PrintAst(AstNode *root)
{
    GVC_t *gvc = gvContext();
    Agraph_t *g = agopen((char *)"ast", Agdirected, NULL);
    agsafeset(g, (char *)"dpi", (char *)"150", (char *)"");
    VisitAstNode(g, root, 0);
    gvLayout(gvc, g, "dot");
    std::string filePath = "/home/william/compiler/MyCompiler/out/ast.png";
    gvRenderFilename(gvc, g, "png", filePath.c_str());
    std::cout << "[Ast] Graph generated" << std::endl;
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

void viz::PrintBasicBlock(GlobalGenerator *gen)
{
    GVC_t *gvc = gvContext();
    Agraph_t *g = agopen((char *)"basicblock", Agdirected, NULL);
    agsafeset(g, (char *)"dpi", (char *)"150", (char *)"");
    for (int i = 0; i < gen->FuncTable.FunctionsOrdered.size(); i++)
    {
        auto func = gen->FuncTable.FunctionsOrdered[i];
        if (!func->IsBuildIn)
        {
            std::vector<int> *block = new std::vector<int>();
            func->Pairs = VisitBasicBlock(g, &func->AllIR);
        }
    }
    gvLayout(gvc, g, "dot");
    std::string filePath = "/home/william/compiler/MyCompiler/out/basicblock.png";
    gvRenderFilename(gvc, g, "png", filePath.c_str());
    std::cout << "[Basic Block] Graph generated" << std::endl;
    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);
}

BlockPairs viz::VisitBasicBlock(Agraph_t *g, ir::IRInsts *insts)
{
    BlockPairs pairs;
    std::map<int, Agnode_t *> block;
    block[0] = agnode(g, (char *)nullptr, 1);
    int last = 0;
    std::string instStr = "";
    bool flag = false;
    for (int i = 0; i < insts->size(); i++)
    {
        auto inst = insts->Insts[i];
        if (flag)
        {
            block[i] = agnode(g, (char *)nullptr, 1);
            last = i;
            flag = false;
        }

        if (inst->Type == IRInsType::BrDirect || inst->Type == IRInsType::Br)
        {
            instStr += inst->ToString() + "\n";
            agsafeset(block[last], (char *)"label", (char *)instStr.c_str(), (char *)"");
            agsafeset(block[last], (char *)"shape", (char *)"box", (char *)"");
            instStr = "";
            flag = true;
        }
        else if (inst->Type == IRInsType::Label)
        {
            if (i != 0 && last != i)
            {
                block[i] = agnode(g, (char *)nullptr, 1);
                last = i;
                instStr = "";
            }
            instStr += inst->ToString() + "\n";
        }
        else if (inst->Type == IRInsType::Ret)
        {
            instStr += inst->ToString() + "\n";
            agsafeset(block[last], (char *)"label", (char *)instStr.c_str(), (char *)"");
            agsafeset(block[last], (char *)"shape", (char *)"box", (char *)"");
            assert(i == insts->size() - 1);
            break;
        }
        else
        {
            instStr += inst->ToString() + "\n";
        }
    }
    auto thisBlock = block[0];
    int thisIdx = 0;
    flag = false;
    for (int i = 0; i < insts->size(); i++)
    {
        if (flag)
        {
            thisBlock = block[i];
            thisIdx = i;
            flag = false;
        }

        auto inst = insts->Insts[i];
        if (inst->Type == IRInsType::BrDirect)
        {
            int idx = dynamic_cast<ir::Br *>(inst)->NonCondLabel->AllIdx;
            auto target = block[idx];
            agedge(g, thisBlock, target, nullptr, 1);
            pairs[thisIdx].push_back(idx);
            flag = true;
        }
        else if (inst->Type == IRInsType::Br)
        {
            int idx1 = dynamic_cast<ir::Br *>(inst)->TrueLabel->AllIdx;
            auto target1 = block[idx1];
            agedge(g, thisBlock, target1, nullptr, 1);
            pairs[thisIdx].push_back(idx1);
            int idx2 = dynamic_cast<ir::Br *>(inst)->FalseLabel->AllIdx;
            auto target2 = block[idx2];
            agedge(g, thisBlock, target2, nullptr, 1);
            pairs[thisIdx].push_back(idx2);
            flag = true;
        }
        else if (inst->Type == IRInsType::Label)
        {
            if (i != 0)
            {
                auto lastInst = insts->Insts[i - 1];
                if (lastInst->Type != IRInsType::BrDirect && lastInst->Type != IRInsType::Br)
                {
                    auto target = block[i];
                    agedge(g, thisBlock, target, nullptr, 1);
                }
                thisBlock = block[i];
                thisIdx = i;
                flag = false;
            }
        }
        else
        {
            continue;
        }
    }
    return pairs;
}
