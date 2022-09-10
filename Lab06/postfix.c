#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  float data;
  struct node *next;
} node_t;

typedef node_t stack_t;

stack_t * push(stack_t *s, float v){
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = v;
    node->next = s;
    s = node;  
    return s;
}

float top(stack_t *s){
    if (s == NULL) {
        return 0;
    }
    return s->data;
}

stack_t * pop(stack_t *s){
    node_t *tmp = NULL;
    if ((tmp = s) == NULL){
        return s;
    }
    tmp = s;
    int v = tmp->data;
    s = tmp->next;
    free(tmp);
    return s;
}

stack_t * plus(stack_t *s){
    float value1 = s->data;
    s = pop(s);
    float value2 = s->data;
    s->data = value1 + value2;
    return s;
}

stack_t * minus(stack_t *s){
    float value1 = s->data;
    s = pop(s);
    float value2 = s->data;
    s->data = value2 - value1;
    return s;
}

stack_t * multiply(stack_t *s){
    float value1 = s->data;
    s = pop(s);
    float value2 = s->data;
    s->data = value1 * value2;
    return s;
}

stack_t * divide(stack_t *s){
    float value1 = s->data;
    s = pop(s);
    float value2 = s->data;
    s->data = value2 / value1;
    return s;
}


int main(){
    int i,n;
    scanf("%d",&n);
    char str[1000000];
    scanf("%s",str);

    stack_t * s = NULL;

    for (i=0;i<n;i++){
        if (str[i] >= '0' && str[i] <= '9'){
            int add = str[i]-'0';
            s = push(s,add);
        }
        else if (str[i] == '+'){
            s = plus(s);
        } else if (str[i] == '-'){
            s = minus(s);

        } else if (str[i] == '*'){
            s = multiply(s);
        } else if (str[i] == '/'){
            s = divide(s);
        }
    }
    printf("%.2lf",s->data);
    return 1;
}