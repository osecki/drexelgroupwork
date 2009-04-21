%{
#include "ML-interpreterHead.tab.h"
#include "string.h"
%}

%%
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
[car]    { return yytext[0]; }
[cdr]    { return yytext[0]; }
[nullp]  { return yytext[0]; }
[intp]   { return yytext[0]; }
[listp]  { return yytext[0]; }
[cons]   { return yytext[0]; }
[||]     { return yytext[0]; }
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
[a-z]+   { yylval.ident = strdup(yytext);  return IDENT; }
[0-9]+   { yylval.value = atoi(yytext); return NUMBER; }
.    return yytext[0];
%%
