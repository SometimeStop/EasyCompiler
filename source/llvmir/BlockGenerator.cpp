#include "BlockGenerator.h"
#include <iostream>
ir::IRInsts *BlockGenerator::MakeBlock(AstNode *block)
{
    auto insts = ir::GenInsts();
    for (auto son : block->Children)
    {
        switch (son->NodeType)
        {
        case AstNodeType::DeclType:
            insts->Append(MakeDecl(son));
            break;
        case AstNodeType::ConstDeclType:
            insts->Append(MakeConstDecl(son));
            break;
        case AstNodeType::StatementType:
            insts->Append(MakeStatement(dynamic_cast<StmtNode *>(son)));
            break;
        case AstNodeType::BlockType:
        {
            BlockGenerator *sonBlock = new BlockGenerator(FuncTable, &VarIDTable);
            sonBlock->SetLoopLabel(LoopStart, LoopEnd);
            sonBlock->SetFuncEndLabel(FuncEnd, RetPtr);
            insts->Append(sonBlock->MakeBlock(son));
            delete sonBlock;
        }
        break;
        default:
            assert(false && "Invalid block son type");
            break;
        }
    }
    return insts;
}

ir::IRInsts *BlockGenerator::GenReturn(bool isVoid)
{
    auto insts = ir::GenInsts();
    if (!isVoid)
    {
        insts->Append(MakeAlloca(RetPtr)->MakeComment("return value"));
    }
    FuncEnd = dynamic_cast<ir::Label *>(MakeLabel(MakeID())->MakeComment("return label"));
    return insts;
}

ir::IRInsts *BlockGenerator::LoadReturn(bool isVoid)
{
    auto insts = ir::GenInsts();
    ID *val = nullptr;
    insts->Append(FuncEnd);
    if (!isVoid)
    {
        insts->Append(MakeLoad(RetPtr, val));
        insts->Append(MakeRet(val));
        return insts;
    }
    insts->Append(MakeRet(val));
    return insts;
}

/// @brief a must-success operation, should only be used in these two cases
/// case 1: determines an array's dimensions
/// case 2: initializes a global variable, both global const and global variable
/// other cases such as optimization: use HotCalculation_function of class IRInsts
int BlockGenerator::HotCalculation(ir::IRInsts *&expr)
{
    int result = 0;
    assert(expr->HotCalculation(result));
    return result;
}

ID *BlockGenerator::MakeID()
{
    return new ID();
}

ID *BlockGenerator::MakeID(std::string name, int32_t value, BasicType type)
{
    return new ID(name, value, type);
}

ID *BlockGenerator::MakeID(std::string name, BasicType type)
{
    return new ID(name, type);
}

ID *BlockGenerator::MakeID(BasicType type)
{
    return new ID(type);
}

ID *BlockGenerator::MakeNum(int32_t value)
{
    return new ID(value);
}

ir::IRInsts *BlockGenerator::MakeDecl(AstNode *decl)
{
    auto insts = ir::GenInsts();
    for (auto son : decl->Children)
    {
        if (son->Children.size() == 0 || son->Children[0]->NodeType == AstNodeType::ExprType)
        {
            insts->Append(MakeIDDecl(son));
        }
        else
        {
            insts->Append(MakeArrDecl(son));
        }
    }
    return insts;
}

ir::IRInsts *BlockGenerator::MakeConstDecl(AstNode *constDecl)
{
    auto insts = ir::GenInsts();
    for (auto son : constDecl->Children)
    {
        if (son->Children[0]->NodeType == AstNodeType::ConstExprType)
        {
            insts->Append(MakeIDConstDecl(son));
        }
        else
        {
            insts->Append(MakeArrConstDecl(son));
        }
    }
    return insts;
}

ir::IRInsts *BlockGenerator::MakeIDDecl(AstNode *idDecl)
{
    ID *ptr = nullptr;
    auto insts = ir::GenInsts();
    insts->Append(MakeAlloca(ptr));
    ptr->Name = idDecl->VarId;
    assert(VarIDTable.AddVar(idDecl->VarId, ptr));
    if (!idDecl->Children.empty())
    {
        ID *initVal = nullptr;
        insts->Append(MakeExpr(idDecl->Children[0], initVal));
        insts->Append(MakeStore(initVal, ptr));
    }
    return insts;
}

ir::IRInsts *BlockGenerator::MakeArrDecl(AstNode *arrDecl)
{
    ID *ptr = nullptr;
    Dim arrDim;
    auto insts = ir::GenInsts();
    auto arrDimNode = arrDecl->Children[0];
    auto arrInitNode = arrDecl->Children[1];
    for (int i = 0; i < arrDimNode->Children.size(); i++)
    {
        auto dimExpr = arrDimNode->Children[i];
        arrDim.push_back(MakeConstExpr(dimExpr));
    }
    insts->Append(MakeAlloca(ptr, arrDim));
    ptr->Name = arrDecl->VarId;
    assert(VarIDTable.AddVar(arrDecl->VarId, ptr));
    CurrentArray = ptr;
    insts->Append(MakeArrInit(arrInitNode));
    CurrentArray = nullptr;
    return insts;
}

