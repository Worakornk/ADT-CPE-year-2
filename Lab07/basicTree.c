#include <stdio.h>
#include <stdlib.h>

// You can define your own (one or more)
// structures here. However, we eventually
// need the data type "tree_t".
// For example:
// typedef struct node {
//    ...
// } node_t;
// typedef node_t tree_t;

// Write your code here
// ...

typedef struct node
{
  int value;
  struct node *next_sibling;
  struct node *first_child;
  struct node *parent;
} node_t;

typedef node_t tree_t;

// returns node that stores the value
tree_t * located(tree_t * t, int v)
{
  if (t == NULL || t->value == v)
  {
    return t;
  }
  tree_t * pos = located(t->first_child, v);
  if (pos != NULL)
  {
    return pos;
  }
  else
  {
    return located(t->next_sibling, v);
  }
}

// 1
tree_t * attach(tree_t *t, int parent, int v)
{
  node_t * child_n = (tree_t *)malloc(sizeof(tree_t));
  child_n->value = v;
  child_n->first_child = NULL;
  child_n->next_sibling = NULL;
  child_n->parent = NULL;

  if (t == NULL || parent == -1){
    t = child_n;
    return t;
  }
   
  tree_t * pos = located(t, parent);
  child_n->parent = pos;
  if (pos->first_child == NULL){
    pos->first_child = child_n;
  } else {
    pos = pos->first_child;
    while (pos->next_sibling != NULL){
      pos = pos->next_sibling;
    }
    pos->next_sibling = child_n;
  }
  return t;
}

// 2
tree_t *detach(tree_t *t, int value) {
  if (t->value == value) {
    return NULL;
  }
  tree_t *pos = located(t, value);
  tree_t *focus = pos->parent;

  if (focus->first_child == pos) {
    if (pos->next_sibling != NULL) {
      focus->first_child = pos->next_sibling;
      return t;
    }
    focus->first_child = NULL;
    return t;
  }

  focus = focus->first_child;
  while (focus->next_sibling != pos) {
    focus = focus->next_sibling;
  }
  if (pos->next_sibling != NULL) {
    focus->next_sibling = pos->next_sibling;
    return t;
  }
  focus->next_sibling = NULL;
  return t;
}
//3
int search(tree_t * t, int value)
{
  return located(t,value) == NULL ? 0 : 1;
}

//4
int degree(tree_t * t, int value)
{
  int count = 0;
  tree_t * pos = located(t,value);
  if (pos->first_child == NULL){
    return count;
  } else {
    pos = pos->first_child;
    count++;
    while(pos->next_sibling != NULL){
      pos = pos->next_sibling;
      count++;
    }
  return count;
  }
}

//5
int is_root(tree_t * t, int value)
{
  tree_t * pos = located(t,value);
  if (pos->parent == NULL){
    return 1;
  } else {
    return 0;
  }
}

//6
int is_leaf(tree_t * t, int value)
{
  tree_t * pos = located(t,value);
  if (pos->first_child == NULL){
    return 1;
  } else {
    return 0;
  }
}

//7
void siblings(tree_t * t, int value)
{
  if (is_root(t,value)==1){
    printf("\n");
    return;
  }
  tree_t * pos = located(t,value);
  pos = pos->parent;
  pos = pos->first_child;
  while (pos != NULL){
    if (pos->value != value){
      printf("%d ",pos->value);
    }
    pos = pos->next_sibling;
  }
  printf("\n");
  return;
}

//8
int depth(tree_t * t, int value)
{
  int count = 0;
  tree_t * pos = located(t,value);
  while(pos->parent != NULL){
    count += 1;
    pos = pos->parent;
  }
  return count;
}

//9
void print_path(tree_t * t, int start, int end)
{
  tree_t * pos = located(t,end);
  if (start == end){
    printf("%d",pos->value);
    return;
  }
  int arr1[1000];
  int i = 0;
  while (pos != NULL){
    arr1[i] = pos->value;
    pos = pos->parent;
    i++;
  }
  int check = 0;
  for (i=i-1;i>=0;i--){
    if (check == 0){
      if (arr1[i] == start){
        check = 1;
      } else {
        continue;
      }
    }
    if(arr1[i] == end){
      printf("%d ",arr1[i]);
      break;
    }
    printf("%d ",arr1[i]);
  }
  printf("\n");
  return;
}

