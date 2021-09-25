// Code For Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create()
{
    int i, x;
    printf("How Many Elements You want to add: ");
    scanf("%d", &x);
    for (i = 1; i <= x; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d of the linked list: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertatbeg()
{
    int value;
    printf("Enter the value to insert at begining\n");
    scanf("%d", &value);
    struct Node *ins = (struct Node *)malloc(sizeof(struct Node));
    ins->data = value;
    ins->next = head;
    head = ins;
}

void insertatend()
{
    int value;
    printf("Enter The Value To be Inserted at the end\n");
    scanf("%d", &value);
    struct Node *ins = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    ins->data = value;
    ins->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ins;
}

void insertAtPos()
{
    int x, pos, i = 1;
    printf("Enter The Value To Be Inserted \n");
    scanf("%d", &x);
    printf("Enter the Position\n");
    scanf("%d", &pos);
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    ptr->data = x;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

void delatbeg()
{
    if (head == NULL)
    {
        printf("Linked List is Already Empty\n");
    }
    else
    {
        struct Node *del = (struct Node *)malloc(sizeof(struct Node));
        printf("Delete Element is %d\n", head->data);
        del = head;
        head = head->next;
        free(del);
    }
}

void delatend()
{
    struct Node *del = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        printf("Linked List is Already Empty\n");
    }
    else if (head->next == NULL)
    {
        del = head;
        head = NULL;
        free(del);
    }
    else
    {
        del = head;
        temp = head->next;
        while (temp->next != NULL)
        {
            del = temp;
            temp = temp->next;
        }
    }
    printf("Deleted Element is %d\n", temp->data);
    del->next = NULL;
    free(temp);
}

void delAtPos()
{
    int pos;
    printf("Enter the postion to be deleted in linked list\n");
    scanf("%d", &pos);
    struct Node *ptr, *ptr1;
    int i;
    ptr = head;
    for (i = 0; i < pos; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d ", pos + 1);
}

void display()
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

void sort_list()
{
    struct Node *ptr1, *ptr2;
    int temp;
    ptr1 = head;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {

            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
    }
    display();
}

void reverse()
{
    printf("Displaying Reverse Linked List\n");
    struct Node *prevNode, *currentNode, *nextNode;
    prevNode = NULL;
    currentNode = head;
    nextNode = head;
    while (nextNode != NULL)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    display();
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
    int opt;
    while (1)
    {
        printf("\nwhich operation do you want to perform?\n");
        printf("1.Create a Linked List\n");
        printf("2.Display\n");
        printf("3.Sort\n");
        printf("4.Insert at beginning\n");
        printf("5.Insert at End\n");
        printf("6.Insert at Position\n");
        printf("7.Delete from beginning\n");
        printf("8.Delete from end\n");
        printf("9.Delete at Position\n");
        printf("10.Reverse\n");
        printf("11.Length of Linked List\n");
        printf("12.Exit\n");
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
            sort_list();
            break;
        case 4:
            insertatbeg();
            break;
        case 5:
            insertatend();
            break;
        case 6:
            insertAtPos();
            break;
        case 7:
            delatbeg();
            break;
        case 8:
            delatend();
            break;
        case 9:
            delAtPos();
            break;
        case 10:
            reverse();
            break;
        case 11:
            get_length();
            break;
        case 12:
            exit(0);
        default:
            printf("Unknown Choice !!\n");
        }
    }
    return 0;
}
