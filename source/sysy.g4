grammar sysy;

/* rules */
compileUnit: (decl | funcDef)*;
decl: constDecl | varDecl;
constDecl: T_CONST bType constDef (',' constDef)* ';';
bType: T_INT;
constDef: T_ID ('[' constExpr ']')* '=' constInitVal;
constInitVal:
	constExpr
	| '{' (constInitVal (',' constInitVal)*)? '}';
varDecl: bType varDef (',' varDef)* ';';
varDef:
	T_ID ('[' constExpr ']')* //branch 1
	| T_ID ('[' constExpr ']')* '=' initVal; //branch 2
initVal: expr | '{' (initVal (',' initVal)*)? '}';

funcDef: funcType T_ID '(' funcFormParams? ')' block;
funcType: T_VOID | T_INT;
funcFormParams: funcFormParam (',' funcFormParam)*;
funcFormParam: funcBasicParam | funcArrayParam; //
funcBasicParam: bType T_ID;
funcArrayParam: bType T_ID '[' ']' ('[' expr ']')*;
block: '{' (blockItem)* '}';
blockItem: decl | stmt;
stmt:
	lVal '=' expr ';'						# assignmentStmt
	| expr? ';'								# exprStmt
	| block									# blockStmt
	| T_IF '(' cond ')' stmt ('else' stmt)?	# ifStmt
	| T_WHILE '(' cond ')' stmt				# whileStmt
	| T_BREAK ';'							# breakStmt
	| T_CONTINUE ';'						# continueStmt
	| T_RETURN expr? ';'					# returnStmt;
expr: addExpr;
cond: lOrExpr;
lVal: T_ID ('[' expr ']')*;
primaryExpr: '(' expr ')' | lVal | number;
number: intConst;
unaryExpr:
	primaryExpr
	| T_ID '(' funcRealParams? ')'
	| unaryOp unaryExpr;
unaryOp: T_ADD | T_SUB | T_NOT;
funcRealParams: expr (',' expr)*;
mulExpr: unaryExpr | mulExpr mulOp unaryExpr;
mulOp: T_MUL | T_DIV | T_MOD;
addExpr: mulExpr | addExpr addOp mulExpr;
addOp: T_ADD | T_SUB;
relationExpr: addExpr | relationExpr relationOp addExpr;
relationOp: T_LT | T_GT | T_LE | T_GE;
eqExpr: relationExpr | eqExpr eqOp relationExpr;
eqOp: T_EQ | T_NE;
lAndExpr: eqExpr | lAndExpr T_AND eqExpr;
lOrExpr: lAndExpr | lOrExpr T_OR lAndExpr;
constExpr: addExpr;
intConst: T_DEC_CONST | T_OCT_CONST | T_HEX_CONST;
/* keyword definition (must before identifier definition) */
T_CONST: 'const';
T_INT: 'int';
T_VOID: 'void';
T_IF: 'if';
T_WHILE: 'while';
T_BREAK: 'break';
T_CONTINUE: 'continue';
T_RETURN: 'return';

/* operator definition */
T_ADD: '+';
T_SUB: '-';
T_MUL: '*';
T_DIV: '/';
T_MOD: '%';
T_LT: '<';
T_GT: '>';
T_LE: '<=';
T_GE: '>=';
T_EQ: '==';
T_NE: '!=';
T_AND: '&&';
T_OR: '||';
T_NOT: '!';

/* const definition */
T_DEC_CONST: [1-9][0-9]*;
T_OCT_CONST: '0' [0-7]*;
T_HEX_CONST: ('0x' | '0X') [0-9a-fA-F]*;

/* identifier definition */
T_ID: [a-zA-Z_][a-zA-Z0-9_]*;

/* skip empty words */
WS: [ \r\n\t]+ -> skip;

/* skip single-line comment */
LineComment: '//' ~ [\r\n]* -> skip;

/* skip multi-line comment */
MultiLineComment: '/*' .*? '*/' -> skip;