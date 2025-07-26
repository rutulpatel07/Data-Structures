//a) To traverse elements of an array. Traverse means Print

#include<stdio.h>

int main(){
    int i;

    int arr[5] = {11,25,36,89,52};
    printf("Array Traversed elements: ");
    for(i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}