ir::IRInsts *BlockGenerator::MakeIDConstDecl(AstNode *idConstDecl)
{
    ID *ptr = nullptr;
    auto value = idConstDecl->Children[0];
    int number = MakeConstExpr(value);
    auto uselessAlloca = MakeAlloca(ptr);
    delete uselessAlloca;
    assert(VarIDTable.AddVar(idConstDecl->VarId, ptr));
    ptr->SetConst();
    ptr->PtrTarVal = number;
    return nullptr;
}

ir::IRInsts *BlockGenerator::MakeArrConstDecl(AstNode *arrConstDecl)
{
    ID *ptr = nullptr;
    Dim arrDim;
    auto insts = ir::GenInsts();
    auto arrDimNode = arrConstDecl->Children[0];
    auto arrInitNode = arrConstDecl->Children[1];
    for (int i = 0; i < arrDimNode->Children.size(); i++)
    {
        auto dimExpr = arrDimNode->Children[i];
        arrDim.push_back(MakeConstExpr(dimExpr));
    }
    insts->Append(MakeAlloca(ptr, arrDim));
    ptr->SetConst();
    assert(VarIDTable.AddVar(arrConstDecl->VarId, ptr));
    CurrentArray = ptr;
    insts->Append(MakeArrConstInit(arrInitNode));
    CurrentArray = nullptr;
    return insts;
}

ir::IRInsts *BlockGenerator::MakeRightRef(AstNode *ref, ID *&idValueOut)
{
    ID *result = nullptr;
    assert(VarIDTable.RecursiveGetVar(ref->VarId, result));
    if (result->Type.Dims.size() > 1)
    {
        return MakePtrRRef(ref, idValueOut);
    }
    else if (result->Type.PtrDim() == 1)
    {
        return MakeIDRRef(ref, idValueOut);
    }
    else
    {
        assert(false && "Error variable type");
        return nullptr;
    }
}

ir::IRInsts *BlockGenerator::MakeIDRRef(AstNode *idRef, ID *&idValueOut)
{
    ID *ptr = nullptr;
    auto insts = ir::GenInsts();
    insts->Append(MakeIDLRef(idRef, ptr));
    if (ptr->IsConst)
    {
        idValueOut = MakeNum(ptr->PtrTarVal);
        return insts;
    }
    insts->Append(MakeLoad(ptr, idValueOut));
    return insts;
}

ir::IRInsts *BlockGenerator::MakePtrRRef(AstNode *arrayRef, ID *&idPtrOut)
{
    int dim = 0;
    ID *result = nullptr;
    auto insts = ir::GenInsts();
    insts->Append(MakePtrLRef(arrayRef, idPtrOut));
    VarIDTable.RecursiveGetVar(arrayRef->VarId, result);
    if (result->Type.Dims[1] == 0 && arrayRef->Children.empty())
    {
        return insts;
    }
    else if (idPtrOut->Type.Dims.size() > 1)
    {
        insts->Append(MakeGetElementPtr(idPtrOut, idPtrOut, MakeNum(0)));
    }
    else
    {
        insts->Append(MakeLoad(idPtrOut, idPtrOut));
    }
    return insts;
}

ir::IRInsts *BlockGenerator::MakeLeftRef(AstNode *ref, ID *&idPtrOut)
{
    ID *result = nullptr;
    assert(VarIDTable.RecursiveGetVar(ref->VarId, result));
    if (result->Type.Dims.size() > 1)
    {
        return MakePtrLRef(ref, idPtrOut);
    }
    else if (result->Type.PtrDim() == 1)
    {
        return MakeIDLRef(ref, idPtrOut);
    }
    else
    {
        assert(false && "Error variable type");
        return nullptr;
    }
}

ir::IRInsts *BlockGenerator::MakeIDLRef(AstNode *idRef, ID *&idPtrOut)
{
    assert(VarIDTable.RecursiveGetVar(idRef->VarId, idPtrOut));
    return nullptr;
}

