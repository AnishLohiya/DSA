#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head, *newNode, *tail;

void create()
{
    int n;
    head = NULL;
    printf("How Many Elements You want to add: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d of the linked list : ", i);
        scanf("%d", &newNode->data);

        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\n Linked list is empty. \n");
        exit(1);
    }
    else
    {
        tail = head;
        printf("The current linked list: \n");
        while (tail != NULL)
        {
            printf("%d ", tail->data);
            tail = tail->next;
        }
    }
}

int main()
{
    create();
    display();
    return 0;
}