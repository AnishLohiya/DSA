#include <stdio.h>

int G[][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}};
int start = 0, n = 5;
void DFSTraversal(int G[][5], int start, int n)
{
    static int visited[5] = {0};
    int j;
    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
                DFSTraversal(G, j, n);
        }
    }
}

int main()
{
    DFSTraversal(G, start, n);
    return 0;
}