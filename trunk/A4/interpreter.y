%{
#include <stdio.h>
%}


%union{

/**
 *  Program:  ML-interpreterHead.y
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 4, Spring 2009
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

program:
    stmt_list {
        printf("program -> stmt_list\n");
    }
    ;

stmt_list:
    stmt ';' stmt_list {
        printf("stmt_list -> stmt ; stmt_list\n");
    }
    |   stmt  {
        printf("stmt_list -> stmt\n");
    }
    ;

stmt:
    assign_stmt {
        printf("stmt -> assign_stmt\n");
    }
    |
    if_stmt {
        printf("stmt -> if_stmt\n");
    }
    |
    while_stmt {
        printf("stmt -> while_stmt\n");
    }
    ;

assign_stmt:
    IDENT ASSIGNOP expr {
        printf("assign_stmt -> identifier := expr\n");
    }
    |
    DEFINE IDENT proc_stmt {
        printf("define_stmt -> proc");
    }
    ;

proc_stmt:
    PROC '(' param_list ')' stmt_list END {
        printf("( param_list ) stmt_list end\n");
    }
    |
    PROC '(' ')' stmt_list END {
        printf("() stmt_list end\n");
    }
    ;

if_stmt:
    IF expr THEN stmt_list ELSE stmt_list FI{
        printf("if_stmt -> IF expr THEN stmt_list ELSE stmt_list FI\n");
    }
    ;

while_stmt:
    WHILE expr DO stmt_list OD {
        printf("while_stmt -> WHILE expr DO stmt_list OD\n");
    }
    ;

param_list:
    IDENT ',' param_list {
        printf("param_list -> IDENT, param_list\n");
    }
    |
    IDENT {
        printf("param_list -> IDENT\n");
    }

expr:
    expr '+' term {
        printf("expr -> expr + term\n");
    }
    |
    expr '-' term {
        printf("expr -> expr - term\n");
    }
    |
    expr '||' factor {
        printf("expr -> expr || factor\n");
    }
    |
    term {
        printf("expr -> term\n");
    }
    |
    proc_stmt {
        printf("expr->proc\n");
    }
    ;

term:
    term '*' factor {
        printf("term -> term * factor\n");
    }
    |
    factor {
        printf("term -> factor\n");
    }
    ;

factor:
    '(' expr ')' {
        printf("factor -> ( expr ) \n");
    }
    |
    element {
        printf("factor -> element\n");
    }
    |
    IDENT {
        printf("factor -> identifier\n");
    }
    |
    funcall {
        printf("factor -> funcall\n");
    }
    |
    CAR '(' expr ')' {
        printf("factor -> car (expr)\n");
    }
    |
    CDR '(' expr ')' {
        printf("factor -> cdr (expr)\n");
    }
    |
    NULLP '(' expr ')' {
        printf("factor -> nullp(expr)\n");
    }
    |
    INTP '(' expr ')' {
        printf("factor -> intp(expr)\n");
    }
    |
    LISTP '(' expr ')' {
        printf("factor -> listp(expr)\n");
    }
    |
    CONS '(' expr ',' expr ')' {
        printf("factor -> cons(expr, expr)\n");
    }
    ;

list:
    '[' sequence ']' {
        printf("list -> sequence\n");
    }
    |
    '[' ']' {
        printf("list -> empty list\n");
    }
    ;

sequence:
    element ',' sequence {
        printf("sequence -> element, seq\n");
    }
    |
    element {
        printf("sequence -> element\n");
    }
    ;

element:
    list {
        printf("element -> list\n");
    }
    |
    NUMBER {
        printf("element -> NUMBER\n");
    }
    ;

funcall:
    IDENT '(' expr_list ')' {
        printf("funcall -> identifier ( expr_list )\n");
    }
    |
    IDENT '(' ')' {
        printf("funcall -> identifier ( )\n");
    }
    |
    proc_stmt '(' expr_list ')' {
        printf("funcall -> proc ( expr_list )\n");
    }
    |
    proc_stmt '(' ')' {
        printf("funcall -> proc ( )\n");
    }
    |
    funcall '(' expr_list ')' {
        printf("funcall -> funcall ( expr_list )\n");
    }
    |
    funcall '('  ')' {
        printf("funcall -> funcall (  )\n");
    }
    ;


expr_list:
    expr ',' expr_list {
        printf("expr_list -> expr , expr_list\n");
    }
    |
    expr {
        printf("expr_list -> expr\n");
    }
%%
