// a) To recognize string with language L={wCwR / w takes multiple occurrences of {a,b}.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

char stack[MAX];
int top = -1;

// stack operations
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

bool isPalindromeLike(char str[]) {
    int i = 0;

    // Step 1: Push all characters before 'C'
    while (str[i] != 'C' && str[i] != '\0') {
        push(str[i]);
        i++;
    }

    // if no 'C' found → invalid
    if (str[i] != 'C') return false;

    i++; // skip 'C'

    // Step 2: Compare rest of string with stack
    while (str[i] != '\0') {
        if (top == -1 || str[i] != pop()) {
            return false; // mismatch
        }
        i++;
    }

    // Step 3: if stack is empty → valid
    return (top == -1);
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindromeLike(str)) {
        printf("String is in the language L = {wCwR}\n");
    } else {
        printf("String is NOT in the language\n");
    }

    return 0;
}
