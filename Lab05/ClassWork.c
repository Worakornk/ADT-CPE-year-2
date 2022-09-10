#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000

typedef struct list {
  int *arr;
  int count;
} list_t;

list_t create(){
  list_t l = {NULL, 0};
  l.arr = (int *)malloc(sizeof(int) * MAXSIZE);
  return l;
}



int insert(list_t *l, int v, int p){
  int i = 0;
  if (l->count == MAXSIZE){         // list is full
    return 0;
  }
  if (p < 0 || p > MAXSIZE-1){      // out of range 
    return 0;
  }
  if (p < l->count){                // shift right
    for (i=l->count;i>p;i--){
      l->arr[i] = l->arr[i-1];
    }
    l->arr[p] = v;
  }
  else{                             // insert at the end of list
    l->arr[l->count] = v;
  }
  l->count++;
  return 1;
}



int main(void){
  list_t  l = create();
  insert(&l, 10, 0);
  return 0;
}






