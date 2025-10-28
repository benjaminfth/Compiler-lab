%{
#include<stdio.h>
#include<stdlib.h>
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

calc:
    exp '\n' { printf("Result: %d\n", $1); }
    ;

exp:
    exp '+' exp { $$ = $1 + $3; }
    | exp '-' exp { $$ = $1 - $3; }
    | exp '*' exp { $$ = $1 * $3; }
    | exp '/' exp { $$ = $1 / $3; }
    ;
%%

int main() {
    printf("Enter expression: ");
    yyparse();
    return 0;
}

int yyerror(char *msg) {
    printf("Invalid expression\n");
    return 1;
}