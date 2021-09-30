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

void insertAtBeg()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data you want to insert: ");
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
    }
}

void insertAtEnd()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data you want to insert: ");
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

void insertAtPos()
{
    int pos, i = 1;
    struct Node *newNode, *temp;
    printf("Enter the Postion: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertAtBeg();
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data to be inserted: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        temp = tail->next;

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insert_after()
{
    int c, d;
    struct Node *temp = tail->next;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:");
    scanf("%d", &d);
    newNode->data = d;
    newNode->next = NULL;
    printf("Enter the value after which the data has to be inserted:");
    scanf("%d", &c);

    while (temp->data != c)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_before()
{
    int c, d;
    struct Node *newNode, *ptr, *preptr;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:");
    scanf("%d", &d);
    newNode->data = d;
    printf("Enter the value before which the data has to be inserted:");
    scanf("%d", &c);
    ptr = tail->next;
    while (ptr->data != c)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;
}

void delAtBeg()
{
    struct Node *temp = tail->next;
    if (tail == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}

void delAtEnd()
{
    struct Node *current = tail->next;
    struct Node *prev;
    if (tail == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        while (current->next != tail->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = tail->next;
        tail = prev;
        free(current);
    }
}

void delAtPos()
{
    struct Node *nextNode;
    struct Node *current = tail->next;
    int pos, i = 1;
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        delAtBeg();
    }
    else
    {
        while (i < pos - 1)
        {
            current = current->next;
            i++;
        }
        nextNode = current->next;
        current->next = nextNode->next;
        free(nextNode);
    }
}

void delete_after()
{
    int c;
    printf("Enter the value after which the data has to be deleted:");
    scanf("%d", &c);
    struct Node *ptr, *preptr, *temp;
    if (tail == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        ptr = tail->next;
        preptr = ptr;
        while (preptr->data != c)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        temp = ptr;
        preptr->next = temp->next;

        free(temp);
    }
}

void delete_before()
{
    int c;
    struct Node *ptr, *preptr;
    printf("Enter the value before which the data has to be deleted:");
    scanf("%d", &c);
    ptr = tail->next;
    preptr = ptr;
    while (ptr->next->data != c)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}

void updateAtPos()
{
    int pos, d, i = 1;
    struct Node *temp = tail->next;
    printf("Enter The Position to be Updated in the list:");
    scanf("%d", &pos);
    printf("Enter the updated data:");
    scanf("%d", &d);

    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->data = d;
}

void update_before()
{
    int c, d;
    struct Node *prev;
    struct Node *temp = tail->next;
    printf("Enter the data after which the data has to be updated:");
    scanf("%d", &c);
    printf("Enter the updated data: ");
    scanf("%d", &d);
    prev = temp;

    while (temp->data != c)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->data = d;
}

void update_after()
{
    int c, d;
    struct Node *temp = tail->next;
    printf("Enter the data after which the data has to be updated:");
    scanf("%d", &c);
    printf("Enter the updated data: ");
    scanf("%d", &d);

    while (temp->data != c)
    {
        temp = temp->next;
    }

    temp->next->data = d;
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

void get_length()
{
    int count = 0;
    struct Node *temp = tail->next;
    if (tail == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        do
        {
            count++;
            temp = temp->next;
        } while (temp != tail->next);
    }
    printf("Length of Linked List is %d\n", count);
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
    int opt;
    while (1)
    {
        printf("\nwhich operation do you want to perform?\n");
        printf("1.Create a Linked List\n");
        printf("2.Display\n");
        printf("3.Search\n");
        printf("4.Insert at beginning\n");
        printf("5.Insert at End\n");
        printf("6.Insert at Position\n");
        printf("7.Insert before Position\n");
        printf("8.Insert after Position\n");
        printf("9.Delete from beginning\n");
        printf("10.Delete from end\n");
        printf("11.Delete at Position\n");
        printf("12.Delete After Value\n");
        printf("13.Delete Before Value\n");
        printf("14.Update Element at Position\n");
        printf("15.Update Element at Before given value\n");
        printf("16.Update Element at After given value\n");
        printf("17.Reverse\n");
        printf("18.Length of Linked List\n");
        printf("19.Exit\n");
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
            insertAtBeg();
            break;
        case 5:
            insertAtEnd();
            break;
        case 6:
            insertAtPos();
            break;
        case 7:
            insert_before();
            break;
        case 8:
            insert_after();
            break;
        case 9:
            delAtBeg();
            break;
        case 10:
            delAtEnd();
            break;
        case 11:
            delAtPos();
            break;
        case 12:
            delete_after();
            break;
        case 13:
            delete_before();
            break;
        case 14:
            updateAtPos();
            break;
        case 15:
            update_before();
            break;
        case 16:
            update_after();
            break;
        case 17:
            reverse();
            break;
        case 18:
            get_length();
            break;
        case 19:
            exit(0);
        default:
            printf("Unknown Choice !!\n");
        }
    }
    return 0;
}