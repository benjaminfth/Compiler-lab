%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token DIGIT LETTER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

expr: 
    expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '-' DIGIT
    | '(' expr ')'
    | LETTER
    | DIGIT
;
%%

int main(){
    printf("enter:");
    yyparse();
    printf("parsing completed\n");
    return 0;
}

void yyerror(char *msg){
    printf("inalid aahda \n");
    exit(1);
}