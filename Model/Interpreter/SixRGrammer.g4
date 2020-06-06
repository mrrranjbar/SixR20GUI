grammar SixRGrammer;



start
	: moduleRoutines EOF
	;

moduleRoutines
    : ( mainRoutine
	|  subRoutine
	|  variableDeclaration
   |  interruptDeclaration
    |  NEWLINE
    )*
    ;

mainRoutine
    : INT? MAIN '(' ')' NEWLINE routineBody END  NEWLINE?
    ;

subRoutine
    : type? procedureName '(' formalParameters ')' NEWLINE routineBody END  NEWLINE?
    ;

procedureName
    : IDENTIFIER
    ;

formalParameters
    : (parameter (',' parameter)* )? 
    ;

parameter
    : type variableName
    ;

routineBody
    : statementList
    ;

statementList
   : statement*
   ;

statement
   : CONTINUE NEWLINE    # STATCONTINUE
   | FOR IDENTIFIER '=' expression TO expression NEWLINE statementList ENDFOR  NEWLINE?   # STATFOR
   | IF expression THEN NEWLINE statementList (ELSE NEWLINE statementList)? ENDIF NEWLINE?    # STATIF
   | WAIT FOR expression NEWLINE?    # STATWAITFOR
   | WAIT SEC expression NEWLINE?    # STATWAITSEC
   | WHILE expression NEWLINE statementList ENDWHILE NEWLINE?    # STATWHILE
   | RETURN (expression)? NEWLINE    # STATRETURN
   | assignmentExpression NEWLINE?    # STATASINEPR
   | expression NEWLINE? # STATEXP
   | BREAK NEWLINE    # STATBRAKE
   | PTP targetPoint ffExpr? conExpr? timeExpr? (apprxExpr)? NEWLINE?    # STATPTP
   | LIN targetPoint ffExpr? conExpr? timeExpr? (apprxExpr)? NEWLINE?    # STATLIN
   | CIR targetPoint targetPoint thetaExpr? ffExpr? conExpr? timeExpr? (apprxExpr)? NEWLINE?    # STATCIR
   | ( variableDeclaration ) NEWLINE? # STATVARDEC
   | SETFRAME FrameType variableName NEWLINE?    # STATSCF
   | NEWLINE    # STATNEWLINE
   | (interruptDeclaration) NEWLINE?    # STATINTERRUPTDEC
   | (interruptPriority) NEWLINE?    # STATINTERRUPT
   | GOTOSTART #STATGOTOSTART
  // | EXIT NEWLINE    # STATEXIT
  // | GOTO IDENTIFIER NEWLINE?    # STATGOTO
  // | HALT NEWLINE?    # STATHALT
  // | LOOP NEWLINE statementList ENDLOOP NEWLINE?    # STATLOOP
  // | REPEAT NEWLINE statementList UNTIL expression NEWLINE?    # STATREPEAT
  // | SWITCH expression NEWLINE switchBlockStatementGroups ENDSWITCH NEWLINE?    # STATSWITCH
  // | IDENTIFIER ':' NEWLINE?    # STATIDENTIFIER
  // | GLOBAL? INTERRUPT DECL primary WHEN expression DO assignmentExpression NEWLINE?    # STATINTERRUPT
  // | INTERRUPT IDENTIFIER primary? NEWLINE?    # STATINTERRUPT
   //| TRIGGER WHEN (IDENTIFIER) '=' expression DELAY '=' expression DO assignmentExpression (PRIO '=' expression)? NEWLINE?    # STATTRIGGER
   ;
   
FrameType
	: ( TOOL | BASE | OBJECT | TASK )
	;
TOOL
	: T O O L
	;

BASE
	: B A S E
	;

GOTOSTART
	: G O T O S T A R T
	;

TASK
	: T A S K
	;

OBJECT
	: O B J E C T
	;
targetPoint
   :(sixRJXPoint|variableName)
   ;
apprxExpr
   : Apprx expression
   ;
ffExpr
   : FF expression
   ;
timeExpr
   : TIME expression
   ;

conExpr
   : CON expression
   ;

thetaExpr
   : THETA expression
   ;
interruptDeclaration
   :  GLOBAL? INTERRUPT DECL IDENTIFIER primary WHEN expression DO expression
   ;

interruptPriority
   :  INTERRUPT IDENTIFIER primary?
   ;
variableDeclaration
   :  type variableName (variableListRest | variableInitialisation) 
   ;
variableInitialisation
   : '=' ( expression | sixRJPR)
   ;

variableListRest
   : (',' variableName)*
   ;

assignmentExpression
   : variableName '=' ( expression | sixRJPR )
   ;

sixRJPR
	: ( sixRJXPoint | sixRPosition | sixROrientation)
	;

sixRJXPoint
	: (sixRPPoint | sixRJPoint)
	;