ir::IRInsts *BlockGenerator::MakePtrLRef(AstNode *arrayRef, ID *&idPtrOut)
{
    auto insts = ir::GenInsts();
    ID *targetPtr = nullptr;
    assert(VarIDTable.RecursiveGetVar(arrayRef->VarId, targetPtr));
    assert(targetPtr->Type.Dims.size() >= 1);
    bool needLower = false;
    int idx = 0;
    idPtrOut = targetPtr;
    while (true)
    {
        idx++;
        if (targetPtr->Type.Dims.size() <= idx)
        {
            return insts;
        }

        if (targetPtr->Type.Dims[idx] == 0)
        {
            needLower = true;
            insts->Append(MakeLoad(idPtrOut, idPtrOut));
        }

        if (arrayRef->Children.empty() || idx > arrayRef->Children[0]->Children.size())
        {
            return insts;
        }
        auto arrDim = arrayRef->Children[0];
        ID *offset = nullptr;
        if (needLower)
        {
            needLower = false;
            insts->Append(MakeExpr(arrDim->Children[idx - 1], offset));
            insts->Append(MakeGetPtr(idPtrOut, idPtrOut, offset));
        }
        else
        {
            insts->Append(MakeExpr(arrDim->Children[idx - 1], offset));
            insts->Append(MakeGetElementPtr(idPtrOut, idPtrOut, offset));
        }
    }
}

Dim BlockGenerator::IdxToDim(int idx)
{
    int product = 1;
    for (int i = 2; i < CurrentArray->Type.Dims.size(); i++)
    {
        product *= CurrentArray->Type.Dims[i];
    }
    Dim result;
    int thisDim = idx;
    for (int i = 2; i < CurrentArray->Type.Dims.size(); i++)
    {
        int arrIdx = thisDim / product;
        result.push_back(arrIdx);
        thisDim -= arrIdx * product;
        product /= CurrentArray->Type.Dims[i];
    }
    result.push_back(thisDim);
    return result;
}

ir::IRInsts *BlockGenerator::MakeArrInit(AstNode *arrInit)
{
    if (arrInit->Children.empty())
    {
        return nullptr;
    }
    int initCount = GetInitCount(1);
    int actualCount = 0;
    auto insts = ir::GenInsts();
    insts->Append(MakeArrInitLevel(arrInit->Children[0], 1, actualCount));
    assert(initCount == actualCount && "Init incomplete!");
    return insts;
}

ir::IRInsts *BlockGenerator::MakeArrInitLevel(AstNode *arrInitLevel, int level, int &currIdx)
{
    int totalInit = GetInitCount(level);
    int targetIdx = currIdx + totalInit;
    auto insts = ir::GenInsts();
    for (int i = 0; i < arrInitLevel->Children.size(); i++)
    {
        auto child = arrInitLevel->Children[i];
        switch (child->NodeType)
        {
        case AstNodeType::ExprType:
        {
            ID *ptr = nullptr;
            ID *result = nullptr;
            insts->Append(MakeExpr(child, result));
            insts->Append(MakeArrInitLRef(currIdx, ptr));
            insts->Append(MakeStore(result, ptr));
            ++currIdx;
        }
        break;
        case AstNodeType::ArrayInitLevelType:
        {
            insts->Append(MakeArrInitLevel(child, GetLevel(currIdx), currIdx));
        }
        break;
        default:
        {
            assert(false && "Unexpected node type in ArrayInitLevel");
        }
        break;
        }
    }
    for (int i = currIdx; i < targetIdx; i++)
    {
        ID *ptr = nullptr;
        insts->Append(MakeArrInitLRef(currIdx, ptr));
        insts->Append(MakeStore(MakeNum(0), ptr));
        ++currIdx;
    }

    return insts;
}

ir::IRInsts *BlockGenerator::MakeArrInitLRef(int idx, ID *&idPtrOut)
{
    Dim tempDim = IdxToDim(idx);
    return MakeArrInitLRef(tempDim, idPtrOut);
}

ir::IRInsts *BlockGenerator::MakeArrInitLRef(Dim &dim, ID *&idPtrOut)
{
    auto insts = ir::GenInsts();
    idPtrOut = CurrentArray;
    for (int i = 0; i < dim.size(); i++)
    {
        insts->Append(MakeGetElementPtr(idPtrOut, idPtrOut, MakeNum(dim[i])));
    }
    return insts;
}

int BlockGenerator::GetInitCount(int level)
{
    int cnt = 1;
    for (int i = level; i < CurrentArray->Type.Dims.size(); i++)
    {
        cnt *= CurrentArray->Type.Dims[i];
    }
    return cnt;
}

int BlockGenerator::GetLevel(int currIdx)
{
    int level = -1;
    int product = 1;
    int idx = currIdx;
    for (int i = CurrentArray->Type.Dims.size() - 1; i > 1; i--)
    {
        product *= CurrentArray->Type.Dims[i];
        if (idx % product != 0)
        {
            assert(level != -1);
            return level;
        }
        level = i;
    }
    assert(level != -1);
    return level;
}

