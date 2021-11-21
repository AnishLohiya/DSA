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

int main(){
    
    return 0;
}