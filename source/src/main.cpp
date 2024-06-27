#include "AntlrExecutor.h"
#include <string>
#include <iostream>
#include "AstNode.h"
#include "visualization.h"
int main()
{
    std::string fileName;
    std::string testDir = "/home/william/compiler/MyCompiler/demo/";
    std::cout << "FileName:";
    std::cin >> fileName;
    AstNode *rootNode;
    AntlrExecutor *executor = new AntlrExecutor(testDir + fileName);
    if (!executor->execute(rootNode))
    {
        std::cout << "Generate ast error!" << std::endl;
        return 0;
    }
    std::cout << "[Ast] Generate complete!" << std::endl;
    std::string visualization;
    std::cout << "[Ast] Visualize? [Y(default)/n]: ";
    std::cin >> visualization;
    if (visualization != "n")
    {
        viz::PrintAst(rootNode);
    }
    std::cout << "[Ast] Done!" << std::endl;

    return 0;
}