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

int main(){
    
    return 0;
}