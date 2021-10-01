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
}
int main()
{
    create();
    display();
    return 0;
}