// b) To check the validity of expressions, which contains multiple opening and closing brackets. (i.e., [{(a+b) * c} – d])

#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char expr[MAX];
    char stack[MAX];
    int top = -1;
    int i;
    
    printf("Enter an expression: ");
    gets(expr);
    
    for (i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        
        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                printf("INVALID expression\n");
                return 0;
            }
            
            char last = stack[top--];
            
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                printf("INVALID expression\n");
                return 0;
            }
        }
    }
    
    if (top == -1) {
        printf("VALID expression\n");
    } else {
        printf("INVALID expression\n");
    }
    
    return 0;
}
