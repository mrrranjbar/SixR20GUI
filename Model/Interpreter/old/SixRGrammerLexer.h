
// Generated from SixRGrammer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SixRGrammerLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, AND = 19, ANIN = 20, 
    ANOUT = 21, B_AND = 22, B_NOT = 23, B_OR = 24, B_EXOR = 25, BOOL = 26, 
    BREAK = 27, C_DIS = 28, C_ORI = 29, C_PTP = 30, C_VEL = 31, CASE = 32, 
    CAST_FROM = 33, CAST_TO = 34, CHAR = 35, CIR_REL = 36, CIR = 37, CONST = 38, 
    CONTINUE = 39, DELAY = 40, DECL = 41, DEF = 42, DEFAULT = 43, DEFDAT = 44, 
    DEFFCT = 45, DO = 46, ELSE = 47, END = 48, ENDDAT = 49, ENDFCT = 50, 
    ENDFOR = 51, ENDIF = 52, ENDLOOP = 53, ENDSWITCH = 54, ENDWHILE = 55, 
    ENUM = 56, EXIT = 57, EXT = 58, EXTFCT = 59, FALSE = 60, FOR = 61, GLOBAL = 62, 
    GOTO = 63, HALT = 64, IF = 65, IMPORT = 66, INTERRUPT = 67, INT = 68, 
    IS = 69, LIN_REL = 70, LIN = 71, LOOP = 72, MAIN = 73, MAXIMUM = 74, 
    MINIMUM = 75, NOT = 76, OR = 77, PRIO = 78, PTP_REL = 79, PTP = 80, 
    PUBLIC = 81, FLOAT = 82, REPEAT = 83, RETURN = 84, SEC = 85, SIGNAL = 86, 
    STRUC = 87, SWITCH = 88, THEN = 89, TO = 90, TRIGGER = 91, TRUE = 92, 
    UNTIL = 93, WAIT = 94, WHEN = 95, WHILE = 96, EXOR = 97, STARTPROG = 98, 
    ENDPROG = 99, POINTJ = 100, POINTP = 101, POS = 102, ORIENT = 103, VECTOR = 104, 
    CON = 105, XX = 106, YY = 107, ZZ = 108, AA = 109, BB = 110, CC = 111, 
    FF = 112, J1 = 113, J2 = 114, J3 = 115, J4 = 116, J5 = 117, J6 = 118, 
    FragINTLITERAL = 119, FragFLOATLITERAL = 120, FragCHARLITERAL = 121, 
    FragSTRINGLITERAL = 122, IDENTIFIER = 123, NEWLINE = 124, WS = 125
  };

  SixRGrammerLexer(antlr4::CharStream *input);
  ~SixRGrammerLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

