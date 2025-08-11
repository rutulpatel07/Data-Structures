// iii) To create, initialize and print the values of the 3-D array.

#include <stdio.h>

int main() {
    int arr[2][2][2]; 
    int i, j, k;

    printf("Enter elements for a 3-D array (2x2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                printf("Enter element at position [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\n3-D Array elements are:\n");
    for (i = 0; i < 2; i++) {
        printf("Layer %d:\n", i);
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                printf("%d\t", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
