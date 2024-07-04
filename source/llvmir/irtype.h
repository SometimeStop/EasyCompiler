enum class IRInsType
{
    ///@def <type>:[i32/...]
    ///@def <ptr-type>:[i32*/...]
    ///@def <value>:[imm/%<variable>]

    //%[ptr-var] = alloca <type>
    //%[ptr-var] = global <type> {init list...}
    //*In C: *p = new <type>;
    //*type is strong related to ptr-var
    Alloca,
    Global,

    //%[var] = load <type>, <ptr-type> %[ptr-var]
    //*In C: v = (<type>)*p;
    //*type is strong related to var
    Load,

    // store <type> %var, <ptr-type> %[ptr-var]
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

    //%[var #3] = icmp [cmp] <type> %[var #2], %[var #1]
    ICmp,

    // label <label-No>
    Label,

    // br <type:i1> %[syb-var], label %[label-var#1], label %[label-var #2]
    // br label %[label-var]
    Br,
    BrDirect,

    //%[ptr-var]^(dim - 1) = getelementptr %[ptr-var]
    GetElementPtr,
    GetPtr,
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