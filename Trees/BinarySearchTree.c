#include<stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
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

struct Node *createNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNewNode(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node *delete (struct Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
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
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        }
        else if (root->left == NULL)
        {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        }
        else
        {
            struct Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
}

void search(struct Node *root, int val)
{
    if (root->data == val)
    {
        printf("%d is present in the tree\n", val);
        return;
    }
    if ((root->right == NULL && root->left == NULL) || root == NULL)
    {
        printf("Elment Not present in the tree\n");
        return;
    }
    if (val <= root->data)
    {
        search(root->left, val);
    }
    else
    {
        search(root->right, val);
    }
}

int countAllNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return countAllNodes(root->left) + countAllNodes(root->right) + 1;
    }
}

int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

int countNonLeafNodes(struct Node *root)
{
    return (countAllNodes(root) - countLeafNodes(root));
}

void PreOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void PostOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

void MirrorTree(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    struct Node *temp = root;

    MirrorTree(root->left);
    MirrorTree(root->right);

    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void printTree(struct Node *root, int space)
{
    if (root == NULL)
        return;

    space += 5;

    printTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTree(root->left, space);
}

struct Node *deleteCompleteTree(struct Node *root)
{
    if (root != NULL)
    {
        deleteCompleteTree(root->left);
        deleteCompleteTree(root->right);
        free(root);
        root = NULL;
    }
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
        printf("5.INORDER\n");
        printf("6.PREORDER\n");
        printf("7.POSTORDER\n");
        printf("8.Total number of nodes\n");
        printf("9.Number of Leaf nodes\n");
        printf("10.Number of Non-Leaf nodes\n");
        printf("11.Find MIN\n");
        printf("12.Find MAX\n");
        printf("13.Display\n");
        printf("14.Mirror\n");
        printf("15.Excise Tree\n");
        printf("16.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    return 0;
}