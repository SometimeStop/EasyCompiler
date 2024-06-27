#pragma once
#include <string>
#include "AstNode.h"
class AntlrExecutor
{
private:
    std::string fName;

public:
    AntlrExecutor(std::string fileName)
    {
        fName = fileName;
    };
    bool execute(AstNode *&node);
    ~AntlrExecutor(){};
};
