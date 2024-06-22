#include <string>
#include "AST.h"
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
