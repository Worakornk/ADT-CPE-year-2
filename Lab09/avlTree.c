#include <stdio.h>
#include <stdlib.h>
#include "week9.h"

#ifndef __avl_tree__
typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;

typedef node_t avl_t;
#endif

// Write your code here
// ** Note that the print_tree() function
// has been implemented already and
// included in the week9.h header
// ...

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int height(node_t *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return node->height;
    }
}

node_t *new_node(int data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

node_t *right_rotate(node_t *y)
{
    node_t *x = y->left;
    node_t *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

node_t *left_rotate(node_t *x)
{
    node_t *y = x->right;
    node_t *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int get_balance(node_t *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return height(node->left) - height(node->right);
    }
}

node_t *min_value_node(node_t *node)
{
    node_t *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

avl_t *insert(avl_t *root, int data)
{
    if (root == NULL)
    {
        root = (avl_t *)malloc(sizeof(avl_t));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->height = 0;
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
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = get_balance(root);
    if (balance > 1 && data < root->left->data)
    {
        return right_rotate(root);
    }
    if (balance < -1 && data > root->right->data)
    {
        return left_rotate(root);
    }
    if (balance > 1 && data > root->left->data)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

avl_t *delete (avl_t *root, int data)
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
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            avl_t *temp = min_value_node(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = get_balance(root);
    if (balance > 1 && get_balance(root->left) >= 0)
    {
        return right_rotate(root);
    }
    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (balance < -1 && get_balance(root->right) <= 0)
    {
        return left_rotate(root);
    }
    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

int main(void)
{
    avl_t *t = NULL;
    int n, i;
    int command, data;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete (t, data);
            break;
        case 3:
            print_tree(t);
            break;
        }
    }
    return 0;
}