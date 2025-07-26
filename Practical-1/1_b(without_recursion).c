// b) To calculate Nth term of a Fibonacci series without using recursion.

#include <stdio.h>
int fibonacci(int n) {
    int a = 0, b = 1, next;
    
    if (n == 0)
        return a;
    if (n == 1)
        return b;

    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main() {
    int n;
    printf("Enter the term number (n): ");
    scanf("%d", &n);
    printf("Fibonacci term %d is %d\n", n, fibonacci(n));
    return 0;
}

