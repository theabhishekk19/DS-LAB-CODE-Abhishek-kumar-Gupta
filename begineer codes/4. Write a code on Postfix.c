#include <stdio.h>
#include <ctype.h>   
#include <string.h>  

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return 0;
    }
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i, a, b, result;

    printf("Enter postfix expression (single-digit operands): ");
    fgets(postfix, MAX, stdin); 

    for (i = 0; postfix[i] != '\0' && postfix[i] != '\n'; i++) {
        char ch = postfix[i];

        if (ch == ' ')
            continue; 

        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            b = pop();
            a = pop();

            switch (ch) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;  
                break;
            default:
                printf("Invalid operator: %c\n", ch);
                return 1;
            }

            push(result);
        }
    }

    result = pop();
    printf("Result of postfix expression = %d\n", result);

    return 0;
}
