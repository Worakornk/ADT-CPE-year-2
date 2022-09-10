#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t * push(stack_t *s, int v){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = v;
    node->next = s; // make the new node point to the node that we used to focus
    s = node;  // main focus point to the new node
    return s;
}

void top(stack_t *s){
    if (s == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("%d\n",s->data);
    return;
}

stack_t * pop(stack_t *s){
    node_t *tmp = NULL; // create temporary node
    if ((tmp = s) == NULL){ // empty?
        return s;
    }
    tmp = s;
    s = tmp->next; // starting next node instead
    free(tmp);
    return s;
}

void empty(stack_t *s){
    if (s == NULL){
      printf("Stack is empty.\n");
      return;
    }
    printf("Stack is not empty.\n");
    return;
}

void size(stack_t * s){
    if (s == NULL){
        printf("0\n");
        return;
    }
    int count = 1;
    node_t * current_node = s;
    while (current_node->next != NULL){
        current_node = current_node->next;
        count +=1 ;
    }
    printf("%d\n",count);
    return;
}

int main(void) {
  stack_t *s = NULL;
  int n, i, command, value;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &command); 
    switch (command) {
      case 1:
        scanf("%d", &value);
        s = push(s, value);
        break;
      case 2:
        top(s);
        break;

      case 3:
        s = pop(s);
        break;

      case 4:
        empty(s);
        break;

      case 5:
        size(s);
        break;

      default:
        break;
    }
  }

  return 0;
}