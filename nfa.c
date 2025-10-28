#include<stdio.h>
#include<stdlib.h>

#define MAX_TRANSACTION 20
#define MAX_STATES 20

struct transactions{
    int from;
    char input;
    int to;
};
int no_trans;
struct transactions tr[MAX_TRANSACTION];
int closure[MAX_STATES];
int count=0;

int in_closure(int state){
    for(int i=0;i<count;i++){
        if(closure[i]==state){
            return 1;
        }
    }
    return 0;
}

int epsilon_closure(int state){
    if(!in_closure(state)) closure[count++]=state;

    for(int i=0;i<no_trans;i++){
        if (tr[i].from ==state &&
            tr[i].input=='e' &&
            !in_closure(tr[i].to)){
                epsilon_closure(tr[i].to);
            }
    }
    return 0;
}


void main(){
    printf("Enter No. of Transactions:");
    scanf("%d",&no_trans);

    for(int i=0;i<no_trans;i++){
        printf("Transaction %d\n",i+1);
        printf("from state:");
        scanf("%d",&tr[i].from);
        printf("input:");
        scanf(" %c",&tr[i].input); // Added space before %c to skip whitespace
        printf("To state:");
        scanf("%d",&tr[i].to);
    }

    printf("\n--- Transitions ---\n");
    for (int i = 0; i < no_trans; i++) {
        printf("q%d --%c--> q%d\n", tr[i].from, tr[i].input, tr[i].to);
    }

    int max_state=0;
    for(int i=0;i<no_trans;i++){
        if(tr[i].from>max_state) max_state=tr[i].from;
        if(tr[i].to>max_state) max_state=tr[i].to;
    }

    printf("Epsilon Transitions\n");

    for(int i=0;i<=max_state;i++){
        count=0;
        epsilon_closure(i);
        printf("Epsilon Closure(q%d) : {",i);
        for(int j=0;j<count;j++){
            printf("q%d",closure[j]);
            if(j<count-1) printf(",");
        }
        printf("}\n");
    }
}