ir::IRInsts *BlockGenerator::MakeArrConstInit(AstNode *arrConstInit)
{
    if (arrConstInit->Children.empty())
    {
        assert(false && "const must not be empty");
    }
    int initCount = GetInitCount(1);
    int actualCount = 0;
    auto insts = ir::GenInsts();
    insts->Append(MakeArrCInitLevel(arrConstInit->Children[0], 1, actualCount));
    assert(initCount == actualCount && "Init incomplete!");
    return insts;
}

ir::IRInsts *BlockGenerator::MakeArrCInitLevel(AstNode *arrCInitLevel, int level, int &currIdx)
{
    int totalInit = GetInitCount(level);
    int targetIdx = currIdx + totalInit;
    auto insts = ir::GenInsts();
    for (int i = 0; i < arrCInitLevel->Children.size(); i++)
    {
        auto child = arrCInitLevel->Children[i];
        switch (child->NodeType)
        {
        case AstNodeType::ConstExprType:
        {
            ID *ptr = nullptr;
            int value = MakeConstExpr(child);
            insts->Append(MakeArrInitLRef(currIdx, ptr));
            insts->Append(MakeStore(MakeNum(value), ptr));
            ++currIdx;
        }
        break;
        case AstNodeType::ArrayInitLevelType:
        {
            insts->Append(MakeArrCInitLevel(child, GetLevel(currIdx), currIdx));
        }
        break;
        default:
        {
            assert(false && "Unexpected node type in ArrayInitLevel");
        }
        break;
        }
    }
    for (int i = currIdx; i < targetIdx; i++)
    {
        ID *ptr = nullptr;
        insts->Append(MakeArrInitLRef(currIdx, ptr));
        insts->Append(MakeStore(MakeNum(0), ptr));
        ++currIdx;
    }

    return insts;
}

int BlockGenerator::MakeConstExpr(AstNode *constExpr)
{
    ID *uselessID = nullptr;
    AstNode *sonNode = constExpr->Children[0];
    auto insts = ir::GenInsts();
    insts->Append(MakeExprInner(sonNode, uselessID));
    if (insts->Empty())
    {
        return uselessID->Value;
    }
    return HotCalculation(insts);
}

///@param resultOut build inside, repersent the result of the expression
ir::IRInsts *BlockGenerator::MakeExpr(AstNode *expr, ID *&resultOut)
{
    AstNode *sonNode = expr->Children[0];
    return MakeExprInner(sonNode, resultOut);
}

ir::IRInsts *BlockGenerator::MakeExprInner(AstNode *son, ID *&resultOut)
{
    switch (son->NodeType)
    {
    case AstNodeType::IdentifierType:
        return MakeRightRef(son, resultOut);
    case AstNodeType::FuncCallType:
        return MakeFuncCall(son, resultOut);
    case AstNodeType::OperatorType:
    {
        auto operatorNode = dynamic_cast<OperatorNode *>(son);
        return MakeExprOperator(operatorNode, resultOut);
    }
    case AstNodeType::NumValueType:
        resultOut = MakeNum(son->IntVal);
        return ir::GenInsts();
    default:
        assert(false && "Invalid expr node type");
        break;
    }
}

ir::IRInsts *BlockGenerator::MakeExprOperator(OperatorNode *op, ID *&resultOut)
{
    switch (op->SubNodeType)
    {
    case OperatorType::OperatorAdd:
    case OperatorType::OperatorSub:
    case OperatorType::OperatorMul:
    case OperatorType::OperatorDiv:
    case OperatorType::OperatorMod:
        return MakeBinaryOperator(op, resultOut);
        break;
    case OperatorType::OperatorPos:
    case OperatorType::OperatorNeg:
    case OperatorType::OperatorNot:
        return MakeUnaryOperator(op, resultOut);
        break;
    default:
        assert(false && "Invalid numeric operator: A condition operator is recieved!");
        break;
    }
}

ir::IRInsts *BlockGenerator::MakeFuncCall(AstNode *func, ID *&resultOut)
{
    Function *callTarget = nullptr;
    assert(FuncTable.GetFunc(func->VarId, callTarget) && "Function not defined!");
    AstNode *paramsNode = func->Children[0];
    IDArgs *args = nullptr;
    auto insts = ir::GenInsts();
    insts->Append(MakeRealParams(paramsNode, args));
    if (callTarget->RetType == BasicType::TYPE_VOID)
    {
        resultOut = nullptr;
        ir::Call *call = new ir::Call(nullptr, func->VarId, args);
        insts->Append(call);
    }
    else
    {
        resultOut = new ID(BasicType::TYPE_INT32);
        ir::Call *call = new ir::Call(resultOut, func->VarId, args);
        insts->Append(call);
    }
    return insts;
}

