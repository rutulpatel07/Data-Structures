// c) To find the address of a variable using pointers.

#include <stdio.h>
int main() {
    int x = 25;          
    int *ptr;            

    ptr = &x;            

    printf("Value of x: %d\n", x);
    printf("Address of x using &x: %p\n", &x);
    printf("Address of x using pointer ptr: %p\n", ptr);
    printf("Value at address stored in ptr (*ptr): %d\n", *ptr);

    return 0;
}
