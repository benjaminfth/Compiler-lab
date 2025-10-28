%{
#include<stdio.h>
#include<stdlib.h>
extern FILE *yyin;
pc=0;
sc=0;
%}

%%
"printf" {pc++; printf("writef");}
"scanf" {sc++; printf("readf");}
.|\n {putchar(yytext[0]);}
%%

int main(int argc, char* argv[]){
    FILE *file=fopen("input.txt","r");
    if(!file){
        perror("cant open file");
        return 1;
    }
    yyin=file;
    yylex();
    fclose(file);
    printf("\n printf = %d \n scanf = %d \n",pc,sc);
    return 0;
}


int yywrap(){
    return 1;
}
