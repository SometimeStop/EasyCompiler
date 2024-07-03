grammar sysyNode;

compileUnit: (decl | const_decl | func_def)*;
decl: (identifier)+; //definition
const_decl: (identifier)+; //definition

func_form_param:
	array_dim //definition
	|; //definition

array_dim:
	expr* //Reference
	| const_expr*; //definition
array_init: init_level;
init_level: (expr* | const_expr*) | init_level*;

func_def: func_form_params block;
func_form_params: (func_form_param)*; //definition

block: (decl | const_decl | statement | block)*;
statement:
	assign
	| stmt_expr
	| stmt_block
	| if
	| while
	| break
	| continue
	| return;

assign: identifier expr; //Reference
stmt_expr: expr;
stmt_block: block;
if: cond_expr statement statement?;
while: cond_expr statement;
break:;
continue:;
return: expr?;

identifier: (expr?) //definition
	| (const_expr?) //definition
	| (array_dim array_init) //definition
	| (array_dim) //Reference
	|; //Reference

cond_expr: // condition expression
	identifier //Reference
	| func_call
	| operator
	| T_NUM_VALUE;

const_expr:
	identifier //Reference
	| func_call
	| operator
	| T_NUM_VALUE;

expr: //
	identifier //Reference
	| func_call
	| operator
	| T_NUM_VALUE;

operator: (
		identifier //Reference
		| func_call
		| operator
		| T_NUM_VALUE
	)+; //[1~2个]

func_call: func_real_params;
func_real_params: expr*;
T_NUM_VALUE: [1-9][0-9]*;
T_OPERATOR:
	'+'
	| '-'
	| '*'
	| '/'
	| '&&'
	| '||'
	| '!='
	| '=='
	| '>'
	| '<'
	| '>='
	| '<='
	| '!';

warning: nowarning;