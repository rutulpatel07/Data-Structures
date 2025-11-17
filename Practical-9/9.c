#include <stdio.h>
int linearSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}
int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n, key, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &key);

    printf("\n--- Search Menu ---\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Note: Array must be sorted!)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int result;

    switch (choice)
    {
    case 1:
        result = linearSearch(a, n, key);
        break;
    case 2:
        result = binarySearch(a, n, key);
        break;
    default:
        printf("Invalid Choice!");
        return 0;
    }

    if (result == -1)
        printf("\nElement Not Found.\n");
    else
        printf("\nElement Found at Position: %d (Index: %d)\n", result + 1, result);

    return 0;
}
