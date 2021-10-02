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

void insertAtPos()
{
    int pos, i = 1;
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the postion at which data is inserted: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertAtBeg();
    }
    else
    {
        printf("Enter the postion at which data is inserted: ");
        scanf("%d", &newNode->data);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void deleteAtBeg()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Linked List in Empty\n");
    }
    else if (head == tail)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
}

void deleteAtEnd()
{
    struct Node *temp = tail;
    if (head == NULL)
    {
        printf("Linked List in Empty\n");
    }
    else if (head == tail)
    {
        head = tail = 0;
        free(temp);
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}

void deleteAtPos()
{
    int pos, i = 0;
    struct Node *temp = head;

    printf("Enter position: \n");
    scanf("%d", &pos);
    if (pos == 1)
    {
        deleteAtBeg();
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
        if (temp->next == head)
        {
            tail = temp->prev;
            free(temp);
        }
        else
        {
            free(temp);
        }
    }
}

void update()
{
    struct Node *temp = head;
    int c, d;
    printf("Enter the value to be updated: \n");
    scanf("%d", &c);
    printf("Enter the data:");
    scanf("%d", &d);

    while (temp->data != c)
    {
        temp = temp->next;
    }
    temp->data = d;
}

void updateAtPos()
{
    struct Node *temp = head;
    int pos, i = 0, x;
    printf("Enter position to be updated: \n");
    scanf("%d", &pos);
    printf("Enter the data: \n");
    scanf("%d", &x);
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    temp->data = x;
}

void get_length()
{
    int count = 1;
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        while (temp != tail)
        {
            temp = temp->next;
            count++;
        }
    }
    printf("Length of Linked List is %d\n", count);
}

void search()
{
    int x, i = 1;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode = tail->next;
    if (newNode == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        printf("Enter the data you want to search\n");
        scanf("%d", &x);
        while (newNode->data != x)
        {
            newNode = newNode->next;
            i++;
        }
        printf("Node found at %d\n", i);
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
    int opt;
    while (1)
    {
        printf("\nwhich operation do you want to perform?\n");
        printf("1.Create a Linked List\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("4.Count Nodes\n");
        printf("5.Insert at Beginning\n");
        printf("6.Insert at End\n");
        printf("7.Insert at Position\n");
        printf("8.Delete at Beginning\n");
        printf("9.Delete at End\n");
        printf("10.Delete at given Position\n");
        printf("11.Update Element \n");
        printf("12.Update Element at Position\n");
        printf("13.Exit\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            get_length();
            break;
        case 5:
            insertAtBeg();
            break;
        case 6:
            insertAtEnd();
            break;
        case 7:
            insertAtPos();
            break;
        case 8:
            deleteAtBeg();
            break;
        case 9:
            deleteAtEnd();
            break;
        case 10:
            deleteAtPos();
            break;
        case 11:
            update();
            break;
        case 12:
            updateAtPos();
            break;
        case 13:
            exit(0);
        default:
            printf("Unknown Choice !!\n");
        }
    }
    return 0;
}