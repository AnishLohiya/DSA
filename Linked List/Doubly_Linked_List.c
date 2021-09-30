// Doubly Linked List

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

void insertatbeg()
{
    int x;
    printf("Insert at beginning: ");
    scanf("%d", &x);
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = x;
    if (head == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = tail = ptr;
    }
    else
    {
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

void insertatend()
{
    int x;
    printf("enter the value\n");
    scanf("%d", &x);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    if (tail == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = tail = temp;
    }
    else
    {
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void insertpos()
{
    temp = head;
    int pos, i = 1, x, n;
    printf("Enter the position to be inserted\n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertatbeg();
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data to be inserted at the end\n");
        scanf("%d", &x);
        newNode->data = x;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
    }
}

void delatbeg()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        printf("list already empty\n");
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = tail = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}

void delatend()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (tail == NULL)
    {
        printf("list already empty\n");
    }
    else if (tail->prev == NULL)
    {
        temp = tail;
        head = tail = NULL;
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

void delatpos()
{
    int pos, i = 1;
    temp = head;
    printf("Enter position to be deleted\n");
    scanf("%d", &pos);
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void Display()
{
    printf("Displaying Linked List\n");
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
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

void get_length()
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Length of the Linked List is %d\n", count);
}

int main()
{
    int opt, value, loct;
    create();
    while (1)
    {

        printf("\nwhich operation do you want to perform?\n");
        printf("1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert element at a position\n");
        printf("4.Delete from beginning\n");
        printf("5.Delete from end\n");
        printf("6.Delete element at a position\n");
        printf("7.Display\n");
        printf("8.Reverse Linked List\n");
        printf("9.Length of List\n");
        printf("10.Exit\n");

        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            insertatbeg();
            break;
        case 2:
            insertatend();
            break;
        case 3:
            insertpos();
            break;
        case 4:
            delatbeg();
            break;
        case 5:
            delatbeg();
            break;
        case 6:
            delatpos();
            break;
        case 7:
            Display();
            break;
        case 8:
            reverse();
            break;
        case 9:
            get_length();
            break;
        case 10:
            exit(0);
        default:
            printf("Wrong Choice!!\n");
        }
    }
    return 0;
}
