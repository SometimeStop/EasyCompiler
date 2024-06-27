enum class IRInsType
{
    ///@def <type>:[i32/...]
    ///@def <ptr-type>:[i32*/...]
    ///@def <value>:[imm/%<variable>]
    ///@def [align-val]: 4(i32)/8(array)

    //%[ptr-var] = alloca <type>, align [align-val]
    //*In C: *p = new <type>;
    //*type is strong related to ptr-var
    Alloca,

    //%[var] = load <type>, <ptr-type> %[ptr-var], align [align-val]
    //*In C: v = (<type>)*p;
    //*type is strong related to var
    Load,

    // store <type> %var, <ptr-type> %[ptr-var], align [align-val]
    //*In C: *p = v;
    Store,

    //%[var] = call <type> @[function name](<type> %[var], ...)
    //*In C: v = (<type>)f(v, ...);
    Call,

    // ret <type> %[var]
    // ret void
    Ret,

    //%[var #3] = add/sub/mul nsw <type> %[var #1], %[var #2]
    //%[var #3] = sdiv/srem <type> %[var #1], %[var #2]
    Add,
    Sub,
    Mul,
    SDiv,
    SRem,
    //%[var #3] = icmp slt <type> %[var #2], %[var #1]
    ICmp,

    //br <type:i1> %[syb-var], label %[label-var#1], label %[label-var #2]
    //
    GetElementPtr,
};

enum class ICmpType
{
    SGT, //* >
    SLT, //* <
    SGE, //* >=
    SLE, //* <=
    EQ,  //* ==
    NE,  //* !=
};