ir::IRInsts *BlockGenerator::MakeRealParams(AstNode *params, IDArgs *&paramOut)
{
    if (params->Children.empty())
    {
        paramOut = nullptr;
        return nullptr;
    }
    auto insts = ir::GenInsts();
    paramOut = new IDArgs;
    for (auto &&expr : params->Children)
    {
        ID *result = nullptr;
        insts->Append(MakeExpr(expr, result));
        if (!result->Type.Dims.empty())
        {
            result->Type.Dims[0] = 0;
        }
        paramOut->push_back(result);
    }
    return insts;
}

ir::IRInsts *BlockGenerator::MakeBinaryOperator(OperatorNode *op, ID *&resultOut)
{
    auto left = op->Children[0];
    auto right = op->Children[1];
    auto insts = ir::GenInsts();
    ID *leftResult = nullptr;
    ID *rightResult = nullptr;
    insts->Append(MakeExprInner(left, leftResult));
    insts->Append(MakeExprInner(right, rightResult));
    ir::IRInstruction *opInst = nullptr;
    switch (op->SubNodeType)
    {
    case OperatorType::OperatorAdd:
        opInst = MakeAdd(leftResult, rightResult, resultOut);
        break;
    case OperatorType::OperatorSub:
        opInst = MakeSub(leftResult, rightResult, resultOut);
        break;
    case OperatorType::OperatorMul:
        opInst = MakeMul(leftResult, rightResult, resultOut);
        break;
    case OperatorType::OperatorDiv:
        opInst = MakeSDiv(leftResult, rightResult, resultOut);
        break;
    case OperatorType::OperatorMod:
        opInst = MakeSRem(leftResult, rightResult, resultOut);
        break;
    default:
        assert(false && "Invalid binary operator");
        break;
    }
    insts->Append(opInst);
    return insts;
}

ir::Add *BlockGenerator::MakeAdd(ID *left, ID *right, ID *&resultOut)
{
    resultOut = new ID(BasicType::TYPE_INT32);
    return new ir::Add(resultOut, left, right);
}

ir::Sub *BlockGenerator::MakeSub(ID *left, ID *right, ID *&resultOut)
{
    resultOut = new ID(BasicType::TYPE_INT32);
    return new ir::Sub(resultOut, left, right);
}

ir::Mul *BlockGenerator::MakeMul(ID *left, ID *right, ID *&resultOut)
{
    resultOut = new ID(BasicType::TYPE_INT32);
    return new ir::Mul(resultOut, left, right);
}

ir::SDiv *BlockGenerator::MakeSDiv(ID *left, ID *right, ID *&resultOut)
{
    resultOut = new ID(BasicType::TYPE_INT32);
    return new ir::SDiv(resultOut, left, right);
}

ir::SRem *BlockGenerator::MakeSRem(ID *left, ID *right, ID *&resultOut)
{
    resultOut = new ID(BasicType::TYPE_INT32);
    return new ir::SRem(resultOut, left, right);
}

ir::Label *BlockGenerator::MakeLabel(ID *labelNo)
{
    return new ir::Label(labelNo);
}

ir::Ret *BlockGenerator::MakeRet(ID *ret)
{
    return new ir::Ret(ret);
}

ir::GetElementPtr *BlockGenerator::MakeGetElementPtr(ID *ptr, ID *&resultPtr, ID *offset)
{
    resultPtr = ptr->ToLowDimArr();
    return new ir::GetElementPtr(ptr, resultPtr, offset);
}

ir::GetPtr *BlockGenerator::MakeGetPtr(ID *ptr, ID *&resultPtr, ID *offset)
{
    resultPtr = ptr->ToSameDimPtr();
    return new ir::GetPtr(ptr, resultPtr, offset);
}

ir::IRInsts *BlockGenerator::MakeUnaryOperator(OperatorNode *op, ID *&resultOut)
{
    auto son = op->Children[0];
    switch (op->SubNodeType)
    {
    case OperatorType::OperatorPos:
    {
        auto insts = ir::GenInsts();
        insts->Append(MakeExprInner(son, resultOut));
        return insts;
    }
    case OperatorType::OperatorNeg:
    {
        ID *sonResult = nullptr;
        auto insts = ir::GenInsts();
        insts->Append(MakeExprInner(son, sonResult));
        auto inst = MakeSub(MakeNum(0), sonResult, resultOut);
        insts->Append(inst);
        return insts;
    }
    case OperatorType::OperatorNot:
    {
        ID *sonResult = nullptr;
        auto insts = ir::GenInsts();
        insts->Append(MakeExprInner(son, sonResult));
        insts->Append(MakeICmp(sonResult, ICmpType::EQ, MakeNum(0), resultOut));
        return insts;
    }
    default:
        assert(false);
        break;
    }
}

