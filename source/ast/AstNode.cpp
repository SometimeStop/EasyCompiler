#include "AstNode.h"
AstNode::AstNode(VarType vType, int32_t line)
{
    VType = vType;
    LineNo = line;

    NodeType = AstNodeType::UnknownType;
    Parent = nullptr;
}

AstNode::AstNode(uint32_t value)
{
    IntVal = value;
    LineNo = -1;

    NodeType = AstNodeType::IntConstType;
    VType = BasicType::TYPE_INT;
    Parent = nullptr;
}

AstNode::AstNode(std::string id, int32_t line, bool isRef)
{
    VarId = id;
    LineNo = line;
    IsRef = isRef;
    NodeType = AstNodeType::IdentifierType;
    VType = BasicType::TYPE_INT;
}

AstNode::AstNode(AstNodeType type, int32_t line)
{
    NodeType = type;
    LineNo = line;

    VType = BasicType::TYPE_UKNOWN;
    Parent = nullptr;
}

std::string AstNode::ToString()
{
    std::string ret;
    switch (NodeType)
    {
    case AstNodeType::IdentifierType:
    case AstNodeType::FuncCallType:
    case AstNodeType::FuncDefType:
        if (IsRef)
        {
            ret += "[Syb Ref]\n";
        }
        else
        {
            ret += "[Syb Def]\n";
        }
        break;
    case AstNodeType::FuncFormParamType:
        if (IsRef)
        {
            ret += "[FP Syb Ref]\n";
        }
        else
        {
            ret += "[FP Syb Def]\n";
        }
        break;
    default:
        break;
    }
    switch (NodeType)
    {
    case AstNodeType::CompileUnitType:
        ret += "CompileUnit";
        break;
    case AstNodeType::OperatorType:
        ret += "error";
        break;
    case AstNodeType::IdentifierType:
        ret += VType.ToString() + " id: " + VarId;
        break;
    case AstNodeType::IntConstType:
        ret += "int: " + std::to_string(IntVal);
        break;
    case AstNodeType::ConstDeclType:
        ret += "const decl";
        break;
    case AstNodeType::DeclType:
        ret += "decl";
        break;
    case AstNodeType::FuncDefType:
        ret += "func def: (" + VType.ToString() + ")" + VarId;
        break;
    case AstNodeType::FuncFormParamsType:
        ret += "func form params";
        break;
    case AstNodeType::FuncFormParamType:
        ret += "(" + VType.ToString() + "): " + VarId;
        break;
    case AstNodeType::ArrayDimType:
        ret += "array dim";
        break;
    case AstNodeType::ArrayInitValType:
        ret += "array init";
        break;
    case AstNodeType::ArrayInitLevelType:
        ret += "init level";
        break;
    case AstNodeType::FuncCallType:
        ret += "func call: " + VarId;
        break;
    case AstNodeType::FuncRealParamsType:
        ret += "func real params";
        break;
    case AstNodeType::BlockType:
        ret += "block";
        break;
    case AstNodeType::ExprType:
        ret += "expr";
        break;
    case AstNodeType::CondExprType:
        ret += "cond expr";
        break;
    case AstNodeType::ConstExprType:
        ret += "const expr";
        break;
    case AstNodeType::UnknownType:
        ret += "unknown";
        break;
    default:
        break;
    }
    return ret;
}