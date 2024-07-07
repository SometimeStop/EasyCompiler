#pragma once
enum class AsmType
{
    BEQZ,
    BNEZ,
    J,
    CALL,
    RET,
    LW,
    SW,
    ADD,
    ADDI,
    SUB,
    SLT,
    SGT,
    SEQZ,
    SNEZ,
    XOR,
    XORI,
    OR,
    ORI,
    AND,
    ANDI,
    MUL,
    DIV,
    REM,
    LI,
    LA,
    MV,
    DESC,
    LABEL,
    TAB,
};