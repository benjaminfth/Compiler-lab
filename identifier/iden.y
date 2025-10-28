%{
    #include<stdio.h>
    #include<stdlib.h>
%}

%token ID

%%

Start:
    ID {printf("true"); exit(0);}
;

%%

void yyerror(char *msg){
    printf("falseeee");
}

void main(){
    printf("enter identiofier:");
    yyparse();
}