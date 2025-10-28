#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int dfa(char str[]){
    int state = 0;
    for(int i=0;i<strlen(str);i++){
        switch(state){
            case 0:
                if(str[i]=='0'){
                    state=1;
                }else if(str[i]=='1'){
                    state=0;
                }
                else{
                    printf("wrong input");
                    exit(0);
                }
                break;
            case 1:
                if(str[i]=='0'){
                    state=1;
                }else if(str[i]=='1'){
                    state=2;
                }
                else{
                    printf("wrong input");
                    exit(0);
                }
                break;
            case 2:
                if(str[i]=='0'){
                    state=1;
                }else if(str[i]=='1'){
                    state=0;
                }
                else{
                    printf("wrong input");
                    exit(0);
                }
                break;
        }
    }
    return state;
}

void main(){
    char str[100];
    printf("enter string:");
    scanf("%s",str);
    int res=dfa(str);
    if(res==2){
        printf("accepted\n");
    }
    else{
        printf("rejected\n");
    }
}