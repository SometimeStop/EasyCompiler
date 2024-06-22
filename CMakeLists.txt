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
    source/ast/AST.cpp
    source/ast/AST.h
    source/src/visualization.cpp
    source/src/visualization.h
    source/src/Antlr4CSTVisitor.cpp
    source/src/Antlr4CSTVisitor.h
    source/src/AntlrExecutor.cpp
    source/src/AntlrExecutor.h
)

set(GLOBAL_SRC
    global/type.cpp
    global/type.h
)

add_executable(${PROJECT_NAME}
    source/src/main.cpp
    ${FRONTEND_SRC}
    ${GLOBAL_SRC}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${Graphviz_INCLUDE_DIRS}
    ${ANTLR4_INCLUDE_DIR}
    source/autogen
    source/src
    source/ast
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