
// Generated from sysy.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  sysyLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T_CONST = 11, T_INT = 12, T_VOID = 13, 
    T_IF = 14, T_WHILE = 15, T_BREAK = 16, T_CONTINUE = 17, T_RETURN = 18, 
    T_ADD = 19, T_SUB = 20, T_MUL = 21, T_DIV = 22, T_MOD = 23, T_LT = 24, 
    T_GT = 25, T_LE = 26, T_GE = 27, T_EQ = 28, T_NE = 29, T_AND = 30, T_OR = 31, 
    T_NOT = 32, T_DEC_CONST = 33, T_OCT_CONST = 34, T_HEX_CONST = 35, T_ID = 36, 
    WS = 37, LineComment = 38, MultiLineComment = 39
  };

  explicit sysyLexer(antlr4::CharStream *input);

  ~sysyLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