ir::ICmp *BlockGenerator::MakeICmp(ID *left, ICmpType cmpType, ID *right, ID *&resultOut)
{
    resultOut = new ID(BasicType::TYPE_INT32);
    return new ir::ICmp(resultOut, cmpType, left, right);
}

ir::Br *BlockGenerator::MakeBr(ID *cond, ir::Label *trueLabel, ir::Label *falseLabel)
{
    return new ir::Br(cond, trueLabel, falseLabel);
}

ir::Br *BlockGenerator::MakeBr(ir::Label *target)
{
    return new ir::Br(target);
}

ir::IRInsts *BlockGenerator::MakeStatement(StmtNode *stmt)
{

    switch (stmt->SubNodeType)
    {
    case StmtType::StmtAssign:
    {
        return MakeAssignStmt(stmt);
    }
    case StmtType::StmtBlock:
    {
        return MakeBlockStmt(stmt);
    }
    case StmtType::StmtBreak:
    {
        return MakeBreakStmt(stmt);
    }
    case StmtType::StmtContinue:
    {
        return MakeContinueStmt(stmt);
    }
    case StmtType::StmtExpr:
    {
        return MakeExprStmt(stmt);
    }
    case StmtType::StmtIf:
    {
        return MakeIfStmt(stmt);
    }
    case StmtType::StmtReturn:
    {
        return MakeReturnStmt(stmt);
    }
    case StmtType::StmtWhile:
    {
        return MakeWhileStmt(stmt);
    }
    default:
        break;
    }
    return nullptr;
}

ir::IRInsts *BlockGenerator::MakeAssignStmt(StmtNode *assignStmt)
{
    auto target = assignStmt->Children[0];
    auto expr = assignStmt->Children[1];
    ID *ptr = nullptr;
    ID *exprResult = nullptr;
    auto insts = ir::GenInsts();
    insts->Append(MakeExpr(expr, exprResult));
    insts->Append(MakeLeftRef(target, ptr));
    assert(!ptr->IsConst && "Try to assign a constant");
    assert(ptr->Type.Dims.size() == 1 && "Try to assign a non-left value");
    insts->Append(MakeStore(exprResult, ptr));
    ptr->SetLRefed();
    return insts;
}

ir::IRInsts *BlockGenerator::MakeIfStmt(StmtNode *ifStmt)
{
    auto cond = ifStmt->Children[0];
    auto trueNode = ifStmt->Children[1];
    auto falseNode = ifStmt->Children.size() > 2 ? ifStmt->Children[2] : nullptr;
    ir::Label *trueLabel = MakeLabel(MakeID());
    ir::Label *falseLabel = MakeLabel(MakeID());
    ir::Label *outLabel = nullptr;
    auto insts = ir::GenInsts();
    insts->Append(MakeCond(cond, trueLabel, falseLabel));
    insts->Append(trueLabel);
    insts->Append(MakeStatement(dynamic_cast<StmtNode *>(trueNode)));
    if (falseNode != nullptr)
    {
        outLabel = MakeLabel(MakeID());
        insts->Append(MakeBr(outLabel));
        insts->Append(falseLabel);
        insts->Append(MakeStatement(dynamic_cast<StmtNode *>(falseNode)));

        insts->Append(outLabel);
    }
    else
    {

        insts->Append(falseLabel);
    }
    return insts;
}

ir::IRInsts *BlockGenerator::MakeExprStmt(StmtNode *exprStmt)
{
    ID *result = nullptr;
    if (exprStmt->Children.empty())
    {
        return ir::GenInsts();
    }
    return MakeExpr(exprStmt->Children[0], result);
}

ir::IRInsts *BlockGenerator::MakeWhileStmt(StmtNode *whileStmt)
{

    ID *result = nullptr;
    auto insts = ir::GenInsts();

    auto cond = whileStmt->Children[0];
    auto body = whileStmt->Children[1];

    auto loopStartContainer = MakeLabel(MakeID());
    auto loopBody = MakeLabel(MakeID());
    auto loopEndContainer = MakeLabel(MakeID());
    ReplaceLoopStart(loopStartContainer);
    ReplaceLoopEnd(loopEndContainer);

    insts->Append(LoopStart->MakeComment("loop start"));
    insts->Append(MakeCond(cond, loopBody, LoopEnd));
    insts->Append(loopBody->MakeComment("loop body"));
    insts->Append(MakeStatement(dynamic_cast<StmtNode *>(body)));
    insts->Append(MakeBr(LoopStart));
    insts->Append(LoopEnd->MakeComment("loop end"));

    ReplaceLoopStart(loopStartContainer);
    ReplaceLoopEnd(loopEndContainer);
    return insts;
}

