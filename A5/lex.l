%{

/**
 *  Program:  ML-lex.l
 *  Authors:  Group 7: Jordan Osecki, Geoff Oxholm, Alimoor Reza
 *  Class:    CS550, Assignment 4, Spring 2009
**/

#include "interpreter.tab.h"
#include "string.h"
%}

%%
[ \t\n\r]*\#[A-Za-z\:0-9= ;']+\n ;
[ \t\n\r] ;    /* ignore whitespace */
\+       { return yytext[0]; }
\-       { return yytext[0]; }
\*       { return yytext[0]; }
\(       { return yytext[0]; }
\)       { return yytext[0]; }
\;       { return yytext[0]; }
\,       { return yytext[0]; }
\[       { return yytext[0]; }
\]       { return yytext[0]; }
car      { return CAR; }
cdr      { return CDR; }
nullp    { return NULLP; }
intp     { return INTP; }
listp    { return LISTP; }
cons     { return CONS; }
Class	 { return CLASS; }
\|\|       { return yytext[0]; }
:=       { return ASSIGNOP; }
define   { return DEFINE; }
if       { return IF; }
then     { return THEN; }
else     { return ELSE; }
fi       { return FI; }
while    { return WHILE; }
do       { return DO; }
od       { return OD; }
proc     { return PROC; }
end      { return END; }
[A-Za-z]+   { yylval.ident = strdup(yytext);  return IDENT; }
[0-9]+   { yylval.value = atoi(yytext); return NUMBER; }
.        return yytext[0];
%%
