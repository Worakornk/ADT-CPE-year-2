#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000000

typedef struct node
{
    int data;
    struct node * next;
} node_t;

typedef struct list{
    int * arr;
    int count;
} list_t;

list_t create(){
    list_t l = {NULL,0};
    l.arr = (int *)malloc(sizeof(int) * MAXSIZE);
    return l;
}

node_t * append(node_t * n){
    int value;
    scanf("%d",&value);
    if(n == NULL){
        n = (node_t *)malloc(sizeof(node_t));
        n->data = value;
        n->next = NULL;
        return n;
    }
    node_t * current_node = n;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    node_t * last = (node_t *)malloc(sizeof(node_t));
    last->data = value;
    last->next = NULL;
    current_node->next = last;
    return n;
}
    
void get(node_t * n){
    int index,count=0,data,i;
    scanf("%d",&index);
    node_t * current_node = n;
    if (index == 0){
        printf("%d\n",current_node->data);
        return;
    }
    for (i = 0; i < index ; i++){
        current_node = current_node->next;
    }
    printf("%d\n",current_node->data);
}

void show(node_t * n){
    node_t * current_node = n;
    if (current_node == NULL){
        printf("\n");
        return;
    }
    while (1)
    {
        printf("%d ",current_node->data);
        current_node = current_node->next;
        if (current_node->next == NULL){
            printf("%d\n",current_node->data);
            break;
        }
    }
}

node_t * reverse(node_t * n){
    node_t * current_node = n;
    if (current_node == NULL){
        printf("\n");
        return n;
    }
    else if (current_node->next == NULL){
        printf("%d",current_node->data);
        return n;
    }
    list_t l = create();
    while (1){
        l.arr[l.count] = current_node->data;
        l.count++;
        current_node = current_node->next;
        if (current_node->next == NULL){
            l.arr[l.count] = current_node->data;
            break;
        }
    }
    current_node = n; // reset pointer to the starting point
    for (int i=l.count;i>=0;i--){
        current_node->data = l.arr[i];
        current_node = current_node->next;
    }
    return n;
}

node_t * cut(node_t * n){
    node_t * current_node = n;
    if (current_node == NULL){
        return n;
    }
    list_t l = create();
    while (1){
        l.arr[l.count] = current_node->data;
        l.count++;
        current_node = current_node->next;
        if (current_node->next == NULL){
            l.arr[l.count] = current_node->data;
            break;
        }
    }
    int start, end;
    scanf("%d %d",&start,&end);
    current_node = n;
    if (start == end){
        current_node->data = l.arr[start];
        current_node->next = NULL;
        return n;
    }
    while (1){
        current_node->data = l.arr[start];
        start += 1;
        current_node = current_node->next;
        if (start == end){
            current_node->data = l.arr[end];
            current_node->next = NULL;
            break;
        }
    }
    return n;
}


int main(void)
{
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf(" %c",&command);
        switch(command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'R':
            startNode = reverse(startNode);
            break;
        case 'C':
            startNode = cut(startNode);
            break;
        default:
            break;
        }
    }
    return 0;
}