sixRPPoint
	: '[' (sixRRPPart ( ',' sixRRPPart)* )? ']'
	| '[' variableName ',' variableName ']'
	;

sixRPosition
	: '(' ( sixRPPart ( ',' sixRPPart )*  )? ')'
	;

sixROrientation
	: '(' ( sixRRPart ( ',' sixRRPart )*  )? ')'
	;

sixRJPoint
	: '[' ( sixRJPart ( ',' sixRJPart )*  )? ']'
	;

sixRJPart
	: ( J1 | J2 | J3 | J4 | J5 | J6 ) ':' expression
	;
sixRRPPart
	: sixRRPart | sixRPPart
	;
sixRPPart
	: ( XX | YY | ZZ ) ':' expression
	;

sixRRPart
	: ( AA | BB | CC ) ':' expression
	;

variableName
   : IDENTIFIER (arrayVariableSuffix)?
   ;

arrayVariableSuffix
   : '[' ( expression (',' expression)* ) ']'
   ;

expression
   : procedureName '(' (expression ( ',' expression)*)? ')'
   | conditionalOrExpression (relationalOp conditionalOrExpression)*
   ;

relationalOp
   : '=='
   | '!='
   | '<='
   | '>='
   | '<'
   | '>'
   ;

conditionalOrExpression
   : exclusiveOrExpression ((OR ) exclusiveOrExpression)*
   ;

exclusiveOrExpression
   : conditionalAndExpression ((EXOR) conditionalAndExpression)*
   ;

conditionalAndExpression
   : additiveExpression ((AND) additiveExpression)*
   ;

additiveExpression
   : multiplicativeExpression (('+' | '-') multiplicativeExpression)*
   ;

multiplicativeExpression
   : unaryNotExpression (('*' | '/') unaryNotExpression)*
   ;

unaryNotExpression
   : NOT unaryNotExpression
   | '!' unaryNotExpression
   | unaryPlusMinuxExpression
   ;

unaryPlusMinuxExpression
   : '+' unaryPlusMinuxExpression
   | '-' unaryPlusMinuxExpression
   | primary
   ;

primary
   : parExpression		
   | variableName		
   | literal			
   ;

literal
   : numberLITERAL
   | charLITERAL
   | stringLITERAL
   | booleanLiteral
   ;
   
 
intLITERAL
	: FragINTLITERAL
	;

floatLITERAL
	: FragFLOATLITERAL
	;

charLITERAL
	: FragCHARLITERAL 
	;

stringLITERAL
	: FragSTRINGLITERAL
	;
numberLITERAL
	: intLITERAL
    | floatLITERAL
	;
booleanLiteral
	: TRUE
	| FALSE
	;

parExpression
   : '(' expression ')'
   ;

type
   : primitiveType 
   | sixRPrimitiveType
   ;

sixRPrimitiveType
	: POS
	| ORIENT
	| POINTJ
	| POINTP
	;
primitiveType
   : BOOL
   | CHAR
   | INT
   | FLOAT
   ;



 
/////////////////////////////////////////////////////////////
/////     Lexer
/////////////////////////////////////////////////////////////


AND
   : A N D
   ;


ANIN
   : A N I N
   ;


ANOUT
   : A N O U T
   ;

B_AND
   : B '_' A N D
   ;


B_NOT
   : B '_' N O T
   ;


B_OR
   : B '_' O R
   ;


B_EXOR
   : B '_' E X O R
   ;


BOOL
   : B O O L
   ;


BREAK
   : B R E A K
   ;


C_DIS
   : C '_' D I S
   ;


C_ORI
   : C '_' O R I
   ;


C_PTP
   : C '_' P T P
   ;


C_VEL
   : C '_' V E L
   ;


CASE
   : C A S E
   ;


CAST_FROM
   : C A S T '_' F R O M
   ;


CAST_TO
   : C A S T '_' T O
   ;


CHAR
   : C H A R
   ;


CIR_REL
   : C I R '_' R E L
   ;


CIR
   : C I R
   ;


CONST
   : C O N S T
   ;


CONTINUE
   : C O N T I N U E
   ;


DELAY
   : D E L A Y
   ;


DECL
   : D E C L
   ;


DEF
   : D E F
   ;


DEFAULT
   : D E F A U L T
   ;


DEFDAT
   : D E F D A T
   ;


DEFFCT
   : D E F F C T
   ;


DO
   : D O
   ;


ELSE
   : E L S E
   ;


END
   : E N D
   ;


ENDDAT
   : E N D D A T
   ;


ENDFCT
   : E N D F C T
   ;


ENDFOR
   : E N D F O R
   ;


ENDIF
   : E N D I F
   ;


ENDLOOP
   : E N D L O O P
   ;


ENDSWITCH
   : E N D S W I T C H
   ;


