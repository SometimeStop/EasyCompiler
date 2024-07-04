cmake_minimum_required(VERSION 3.12)

project(MyCompiler VERSION 1.0.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)

find_package(Java COMPONENTS Runtime REQUIRED)

find_package(ANTLR4 REQUIRED)

find_package(Graphviz REQUIRED)

set(ANTLR4_JAR_LOCATION /usr/local/bin/antlr-4.12.0-complete.jar)
message(STATUS ${ANTLR4_JAR_LOCATION})

find_package(ANTLR4 REQUIRED)
message(STATUS ${ANTLR4_INCLUDE_DIR})

set(ANTLR4_GEN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source/autogen)
set(ANTLR4_INPUT
    ${CMAKE_CURRENT_SOURCE_DIR}/source/sysy.g4
)
set(ANTLR4_OUTPUT
    ${ANTLR4_GEN_DIR}/sysyBaseVisitor.cpp
    ${ANTLR4_GEN_DIR}/sysyBaseVisitor.h
    ${ANTLR4_GEN_DIR}/sysyVisitor.cpp
    ${ANTLR4_GEN_DIR}/sysyVisitor.h
    ${ANTLR4_GEN_DIR}/sysyLexer.cpp
    ${ANTLR4_GEN_DIR}/sysyLexer.h
    ${ANTLR4_GEN_DIR}/sysyParser.cpp
    ${ANTLR4_GEN_DIR}/sysyParser.h
)

set(FRONTEND_SRC
    ${ANTLR4_OUTPUT}
    source/ast/AstFunc.cpp
    source/ast/AstFunc.h
    source/ast/AstNode.cpp
    source/ast/AstNode.h
    source/ast/OperatorNode.cpp
    source/ast/OperatorNode.h
    source/ast/StmtNode.cpp
    source/ast/StmtNode.h
    source/ast/Antlr4CSTVisitor.cpp
    source/ast/Antlr4CSTVisitor.h
    source/ast/AntlrExecutor.cpp
    source/ast/AntlrExecutor.h

    source/src/visualization.cpp
    source/src/visualization.h
)

set(IRGENERATE_SRC
    source/llvmir/IRInstruction.cpp
    source/llvmir/IRInstruction.h
    source/llvmir/BlockGenerator.cpp
    source/llvmir/BlockGenerator.h
    source/llvmir/GlobalGenerator.cpp
    source/llvmir/GlobalGenerator.h
    source/llvmir/IRGen.cpp
    source/llvmir/IRGen.h
    source/llvmir/irtype.h
)

set(SYMBOLTABLE_SRC
    source/symbolTable/ID.cpp
    source/symbolTable/ID.h
    source/symbolTable/FuncSybTable.cpp
    source/symbolTable/FuncSybTable.h
    source/symbolTable/Function.cpp
    source/symbolTable/Function.h
    source/symbolTable/VarSybTable.cpp
    source/symbolTable/VarSybTable.h
)

set(GLOBAL_SRC
    global/type.cpp
    global/type.h
    global/VarType.cpp
    global/VarType.h
)

add_executable(${PROJECT_NAME}
    source/src/main.cpp
    ${FRONTEND_SRC}
    ${GLOBAL_SRC}
    ${IRGENERATE_SRC}
    ${SYMBOLTABLE_SRC}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${Graphviz_INCLUDE_DIRS}
    ${ANTLR4_INCLUDE_DIR}
    source/autogen
    source/src
    source/ast
    source/symbolTable
    source/llvmir
    global
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${Graphviz_LIBRARIES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${ANTLR4_LIBRARY})

add_custom_command(
    OUTPUT
    ${ANTLR4_OUTPUT}
    COMMAND
    ${Java_JAVA_EXECUTABLE} -jar ${ANTLR4_JAR_LOCATION} -Dlanguage=Cpp -no-listener -visitor -o ${ANTLR4_GEN_DIR} sysy.g4
    DEPENDS
    ${ANTLR4_INPUT}
    WORKING_DIRECTORY
    ${ANTLR4_GEN_DIR}/..
)