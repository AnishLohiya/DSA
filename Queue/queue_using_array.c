#include <stdio.h>
#include <stdlib.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue()
{
    int x;
    printf("Enter the Element to be inserted:\n");
    scanf("%d", &x);
    if (rear == N - 1)
    {
        printf("Queue is Full!\n");
    }
    else if (front == -1 && rear == -1)
    {
        rear = front = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty!\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front Element: %d", queue[front]);
    }
}

int main()
{
    int ch;

    while (1)
    {

        printf("\n*** Queue Menu ***");
        printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Peek\n5.Exit\n");
        printf("\n\nEnter your choice(1-4):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong Choice!!");
        }
    }
    return 0;
}