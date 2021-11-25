#include <stdio.h>

void BinarySearch(int arr[], int n, int x)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            printf("Element found at %d", mid);
            return;
        }
        else if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("Element not found");
}

int main()
{
    int arr[10] = {10, 21, 33, 45, 56, 69, 70, 81, 99, 102};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 56;
    BinarySearch(arr, n, key);
    return 0;
}