ENDWHILE
   : E N D W H I L E
   ;


ENUM
   : E N U M
   ;


EXIT
   : E X I T
   ;


EXT
   : E X T
   ;


EXTFCT
   : E X T F C T
   ;


FALSE
   : F A L S E
   ;


FOR
   : F O R
   ;


GLOBAL
   : G L O B A L
   ;


GOTO
   : G O T O
   ;


HALT
   : H A L T
   ;


IF
   : I F
   ;


IMPORT
   : I M P O R T
   ;


INTERRUPT
   : I N T E R R U P T
   ;


INT
   : I N T
   ;


IS
   : I S
   ;


LIN_REL
   : L I N '_' R E L
   ;


LIN
   : L I N
   ;


LOOP
   : L O O P
   ;
MAIN
	: M A I N
	;

MAXIMUM
   : M A X I M U M
   ;


MINIMUM
   : M I N I M U M
   ;


NOT
   : N O T
   ;


OR
   : O R
   ;


PRIO
   : P R I O
   ;


PTP_REL
   : P T P '_' R E L
   ;


PTP
   : P T P
   ;


PUBLIC
   : P U B L I C
   ;


FLOAT
   : F L O A T
   ;


REPEAT
   : R E P E A T
   ;


RETURN
   : R E T U R N
   ;


SEC
   : S E C
   ;

SETFRAME
: S E T F R A M E
;

SIGNAL
   : S I G N A L
   ;


STRUC
   : S T R U C
   ;


SWITCH
   : S W I T C H
   ;


THEN
   : T H E N
   ;


TO
   : T O
   ;


TRIGGER
   : T R I G G E R
   ;


TRUE
   : T R U E
   ;


UNTIL
   : U N T I L
   ;


WAIT
   : W A I T
   ;


WHEN
   : W H E N
   ;


WHILE
   : W H I L E
   ;


EXOR
   : E X O R
   ;

STARTPROG
   : S T A R T P R O G
   ;

ENDPROG
   : E N D P R O G
   ;
POINTJ
	: P O I N T J
	;
POINTP
	: P O I N T P
	;
POS
	: P O S
	;
ORIENT
	: O R I E N T
	;
Apprx
: A P P R O X
;
THETA
: T H E T A
;
VECTOR
	: V E C T O R
	;
CON
	: C O N
	;
XX
	: X
	;
YY
	: Y
	;
ZZ
	: Z
	;
AA
	: A
	;
BB
	: B
	;
CC
	: C
	;
FF
	: F
	;
TIME
   : T I M E
   ;
J1
	: J '1'
	;
J2
	: J '2'
	;
J3
	: J '3'
	;
J4
	: J '4'
	;
J5
	: J '5'
	;
J6
	: J '6'
	;

fragment A
   : ('a' | 'A')
   ;


fragment B
   : ('b' | 'B')
   ;


fragment C
   : ('c' | 'C')
   ;


fragment D
   : ('d' | 'D')
   ;


fragment E
   : ('e' | 'E')
   ;


fragment F
   : ('f' | 'F')
   ;


fragment G
   : ('g' | 'G')
   ;


fragment H
   : ('h' | 'H')
   ;


fragment I
   : ('i' | 'I')
   ;


fragment J
   : ('j' | 'J')
   ;


fragment K
   : ('k' | 'K')
   ;


fragment L
   : ('l' | 'L')
   ;


fragment M
   : ('m' | 'M')
   ;


fragment N
   : ('n' | 'N')
   ;


fragment O
   : ('o' | 'O')
   ;


fragment P
   : ('p' | 'P')
   ;


fragment Q
   : ('q' | 'Q')
   ;


fragment R
   : ('r' | 'R')
   ;


fragment S
   : ('s' | 'S')
   ;


fragment T
   : ('t' | 'T')
   ;


fragment U
   : ('u' | 'U')
   ;


fragment V
   : ('v' | 'V')
   ;


fragment W
   : ('w' | 'W')
   ;


fragment X
   : ('x' | 'X')
   ;


fragment Y
   : ('y' | 'Y')
   ;


fragment Z
   : ('z' | 'Z')
   ;



fragment IdentifierStart
   : 'a' .. 'z' | 'A' .. 'Z' | '_' | '$'
   ;

FragINTLITERAL
: ('0' .. '9')+
;

FragFLOATLITERAL
    : (('0' .. '9')*)('.' ('0' .. '9')+)
    ;

FragCHARLITERAL
    : '\'' . '\'' 
    ;

FragSTRINGLITERAL
    : '"' .*? '"'
    ;
IDENTIFIER
   : IdentifierStart IdentifierPart*
   ;
fragment IdentifierPart
   : IdentifierStart | '0' .. '9'
;

NEWLINE:
           '\r' ? '\n' ;
WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) ->channel(HIDDEN)
    ;
