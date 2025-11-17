#include <stdio.h> #include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Bubble Sort
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
}

// 2. Insertion Sort
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// 3. Selection Sort
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(&a[min], &a[i]);
    }
}

// 4. Quick Sort
int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (a[j] < pivot)
            swap(&a[++i], &a[j]);
    swap(&a[i + 1], &a[high]);
    return i + 1;
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// 5. Merge Sort
void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];
    while (i <= mid && j <= high)
        temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];

    for (int x = 0; x < k; x++)
        a[low + x] = temp[x];
}
void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

// 6. Shell Sort
void shellSort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++)
        {
            int temp = a[i], j = i;
            while (j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
}

// 7. Heap Sort
void heapify(int a[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

// 8. Counting Sort
void countingSort(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[a[i]]++;
    int k = 0;
    for (int i = 0; i <= max; i++)
        while (count[i]--)
            a[k++] = i;
}

// 9. Radix Sort
int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
void countSortRadix(int a[], int n, int place)
{
    int output[n], count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(a[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
        output[--count[(a[i] / place) % 10]] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}
void radixSort(int a[], int n)
{
    int max = getMax(a, n);
    for (int place = 1; max / place > 0; place *= 10)
        countSortRadix(a, n, place);
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (1)
    {
        printf("\n--- Sorting Menu ---\n");
        printf("1) Bubble Sort\n2) Insertion Sort\n3) Selection Sort\n4) Quick Sort\n5) Merge Sort\n6) Shell Sort\n7) Heap Sort\n8) Counting Sort\n9) Radix Sort\n10) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubbleSort(a, n);
            break;
        case 2:
            insertionSort(a, n);
            break;
        case 3:
            selectionSort(a, n);
            break;
        case 4:
            quickSort(a, 0, n - 1);
            break;
        case 5:
            mergeSort(a, 0, n - 1);
            break;
        case 6:
            shellSort(a, n);
            break;
        case 7:
            heapSort(a, n);
            break;
        case 8:
            countingSort(a, n);
            break;
        case 9:
            radixSort(a, n);
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid choice!");
        }
        printf("Sorted Array: ");
        display(a, n);
    }
}
