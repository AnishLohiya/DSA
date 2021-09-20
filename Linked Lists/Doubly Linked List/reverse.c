#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *temp;

void create()
{
    int n;
    head = NULL;
    printf("How Many Elements You want to add: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
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

void reverse()
{
    printf("Displaying Reverse Linked List\n");
    struct Node *temp = tail;
    while (temp->prev != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

int main()
{
    create();
    reverse();
    return 0;
}