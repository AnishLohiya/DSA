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

    if (balanceFactor > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    if (balanceFactor < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }
    if (balanceFactor > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balanceFactor < -1 && data < root->right->data)
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

    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
    {
        return rightRotate(root);
    }
    if (balanceFactor > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
    {
        return leftRotate(root);
    }
    if (balanceFactor < -1 && getBalanceFactor(root->right) > 0)
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

int main(){
    
    return 0;
}