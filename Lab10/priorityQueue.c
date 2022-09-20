#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
  int * data;
  int last_index;
} heap_t;

//1
heap_t * init_heap(int size) 
{
    heap_t * heap = (heap_t *)malloc(sizeof(heap_t));
    heap->data = (int *)malloc(sizeof(int) * size);
    heap->last_index = 0;
    return heap;
}

//2
void insert(heap_t * max_heap, int data)
{
    if (max_heap->last_index == 0) {
        max_heap->data[1] = data;
        max_heap->last_index++;
        return;
    }
    int i = max_heap->last_index + 1;
    max_heap->data[i] = data;
    max_heap->last_index++;
    // Loop back to the root if necessary
    int check = 1;
    while (check)             
    {
        if (i == 1) 
        {
            check = 0;
            break;
        }
        if (max_heap->data[i] > max_heap->data[i / 2])
        {
            int temp = max_heap->data[i];
            max_heap->data[i] = max_heap->data[i / 2];
            max_heap->data[i / 2] = temp;
            i = i / 2;
        }
        else
        {
            check = 0;
        }
    }
    return;
}

//3
void delete_max(heap_t * max_heap)
{
    if (max_heap->last_index == 0)
    {
        return;
    }
    else if (max_heap->last_index == 1)
    {
        max_heap->last_index--;
        return;
    }
    else
    {
        max_heap->data[1] = max_heap->data[max_heap->last_index];
        // max_heap->data[max_heap->last_index] = NULL;
        max_heap->last_index--;
        int k = 1;
        int check = 1;
        while (check)
        {
            if (max_heap->data[k] < max_heap->data[k * 2] || max_heap->data[k] < max_heap->data[k * 2 + 1])
            {
                if (max_heap->data[k * 2] > max_heap->data[k * 2 + 1])
                {
                    int temp = max_heap->data[k];
                    max_heap->data[k] = max_heap->data[k * 2];
                    max_heap->data[k * 2] = temp;
                    k = k * 2;
                }
                else
                {
                    int temp = max_heap->data[k];
                    max_heap->data[k] = max_heap->data[k * 2 + 1];
                    max_heap->data[k * 2 + 1] = temp;
                    k = k * 2 + 1;
                }
            }
            else
            {
                check = 0;
            }
        }
        return;
    }
}

//4
int find_max(heap_t * max_heap)
{
    if (max_heap->last_index == 0)
    {
        return -1;
    }
    else
    {
        return max_heap->data[1];
    }
}

//5
void update_key(heap_t * max_heap, int old_key, int new_key)
{
    int i = 1;
    while (max_heap->data[i] != old_key)
    {
        i++;
    }
    max_heap->data[i] = new_key;
    int check = 1;
    while (check)
    {
        if (i == 1)
        {
            check = 0;
            break;
        }
        if (max_heap->data[i] > max_heap->data[i / 2])
        {
            int temp = max_heap->data[i];
            max_heap->data[i] = max_heap->data[i / 2];
            max_heap->data[i / 2] = temp;
            i = i / 2;
        }
        else
        {
            check = 0;
        }
    }
    return;
}

//6
void bfs(heap_t * max_heap)
{
    int i = 1;
    while (i <= max_heap->last_index)
    {
        printf("%d ", max_heap->data[i]);
        i++;
    }
    printf("\n");
    return;
}

int main(void){
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;

    scanf("%d %d", &m, &n);

    max_heap = init_heap(m);

    for (i=0; i<n; i++){
        scanf("%d", &command);
        switch(command){
            case 1:
                scanf("%d", &data);
                insert(max_heap, data);
                break;
            case 2:
                delete_max(max_heap);
                break;
            case 3:
                printf("%d\n", find_max(max_heap));
                break;
            case 4:
                scanf("%d %d", &old_key, &new_key);
                update_key(max_heap, old_key, new_key);
                break;
            case 5:
                bfs(max_heap);
                break;
        }
    }
    return 0;
}