#include <stdio.h>
#include <stdlib.h>
#include <week9.h>

#ifndef __avl_tree__
typedef struct node {
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

avl_t * single_rot_left(avl_t * y)
{
    avl_t* x=y->left;
    y->left=x->right;
    x->right=y;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),y->height)+1;
    return x;
}

avl_t * single_rot_right(avl_t * y)
{
    avl_t* x=y->right;
    y->right=x->left;
    x->left=y;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->right),y->height)+1;
    return x;
}

avl_t * double_rot_left(avl_t * k3)
{
    k3->left=single_rot_right(k3->left);
    return single_rot_left(k3);
}

avl_t * double_rot_right(avl_t * k3)
{
    k3->right=single_rot_left(k3->right);
    return single_rot_right(k3);
}

avl_t * insert(avl_t * root, int data)
{
  if (root == NULL) {
    root = (avl_t*)malloc(sizeof(avl_t));
    root->data = data;
    root->height = 0;
    root->left = NULL;
    root->right = NULL;
  } 
  else if (data < root->data) 
  {
    root->left = insert(root->left, data);
    if (height(root->left) - height(root->right) == 2) {
      if (data < root->left->data) {
        root = single_rot_left(root);
      } else {
        root = double_rot_left(root);
      }
    }
  } 
  else if (data > root->data) 
  {
    root->right = insert(root->right, data);
    if (height(root->right) - height(root->left) == 2) {
      if (data > root->right->data) {
        root = single_rot_right(root);
      } else {
        root = double_rot_right(root);
      }
    }
  }
  root->height = max(height(root->left), height(root->right)) + 1;
  return root;
}

int height(avl_t* root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        return root->height;
    }
}

int max(int a,int b)
{
    return a > b ? a : b;
}

avl_t * delete(avl_t* root, int data)
{
  if (root == NULL) 
  {
    return NULL;
  } 
  else if (data < root->data) 
  {
    root->left = delete(root->left, data);
    if (height(root->right) - height(root->left) == 2) {
      if (height(root->right->left) > height(root->right->right)) {
        root = double_rot_right(root);
      } else {
        root = single_rot_right(root);
      }
    }
  } 
  else if (data > root->data) 
  {
    root->right = delete(root->right, data);
    if (height(root->left) - height(root->right) == 2) {
      if (height(root->left->right) > height(root->left->left)) {
        root = double_rot_left(root);
      } else {
        root = single_rot_left(root);
      }
    }
  } 
  else 
  {
    if (root->left != NULL && root->right != NULL) {
      avl_t* tmp = root->right;
      while (tmp->left != NULL) {
        tmp = tmp->left;
      }
      root->data = tmp->data;
      root->right = delete(root->right, root->data);
    } else {
      avl_t* tmp = root;
      if (root->left == NULL) {
        root = root->right;
      } else if (root->right == NULL) {
        root = root->left;
      }
      free(tmp);
    }
  }
  if (root != NULL) {
    root->height = max(height(root->left), height(root->right)) + 1;
  }
  return root;
}


int main(void) {
  avl_t *root = NULL;
  int n, i;
  int command, data;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &command);
    switch (command) {
    case 1:
      scanf("%d", &data);
      root = insert(root, data);
      break;
    case 2:
      scanf("%d", &data);
      root = delete (root, data);
      break;
    case 3:
      print_tree(root);
      break;
    }
  }
  return 0;
}