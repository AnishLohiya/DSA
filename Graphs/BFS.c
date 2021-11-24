#include <stdio.h>
#include <stdlib.h>

int G[][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}};

int start = 0, n = 5;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int dequeue()
{
    int x = -1;
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct Node *temp = front;
        x = temp->data;
        front = front->next;
        free(temp);
    }
    return x;
}

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void BFSTraversal(int G[][5], int start, int n)
{
    int i, j;
    int visited[5] = {0};
    enqueue(start);
    visited[start] = 1;
    while (!isEmpty())
    {
        i = dequeue();
        printf("%d ", i);
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
}

int main(){
    BFSTraversal(G, start, n);
    return 0;
}