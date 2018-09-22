%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

#include "types.hpp"
#include "ns.tab.h"
%}

%option yylineno

WS [ \t\n]

%%

begin { return O_BEGIN; }
end { return O_END; }
\= { return O_EQ; }
\^ { return O_EXP; }
\* { return O_MULT; }
\- { return O_MINUS; }
\; { return O_SEMI; }
\/ { return O_DIV; }
\( {  return O_LPAREN; }
\) {  return O_RPAREN; }
\+ { return O_PLUS; }
output {  return O_OUTPUT; }
[a-zA-Z]([a-zA-Z0-9])* { return O_IDENTIFIER; }
([1-9]+[0-9]*)|0 { 
    yylval.val = std::atoi(yytext);
    return O_INTEGER; 
}

{WS} {;}
. { printf("lex error: line %d  (%s)\n", yylineno, yytext); }

%%

int yywrap()
{
   return(1);
}
