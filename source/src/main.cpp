#include "AntlrExecutor.h"
#include <string>
#include <iostream>
#include "AST.h"
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
    std::cout << "Generate complete!" << std::endl;
    std::string visualization;
    std::cout << "Visualize?[y/N]";
    std::cin >> visualization;
    if (visualization == "y")
    {
        viz::PrintAst(rootNode);
    }
    std::cout << "Done!" << std::endl;
    return 0;
}