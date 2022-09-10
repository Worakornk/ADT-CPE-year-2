#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
  char data;
  struct node *next;
} node_t;


typedef node_t stack_t;


stack_t * push(stack_t *s, char v){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = v;
    node->next = s; // make the new node point to the node that we used to focus
    s = node;  // main focus point to the new node
    return s;
}


char top(stack_t *s){
    if (s == NULL) {
        return '0';
    }
    return s->data;
}


stack_t * pop(stack_t *s){
    node_t *tmp = NULL; // create temporary node
    if ((tmp = s) == NULL){ // empty?
        return s;
    }
    tmp = s;
    int v = tmp->data; // recieve data from the first 
    s = tmp->next; // starting next node instead
    free(tmp);
    return s;
}


int main(){
    int n,i,check=1;
    scanf("%d",&n);
    char Input[1000000];
    if (n%2 != 0){
        check = 0;
    }
    scanf("%s",Input);
    stack_t *s = NULL;
    for (i=0;i<n;i++){
        char character = Input[i];
        if (character == '(' || character == '[' || character == '{'){
            s = push(s,character);
        }
        else if (character == ')' || character == ']' || character == '}'){
            if (s == NULL){
                check = 0;
            }
            if (top(s) == '(' && character == ')'){
                s = pop(s);
            }
            else if (top(s) == '[' && character == ']'){
                s = pop(s);
            }
            else if (top(s) == '{' && character == '}'){
                s = pop(s);
            }
        } else {
            check = 0;
            break;
        }
    }
    if (check == 0 || s != NULL){
        printf("0\n");
    }
    else if (check == 1){
        printf("1\n");
    }
    return 1;
}
