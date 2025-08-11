// ii) To search the element in 2-D array.

#include <stdio.h>

#define MAX 50

int main() {
    int arr[MAX][MAX];
    int rows, cols;
    int i, j, element;
    int found = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &element);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] == element) {
                printf("Element %d found at position: Row %d, Column %d\n", element, i, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Element %d not found in the matrix.\n", element);
    }
    return 0;
}
