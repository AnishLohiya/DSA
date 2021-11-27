#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
    int height;
};

struct Node *root = NULL;

struct Node *FindMax(struct Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *FindMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

int Max(int n1, int n2)
{
    return n1 > n2 ? n1 : n2;
}

struct Node *getNewNode(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int FindHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (FindHeight(root->left) - FindHeight(root->right));
}

struct Node *rightRotate(struct Node *root)
{
    struct Node *leftChild = root->left;
    struct Node *leftRightChild = leftChild->right;

    leftChild->right = root;
    root->left = leftRightChild;

    root->height = Max(FindHeight(root->left), FindHeight(root->right)) + 1;
    leftChild->height = Max(FindHeight(leftChild->left), FindHeight(leftChild->right)) + 1;

    return leftChild;
}

struct Node *leftRotate(struct Node *root)
{
    struct Node *rightChild = root->right;
    struct Node *rightLeftChild = rightChild->left;

    rightChild->left = root;
    root->right = rightLeftChild;

    root->height = Max(FindHeight(root->left), FindHeight(root->right)) + 1;
    rightChild->height = Max(FindHeight(rightChild->left), FindHeight(rightChild->right)) + 1;

    return rightChild;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }

    root->height = Max(FindHeight(root->left), FindHeight(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && data < root->left->data)    // LEFT-LEFT
    {
        return rightRotate(root);             
    }
    if (balanceFactor < -1 && data > root->right->data)  // RIGHT-RIGHT
    {
        return leftRotate(root);
    }
    if (balanceFactor > 1 && data > root->left->data)    // LEFT-RIGHT
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balanceFactor < -1 && data < root->right->data)  // RIGHT-LEFT
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

struct Node *delete (struct Node *root, int data) // delete node with given data
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        struct Node *temp = FindMin(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }

    if (root == NULL)
    {
        return root;
    }

    root->height = Max(FindHeight(root->left), FindHeight(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);

    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)       // LEFT-LEFT
    {
        return rightRotate(root);
    }
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0)        // LEFT-RIGHT
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)     // RIGHT-RIGHT
    { 
        return leftRotate(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0)      // RIGHT-LEFT
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int countAllNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countAllNodes(root->left) + countAllNodes(root->right);
}

void search(struct Node *root, int data)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return;
    }
    if (data == root->data)
    {
        printf("Element found\n");
        return;
    }
    if (data < root->data)
    {
        search(root->left, data);
    }
    else
    {
        search(root->right, data);
    }
}

void InOrder(struct Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

void display(struct Node *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += 10;
    display(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    display(root->left, space);
}

int main(){
    struct Node *temp;
    int data, choice, val, i;
    while (1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Height\n");
        printf("5.Inorder\n");
        printf("6.Total number of nodes\n");
        printf("7.Display\n");
        printf("8.EXIT\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                root = delete (root, data);
                break;
            case 3:
                printf("Enter the data to be searched: ");
                scanf("%d", &val);
                search(root, val);
                break;
            case 4:
                printf("Height of the tree is %d\n", FindHeight(root));
                break;
            case 5:
                printf("INORDER: ");
                InOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Total number of nodes in the tree is %d\n", countAllNodes(root));
                break;
            case 7:
                display(root, 0);
                break;
            case 8:
                exit(0);
            default:
                printf("Wrong choice\n");
        };
    }
    return 0;
}
