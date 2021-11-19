#include<stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *findMax(struct Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *findMin(struct Node *root)
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

int main(){
    
    return 0;
}