#include <stdio.h>

void CycleSort(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct])
        {
            int temp = arr[i];
            arr[i] = arr[correct];
            arr[correct] = temp;
        }
        else
        {
            i++;
        }
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int arr[] = {5, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sorting\n");
    printArray(arr, n);
    CycleSort(arr, n);
    printf("\nAfter Sorting\n");
    printArray(arr, n);
    return 0;
}