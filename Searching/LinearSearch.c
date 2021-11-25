#include <stdio.h>

int LinearSearch(int *arr, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("%d found at index %d\n", key, i);
            return i;
        }
    }
    printf("%d not found\n", key);
    return -1;
};

int main()
{
    int a[10] = {10, 12, 3, 41, 5, 16, 77, 87, 9, 100};
    int key = 41;
    int n = sizeof(a) / sizeof(a[0]);
    LinearSearch(a, n, key);
    return 0;
}
