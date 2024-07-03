#include "StmtNode.h"

StmtNode::StmtNode(StmtType type, int32_t line)
    : AstNode(AstNodeType::StatementType, line)
{
    SubNodeType = type;
}

std::string StmtNode::ToString()
{
    std::string ret = "[Statement]\n";
    switch (SubNodeType)
    {
    case StmtType::StmtAssign:
        ret += "=";
        break;
    case StmtType::StmtExpr:
        ret += "expr";
        break;
    case StmtType::StmtIf:
        ret += "if";
        break;
    case StmtType::StmtBlock:
        ret += "block";
        break;
    case StmtType::StmtWhile:
        ret += "while";
        break;
    case StmtType::StmtBreak:
        ret += "break";
        break;
    case StmtType::StmtContinue:
        ret += "continue";
        break;
    case StmtType::StmtReturn:
        ret += "return";
        break;
    default:
        break;
    }
    return ret;
}
