#include <stdio.h>

void LinearSearch(int *arr, int key)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == key)
        {
            printf("%d found at index %d\n", key, i);
            return;
        }
    }
    printf("%d not found\n", key);
};

int main()
{
    int a[10] = {10, 12, 3, 41, 5, 16, 77, 87, 9, 100};
    int key = 41;
    LinearSearch(a, key);
    return 0;
}
