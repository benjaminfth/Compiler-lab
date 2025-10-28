#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1, i = 0;

void push(char c) { 
	stack[++top] = c; stack[top + 1] = '\0';
}

void printRow(const char *act) {
    printf("%-15s %-15s %-20s\n", stack, input + i, act);
}

void reduce() {
    int done;
    do {
        done = 0;
        // Accept a, b, c as identifiers (reduce to E)
        if (top >= 0 && (stack[top] == 'a' || stack[top] == 'b' || stack[top] == 'c')) {
            char ch = stack[top];
            stack[top] = 'E'; 
            stack[top + 1] = '\0';
            char msg[32]; 
            sprintf(msg, "Reduce %c→E", ch);
            printRow(msg); 
            done = 1;
        } else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
            top -= 2; 
            stack[top] = 'E'; 
            stack[top + 1] = '\0';
            printRow("Reduce E+E→E"); 
            done = 1;
        } else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E') {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            printRow("Reduce E*E→E");
            done = 1;
        } else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '/' && stack[top - 2] == 'E') {
            top -= 2;
            stack[top] = 'E';
            stack[top + 1] = '\0';
            printRow("Reduce E/E→E");
             done = 1;
        }
    } while (done);
}

int main() {
    printf("Enter input (e.g. a+b*c/a): ");
    scanf("%s", input);

    printf("\n%-15s %-15s %-20s\n", "STACK", "INPUT", "ACTION");
    printf("---------------------------------------------------\n");

    while (i < strlen(input)) {
        push(input[i]);
        char msg[20]; sprintf(msg, "Shift: %c", input[i]);
        printRow(msg);
        i++;
        reduce();
    }

    printf("\n%s\n", strcmp(stack, "E") == 0 ? "✅ String Accepted" : "❌ String Rejected");

    return 0;
}