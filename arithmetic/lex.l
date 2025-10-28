%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
%}

%%

[0-9]+ {yylval=atoi(yytext); return DIGIT;}
[_a-zA-Z][_a-zA-Z0-9]* {return LETTER;}

[\t]+ ;
\n {return 0;}
. {return yytext[0];}

%%

int yywrap(){
    return 1;
}