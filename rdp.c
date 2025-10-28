#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[10];
int i=0,error=0;

void E();
void EPRIME();
void T();
void TPRIME();
void F();

int main(){
    
    printf("Enter the arithmetic expression:\n");
    scanf("%s",input);
    
    E();
    
    if(strlen(input)==i && error==0)
    {
        printf("String Accepted\n");
    }
    else{
        printf("String Rejected\n");
    }
    return 0;
}

void E()
{
    T();
    EPRIME();
}

void EPRIME()
{
    if(input[i]=='+'){
        i++;
        T();
        EPRIME();
    }
}

void T()
{
    F();
    TPRIME();
}

void TPRIME()
{
    if(input[i]=='*'){
        i++;
        F();
        TPRIME();
    }
}

void F()
{
    if(isalpha(input[i])){
        i++;
    }
    else if(input[i]=='('){
        i++;
        E();
        if(input[i]==')'){
            i++;
        }
    }
    else{
        error =1;
    }
}