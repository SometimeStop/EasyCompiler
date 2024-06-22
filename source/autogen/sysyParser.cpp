
// Generated from sysy.g4 by ANTLR 4.12.0


#include "sysyVisitor.h"

#include "sysyParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SysyParserStaticData final {
  SysyParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SysyParserStaticData(const SysyParserStaticData&) = delete;
  SysyParserStaticData(SysyParserStaticData&&) = delete;
  SysyParserStaticData& operator=(const SysyParserStaticData&) = delete;
  SysyParserStaticData& operator=(SysyParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sysyParserOnceFlag;
SysyParserStaticData *sysyParserStaticData = nullptr;

void sysyParserInitialize() {
  assert(sysyParserStaticData == nullptr);
  auto staticData = std::make_unique<SysyParserStaticData>(
    std::vector<std::string>{
      "compileUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
      "varDecl", "varDef", "initVal", "funcDef", "funcType", "funcFormParams", 
      "funcFormParam", "funcBasicParam", "funcArrayParam", "block", "blockItem", 
      "stmt", "expr", "cond", "lVal", "primaryExpr", "number", "unaryExpr", 
      "unaryOp", "funcRealParams", "mulExpr", "mulOp", "addExpr", "addOp", 
      "relationExpr", "relationOp", "eqExpr", "eqOp", "lAndExpr", "lOrExpr", 
      "constExpr", "intConst"
    },
    std::vector<std::string>{
      "", "','", "';'", "'['", "']'", "'='", "'{'", "'}'", "'('", "')'", 
      "'else'", "'const'", "'int'", "'void'", "'if'", "'while'", "'break'", 
      "'continue'", "'return'", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", 
      "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", "'||'", "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "T_CONST", "T_INT", "T_VOID", 
      "T_IF", "T_WHILE", "T_BREAK", "T_CONTINUE", "T_RETURN", "T_ADD", "T_SUB", 
      "T_MUL", "T_DIV", "T_MOD", "T_LT", "T_GT", "T_LE", "T_GE", "T_EQ", 
      "T_NE", "T_AND", "T_OR", "T_NOT", "T_DEC_CONST", "T_OCT_CONST", "T_HEX_CONST", 
      "T_ID", "WS", "LineComment", "MultiLineComment"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,39,396,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,1,0,1,0,5,0,79,8,0,10,0,12,0,82,9,0,1,1,1,1,3,
  	1,86,8,1,1,2,1,2,1,2,1,2,1,2,5,2,93,8,2,10,2,12,2,96,9,2,1,2,1,2,1,3,
  	1,3,1,4,1,4,1,4,1,4,1,4,5,4,107,8,4,10,4,12,4,110,9,4,1,4,1,4,1,4,1,5,
  	1,5,1,5,1,5,1,5,5,5,120,8,5,10,5,12,5,123,9,5,3,5,125,8,5,1,5,3,5,128,
  	8,5,1,6,1,6,1,6,1,6,5,6,134,8,6,10,6,12,6,137,9,6,1,6,1,6,1,7,1,7,1,7,
  	1,7,1,7,5,7,146,8,7,10,7,12,7,149,9,7,1,7,1,7,1,7,1,7,1,7,5,7,156,8,7,
  	10,7,12,7,159,9,7,1,7,1,7,3,7,163,8,7,1,8,1,8,1,8,1,8,1,8,5,8,170,8,8,
  	10,8,12,8,173,9,8,3,8,175,8,8,1,8,3,8,178,8,8,1,9,1,9,1,9,1,9,3,9,184,
  	8,9,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,11,5,11,194,8,11,10,11,12,11,197,
  	9,11,1,12,1,12,3,12,201,8,12,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,5,14,214,8,14,10,14,12,14,217,9,14,1,15,1,15,5,15,221,
  	8,15,10,15,12,15,224,9,15,1,15,1,15,1,16,1,16,3,16,230,8,16,1,17,1,17,
  	1,17,1,17,1,17,1,17,3,17,238,8,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,3,17,249,8,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,1,17,3,17,263,8,17,1,17,3,17,266,8,17,1,18,1,18,1,19,1,19,1,
  	20,1,20,1,20,1,20,1,20,5,20,277,8,20,10,20,12,20,280,9,20,1,21,1,21,1,
  	21,1,21,1,21,1,21,3,21,288,8,21,1,22,1,22,1,23,1,23,1,23,1,23,3,23,296,
  	8,23,1,23,1,23,1,23,1,23,3,23,302,8,23,1,24,1,24,1,25,1,25,1,25,5,25,
  	309,8,25,10,25,12,25,312,9,25,1,26,1,26,1,26,1,26,1,26,1,26,1,26,5,26,
  	321,8,26,10,26,12,26,324,9,26,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,
  	1,28,5,28,335,8,28,10,28,12,28,338,9,28,1,29,1,29,1,30,1,30,1,30,1,30,
  	1,30,1,30,1,30,5,30,349,8,30,10,30,12,30,352,9,30,1,31,1,31,1,32,1,32,
  	1,32,1,32,1,32,1,32,1,32,5,32,363,8,32,10,32,12,32,366,9,32,1,33,1,33,
  	1,34,1,34,1,34,1,34,1,34,1,34,5,34,376,8,34,10,34,12,34,379,9,34,1,35,
  	1,35,1,35,1,35,1,35,1,35,5,35,387,8,35,10,35,12,35,390,9,35,1,36,1,36,
  	1,37,1,37,1,37,0,6,52,56,60,64,68,70,38,0,2,4,6,8,10,12,14,16,18,20,22,
  	24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,
  	70,72,74,0,7,1,0,12,13,2,0,19,20,32,32,1,0,21,23,1,0,19,20,1,0,24,27,
  	1,0,28,29,1,0,33,35,401,0,80,1,0,0,0,2,85,1,0,0,0,4,87,1,0,0,0,6,99,1,
  	0,0,0,8,101,1,0,0,0,10,127,1,0,0,0,12,129,1,0,0,0,14,162,1,0,0,0,16,177,
  	1,0,0,0,18,179,1,0,0,0,20,188,1,0,0,0,22,190,1,0,0,0,24,200,1,0,0,0,26,
  	202,1,0,0,0,28,205,1,0,0,0,30,218,1,0,0,0,32,229,1,0,0,0,34,265,1,0,0,
  	0,36,267,1,0,0,0,38,269,1,0,0,0,40,271,1,0,0,0,42,287,1,0,0,0,44,289,
  	1,0,0,0,46,301,1,0,0,0,48,303,1,0,0,0,50,305,1,0,0,0,52,313,1,0,0,0,54,
  	325,1,0,0,0,56,327,1,0,0,0,58,339,1,0,0,0,60,341,1,0,0,0,62,353,1,0,0,
  	0,64,355,1,0,0,0,66,367,1,0,0,0,68,369,1,0,0,0,70,380,1,0,0,0,72,391,
  	1,0,0,0,74,393,1,0,0,0,76,79,3,2,1,0,77,79,3,18,9,0,78,76,1,0,0,0,78,
  	77,1,0,0,0,79,82,1,0,0,0,80,78,1,0,0,0,80,81,1,0,0,0,81,1,1,0,0,0,82,
  	80,1,0,0,0,83,86,3,4,2,0,84,86,3,12,6,0,85,83,1,0,0,0,85,84,1,0,0,0,86,
  	3,1,0,0,0,87,88,5,11,0,0,88,89,3,6,3,0,89,94,3,8,4,0,90,91,5,1,0,0,91,
  	93,3,8,4,0,92,90,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,
  	97,1,0,0,0,96,94,1,0,0,0,97,98,5,2,0,0,98,5,1,0,0,0,99,100,5,12,0,0,100,
  	7,1,0,0,0,101,108,5,36,0,0,102,103,5,3,0,0,103,104,3,72,36,0,104,105,
  	5,4,0,0,105,107,1,0,0,0,106,102,1,0,0,0,107,110,1,0,0,0,108,106,1,0,0,
  	0,108,109,1,0,0,0,109,111,1,0,0,0,110,108,1,0,0,0,111,112,5,5,0,0,112,
  	113,3,10,5,0,113,9,1,0,0,0,114,128,3,72,36,0,115,124,5,6,0,0,116,121,
  	3,10,5,0,117,118,5,1,0,0,118,120,3,10,5,0,119,117,1,0,0,0,120,123,1,0,
  	0,0,121,119,1,0,0,0,121,122,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,124,
  	116,1,0,0,0,124,125,1,0,0,0,125,126,1,0,0,0,126,128,5,7,0,0,127,114,1,
  	0,0,0,127,115,1,0,0,0,128,11,1,0,0,0,129,130,3,6,3,0,130,135,3,14,7,0,
  	131,132,5,1,0,0,132,134,3,14,7,0,133,131,1,0,0,0,134,137,1,0,0,0,135,
  	133,1,0,0,0,135,136,1,0,0,0,136,138,1,0,0,0,137,135,1,0,0,0,138,139,5,
  	2,0,0,139,13,1,0,0,0,140,147,5,36,0,0,141,142,5,3,0,0,142,143,3,72,36,
  	0,143,144,5,4,0,0,144,146,1,0,0,0,145,141,1,0,0,0,146,149,1,0,0,0,147,
  	145,1,0,0,0,147,148,1,0,0,0,148,163,1,0,0,0,149,147,1,0,0,0,150,157,5,
  	36,0,0,151,152,5,3,0,0,152,153,3,72,36,0,153,154,5,4,0,0,154,156,1,0,
  	0,0,155,151,1,0,0,0,156,159,1,0,0,0,157,155,1,0,0,0,157,158,1,0,0,0,158,
  	160,1,0,0,0,159,157,1,0,0,0,160,161,5,5,0,0,161,163,3,16,8,0,162,140,
  	1,0,0,0,162,150,1,0,0,0,163,15,1,0,0,0,164,178,3,36,18,0,165,174,5,6,
  	0,0,166,171,3,16,8,0,167,168,5,1,0,0,168,170,3,16,8,0,169,167,1,0,0,0,
  	170,173,1,0,0,0,171,169,1,0,0,0,171,172,1,0,0,0,172,175,1,0,0,0,173,171,
  	1,0,0,0,174,166,1,0,0,0,174,175,1,0,0,0,175,176,1,0,0,0,176,178,5,7,0,
  	0,177,164,1,0,0,0,177,165,1,0,0,0,178,17,1,0,0,0,179,180,3,20,10,0,180,
  	181,5,36,0,0,181,183,5,8,0,0,182,184,3,22,11,0,183,182,1,0,0,0,183,184,
  	1,0,0,0,184,185,1,0,0,0,185,186,5,9,0,0,186,187,3,30,15,0,187,19,1,0,
  	0,0,188,189,7,0,0,0,189,21,1,0,0,0,190,195,3,24,12,0,191,192,5,1,0,0,
  	192,194,3,24,12,0,193,191,1,0,0,0,194,197,1,0,0,0,195,193,1,0,0,0,195,
  	196,1,0,0,0,196,23,1,0,0,0,197,195,1,0,0,0,198,201,3,26,13,0,199,201,
  	3,28,14,0,200,198,1,0,0,0,200,199,1,0,0,0,201,25,1,0,0,0,202,203,3,6,
  	3,0,203,204,5,36,0,0,204,27,1,0,0,0,205,206,3,6,3,0,206,207,5,36,0,0,
  	207,208,5,3,0,0,208,215,5,4,0,0,209,210,5,3,0,0,210,211,3,36,18,0,211,
  	212,5,4,0,0,212,214,1,0,0,0,213,209,1,0,0,0,214,217,1,0,0,0,215,213,1,
  	0,0,0,215,216,1,0,0,0,216,29,1,0,0,0,217,215,1,0,0,0,218,222,5,6,0,0,
  	219,221,3,32,16,0,220,219,1,0,0,0,221,224,1,0,0,0,222,220,1,0,0,0,222,
  	223,1,0,0,0,223,225,1,0,0,0,224,222,1,0,0,0,225,226,5,7,0,0,226,31,1,
  	0,0,0,227,230,3,2,1,0,228,230,3,34,17,0,229,227,1,0,0,0,229,228,1,0,0,
  	0,230,33,1,0,0,0,231,232,3,40,20,0,232,233,5,5,0,0,233,234,3,36,18,0,
  	234,235,5,2,0,0,235,266,1,0,0,0,236,238,3,36,18,0,237,236,1,0,0,0,237,
  	238,1,0,0,0,238,239,1,0,0,0,239,266,5,2,0,0,240,266,3,30,15,0,241,242,
  	5,14,0,0,242,243,5,8,0,0,243,244,3,38,19,0,244,245,5,9,0,0,245,248,3,
  	34,17,0,246,247,5,10,0,0,247,249,3,34,17,0,248,246,1,0,0,0,248,249,1,
  	0,0,0,249,266,1,0,0,0,250,251,5,15,0,0,251,252,5,8,0,0,252,253,3,38,19,
  	0,253,254,5,9,0,0,254,255,3,34,17,0,255,266,1,0,0,0,256,257,5,16,0,0,
  	257,266,5,2,0,0,258,259,5,17,0,0,259,266,5,2,0,0,260,262,5,18,0,0,261,
  	263,3,36,18,0,262,261,1,0,0,0,262,263,1,0,0,0,263,264,1,0,0,0,264,266,
  	5,2,0,0,265,231,1,0,0,0,265,237,1,0,0,0,265,240,1,0,0,0,265,241,1,0,0,
  	0,265,250,1,0,0,0,265,256,1,0,0,0,265,258,1,0,0,0,265,260,1,0,0,0,266,
  	35,1,0,0,0,267,268,3,56,28,0,268,37,1,0,0,0,269,270,3,70,35,0,270,39,
  	1,0,0,0,271,278,5,36,0,0,272,273,5,3,0,0,273,274,3,36,18,0,274,275,5,
  	4,0,0,275,277,1,0,0,0,276,272,1,0,0,0,277,280,1,0,0,0,278,276,1,0,0,0,
  	278,279,1,0,0,0,279,41,1,0,0,0,280,278,1,0,0,0,281,282,5,8,0,0,282,283,
  	3,36,18,0,283,284,5,9,0,0,284,288,1,0,0,0,285,288,3,40,20,0,286,288,3,
  	44,22,0,287,281,1,0,0,0,287,285,1,0,0,0,287,286,1,0,0,0,288,43,1,0,0,
  	0,289,290,3,74,37,0,290,45,1,0,0,0,291,302,3,42,21,0,292,293,5,36,0,0,
  	293,295,5,8,0,0,294,296,3,50,25,0,295,294,1,0,0,0,295,296,1,0,0,0,296,
  	297,1,0,0,0,297,302,5,9,0,0,298,299,3,48,24,0,299,300,3,46,23,0,300,302,
  	1,0,0,0,301,291,1,0,0,0,301,292,1,0,0,0,301,298,1,0,0,0,302,47,1,0,0,
  	0,303,304,7,1,0,0,304,49,1,0,0,0,305,310,3,36,18,0,306,307,5,1,0,0,307,
  	309,3,36,18,0,308,306,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,310,311,
  	1,0,0,0,311,51,1,0,0,0,312,310,1,0,0,0,313,314,6,26,-1,0,314,315,3,46,
  	23,0,315,322,1,0,0,0,316,317,10,1,0,0,317,318,3,54,27,0,318,319,3,46,
  	23,0,319,321,1,0,0,0,320,316,1,0,0,0,321,324,1,0,0,0,322,320,1,0,0,0,
  	322,323,1,0,0,0,323,53,1,0,0,0,324,322,1,0,0,0,325,326,7,2,0,0,326,55,
  	1,0,0,0,327,328,6,28,-1,0,328,329,3,52,26,0,329,336,1,0,0,0,330,331,10,
  	1,0,0,331,332,3,58,29,0,332,333,3,52,26,0,333,335,1,0,0,0,334,330,1,0,
  	0,0,335,338,1,0,0,0,336,334,1,0,0,0,336,337,1,0,0,0,337,57,1,0,0,0,338,
  	336,1,0,0,0,339,340,7,3,0,0,340,59,1,0,0,0,341,342,6,30,-1,0,342,343,
  	3,56,28,0,343,350,1,0,0,0,344,345,10,1,0,0,345,346,3,62,31,0,346,347,
  	3,56,28,0,347,349,1,0,0,0,348,344,1,0,0,0,349,352,1,0,0,0,350,348,1,0,
  	0,0,350,351,1,0,0,0,351,61,1,0,0,0,352,350,1,0,0,0,353,354,7,4,0,0,354,
  	63,1,0,0,0,355,356,6,32,-1,0,356,357,3,60,30,0,357,364,1,0,0,0,358,359,
  	10,1,0,0,359,360,3,66,33,0,360,361,3,60,30,0,361,363,1,0,0,0,362,358,
  	1,0,0,0,363,366,1,0,0,0,364,362,1,0,0,0,364,365,1,0,0,0,365,65,1,0,0,
  	0,366,364,1,0,0,0,367,368,7,5,0,0,368,67,1,0,0,0,369,370,6,34,-1,0,370,
  	371,3,64,32,0,371,377,1,0,0,0,372,373,10,1,0,0,373,374,5,30,0,0,374,376,
  	3,64,32,0,375,372,1,0,0,0,376,379,1,0,0,0,377,375,1,0,0,0,377,378,1,0,
  	0,0,378,69,1,0,0,0,379,377,1,0,0,0,380,381,6,35,-1,0,381,382,3,68,34,
  	0,382,388,1,0,0,0,383,384,10,1,0,0,384,385,5,31,0,0,385,387,3,68,34,0,
  	386,383,1,0,0,0,387,390,1,0,0,0,388,386,1,0,0,0,388,389,1,0,0,0,389,71,
  	1,0,0,0,390,388,1,0,0,0,391,392,3,56,28,0,392,73,1,0,0,0,393,394,7,6,
  	0,0,394,75,1,0,0,0,36,78,80,85,94,108,121,124,127,135,147,157,162,171,
  	174,177,183,195,200,215,222,229,237,248,262,265,278,287,295,301,310,322,
  	336,350,364,377,388
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sysyParserStaticData = staticData.release();
}

}

sysyParser::sysyParser(TokenStream *input) : sysyParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

sysyParser::sysyParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  sysyParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *sysyParserStaticData->atn, sysyParserStaticData->decisionToDFA, sysyParserStaticData->sharedContextCache, options);
}

