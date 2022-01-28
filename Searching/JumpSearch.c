#include <stdio.h>
#include <math.h>

int JumpSearch(int arr[], int n, int jump, int target)
{
    int start = 0, end = jump;
    while (end < n)
    {
        if (arr[end] < target)
        {
            start = end;
            end = end + jump;
        }
        else
        {
            while (start <= end)
            {
                if (arr[start] == target)
                    return start;
                start++;
            }
        }
    }
    return -1;
}

int main()
{
    int target, n, jump;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    n = sizeof(arr) / sizeof(arr[0]);
    jump = (int)sqrt(n);

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int index = jump_search(arr, n, jump, target);

    if (index == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", index + 1);
    return 0;
}