ir::IRInsts *BlockGenerator::MakeBlockStmt(StmtNode *blockStmt)
{
    BlockGenerator subBlock(FuncTable, &VarIDTable);
    AstNode *blockNode = blockStmt->Children[0];
    subBlock.SetLoopLabel(LoopStart, LoopEnd);
    subBlock.SetFuncEndLabel(FuncEnd, RetPtr);
    return subBlock.MakeBlock(blockNode);
}

ir::IRInsts *BlockGenerator::MakeContinueStmt(StmtNode *continueStmt)
{
    auto insts = ir::GenInsts();
    insts->Append(MakeBr(LoopStart));
    return insts;
}

ir::IRInsts *BlockGenerator::MakeReturnStmt(StmtNode *returnStmt)
{
    auto insts = ir::GenInsts();
    if (returnStmt->Children.empty())
    {
        insts->Append(MakeBr(FuncEnd));
        return insts;
    }
    auto expr = returnStmt->Children[0];
    ID *exprResult = nullptr;
    insts->Append(MakeExpr(expr, exprResult));
    insts->Append(MakeStore(exprResult, RetPtr));
    insts->Append(MakeBr(FuncEnd));
    return insts;
}

ir::IRInsts *BlockGenerator::MakeBreakStmt(StmtNode *breakStmt)
{
    auto insts = ir::GenInsts();
    insts->Append(MakeBr(LoopEnd));
    return insts;
}

ir::IRInsts *BlockGenerator::MakeShortAnd(OperatorNode *andNode, ir::Label *trueLabel, ir::Label *falseLabel)
{
    ir::Label *extraLabel = MakeLabel(MakeID());
    auto left = andNode->Children[0];
    auto right = andNode->Children[1];
    auto insts = ir::GenInsts();
    insts->Append(MakeCondInner(left, extraLabel, falseLabel));
    insts->Append(extraLabel);
    insts->Append(MakeCondInner(right, trueLabel, falseLabel));
    return insts;
}

ir::IRInsts *BlockGenerator::MakeShortOr(OperatorNode *orNode, ir::Label *trueLabel, ir::Label *falseLabel)
{
    ir::Label *extraLabel = MakeLabel(MakeID());
    auto left = orNode->Children[0];
    auto right = orNode->Children[1];
    auto insts = ir::GenInsts();
    insts->Append(MakeCondInner(left, trueLabel, extraLabel));
    insts->Append(extraLabel);
    insts->Append(MakeCondInner(right, trueLabel, falseLabel));
    return insts;
}

ir::IRInsts *BlockGenerator::MakeCond(AstNode *cond, ir::Label *trueLabel, ir::Label *falseLabel)
{
    assert(trueLabel != nullptr && falseLabel != nullptr);
    auto son = cond->Children[0];
    return MakeCondInner(son, trueLabel, falseLabel);
}

ir::IRInsts *BlockGenerator::MakeCondInner(AstNode *inner, ir::Label *trueLabel, ir::Label *falseLabel)
{
    switch (inner->NodeType)
    {
    case AstNodeType::ExprType:
    {
        ID *result = nullptr;
        auto insts = ir::GenInsts();
        insts->Append(MakeExpr(inner, result));
        insts->Append(MakeExprToBr(result, trueLabel, falseLabel));
        return insts;
    }
    case AstNodeType::OperatorType:
    {
        auto op = dynamic_cast<OperatorNode *>(inner);
        return MakeCondOperator(op, trueLabel, falseLabel);
    }
    default:
        assert(false && "Invalid condition node");
        return nullptr;
        break;
    }
}

ir::IRInsts *BlockGenerator::MakeCondOperator(OperatorNode *op, ir::Label *trueLabel, ir::Label *falseLabel)
{
    switch (op->SubNodeType)
    {
    case OperatorType::OperatorAnd:
        return MakeShortAnd(op, trueLabel, falseLabel);
    case OperatorType::OperatorOr:
        return MakeShortOr(op, trueLabel, falseLabel);
    case OperatorType::OperatorEQ:
    case OperatorType::OperatorNE:
    case OperatorType::OperatorLT:
    case OperatorType::OperatorGT:
    case OperatorType::OperatorLE:
    case OperatorType::OperatorGE:
    {
        ID *result = nullptr;
        auto insts = ir::GenInsts();
        insts->Append(MakeRelationOperator(op, result));
        insts->Append(MakeBr(result, trueLabel, falseLabel));
        return insts;
    }
    default:
        assert(false && "Invalid condition operator");
        break;
    }
}

