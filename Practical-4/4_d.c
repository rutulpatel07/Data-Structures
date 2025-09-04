// d) To evaluate the given postfix expression.

#include <stdio.h>
#include <ctype.h>  // for isdigit()

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top < MAX - 1) stack[++top] = val;
}

int pop() {
    if (top >= 0) return stack[top--];
    return 0;
}

int evaluatePostfix(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            push(ch - '0'); // convert char to int
        } else {
            int a = pop();  // right operand
            int b = pop();  // left operand
            int res = 0;

            switch (ch) {
                case '+': res = b + a; break;
                case '-': res = b - a; break;
                case '*': res = b * a; break;
                case '/': res = b / a; break;
            }
            push(res);
        }
    }
    return pop();
}

int main() {
    char expr[MAX];

    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%s", expr);

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);

    return 0;
}