sysyParser::~sysyParser() {
  delete _interpreter;
}

const atn::ATN& sysyParser::getATN() const {
  return *sysyParserStaticData->atn;
}

std::string sysyParser::getGrammarFileName() const {
  return "sysy.g4";
}

const std::vector<std::string>& sysyParser::getRuleNames() const {
  return sysyParserStaticData->ruleNames;
}

const dfa::Vocabulary& sysyParser::getVocabulary() const {
  return sysyParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView sysyParser::getSerializedATN() const {
  return sysyParserStaticData->serializedATN;
}


//----------------- CompileUnitContext ------------------------------------------------------------------

sysyParser::CompileUnitContext::CompileUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<sysyParser::DeclContext *> sysyParser::CompileUnitContext::decl() {
  return getRuleContexts<sysyParser::DeclContext>();
}

sysyParser::DeclContext* sysyParser::CompileUnitContext::decl(size_t i) {
  return getRuleContext<sysyParser::DeclContext>(i);
}

std::vector<sysyParser::FuncDefContext *> sysyParser::CompileUnitContext::funcDef() {
  return getRuleContexts<sysyParser::FuncDefContext>();
}

sysyParser::FuncDefContext* sysyParser::CompileUnitContext::funcDef(size_t i) {
  return getRuleContext<sysyParser::FuncDefContext>(i);
}


size_t sysyParser::CompileUnitContext::getRuleIndex() const {
  return sysyParser::RuleCompileUnit;
}


std::any sysyParser::CompileUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitCompileUnit(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::CompileUnitContext* sysyParser::compileUnit() {
  CompileUnitContext *_localctx = _tracker.createInstance<CompileUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, sysyParser::RuleCompileUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14336) != 0)) {
      setState(78);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(76);
        decl();
        break;
      }

      case 2: {
        setState(77);
        funcDef();
        break;
      }

      default:
        break;
      }
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

sysyParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::ConstDeclContext* sysyParser::DeclContext::constDecl() {
  return getRuleContext<sysyParser::ConstDeclContext>(0);
}

sysyParser::VarDeclContext* sysyParser::DeclContext::varDecl() {
  return getRuleContext<sysyParser::VarDeclContext>(0);
}


size_t sysyParser::DeclContext::getRuleIndex() const {
  return sysyParser::RuleDecl;
}


std::any sysyParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::DeclContext* sysyParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, sysyParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(85);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sysyParser::T_CONST: {
        enterOuterAlt(_localctx, 1);
        setState(83);
        constDecl();
        break;
      }

      case sysyParser::T_INT: {
        enterOuterAlt(_localctx, 2);
        setState(84);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

sysyParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::ConstDeclContext::T_CONST() {
  return getToken(sysyParser::T_CONST, 0);
}

sysyParser::BTypeContext* sysyParser::ConstDeclContext::bType() {
  return getRuleContext<sysyParser::BTypeContext>(0);
}

std::vector<sysyParser::ConstDefContext *> sysyParser::ConstDeclContext::constDef() {
  return getRuleContexts<sysyParser::ConstDefContext>();
}

sysyParser::ConstDefContext* sysyParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<sysyParser::ConstDefContext>(i);
}


size_t sysyParser::ConstDeclContext::getRuleIndex() const {
  return sysyParser::RuleConstDecl;
}


