// e) Add two numbers using a pointer and display the sum of two numbers.

#include<stdio.h>
int main(){
    int x,y,sum;
    int *xp , *yp;
    printf("Enter Two Numbers: ");
    scanf("%d %d",&x,&y);

    xp = &x;
    yp = &y;

    sum = *xp + *yp;

    printf("Sum of two numbers using pointer: %d",sum);

    return 0;
}