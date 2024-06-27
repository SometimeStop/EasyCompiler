#include "AntlrExecutor.h"
#include "Antlr4CSTVisitor.h"
#include "sysyLexer.h"
#include <iostream>
#include <fstream>

bool AntlrExecutor::execute(AstNode *&node)
{
    std::ifstream inputFS;
    inputFS.open(fName);
    if (!inputFS.is_open())
    {
        std::cout << "Unable to open " << fName << std::endl;
        return false;
    }

    antlr4::ANTLRInputStream input{inputFS};
    sysyLexer lexer{&input};
    antlr4::CommonTokenStream tokens{&lexer};
    sysyParser parser{&tokens};
    auto root = parser.compileUnit();
    if (!root)
    {
        std::cout << "Unable to parse " << fName << std::endl;
        return false;
    }
    sysyCSTVisitor visitor;
    node = visitor.run(root);
    return true;
}