std::any sysyParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::ConstDeclContext* sysyParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, sysyParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(sysyParser::T_CONST);
    setState(88);
    bType();
    setState(89);
    constDef();
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == sysyParser::T__0) {
      setState(90);
      match(sysyParser::T__0);
      setState(91);
      constDef();
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(97);
    match(sysyParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

sysyParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::BTypeContext::T_INT() {
  return getToken(sysyParser::T_INT, 0);
}


size_t sysyParser::BTypeContext::getRuleIndex() const {
  return sysyParser::RuleBType;
}


std::any sysyParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::BTypeContext* sysyParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, sysyParser::RuleBType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(sysyParser::T_INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

sysyParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::ConstDefContext::T_ID() {
  return getToken(sysyParser::T_ID, 0);
}

sysyParser::ConstInitValContext* sysyParser::ConstDefContext::constInitVal() {
  return getRuleContext<sysyParser::ConstInitValContext>(0);
}

std::vector<sysyParser::ConstExprContext *> sysyParser::ConstDefContext::constExpr() {
  return getRuleContexts<sysyParser::ConstExprContext>();
}

sysyParser::ConstExprContext* sysyParser::ConstDefContext::constExpr(size_t i) {
  return getRuleContext<sysyParser::ConstExprContext>(i);
}


size_t sysyParser::ConstDefContext::getRuleIndex() const {
  return sysyParser::RuleConstDef;
}


std::any sysyParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::ConstDefContext* sysyParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, sysyParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(sysyParser::T_ID);
    setState(108);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == sysyParser::T__2) {
      setState(102);
      match(sysyParser::T__2);
      setState(103);
      constExpr();
      setState(104);
      match(sysyParser::T__3);
      setState(110);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(111);
    match(sysyParser::T__4);
    setState(112);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

sysyParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::ConstExprContext* sysyParser::ConstInitValContext::constExpr() {
  return getRuleContext<sysyParser::ConstExprContext>(0);
}

std::vector<sysyParser::ConstInitValContext *> sysyParser::ConstInitValContext::constInitVal() {
  return getRuleContexts<sysyParser::ConstInitValContext>();
}

sysyParser::ConstInitValContext* sysyParser::ConstInitValContext::constInitVal(size_t i) {
  return getRuleContext<sysyParser::ConstInitValContext>(i);
}


size_t sysyParser::ConstInitValContext::getRuleIndex() const {
  return sysyParser::RuleConstInitVal;
}


std::any sysyParser::ConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitConstInitVal(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::ConstInitValContext* sysyParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, sysyParser::RuleConstInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(127);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sysyParser::T__7:
      case sysyParser::T_ADD:
      case sysyParser::T_SUB:
      case sysyParser::T_NOT:
      case sysyParser::T_DEC_CONST:
      case sysyParser::T_OCT_CONST:
      case sysyParser::T_HEX_CONST:
      case sysyParser::T_ID: {
        enterOuterAlt(_localctx, 1);
        setState(114);
        constExpr();
        break;
      }

      case sysyParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(115);
        match(sysyParser::T__5);
        setState(124);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 133145559360) != 0)) {
          setState(116);
          constInitVal();
          setState(121);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == sysyParser::T__0) {
            setState(117);
            match(sysyParser::T__0);
            setState(118);
            constInitVal();
            setState(123);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(126);
        match(sysyParser::T__6);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

sysyParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::BTypeContext* sysyParser::VarDeclContext::bType() {
  return getRuleContext<sysyParser::BTypeContext>(0);
}

std::vector<sysyParser::VarDefContext *> sysyParser::VarDeclContext::varDef() {
  return getRuleContexts<sysyParser::VarDefContext>();
}

sysyParser::VarDefContext* sysyParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<sysyParser::VarDefContext>(i);
}


size_t sysyParser::VarDeclContext::getRuleIndex() const {
  return sysyParser::RuleVarDecl;
}


std::any sysyParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::VarDeclContext* sysyParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, sysyParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    bType();
    setState(130);
    varDef();
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == sysyParser::T__0) {
      setState(131);
      match(sysyParser::T__0);
      setState(132);
      varDef();
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(138);
    match(sysyParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

sysyParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::VarDefContext::T_ID() {
  return getToken(sysyParser::T_ID, 0);
}

std::vector<sysyParser::ConstExprContext *> sysyParser::VarDefContext::constExpr() {
  return getRuleContexts<sysyParser::ConstExprContext>();
}

sysyParser::ConstExprContext* sysyParser::VarDefContext::constExpr(size_t i) {
  return getRuleContext<sysyParser::ConstExprContext>(i);
}

sysyParser::InitValContext* sysyParser::VarDefContext::initVal() {
  return getRuleContext<sysyParser::InitValContext>(0);
}


size_t sysyParser::VarDefContext::getRuleIndex() const {
  return sysyParser::RuleVarDef;
}


std::any sysyParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::VarDefContext* sysyParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, sysyParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      match(sysyParser::T_ID);
      setState(147);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == sysyParser::T__2) {
        setState(141);
        match(sysyParser::T__2);
        setState(142);
        constExpr();
        setState(143);
        match(sysyParser::T__3);
        setState(149);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(150);
      match(sysyParser::T_ID);
      setState(157);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == sysyParser::T__2) {
        setState(151);
        match(sysyParser::T__2);
        setState(152);
        constExpr();
        setState(153);
        match(sysyParser::T__3);
        setState(159);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(160);
      match(sysyParser::T__4);
      setState(161);
      initVal();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitValContext ------------------------------------------------------------------

sysyParser::InitValContext::InitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::ExprContext* sysyParser::InitValContext::expr() {
  return getRuleContext<sysyParser::ExprContext>(0);
}

std::vector<sysyParser::InitValContext *> sysyParser::InitValContext::initVal() {
  return getRuleContexts<sysyParser::InitValContext>();
}

sysyParser::InitValContext* sysyParser::InitValContext::initVal(size_t i) {
  return getRuleContext<sysyParser::InitValContext>(i);
}


size_t sysyParser::InitValContext::getRuleIndex() const {
  return sysyParser::RuleInitVal;
}


std::any sysyParser::InitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitInitVal(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::InitValContext* sysyParser::initVal() {
  InitValContext *_localctx = _tracker.createInstance<InitValContext>(_ctx, getState());
  enterRule(_localctx, 16, sysyParser::RuleInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sysyParser::T__7:
      case sysyParser::T_ADD:
      case sysyParser::T_SUB:
      case sysyParser::T_NOT:
      case sysyParser::T_DEC_CONST:
      case sysyParser::T_OCT_CONST:
      case sysyParser::T_HEX_CONST:
      case sysyParser::T_ID: {
        enterOuterAlt(_localctx, 1);
        setState(164);
        expr();
        break;
      }

      case sysyParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(165);
        match(sysyParser::T__5);
        setState(174);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 133145559360) != 0)) {
          setState(166);
          initVal();
          setState(171);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == sysyParser::T__0) {
            setState(167);
            match(sysyParser::T__0);
            setState(168);
            initVal();
            setState(173);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(176);
        match(sysyParser::T__6);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

sysyParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::FuncTypeContext* sysyParser::FuncDefContext::funcType() {
  return getRuleContext<sysyParser::FuncTypeContext>(0);
}

tree::TerminalNode* sysyParser::FuncDefContext::T_ID() {
  return getToken(sysyParser::T_ID, 0);
}

sysyParser::BlockContext* sysyParser::FuncDefContext::block() {
  return getRuleContext<sysyParser::BlockContext>(0);
}

sysyParser::FuncFormParamsContext* sysyParser::FuncDefContext::funcFormParams() {
  return getRuleContext<sysyParser::FuncFormParamsContext>(0);
}


size_t sysyParser::FuncDefContext::getRuleIndex() const {
  return sysyParser::RuleFuncDef;
}


std::any sysyParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::FuncDefContext* sysyParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 18, sysyParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    funcType();
    setState(180);
    match(sysyParser::T_ID);
    setState(181);
    match(sysyParser::T__7);
    setState(183);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == sysyParser::T_INT) {
      setState(182);
      funcFormParams();
    }
    setState(185);
    match(sysyParser::T__8);
    setState(186);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

sysyParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::FuncTypeContext::T_VOID() {
  return getToken(sysyParser::T_VOID, 0);
}

tree::TerminalNode* sysyParser::FuncTypeContext::T_INT() {
  return getToken(sysyParser::T_INT, 0);
}


size_t sysyParser::FuncTypeContext::getRuleIndex() const {
  return sysyParser::RuleFuncType;
}


std::any sysyParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::FuncTypeContext* sysyParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, sysyParser::RuleFuncType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    _la = _input->LA(1);
    if (!(_la == sysyParser::T_INT

    || _la == sysyParser::T_VOID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFormParamsContext ------------------------------------------------------------------

sysyParser::FuncFormParamsContext::FuncFormParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<sysyParser::FuncFormParamContext *> sysyParser::FuncFormParamsContext::funcFormParam() {
  return getRuleContexts<sysyParser::FuncFormParamContext>();
}

sysyParser::FuncFormParamContext* sysyParser::FuncFormParamsContext::funcFormParam(size_t i) {
  return getRuleContext<sysyParser::FuncFormParamContext>(i);
}


size_t sysyParser::FuncFormParamsContext::getRuleIndex() const {
  return sysyParser::RuleFuncFormParams;
}


std::any sysyParser::FuncFormParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitFuncFormParams(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::FuncFormParamsContext* sysyParser::funcFormParams() {
  FuncFormParamsContext *_localctx = _tracker.createInstance<FuncFormParamsContext>(_ctx, getState());
  enterRule(_localctx, 22, sysyParser::RuleFuncFormParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    funcFormParam();
    setState(195);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == sysyParser::T__0) {
      setState(191);
      match(sysyParser::T__0);
      setState(192);
      funcFormParam();
      setState(197);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFormParamContext ------------------------------------------------------------------

sysyParser::FuncFormParamContext::FuncFormParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::FuncBasicParamContext* sysyParser::FuncFormParamContext::funcBasicParam() {
  return getRuleContext<sysyParser::FuncBasicParamContext>(0);
}

sysyParser::FuncArrayParamContext* sysyParser::FuncFormParamContext::funcArrayParam() {
  return getRuleContext<sysyParser::FuncArrayParamContext>(0);
}


size_t sysyParser::FuncFormParamContext::getRuleIndex() const {
  return sysyParser::RuleFuncFormParam;
}


std::any sysyParser::FuncFormParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitFuncFormParam(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::FuncFormParamContext* sysyParser::funcFormParam() {
  FuncFormParamContext *_localctx = _tracker.createInstance<FuncFormParamContext>(_ctx, getState());
  enterRule(_localctx, 24, sysyParser::RuleFuncFormParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(200);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(198);
      funcBasicParam();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(199);
      funcArrayParam();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBasicParamContext ------------------------------------------------------------------

sysyParser::FuncBasicParamContext::FuncBasicParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::BTypeContext* sysyParser::FuncBasicParamContext::bType() {
  return getRuleContext<sysyParser::BTypeContext>(0);
}

tree::TerminalNode* sysyParser::FuncBasicParamContext::T_ID() {
  return getToken(sysyParser::T_ID, 0);
}


size_t sysyParser::FuncBasicParamContext::getRuleIndex() const {
  return sysyParser::RuleFuncBasicParam;
}


std::any sysyParser::FuncBasicParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitFuncBasicParam(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::FuncBasicParamContext* sysyParser::funcBasicParam() {
  FuncBasicParamContext *_localctx = _tracker.createInstance<FuncBasicParamContext>(_ctx, getState());
  enterRule(_localctx, 26, sysyParser::RuleFuncBasicParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    bType();
    setState(203);
    match(sysyParser::T_ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncArrayParamContext ------------------------------------------------------------------

sysyParser::FuncArrayParamContext::FuncArrayParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::BTypeContext* sysyParser::FuncArrayParamContext::bType() {
  return getRuleContext<sysyParser::BTypeContext>(0);
}

tree::TerminalNode* sysyParser::FuncArrayParamContext::T_ID() {
  return getToken(sysyParser::T_ID, 0);
}

std::vector<sysyParser::ExprContext *> sysyParser::FuncArrayParamContext::expr() {
  return getRuleContexts<sysyParser::ExprContext>();
}

sysyParser::ExprContext* sysyParser::FuncArrayParamContext::expr(size_t i) {
  return getRuleContext<sysyParser::ExprContext>(i);
}


size_t sysyParser::FuncArrayParamContext::getRuleIndex() const {
  return sysyParser::RuleFuncArrayParam;
}


std::any sysyParser::FuncArrayParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitFuncArrayParam(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::FuncArrayParamContext* sysyParser::funcArrayParam() {
  FuncArrayParamContext *_localctx = _tracker.createInstance<FuncArrayParamContext>(_ctx, getState());
  enterRule(_localctx, 28, sysyParser::RuleFuncArrayParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    bType();
    setState(206);
    match(sysyParser::T_ID);
    setState(207);
    match(sysyParser::T__2);
    setState(208);
    match(sysyParser::T__3);
    setState(215);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == sysyParser::T__2) {
      setState(209);
      match(sysyParser::T__2);
      setState(210);
      expr();
      setState(211);
      match(sysyParser::T__3);
      setState(217);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

sysyParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<sysyParser::BlockItemContext *> sysyParser::BlockContext::blockItem() {
  return getRuleContexts<sysyParser::BlockItemContext>();
}

sysyParser::BlockItemContext* sysyParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<sysyParser::BlockItemContext>(i);
}


size_t sysyParser::BlockContext::getRuleIndex() const {
  return sysyParser::RuleBlock;
}


std::any sysyParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::BlockContext* sysyParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 30, sysyParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(sysyParser::T__5);
    setState(222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 133146073412) != 0)) {
      setState(219);
      blockItem();
      setState(224);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(225);
    match(sysyParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

sysyParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::DeclContext* sysyParser::BlockItemContext::decl() {
  return getRuleContext<sysyParser::DeclContext>(0);
}

sysyParser::StmtContext* sysyParser::BlockItemContext::stmt() {
  return getRuleContext<sysyParser::StmtContext>(0);
}


size_t sysyParser::BlockItemContext::getRuleIndex() const {
  return sysyParser::RuleBlockItem;
}


std::any sysyParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::BlockItemContext* sysyParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 32, sysyParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(229);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sysyParser::T_CONST:
      case sysyParser::T_INT: {
        enterOuterAlt(_localctx, 1);
        setState(227);
        decl();
        break;
      }

      case sysyParser::T__1:
      case sysyParser::T__5:
      case sysyParser::T__7:
      case sysyParser::T_IF:
      case sysyParser::T_WHILE:
      case sysyParser::T_BREAK:
      case sysyParser::T_CONTINUE:
      case sysyParser::T_RETURN:
      case sysyParser::T_ADD:
      case sysyParser::T_SUB:
      case sysyParser::T_NOT:
      case sysyParser::T_DEC_CONST:
      case sysyParser::T_OCT_CONST:
      case sysyParser::T_HEX_CONST:
      case sysyParser::T_ID: {
        enterOuterAlt(_localctx, 2);
        setState(228);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

sysyParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t sysyParser::StmtContext::getRuleIndex() const {
  return sysyParser::RuleStmt;
}

void sysyParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprStmtContext ------------------------------------------------------------------

sysyParser::ExprContext* sysyParser::ExprStmtContext::expr() {
  return getRuleContext<sysyParser::ExprContext>(0);
}

sysyParser::ExprStmtContext::ExprStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any sysyParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* sysyParser::WhileStmtContext::T_WHILE() {
  return getToken(sysyParser::T_WHILE, 0);
}

sysyParser::CondContext* sysyParser::WhileStmtContext::cond() {
  return getRuleContext<sysyParser::CondContext>(0);
}

sysyParser::StmtContext* sysyParser::WhileStmtContext::stmt() {
  return getRuleContext<sysyParser::StmtContext>(0);
}

sysyParser::WhileStmtContext::WhileStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any sysyParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* sysyParser::IfStmtContext::T_IF() {
  return getToken(sysyParser::T_IF, 0);
}

sysyParser::CondContext* sysyParser::IfStmtContext::cond() {
  return getRuleContext<sysyParser::CondContext>(0);
}

std::vector<sysyParser::StmtContext *> sysyParser::IfStmtContext::stmt() {
  return getRuleContexts<sysyParser::StmtContext>();
}

sysyParser::StmtContext* sysyParser::IfStmtContext::stmt(size_t i) {
  return getRuleContext<sysyParser::StmtContext>(i);
}

sysyParser::IfStmtContext::IfStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any sysyParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockStmtContext ------------------------------------------------------------------

sysyParser::BlockContext* sysyParser::BlockStmtContext::block() {
  return getRuleContext<sysyParser::BlockContext>(0);
}

sysyParser::BlockStmtContext::BlockStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any sysyParser::BlockStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitBlockStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

tree::TerminalNode* sysyParser::BreakStmtContext::T_BREAK() {
  return getToken(sysyParser::T_BREAK, 0);
}

sysyParser::BreakStmtContext::BreakStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any sysyParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* sysyParser::ReturnStmtContext::T_RETURN() {
  return getToken(sysyParser::T_RETURN, 0);
}

sysyParser::ExprContext* sysyParser::ReturnStmtContext::expr() {
  return getRuleContext<sysyParser::ExprContext>(0);
}

sysyParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any sysyParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueStmtContext ------------------------------------------------------------------

tree::TerminalNode* sysyParser::ContinueStmtContext::T_CONTINUE() {
  return getToken(sysyParser::T_CONTINUE, 0);
}

sysyParser::ContinueStmtContext::ContinueStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any sysyParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentStmtContext ------------------------------------------------------------------

sysyParser::LValContext* sysyParser::AssignmentStmtContext::lVal() {
  return getRuleContext<sysyParser::LValContext>(0);
}

sysyParser::ExprContext* sysyParser::AssignmentStmtContext::expr() {
  return getRuleContext<sysyParser::ExprContext>(0);
}

sysyParser::AssignmentStmtContext::AssignmentStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any sysyParser::AssignmentStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitAssignmentStmt(this);
  else
    return visitor->visitChildren(this);
}
sysyParser::StmtContext* sysyParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 34, sysyParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(265);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<sysyParser::AssignmentStmtContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(231);
      lVal();
      setState(232);
      match(sysyParser::T__4);
      setState(233);
      expr();
      setState(234);
      match(sysyParser::T__1);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<sysyParser::ExprStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(237);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 133145559296) != 0)) {
        setState(236);
        expr();
      }
      setState(239);
      match(sysyParser::T__1);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<sysyParser::BlockStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(240);
      block();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<sysyParser::IfStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(241);
      match(sysyParser::T_IF);
      setState(242);
      match(sysyParser::T__7);
      setState(243);
      cond();
      setState(244);
      match(sysyParser::T__8);
      setState(245);
      stmt();
      setState(248);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(246);
        match(sysyParser::T__9);
        setState(247);
        stmt();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<sysyParser::WhileStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(250);
      match(sysyParser::T_WHILE);
      setState(251);
      match(sysyParser::T__7);
      setState(252);
      cond();
      setState(253);
      match(sysyParser::T__8);
      setState(254);
      stmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<sysyParser::BreakStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(256);
      match(sysyParser::T_BREAK);
      setState(257);
      match(sysyParser::T__1);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<sysyParser::ContinueStmtContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(258);
      match(sysyParser::T_CONTINUE);
      setState(259);
      match(sysyParser::T__1);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<sysyParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(260);
      match(sysyParser::T_RETURN);
      setState(262);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 133145559296) != 0)) {
        setState(261);
        expr();
      }
      setState(264);
      match(sysyParser::T__1);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

sysyParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::AddExprContext* sysyParser::ExprContext::addExpr() {
  return getRuleContext<sysyParser::AddExprContext>(0);
}


size_t sysyParser::ExprContext::getRuleIndex() const {
  return sysyParser::RuleExpr;
}


std::any sysyParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::ExprContext* sysyParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 36, sysyParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    addExpr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

sysyParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::LOrExprContext* sysyParser::CondContext::lOrExpr() {
  return getRuleContext<sysyParser::LOrExprContext>(0);
}


size_t sysyParser::CondContext::getRuleIndex() const {
  return sysyParser::RuleCond;
}


std::any sysyParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::CondContext* sysyParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 38, sysyParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    lOrExpr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

sysyParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::LValContext::T_ID() {
  return getToken(sysyParser::T_ID, 0);
}

std::vector<sysyParser::ExprContext *> sysyParser::LValContext::expr() {
  return getRuleContexts<sysyParser::ExprContext>();
}

sysyParser::ExprContext* sysyParser::LValContext::expr(size_t i) {
  return getRuleContext<sysyParser::ExprContext>(i);
}


size_t sysyParser::LValContext::getRuleIndex() const {
  return sysyParser::RuleLVal;
}


std::any sysyParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::LValContext* sysyParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 40, sysyParser::RuleLVal);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(sysyParser::T_ID);
    setState(278);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(272);
        match(sysyParser::T__2);
        setState(273);
        expr();
        setState(274);
        match(sysyParser::T__3); 
      }
      setState(280);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExprContext ------------------------------------------------------------------

sysyParser::PrimaryExprContext::PrimaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::ExprContext* sysyParser::PrimaryExprContext::expr() {
  return getRuleContext<sysyParser::ExprContext>(0);
}

sysyParser::LValContext* sysyParser::PrimaryExprContext::lVal() {
  return getRuleContext<sysyParser::LValContext>(0);
}

sysyParser::NumberContext* sysyParser::PrimaryExprContext::number() {
  return getRuleContext<sysyParser::NumberContext>(0);
}


size_t sysyParser::PrimaryExprContext::getRuleIndex() const {
  return sysyParser::RulePrimaryExpr;
}


std::any sysyParser::PrimaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpr(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::PrimaryExprContext* sysyParser::primaryExpr() {
  PrimaryExprContext *_localctx = _tracker.createInstance<PrimaryExprContext>(_ctx, getState());
  enterRule(_localctx, 42, sysyParser::RulePrimaryExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sysyParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(281);
        match(sysyParser::T__7);
        setState(282);
        expr();
        setState(283);
        match(sysyParser::T__8);
        break;
      }

      case sysyParser::T_ID: {
        enterOuterAlt(_localctx, 2);
        setState(285);
        lVal();
        break;
      }

      case sysyParser::T_DEC_CONST:
      case sysyParser::T_OCT_CONST:
      case sysyParser::T_HEX_CONST: {
        enterOuterAlt(_localctx, 3);
        setState(286);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

sysyParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::IntConstContext* sysyParser::NumberContext::intConst() {
  return getRuleContext<sysyParser::IntConstContext>(0);
}


size_t sysyParser::NumberContext::getRuleIndex() const {
  return sysyParser::RuleNumber;
}


std::any sysyParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::NumberContext* sysyParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 44, sysyParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    intConst();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExprContext ------------------------------------------------------------------

sysyParser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::PrimaryExprContext* sysyParser::UnaryExprContext::primaryExpr() {
  return getRuleContext<sysyParser::PrimaryExprContext>(0);
}

tree::TerminalNode* sysyParser::UnaryExprContext::T_ID() {
  return getToken(sysyParser::T_ID, 0);
}

sysyParser::FuncRealParamsContext* sysyParser::UnaryExprContext::funcRealParams() {
  return getRuleContext<sysyParser::FuncRealParamsContext>(0);
}

sysyParser::UnaryOpContext* sysyParser::UnaryExprContext::unaryOp() {
  return getRuleContext<sysyParser::UnaryOpContext>(0);
}

sysyParser::UnaryExprContext* sysyParser::UnaryExprContext::unaryExpr() {
  return getRuleContext<sysyParser::UnaryExprContext>(0);
}


size_t sysyParser::UnaryExprContext::getRuleIndex() const {
  return sysyParser::RuleUnaryExpr;
}


std::any sysyParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::UnaryExprContext* sysyParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 46, sysyParser::RuleUnaryExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(291);
      primaryExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(292);
      match(sysyParser::T_ID);
      setState(293);
      match(sysyParser::T__7);
      setState(295);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 133145559296) != 0)) {
        setState(294);
        funcRealParams();
      }
      setState(297);
      match(sysyParser::T__8);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(298);
      unaryOp();
      setState(299);
      unaryExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

sysyParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::UnaryOpContext::T_ADD() {
  return getToken(sysyParser::T_ADD, 0);
}

tree::TerminalNode* sysyParser::UnaryOpContext::T_SUB() {
  return getToken(sysyParser::T_SUB, 0);
}

tree::TerminalNode* sysyParser::UnaryOpContext::T_NOT() {
  return getToken(sysyParser::T_NOT, 0);
}


size_t sysyParser::UnaryOpContext::getRuleIndex() const {
  return sysyParser::RuleUnaryOp;
}


std::any sysyParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::UnaryOpContext* sysyParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 48, sysyParser::RuleUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4296540160) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRealParamsContext ------------------------------------------------------------------

sysyParser::FuncRealParamsContext::FuncRealParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<sysyParser::ExprContext *> sysyParser::FuncRealParamsContext::expr() {
  return getRuleContexts<sysyParser::ExprContext>();
}

sysyParser::ExprContext* sysyParser::FuncRealParamsContext::expr(size_t i) {
  return getRuleContext<sysyParser::ExprContext>(i);
}


size_t sysyParser::FuncRealParamsContext::getRuleIndex() const {
  return sysyParser::RuleFuncRealParams;
}


std::any sysyParser::FuncRealParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitFuncRealParams(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::FuncRealParamsContext* sysyParser::funcRealParams() {
  FuncRealParamsContext *_localctx = _tracker.createInstance<FuncRealParamsContext>(_ctx, getState());
  enterRule(_localctx, 50, sysyParser::RuleFuncRealParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
    expr();
    setState(310);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == sysyParser::T__0) {
      setState(306);
      match(sysyParser::T__0);
      setState(307);
      expr();
      setState(312);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExprContext ------------------------------------------------------------------

sysyParser::MulExprContext::MulExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::UnaryExprContext* sysyParser::MulExprContext::unaryExpr() {
  return getRuleContext<sysyParser::UnaryExprContext>(0);
}

sysyParser::MulExprContext* sysyParser::MulExprContext::mulExpr() {
  return getRuleContext<sysyParser::MulExprContext>(0);
}

sysyParser::MulOpContext* sysyParser::MulExprContext::mulOp() {
  return getRuleContext<sysyParser::MulOpContext>(0);
}


size_t sysyParser::MulExprContext::getRuleIndex() const {
  return sysyParser::RuleMulExpr;
}


std::any sysyParser::MulExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitMulExpr(this);
  else
    return visitor->visitChildren(this);
}


sysyParser::MulExprContext* sysyParser::mulExpr() {
   return mulExpr(0);
}

sysyParser::MulExprContext* sysyParser::mulExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  sysyParser::MulExprContext *_localctx = _tracker.createInstance<MulExprContext>(_ctx, parentState);
  sysyParser::MulExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, sysyParser::RuleMulExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(314);
    unaryExpr();
    _ctx->stop = _input->LT(-1);
    setState(322);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<MulExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleMulExpr);
        setState(316);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(317);
        mulOp();
        setState(318);
        unaryExpr(); 
      }
      setState(324);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

sysyParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::MulOpContext::T_MUL() {
  return getToken(sysyParser::T_MUL, 0);
}

tree::TerminalNode* sysyParser::MulOpContext::T_DIV() {
  return getToken(sysyParser::T_DIV, 0);
}

tree::TerminalNode* sysyParser::MulOpContext::T_MOD() {
  return getToken(sysyParser::T_MOD, 0);
}


size_t sysyParser::MulOpContext::getRuleIndex() const {
  return sysyParser::RuleMulOp;
}


std::any sysyParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::MulOpContext* sysyParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 54, sysyParser::RuleMulOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14680064) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExprContext ------------------------------------------------------------------

sysyParser::AddExprContext::AddExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::MulExprContext* sysyParser::AddExprContext::mulExpr() {
  return getRuleContext<sysyParser::MulExprContext>(0);
}

sysyParser::AddExprContext* sysyParser::AddExprContext::addExpr() {
  return getRuleContext<sysyParser::AddExprContext>(0);
}

sysyParser::AddOpContext* sysyParser::AddExprContext::addOp() {
  return getRuleContext<sysyParser::AddOpContext>(0);
}


size_t sysyParser::AddExprContext::getRuleIndex() const {
  return sysyParser::RuleAddExpr;
}


std::any sysyParser::AddExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitAddExpr(this);
  else
    return visitor->visitChildren(this);
}


sysyParser::AddExprContext* sysyParser::addExpr() {
   return addExpr(0);
}

sysyParser::AddExprContext* sysyParser::addExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  sysyParser::AddExprContext *_localctx = _tracker.createInstance<AddExprContext>(_ctx, parentState);
  sysyParser::AddExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 56;
  enterRecursionRule(_localctx, 56, sysyParser::RuleAddExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(328);
    mulExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(336);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<AddExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleAddExpr);
        setState(330);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(331);
        addOp();
        setState(332);
        mulExpr(0); 
      }
      setState(338);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

sysyParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::AddOpContext::T_ADD() {
  return getToken(sysyParser::T_ADD, 0);
}

tree::TerminalNode* sysyParser::AddOpContext::T_SUB() {
  return getToken(sysyParser::T_SUB, 0);
}


size_t sysyParser::AddOpContext::getRuleIndex() const {
  return sysyParser::RuleAddOp;
}


std::any sysyParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::AddOpContext* sysyParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 58, sysyParser::RuleAddOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    _la = _input->LA(1);
    if (!(_la == sysyParser::T_ADD

    || _la == sysyParser::T_SUB)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationExprContext ------------------------------------------------------------------

sysyParser::RelationExprContext::RelationExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::AddExprContext* sysyParser::RelationExprContext::addExpr() {
  return getRuleContext<sysyParser::AddExprContext>(0);
}

sysyParser::RelationExprContext* sysyParser::RelationExprContext::relationExpr() {
  return getRuleContext<sysyParser::RelationExprContext>(0);
}

sysyParser::RelationOpContext* sysyParser::RelationExprContext::relationOp() {
  return getRuleContext<sysyParser::RelationOpContext>(0);
}


size_t sysyParser::RelationExprContext::getRuleIndex() const {
  return sysyParser::RuleRelationExpr;
}


std::any sysyParser::RelationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitRelationExpr(this);
  else
    return visitor->visitChildren(this);
}


sysyParser::RelationExprContext* sysyParser::relationExpr() {
   return relationExpr(0);
}

sysyParser::RelationExprContext* sysyParser::relationExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  sysyParser::RelationExprContext *_localctx = _tracker.createInstance<RelationExprContext>(_ctx, parentState);
  sysyParser::RelationExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 60;
  enterRecursionRule(_localctx, 60, sysyParser::RuleRelationExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(342);
    addExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(350);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelationExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelationExpr);
        setState(344);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(345);
        relationOp();
        setState(346);
        addExpr(0); 
      }
      setState(352);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationOpContext ------------------------------------------------------------------

sysyParser::RelationOpContext::RelationOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::RelationOpContext::T_LT() {
  return getToken(sysyParser::T_LT, 0);
}

tree::TerminalNode* sysyParser::RelationOpContext::T_GT() {
  return getToken(sysyParser::T_GT, 0);
}

tree::TerminalNode* sysyParser::RelationOpContext::T_LE() {
  return getToken(sysyParser::T_LE, 0);
}

tree::TerminalNode* sysyParser::RelationOpContext::T_GE() {
  return getToken(sysyParser::T_GE, 0);
}


size_t sysyParser::RelationOpContext::getRuleIndex() const {
  return sysyParser::RuleRelationOp;
}


std::any sysyParser::RelationOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitRelationOp(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::RelationOpContext* sysyParser::relationOp() {
  RelationOpContext *_localctx = _tracker.createInstance<RelationOpContext>(_ctx, getState());
  enterRule(_localctx, 62, sysyParser::RuleRelationOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 251658240) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqExprContext ------------------------------------------------------------------

sysyParser::EqExprContext::EqExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::RelationExprContext* sysyParser::EqExprContext::relationExpr() {
  return getRuleContext<sysyParser::RelationExprContext>(0);
}

sysyParser::EqExprContext* sysyParser::EqExprContext::eqExpr() {
  return getRuleContext<sysyParser::EqExprContext>(0);
}

sysyParser::EqOpContext* sysyParser::EqExprContext::eqOp() {
  return getRuleContext<sysyParser::EqOpContext>(0);
}


size_t sysyParser::EqExprContext::getRuleIndex() const {
  return sysyParser::RuleEqExpr;
}


std::any sysyParser::EqExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitEqExpr(this);
  else
    return visitor->visitChildren(this);
}


sysyParser::EqExprContext* sysyParser::eqExpr() {
   return eqExpr(0);
}

sysyParser::EqExprContext* sysyParser::eqExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  sysyParser::EqExprContext *_localctx = _tracker.createInstance<EqExprContext>(_ctx, parentState);
  sysyParser::EqExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 64;
  enterRecursionRule(_localctx, 64, sysyParser::RuleEqExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(356);
    relationExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(364);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<EqExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleEqExpr);
        setState(358);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(359);
        eqOp();
        setState(360);
        relationExpr(0); 
      }
      setState(366);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqOpContext ------------------------------------------------------------------

sysyParser::EqOpContext::EqOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::EqOpContext::T_EQ() {
  return getToken(sysyParser::T_EQ, 0);
}

tree::TerminalNode* sysyParser::EqOpContext::T_NE() {
  return getToken(sysyParser::T_NE, 0);
}


size_t sysyParser::EqOpContext::getRuleIndex() const {
  return sysyParser::RuleEqOp;
}


std::any sysyParser::EqOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitEqOp(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::EqOpContext* sysyParser::eqOp() {
  EqOpContext *_localctx = _tracker.createInstance<EqOpContext>(_ctx, getState());
  enterRule(_localctx, 66, sysyParser::RuleEqOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    _la = _input->LA(1);
    if (!(_la == sysyParser::T_EQ

    || _la == sysyParser::T_NE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LAndExprContext ------------------------------------------------------------------

sysyParser::LAndExprContext::LAndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::EqExprContext* sysyParser::LAndExprContext::eqExpr() {
  return getRuleContext<sysyParser::EqExprContext>(0);
}

sysyParser::LAndExprContext* sysyParser::LAndExprContext::lAndExpr() {
  return getRuleContext<sysyParser::LAndExprContext>(0);
}

tree::TerminalNode* sysyParser::LAndExprContext::T_AND() {
  return getToken(sysyParser::T_AND, 0);
}


size_t sysyParser::LAndExprContext::getRuleIndex() const {
  return sysyParser::RuleLAndExpr;
}


std::any sysyParser::LAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitLAndExpr(this);
  else
    return visitor->visitChildren(this);
}


sysyParser::LAndExprContext* sysyParser::lAndExpr() {
   return lAndExpr(0);
}

sysyParser::LAndExprContext* sysyParser::lAndExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  sysyParser::LAndExprContext *_localctx = _tracker.createInstance<LAndExprContext>(_ctx, parentState);
  sysyParser::LAndExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, sysyParser::RuleLAndExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(370);
    eqExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(377);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LAndExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLAndExpr);
        setState(372);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(373);
        match(sysyParser::T_AND);
        setState(374);
        eqExpr(0); 
      }
      setState(379);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExprContext ------------------------------------------------------------------

sysyParser::LOrExprContext::LOrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::LAndExprContext* sysyParser::LOrExprContext::lAndExpr() {
  return getRuleContext<sysyParser::LAndExprContext>(0);
}

sysyParser::LOrExprContext* sysyParser::LOrExprContext::lOrExpr() {
  return getRuleContext<sysyParser::LOrExprContext>(0);
}

tree::TerminalNode* sysyParser::LOrExprContext::T_OR() {
  return getToken(sysyParser::T_OR, 0);
}


size_t sysyParser::LOrExprContext::getRuleIndex() const {
  return sysyParser::RuleLOrExpr;
}


std::any sysyParser::LOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitLOrExpr(this);
  else
    return visitor->visitChildren(this);
}


sysyParser::LOrExprContext* sysyParser::lOrExpr() {
   return lOrExpr(0);
}

sysyParser::LOrExprContext* sysyParser::lOrExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  sysyParser::LOrExprContext *_localctx = _tracker.createInstance<LOrExprContext>(_ctx, parentState);
  sysyParser::LOrExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 70;
  enterRecursionRule(_localctx, 70, sysyParser::RuleLOrExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(381);
    lAndExpr(0);
    _ctx->stop = _input->LT(-1);
    setState(388);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LOrExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLOrExpr);
        setState(383);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(384);
        match(sysyParser::T_OR);
        setState(385);
        lAndExpr(0); 
      }
      setState(390);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstExprContext ------------------------------------------------------------------

sysyParser::ConstExprContext::ConstExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sysyParser::AddExprContext* sysyParser::ConstExprContext::addExpr() {
  return getRuleContext<sysyParser::AddExprContext>(0);
}


size_t sysyParser::ConstExprContext::getRuleIndex() const {
  return sysyParser::RuleConstExpr;
}


std::any sysyParser::ConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitConstExpr(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::ConstExprContext* sysyParser::constExpr() {
  ConstExprContext *_localctx = _tracker.createInstance<ConstExprContext>(_ctx, getState());
  enterRule(_localctx, 72, sysyParser::RuleConstExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    addExpr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntConstContext ------------------------------------------------------------------

sysyParser::IntConstContext::IntConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sysyParser::IntConstContext::T_DEC_CONST() {
  return getToken(sysyParser::T_DEC_CONST, 0);
}

tree::TerminalNode* sysyParser::IntConstContext::T_OCT_CONST() {
  return getToken(sysyParser::T_OCT_CONST, 0);
}

tree::TerminalNode* sysyParser::IntConstContext::T_HEX_CONST() {
  return getToken(sysyParser::T_HEX_CONST, 0);
}


size_t sysyParser::IntConstContext::getRuleIndex() const {
  return sysyParser::RuleIntConst;
}


std::any sysyParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<sysyVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}

sysyParser::IntConstContext* sysyParser::intConst() {
  IntConstContext *_localctx = _tracker.createInstance<IntConstContext>(_ctx, getState());
  enterRule(_localctx, 74, sysyParser::RuleIntConst);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 60129542144) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool sysyParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 26: return mulExprSempred(antlrcpp::downCast<MulExprContext *>(context), predicateIndex);
    case 28: return addExprSempred(antlrcpp::downCast<AddExprContext *>(context), predicateIndex);
    case 30: return relationExprSempred(antlrcpp::downCast<RelationExprContext *>(context), predicateIndex);
    case 32: return eqExprSempred(antlrcpp::downCast<EqExprContext *>(context), predicateIndex);
    case 34: return lAndExprSempred(antlrcpp::downCast<LAndExprContext *>(context), predicateIndex);
    case 35: return lOrExprSempred(antlrcpp::downCast<LOrExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool sysyParser::mulExprSempred(MulExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool sysyParser::addExprSempred(AddExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool sysyParser::relationExprSempred(RelationExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool sysyParser::eqExprSempred(EqExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool sysyParser::lAndExprSempred(LAndExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool sysyParser::lOrExprSempred(LOrExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void sysyParser::initialize() {
  ::antlr4::internal::call_once(sysyParserOnceFlag, sysyParserInitialize);
}
