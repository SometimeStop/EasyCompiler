#pragma once
#include "type.h"
#include "riscvtype.h"
#include <cstdint>
#include <string>
class Oprd
{
public:
    bool IsImm;
    Oprd();
};

class Register : public Oprd
{
public:
    ABI ABINo;
    ABI ToABI();
    int ToInt();
    Register(ABI abi);
    Register(int abi);
    std::string ToString();
};

class Imm : public Oprd
{
public:
    bool IsImm12;
    int ImmVal;
    int *Sp;
    Imm();
    Imm(int immVal, bool isImm12 = true, int *sp = nullptr);
};

class Var
{
private:
    bool StackSet;

public:
    bool InStack;
    bool InReg;
    Imm ImmOffset;
    Register *Reg;
    int GetOffset();
    Imm *GetImm12Offset();
    void SetInReg(Register *reg);
    void OnlyInReg();
    void SetInStack(int offset, int *sp);
    void SetInStack();
    void AllocInStack(int offset, int *sp);
    void OnlyInStack();
    Var();
    Var(int offset, int *sp);
    Var(Register *reg);
};

namespace rv
{
    typedef std::vector<Register *> RegList;
    typedef std::string Label;

    class riscvasm
    {
    public:
        AsmType Type;
        RegList Srcs;
        Register *DstReg;
        Imm *ImmVal;
        Label Lbl;
        std::string Comment;
        riscvasm();
        riscvasm(AsmType t);
        Register *&rd();
        Register *&rs1();
        Register *&rs2();
        Imm *&imm();
        virtual std::string ToString();
        riscvasm *Cmt(std::string in);
    };

    class RVAsms
    {
    public:
        RVAsms();
        std::vector<riscvasm *> Asms;
        void Append(riscvasm *rvasm);
        void Append(RVAsms *rvasms);
        void Append(RVAsms &rvasms);
        void Insert(riscvasm *rvasm);
        void Insert(RVAsms *rvasms);
    };

    class split : public riscvasm
    {
    public:
        std::string show;
        split(std::string desc);
        std::string ToString() override;
    };

    class label : public riscvasm
    {
    public:
        label(Label label);
        std::string ToString() override;
    };

    class beqz : public riscvasm
    {
    public:
        beqz(Register *rs, Label lb);
        std::string ToString() override;
    };

    class bnez : public riscvasm
    {
    public:
        bnez(Register *rs, Label lb);
        std::string ToString() override;
    };

    class j : public riscvasm
    {
    public:
        j(Label lb);
        std::string ToString() override;
    };

    class call : public riscvasm
    {
    public:
        // call label
        call(Label lb);
        std::string ToString() override;
    };

    class ret : public riscvasm
    {
    public:
        // ret
        ret();
        std::string ToString() override;
    };

    class ld : public riscvasm
    {
    public:
        // rd[imm12] => rs
        ld(Register *rs, Register *rd, Imm *imm12);
        std::string ToString() override;
    };

    class sd : public riscvasm
    {
    public:
        // rs2 => rs1[imm12]
        sd(Register *rs2, Register *rs1, Imm *imm12);
        std::string ToString() override;
    };

    class add : public riscvasm
    {
    public:
        // rs1 + rs2 => rd
        add(Register *rd, Register *rs1, Register *rs2);
        std::string ToString() override;
    };

    class addi : public riscvasm
    {
    public:
        // rs1 + imm12 => rd
        addi(Register *rd, Register *rs1, Imm *imm12);
        std::string ToString() override;
    };

    class sub : public riscvasm
    {
    public:
        // rs1 - rs2 => rd
        sub(Register *rd, Register *rs1, Register *rs2);
        std::string ToString() override;
    };

    class slt : public riscvasm
    {
    public:
        // rs1 < rs2 ? 1 : 0 => rd
        slt(Register *rd, Register *rs1, Register *rs2);
        std::string ToString() override;
    };

    class sgt : public riscvasm
    {
    public:
        // rs1 > rs2 ? 1 : 0 => rd
        sgt(Register *rd, Register *rs1, Register *rs2);
        std::string ToString() override;
    };

    class seqz : public riscvasm
    {
    public:
        // rs == 0 ? 1 : 0 => rd
        seqz(Register *rd, Register *rs);
        std::string ToString() override;
    };

    class snez : public riscvasm
    {
    public:
        // rs != 0 ? 1 : 0 => rd
        snez(Register *rd, Register *rs);
        std::string ToString() override;
    };

    class mul : public riscvasm
    {
    public:
        // rs1 * rs2 => rd
        mul(Register *rd, Register *rs1, Register *rs2);
        std::string ToString() override;
    };

    class div : public riscvasm
    {
    public:
        // rs1 / rs2 => rd
        div(Register *rd, Register *rs1, Register *rs2);
        std::string ToString() override;
    };

    class rem : public riscvasm
    {
    public:
        // rs1 % rs2 => rd
        rem(Register *rd, Register *rs1, Register *rs2);
        std::string ToString() override;
    };

    class li : public riscvasm
    {
    public:
        // imm => rd
        li(Register *rd, Imm *imm);
        std::string ToString() override;
    };

    class la : public riscvasm
    {
    public:
        // addr(label) => rd
        la(Register *rd, Label label);
        std::string ToString() override;
    };

    class mv : public riscvasm
    {
    public:
        // rs => rd
        mv(Register *rd, Register *rs);
        std::string ToString() override;
    };

}