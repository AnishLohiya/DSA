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

int main(){
    
    return 0;
}