ir::IRInsts *BlockGenerator::MakeRelationInner(AstNode *son, ID *&resultOut)
{
    switch (son->NodeType)
    {
    case AstNodeType::ExprType:
        return MakeExpr(son, resultOut);
        break;
    case AstNodeType::OperatorType:
    {
        auto op = dynamic_cast<OperatorNode *>(son);
        return MakeRelationOperator(op, resultOut);
    }
    break;
    default:
        assert(false && "Invalid relation operator");
        return nullptr;
        break;
    }
}

ir::IRInsts *BlockGenerator::MakeRelationOperator(OperatorNode *op, ID *&resultOut)
{
    auto insts = ir::GenInsts();
    auto left = op->Children[0];
    auto right = op->Children[1];
    ID *leftResult = nullptr;
    ID *rightResult = nullptr;
    insts->Append(MakeRelationInner(left, leftResult));
    insts->Append(MakeRelationInner(right, rightResult));
    ICmpType cmpType;
    switch (op->SubNodeType)
    {
    case OperatorType::OperatorEQ:
        cmpType = ICmpType::EQ;
        break;
    case OperatorType::OperatorNE:
        cmpType = ICmpType::NE;
        break;
    case OperatorType::OperatorLT:
        cmpType = ICmpType::SLT;
        break;
    case OperatorType::OperatorGT:
        cmpType = ICmpType::SGT;
        break;
    case OperatorType::OperatorLE:
        cmpType = ICmpType::SLE;
        break;
    case OperatorType::OperatorGE:
        cmpType = ICmpType::SGE;
        break;
    default:
        assert(false && "Invalid relation operator");
        break;
    }
    insts->Append(MakeICmp(leftResult, cmpType, rightResult, resultOut));
    return insts;
}

ir::IRInsts *BlockGenerator::MakeExprToBr(ID *judge, ir::Label *trueLabel, ir::Label *falseLabel)
{
    ID *result;
    auto insts = ir::GenInsts();
    insts->Append(MakeICmp(judge, ICmpType::NE, MakeNum(0), result));
    insts->Append(MakeBr(result, trueLabel, falseLabel));
    return insts;
}

ir::Alloca *BlockGenerator::MakeAlloca(ID *&ptr)
{
    ptr = new ID(BasicType::TYPE_PTR);
    ptr->AddPtr();
    return new ir::Alloca(ptr);
}

ir::Alloca *BlockGenerator::MakeAlloca(ID *&ptr, Dim &dim)
{
    if (dim.empty())
    {
        return MakeAlloca(ptr);
    }
    ptr = new ID(BasicType::TYPE_PTR);
    ptr->AddPtr();
    ptr->Type.AppendArray(dim);
    return new ir::Alloca(ptr);
}

ir::Alloca *BlockGenerator::MakeAlloca(ID *&ptr, Dim &dim, bool isPtr)
{
    if (!isPtr)
    {
        return MakeAlloca(ptr, dim);
    }
    ptr = new ID(BasicType::TYPE_PTR);
    ptr->AddPtr();
    ptr->AddPtr();
    ptr->Type.AppendArray(dim);
    return new ir::Alloca(ptr);
}

/// @brief input a ptr and return a load instruction, dim will be lower
ir::Load *BlockGenerator::MakeLoad(ID *ptr, ID *&resultOut)
{

    if (ptr->Type.Dims.size() > 1)
    {
        resultOut = ptr->ToLowDimPtr();
    }
    else if (ptr->Type.Dims.size() == 1)
    {
        resultOut = new ID(BasicType::TYPE_INT32);
    }
    else
    {
        assert(false && "invalid load option");
    }
    assert(resultOut->Type.Dims.size() == ptr->Type.Dims.size() - 1 && "invalid load option");
    return new ir::Load(resultOut, ptr);
}

ir::Store *BlockGenerator::MakeStore(ID *value, ID *ptr)
{
    assert(ptr->Type.Dims.size() == value->Type.Dims.size() + 1);
    return new ir::Store(value, ptr);
}

BlockGenerator::BlockGenerator(FuncSybTable &funcTable, VarSybTable *parentVarTable) : FuncTable(funcTable)
{
    VarIDTable.Parent = parentVarTable;
    LoopStart = nullptr;
    LoopEnd = nullptr;
}

void BlockGenerator::SetLoopLabel(ir::Label *lStart, ir::Label *lEnd)
{
    LoopStart = lStart;
    LoopEnd = lEnd;
}

void BlockGenerator::SetFuncEndLabel(ir::Label *label, ID *retVal)
{
    FuncEnd = label;
    RetPtr = retVal;
}

void BlockGenerator::ReplaceLoopStart(ir::Label *&target)
{
    ir::Label *tmp = LoopStart;
    LoopStart = target;
    target = tmp;
}

void BlockGenerator::ReplaceLoopEnd(ir::Label *&target)
{
    ir::Label *tmp = LoopEnd;
    LoopEnd = target;
    target = tmp;
}
