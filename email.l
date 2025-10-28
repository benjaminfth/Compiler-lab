%{
#include<stdio.h>
#include<stdlib.h>
int valid = 0;
%}

%%
[a-zA-Z0-9._%+-/]+@[a-zA-Z0-9]+\.[a-zA-Z]{2,} {valid = 1;}
.|\n {;}
%%

void main(){
    char input[100];
    printf("Enter email:");
    scanf("%s",input);
    YY_BUFFER_STATE buffer= yy_scan_string(input);
    yylex();
    yy_delete_buffer(buffer);
    if(valid)
        printf("Valid\n");
    else
        printf("invalid\n");
}

int yywrap(){
    return 1;
}