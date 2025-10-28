%{
    #include<stdio.h>
    int v=0;
    int c=0;
%}

%%
[aieouAIEOU] {v++;}
[a-zA-Z] {c++;}
. {;}
%%
int main(){
    printf("Enter the string\n");
    yylex();
    printf("Vowels: %d\nConsonants: %d\n",v,c);
    return 0;
}

int yywrap(){
    return 1;
}