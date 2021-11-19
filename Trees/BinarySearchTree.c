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
            struct Node *temp = findMin(root->right);
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

int main(){
    
    return 0;
}