#include <stdio.h>

void ShellSort(int array[], int n)
{
    int i, j, k, temp;
    for (i = n / 2; i > 0; i /= 2)
    {
        for (j = i; j < n; j++)
        {
            temp = array[j];
            for (k = j; k >= i && array[k - i] > temp; k -= i)
            {
                array[k] = array[k - i];
            }
            array[k] = temp;
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int a[] = {64, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Array before sorting:\n");
    printArray(a, n);
    ShellSort(a, n);
    printf("\nArray after sorting:\n");
    printArray(a, n);
    return 0;
}