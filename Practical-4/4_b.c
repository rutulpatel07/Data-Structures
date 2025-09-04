// b) To check the validity of expressions, which contains multiple opening and closing brackets. (i.e., [{(a+b) * c} – d])

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 200

static bool isOpen(char c) {
    return c == '(' || c == '{' || c == '[';
}

static bool isClose(char c) {
    return c == ')' || c == '}' || c == ']';
}

static bool matchPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const char *expr) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isOpen(ch)) {
            if (top >= MAX - 1) return false; // overflow guard
            stack[++top] = ch;
        } else if (isClose(ch)) {
            if (top < 0) return false;        // closing without opener
            if (!matchPair(stack[top--], ch)) // wrong type/ordering
                return false;
        }
        // other characters are ignored
    }
    return top == -1; // all opens matched
}

int main(void) {
    char expr[MAX];

    printf("Enter an expression: ");
    if (!fgets(expr, sizeof(expr), stdin)) return 0;
    // remove trailing newline if present
    size_t len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n') expr[len - 1] = '\0';

    if (isBalanced(expr))
        printf("VALID expression (brackets are balanced).\n");
    else
        printf("INVALID expression (brackets are not balanced).\n");

    return 0;
}
