#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    int start = low;
    int end = high;

    while (start < end)
    {
        while (a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
        {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[low], &a[end]);
    return end;
}

void Quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(a, low, high);
        Quicksort(a, low, pivot - 1);
        Quicksort(a, pivot + 1, high);
    }
}

int main()
{
    int a[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);
    Quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}