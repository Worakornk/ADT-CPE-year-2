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

bst_t * find(bst_t * root, int v)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == v)
    {
        return root;
    }
    if (v < root->data)
    {
        return find(root->left);
    }
    else
    {
        return find(root->right);
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

bst_t * create()
{
    bst_t * node = (bst_t *)malloc(sizeof(bst_t));
    node->data = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bst_t * insert(bst_t * root, int data)
{
    if (root == NULL)
    {
        bst_t * root = create();
        root->data = data;
        return root;
    }
    if (data < root->data)
    {
        return insert(root->left,data);
    }
    if (data > root->data)
    {
        return insert(root->right,data);
    }   
}

bst_t *find_parent(bst_t * root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == data || root->left == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return find_parent(root->left);
    }
    if (data > root->data)
    {
        return find_parent(root->right);
    }
}

bst_t * delete(bst_t * root, int data)
{
    bst_t * del_pos = find(root,data);

    // Case #1 --> leaf node
    if (del_pos->left == NULL && del_pos->right == NULL)
    {


    }

    // Case #2 --> Node has 1 child

    // Case #3 --> Node has 2 children

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