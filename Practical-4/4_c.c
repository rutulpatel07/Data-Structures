// c) To convert unparenthesized infix expression to postfix.

#include <stdio.h>
#include <ctype.h>  // for isalnum()
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) stack[++top] = c;
}

char pop() {
    if (top >= 0) return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0) return stack[top];
    return '\0';
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch; // operand goes directly
        } else { // operator
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression (no parentheses): ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
