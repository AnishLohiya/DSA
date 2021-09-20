#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
struct Node *newnode, *temp;

void create()
{
    int i, x;
    printf("Number of elements in the linked list: \n");
    scanf("%d", &x);
    for (i = 1; i <= x; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d of the linked list: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
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
        temp = head;
        printf("The current linked list: \n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    create();
    display();
    return 0;
}