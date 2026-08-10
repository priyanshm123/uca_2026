#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void randomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

void ascendingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void descendingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

double measureTime(int arr[], int n)
{
    clock_t start = clock();

    heapSort(arr, n);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC * 1000;
}

int main()
{
    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int count = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    printf("Size\tRandom\tAscending\tDescending\n");

    for (int x = 0; x < count; x++)
    {
        int n = sizes[x];

        int *random = malloc(n * sizeof(int));
        int *ascending = malloc(n * sizeof(int));
        int *descending = malloc(n * sizeof(int));

        randomArray(random, n);
        ascendingArray(ascending, n);
        descendingArray(descending, n);

        double t1 = measureTime(random, n);
        double t2 = measureTime(ascending, n);
        double t3 = measureTime(descending, n);

        printf("%d\t%.3f\t%.3f\t\t%.3f\n",
               n, t1, t2, t3);

        free(random);
        free(ascending);
        free(descending);
    }

    return 0;
}

