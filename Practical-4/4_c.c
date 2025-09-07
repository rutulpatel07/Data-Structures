// c) To convert unparenthesized infix expression to postfix.

#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    int i, k = 0;
    
    printf("Enter an infix expression (no parentheses): ");
    scanf("%s", infix);
    
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        
        // If operand (letter or digit), add to postfix
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        }
        // If operator
        else {
            // Pop operators with higher or equal precedence
            while (top != -1) {
                char topOp = stack[top];
                
                // Check precedence
                int topPrec = (topOp == '*' || topOp == '/') ? 2 : 1;
                int chPrec = (ch == '*' || ch == '/') ? 2 : 1;
                
                if (topPrec >= chPrec) {
                    postfix[k++] = pop();
                } else {
                    break;
                }
            }
            push(ch);
        }
    }
    
    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }
    
    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
