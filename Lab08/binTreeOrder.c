#include <stdio.h>
#include <stdlib.h>
#include <week8.h>
// #include "week8.h"

#ifndef __bin_tree__
typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif

// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header
// ...

//1
void pprint_preorder(tree_t * t)
{
    if (t == NULL)
    {
        return;
    }
    printf("%d ", t->data);
    pprint_preorder(t->left);
    pprint_preorder(t->right);
}

void print_preorder(tree_t * t)
{
    pprint_preorder(t);
    printf("\n");
    return;
}

//2
void pprint_postorder(tree_t * t)
{
    if (t == NULL)
    {
        return;
    }
    pprint_postorder(t->left);
    pprint_postorder(t->right);
    printf("%d ",t->data);
}

void print_postorder(tree_t * t)
{
    pprint_postorder(t);
    printf("\n");
    return;
}

//3
void pprint_inorder(tree_t * t)
{
    if (t == NULL)
    {
        return;
    }
    pprint_inorder(t->left);
    printf("%d ",t->data);
    pprint_inorder(t->right);
}

void print_inorder(tree_t * t)
{
    pprint_inorder(t);
    printf("\n");
    return;
}

int main(void) {
  tree_t *t = NULL;
  int n, i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }

  print_preorder(t);
  print_postorder(t);
  print_inorder(t);
  
  return 0;
}