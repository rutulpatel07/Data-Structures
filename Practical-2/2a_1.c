// A)Write a Program
//   i) To implement an Array representation of the sparse matrices.

#include <stdio.h>

#define MAX 50

int main() {
    int matrix[MAX][MAX];
    int sparse[MAX][3];
    int rows, cols;
    int i, j, k = 1; 
    int nonZeroCount = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
                nonZeroCount++;
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZeroCount;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSparse Matrix Representation:\n");
    printf("Row\tCol\tValue\n");
    for (i = 1; i < nonZeroCount + 1; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
