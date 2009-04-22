%union{

/**
 *  Program:  ML-interpreterHead.y
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Rich Price, and Alimoor
 *  Reza
 *  Class:    CS550, Assignment 2, Spring 2009
**/

   int value;
   char *ident;
}
%token CAR
%token CDR
%token NULLP
%token LISTP
%token INTP
%token CONS
%token IDENT
%token NUMBER
%token ASSIGNOP
%token DEFINE
%token IF
%token THEN
%token ELSE
%token FI
%token WHILE
%token DO
%token OD
%token PROC
%token END


%%

program: stmt_list {printf("program -> stmt_list\n"); }
       ;

stmt_list:  stmt ';' stmt_list { printf("stmt_list -> stmt ; stmt_list\n"); }
        |   stmt  { printf("stmt_list -> stmt\n"); }
        ;

stmt:  assign_stmt { printf("stmt -> assign_stmt\n"); }
    |  define_stmt { printf("stmt -> define_stmt\n"); }
    |  if_stmt { printf("stmt -> if_stmt\n"); }
    |  while_stmt { printf("stmt -> while_stmt\n"); }
    ;

assign_stmt:
					 IDENT ASSIGNOP expr { printf("assign_stmt -> identifier := expr\n"); }
           ;


define_stmt:
					 DEFINE IDENT PROC '(' param_list ')' stmt_list END { printf("define_stmt -> define identifier proc");
                                                                printf("( param_list ) stmt_list end\n"); }
           ;

if_stmt: IF expr THEN stmt_list ELSE stmt_list FI
           { printf("if_stmt -> IF expr THEN stmt_list ELSE stmt_list FI\n"); }
           ;

while_stmt: WHILE expr DO stmt_list OD
           { printf("while_stmt -> WHILE expr DO stmt_list OD\n"); }
           ;

param_list: IDENT ',' param_list { printf("param_list -> IDENT, param_list\n"); }
    |      IDENT { printf("param_list -> IDENT\n"); }

expr: expr '+' term   { printf("expr -> expr + term\n"); }
    | expr '-' term   { printf("expr -> expr - term\n"); }
    | factor '||' factor  { printf("expr -> expr || expr\n"); }
    | term            { printf("expr -> term\n"); }
    | CAR '(' factor ')'             { printf("expr -> car (expr)\n"); }
    | CDR '(' factor ')'             { printf("expr -> cdr (expr)\n"); }
    | NULLP '(' factor ')'           { printf("expr -> nullp(expr)\n"); }
    | INTP '(' factor ')'            { printf("expr -> intp(expr)\n"); }
    | LISTP '(' factor ')'           { printf("expr -> listp(expr)\n"); }
    | CONS '(' factor ',' factor ')'   { printf("expr -> cons(expr, expr)\n"); }
    ;

term: term '*' factor   { printf("term -> term * factor\n"); }
    | factor            { printf("term -> factor\n"); }
    ;

factor:     '(' expr ')'  { printf("factor -> ( expr ) \n"); }
    |       element { printf("factor -> element\n"); }
    |       IDENT { printf("factor -> identifier\n"); }
    |       funcall { printf("factor -> funcall\n"); }
    ;

element:		list { printf("element -> list\n"); }
	  |				NUMBER { printf("element -> NUMBER\n"); }
    ;

list:				'[' sequence ']' { printf("list -> sequence\n"); }
    |       '[' ']' { printf("list -> empty list\n"); }
    ;

sequence:   element ',' sequence { printf("sequence -> element, seq\n"); }
    |       element { printf("sequence -> element\n"); }
    ;

funcall:  IDENT '(' expr_list ')'
         { printf("funcall -> identifier ( expr_list )\n"); }

expr_list: expr ',' expr_list { printf("expr_list -> expr , expr_list\n"); }
    |      expr { printf("expr_list -> expr\n"); }
%%
