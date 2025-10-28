%{
#include <stdio.h>
#include <stdlib.h>
char *yytext;
extern int yylex();
void yyerror(char *s) {}

FILE *fvalid, *finvalid;
%}

%union { char *str; }
%token <str> EMAIL INVALID

%%

lines:
    | lines line
    ;

line:
    EMAIL   { fprintf(fvalid, "%s\n", $1); free($1); }
  | INVALID { fprintf(finvalid, "%s\n", $1); free($1); }
  ;

%%

int main() {
    fvalid = fopen("valid.txt", "w");
    finvalid = fopen("invalid.txt", "w");
    yyparse();
    fclose(fvalid);
    fclose(finvalid);
    return 0;
}