//10
int path_length(tree_t * t, int start , int end)
{
  int count = 1;
  if (start == end){
    return count;
  }
  tree_t * start_t = located(t,start);
  tree_t * end_t = located(t,end);
  while(end_t != start_t){
    count += 1;
    end_t = end_t->parent;
  }
  return count;
}

//11
void ancestor(tree_t * t, int value)
{
  int arr[1000];
  tree_t * pos = located(t,value);
  int i = 0;
  while (pos != NULL)
  {
    arr[i] = pos->value;
    i++;
    pos = pos->parent;
  }
  for (i=i-1;i>=0;i--){
    printf("%d ",arr[i]);
  }
  printf("\n");
  return;
}

// //12
void descendant(tree_t* t,int v)
{
    if(t==NULL) return;
    tree_t* arr[10000];
    int index=0;
    int cnt=1;
    arr[0] = located(t,v);
    while(index<cnt)
    {
        printf("%d ",arr[index]->value);
        tree_t* now = arr[index]->first_child;
        index++;
        while(now!=NULL)
        {
            arr[cnt] = now;
            cnt++;
            now = now->next_sibling;
        }
    }
    printf("\n");
}

//13 bfs requires queue implementations
void bfs(tree_t* t)
{
    if(t == NULL) return;
    tree_t* arr[10000];
    int index=0;
    int cnt=1;
    arr[0] = t;
    while(index<cnt)
    {
        printf("%d ",arr[index]->value);
        tree_t* now = arr[index]->first_child;
        index++;
        while(now != NULL)
        {
            arr[cnt] = now;
            cnt++;
            now = now->next_sibling;
        }
    }
    printf("\n");
}

// //14
void printdfs(tree_t* tree)
{
    if(tree == NULL) return;
    printf("%d ",tree->value);
    printdfs(tree->first_child);
    printdfs(tree->next_sibling);
}
void dfs(tree_t* t)
{
    printdfs(t);
    printf("\n");
}
// //15
void depthdfs(tree_t* t,int d)
{
    if(t==NULL) return;
    int i;
    for(i=0; i<d; i++)
    {
        printf("    ");
    }
    printf("%d\n", t->value);
    depthdfs(t->first_child,d+1);
    depthdfs(t->next_sibling,d);
}

void print_tree(tree_t* tree)
{
    depthdfs(tree,0);
}

int main(void)
{
  tree_t * t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &command);
    switch (command)
    {
    case 1:
      scanf("%d %d", &parent, &child);
      t = attach(t, parent, child);
      break;
    case 2:
      scanf("%d", &node);
      t = detach(t, node);
      break;
    case 3:
      scanf("%d", &node);
      printf("%d\n", search(t, node));
      break;
    case 4:
      scanf("%d", &node);
      printf("%d\n", degree(t, node));
      break;
    case 5:
      scanf("%d", &node);
      printf("%d\n", is_root(t, node));
      break;
    case 6:
      scanf("%d", &node);
      printf("%d\n", is_leaf(t, node));
      break;
    case 7:
      scanf("%d", &node);
      siblings(t, node);
      break;
    case 8:
      scanf("%d", &node);
      printf("%d\n", depth(t, node));
      break;
    case 9:
      scanf("%d %d", &start, &end);
      print_path(t, start, end);
      break;
    case 10:
      scanf("%d %d", &start, &end);
      printf("%d\n", path_length(t, start, end));
      break;
    case 11:
      scanf("%d", &node);
      ancestor(t, node);
      break;
    case 12:
      scanf("%d", &node);
      descendant(t, node);
      break;
    case 13:
      bfs(t);
      break;
    case 14:
      dfs(t);
      break;
    case 15:
      print_tree(t);
      break;
    }
  }
  return 0;
}