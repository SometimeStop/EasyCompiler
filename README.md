# Basic Compiler For Sys-Y Language
A simple implemention of sys-y compiler
## Frontend
- use Antlr-4.12.0 finishing the syntax analysis and lexical analysis, language rule is in source/sysy.g4
- use Antlr-4 visitor-mode with AstNode and its subclasses building AST
- use BlockGenerator and GlobalGenerator managing symbol table and IR generating
- use a simplified LLVM-IR as the intermediate representation
## Backend
- a simple risc-v code generator with all variables saved in stack
## Start
### Something need to be done...
1. be sure to install Antlr-4.12.0 and its run-time library correctly
2. be sure to install JDK
3. be sure to install Graphviz inorder to visualize the AST and basic blocks
4. be sure to install riscv64-linux-gnu-gcc
5. be sure to install qemu-riscv64-static
### Getting Started
1. check **makefile** to learn about the commands
2. use generate_run to build and run the compiler, it will load ./demo/1 as the input file and generate AST picture, basic block picture and asm file in folder ./out/
3. some of the generate path in C++ code might be wrong, remember to modify them
