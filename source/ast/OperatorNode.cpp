#include "OperatorNode.h"
OperatorNode::OperatorNode(OperatorType type, int32_t line)
    : AstNode(AstNodeType::OperatorType, line)
{
    SubNodeType = type;
}

std::string OperatorNode::ToString()
{
    std::string ret = "[operator]\n";
    switch (SubNodeType)
    {
    case OperatorType::OperatorAdd:
        ret += "+";
        break;
    case OperatorType::OperatorPos:
        ret += "+(Unary)";
        break;
    case OperatorType::OperatorSub:
        ret += "-";
        break;
    case OperatorType::OperatorNeg:
        ret += "-(Unary)";
        break;
    case OperatorType::OperatorMul:
        ret += "*";
        break;
    case OperatorType::OperatorDiv:
        ret += "/";
        break;
    case OperatorType::OperatorMod:
        ret += "%";
        break;
    case OperatorType::OperatorNot:
        ret += "!";
        break;
    case OperatorType::OperatorLT:
        ret += "<";
        break;
    case OperatorType::OperatorGT:
        ret += ">";
        break;
    case OperatorType::OperatorLE:
        ret += "<=";
        break;
    case OperatorType::OperatorGE:
        ret += ">=";
        break;
    case OperatorType::OperatorEQ:
        ret += "==";
        break;
    case OperatorType::OperatorNE:
        ret += "!=";
        break;
    case OperatorType::OperatorAnd:
        ret += "&&";
        break;
    case OperatorType::OperatorOr:
        ret += "||";
        break;
    default:
        ret += "unknown operator";
        break;
    }
    return ret;
}
