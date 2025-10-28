%{
#include<stdio.h>
#include<stdlib.h>
int odd=0;
int i;
%}

%%
[0-9]+ {
    i=atoi(yytext);
    if(i%2==0)
        odd=0;
    else{
        odd=1;
    }
}

. {;}
%%
void main(){
    printf("Enter a number:");
    yylex();
    if(odd==1){
        printf("The number is odd");
    }
    else{
        printf("even");
    }
}

int yywrap(){
    return 1;
}