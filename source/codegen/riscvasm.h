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

class Reg : public Oprd
{
public:
    int32_t *RegNo;
    Reg(int32_t *regNo);
};

class Imm : public Oprd
{
public:
    bool IsImm12;
    int32_t ImmVal;
    Imm(int32_t immVal, bool isImm12 = true);
};



namespace rv
{
    typedef std::vector<Reg *> RegList;
    typedef std::string Label;

    class riscvasm
    {
    public:
        AsmType Type;
        RegList Srcs;
        Reg *DstReg;
        Imm *ImmVal;
        Label *Lbl;
        riscvasm(AsmType t);
        Reg *&rd();
        Reg *&rs1();
        Reg *&rs2();
        Imm *&imm();
    };

    class beqz : public riscvasm
    {
    public:
        beqz(Reg *rs, Label *lb);
    };

    class bnez : public riscvasm
    {
    public:
        bnez(Reg *rs, Label *lb);
    };

    class j : public riscvasm
    {
    public:
        j(Label *lb);
    };

    class call : public riscvasm
    {
    public:
        // call label
        call(Label *lb);
    };

    class ret : public riscvasm
    {
    public:
        // ret
        ret();
    };

    class lw : public riscvasm
    {
    public:
        // rd[imm12] => rs
        lw(Reg *rs, Reg *rd, Imm *imm12);
    };

    class sw : public riscvasm
    {
    public:
        // rs2 => rs1[imm12]
        sw(Reg *rs2, Reg *rs1, Imm *imm12);
    };

    class add : public riscvasm
    {
    public:
        // rs1 + rs2 => rd
        add(Reg *rd, Reg *rs1, Reg *rs2);
    };

    class addi : public riscvasm
    {
    public:
        // rs1 + imm12 => rd
        addi(Reg *rd, Reg *rs1, Imm *imm12);
    };

    class sub : public riscvasm
    {
    public:
        // rs1 - rs2 => rd
        sub(Reg *rd, Reg *rs1, Reg *rs2);
    };

    class slt : public riscvasm
    {
    public:
        // rs1 < rs2 ? 1 : 0 => rd
        slt(Reg *rd, Reg *rs1, Reg *rs2);
    };

    class sgt : public riscvasm
    {
    public:
        // rs1 > rs2 ? 1 : 0 => rd
        sgt(Reg *rd, Reg *rs1, Reg *rs2);
    };

    class seqz : public riscvasm
    {
    public:
        // rs == 0 ? 1 : 0 => rd
        seqz(Reg *rd, Reg *rs);
    };

    class snez : public riscvasm
    {
    public:
        // rs != 0 ? 1 : 0 => rd
        snez(Reg *rd, Reg *rs);
    };

    class mul : public riscvasm
    {
    public:
        // rs1 * rs2 => rd
        mul(Reg *rd, Reg *rs1, Reg *rs2);
    };

    class div : public riscvasm
    {
    public:
        // rs1 / rs2 => rd
        div(Reg *rd, Reg *rs1, Reg *rs2);
    };

    class rem : public riscvasm
    {
    public:
        // rs1 % rs2 => rd
        rem(Reg *rd, Reg *rs1, Reg *rs2);
    };

    class li : public riscvasm
    {
    public:
        // imm => rd
        li(Reg *rd, Imm *imm);
    };

    class la : public riscvasm
    {
    public:
        // addr(label) => rd
        la(Reg *rd, Label *label);
    };

    class mv : public riscvasm
    {
    public:
        // rs => rd
        mv(Reg *rd, Reg *rs);
    };

    typedef std::vector<riscvasm *> Asms;
}