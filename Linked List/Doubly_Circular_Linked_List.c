// Doubly Circular Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head, *tail;

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

        if (head == NULL)
        {
            head = tail = newNode;
            head->next = head->prev = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }
}

void insertAtBeg()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to be inserted: ");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = newNode->prev = head;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        head = newNode;
    }
}

void insertAtEnd()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to be inserted: ");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = newNode->prev = head;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode;
    }
}

void display()
{
    struct Node *temp = head;
    if (head == NULL)
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
int main()
{
    create();
    display();
    return 0;
}