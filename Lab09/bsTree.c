#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t bst_t;

// Write your code here
// ...

bst_t * locate(bst_t * root, int v)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == v)
    {
        return root;
    }
    if (v < root->data)
    {
        return locate(root->left,v);
    }
    if (v > root->data)
    {
        return locate(root->right,v);
    }
}

int find(bst_t * root, int v)
{
    if (locate(root,v) == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int find_min(bst_t * root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    bst_t * current_pos = root;
    while (current_pos->left != NULL)
    {
        current_pos = current_pos->left;
    }
    return current_pos->data;
} 

int find_max(bst_t * root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    bst_t * current_pos = root;
    while (current_pos->right != NULL)
    {
        current_pos = current_pos->right;
    }
    return current_pos->data;
} 

bst_t * create(int data)
{
    bst_t * node = (bst_t *)malloc(sizeof(bst_t));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bst_t * insert(bst_t * root, int data)
{
    if (root == NULL)
    {
        bst_t * root = create(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left,data);
    }
    if (data > root->data)
    {
        root->right = insert(root->right,data);
    }
    return root;
}


bst_t * delete(bst_t * root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = delete(root->left,data);
    }
    else if (data > root->data)
    {
        root->right = delete(root->right,data);
    }
    else
    {
        // 1 child & leaf node
        if (root->left == NULL)
        {
            bst_t * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t * temp = root->left;
            free(root);
            return temp;
        }
        // 2 children
        bst_t * temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete(root->right,temp->data);
    }
    return root;
}

int main(void) {
    bst_t *t = NULL;
    int n, i;
    int command, data;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch (command) {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete(t, data);
            break;
        case 3:
            scanf("%d", &data);
            printf("%d\n", find(t, data));
            break;
        case 4:
            printf("%d\n", find_min(t));
            break;
        case 5:
            printf("%d\n", find_max(t));
            break;
        }
    }
    return 0;
}