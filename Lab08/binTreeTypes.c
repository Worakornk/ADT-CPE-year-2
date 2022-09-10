#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <week8.h>
#include "week8.h"

#ifndef __bin_tree__

typedef struct node {
  int    data;
  struct node *left;
  struct node *right;
} node_t;

typedef node_t tree_t;
#endif

/*-----------------------------------------------------*/

//1
int is_full(tree_t * t){
  if (t == NULL)
  {
    return 1;
  } 
  if (t->right == NULL && t->left == NULL)
  {
    return 1;
  } 
  if (t->left != NULL && t->right != NULL) 
  {
    return is_full(t->left) && is_full(t->right);
  } 
  return 0;
}

/*-----------------------------------------------------*/

int height(tree_t * t)
{
  if (t == NULL)
  {
    return -1;
  }
  int hl = height(t->left);
  int hr = height(t->right);
  return (hl > hr) ? hl + 1 : hr + 1;
}

int count_nodes(tree_t * t)
{
    if (t == NULL) return 0;
    return 1 + count_nodes(t->left) + count_nodes(t->right);
}

int count_leafs(tree_t * t)
{
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL)
    {
      return 1 + count_leafs(t->left) + count_leafs(t->right);
    }
    return count_leafs(t->left) + count_leafs(t->right);
}

//2
int is_perfect(tree_t * t)
{
  if (t == NULL)
  {
    return 1;
  }

  int n_nodes = count_nodes(t);
  int n_leafs = count_leafs(t);
  int h = height(t);

  if (n_nodes == pow(2,h+1)-1 && n_leafs == pow(2,h))
  {
    return 1;
  } else {
    return 0;
  }
}

/*-----------------------------------------------------*/

int findDepth(tree_t * root, int data)
{
    if (root == NULL)
        return -1;
    int dist = -1;
    if ((root->data == data) 
    || (dist = findDepth(root->left, data)) >= 0 
    || (dist = findDepth(root->right, data)) >= 0)
    {
      return dist + 1;
    }
    return dist;
}

// void bfs(tree_t * t)
// {
//     if(t == NULL) return;
//     tree_t* arr[10000];
//     int front = 0;
//     int back = 1;
//     arr[0] = t;
//     // stack implementation
//     while(front<back)
//     {
//         printf("%d ",arr[front]->data); // ?
//         tree_t * now = arr[front]->left;
//         front++;
//         while(now != NULL)
//         {
//             arr[back] = now;
//             cnt++;
//             now = now->next_sibling;
//         }
//     }
//     printf("\n");
// }

//3
int completed(tree_t *t, int node_id, int size)
{
    if (t == NULL)
    {
        return 1;
    }
    if (node_id >= size)
    {
        return 0;
    }
    return completed(t->left, 2 * node_id + 1, size) && completed(t->right, 2 * node_id + 2, size);
}

int is_complete(tree_t *t)
{
    int node_id = 0; // Start at root node
    int no_node = count_nodes(t); // count no. of root in the tree
    return completed(t, node_id, no_node);
}


/*-----------------------------------------------------*/

//4
int is_degenerate(tree_t * t)
{
    if (t == NULL || (t->left == NULL && t->right == NULL))
    {
        return 1;
    }
    if (t->left != NULL && t->right == NULL)
    {
        is_degenerate(t->left);
    }
    if (t->right != NULL && t->left == NULL)
    {
        is_degenerate(t->right);
    }
    if (t->left != NULL && t->right != NULL)
    {
        return 0;
    }
    return 1;
}

/*-----------------------------------------------------*/

//5
int left = 0;
int right = 0;

int is_skewed(tree_t * t)
{
    if (t == NULL || (t->left == NULL && t->right == NULL))
    {
        return 1;
    }

    if (t->left != NULL && t->right != NULL)
    {
        return 0;
    }
    if (t->left != NULL && right != 1)
    {
        left = 1;
        return is_skewed(t->left);
    }
    if (t->right != NULL && left != 1)
    {
        right = 1;
        return is_skewed(t->right);
    }
    return 0;
}

/*-----------------------------------------------------*/

int main(void) {
  tree_t * t = NULL;
  int n, i;
  int parent, child;
  int branch; // 0 root, 1 left, 2 right

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d %d %d", &parent, &child, &branch);
    t = attach(t, parent, child, branch);
  }

  printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t), is_degenerate(t), is_skewed(t));

  return 0;
}