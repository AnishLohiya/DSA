#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *tail = NULL;

void create()
{
    int i, x;
    printf("How Many Elements You want to add: ");
    scanf("%d", &x);
    for (i = 1; i <= x; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d of the linked list: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (tail == NULL)
        {
            tail = newNode;
            tail->next = newNode;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void display()
{
    struct Node *temp = tail->next;
    if (tail == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
    printf("\n");
}

void reverse()
{
    struct Node *prev, *nextNode;
    struct Node *current = tail->next;
    nextNode = current->next;

    if (tail == NULL)
    {
        printf("Linked List is Empty\n");
    }

    else
    {
        while (current != tail)
        {
            prev = current;
            current = nextNode;
            nextNode = current->next;
            current->next = prev;
        }
        nextNode->next = tail;
        tail = nextNode;
    }
    display();
}

int main()
{
    create();
    display();
    reverse();
    return 0;
}