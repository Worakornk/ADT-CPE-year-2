#include <stdio.h>
#include <stdlib.h>

char ps[1000000] = {'\0'};

typedef struct node
{
    int frequency;
    char str[30];
    struct node *left;
    struct node *right;
} node_t;

typedef struct heap
{
    node_t **data;
    int last_index;
} heap_t;

heap_t *init_heap(int m)
{
    heap_t *new_heap = (heap_t *)malloc(sizeof(heap_t));
    new_heap->last_index = 0;
    new_heap->data = (node_t **)malloc(sizeof(node_t *) * (m + 1));
    // printf("adgaskdfgnvasdk");
    return new_heap;
}

void sw(node_t **a, node_t **b)
{
    node_t *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void up(heap_t *h, int idx)
{
    while (1)
    {
        if (idx == 1)
        {
            return;
        }
        if (h->data[idx]->frequency < h->data[idx / 2]->frequency)
        {
            sw(&(h->data[idx]), &(h->data[idx / 2]));
            idx /= 2;
        }
        else
        {
            return;
        }
    }
}

void down(heap_t *h, int idx)
{
    while (1)
    {
        if (idx >= h->last_index)
        {
            return;
        }
        if (((idx * 2 <= h->last_index) && h->data[idx]->frequency > h->data[idx * 2]->frequency) || ((idx * 2 + 1 <= h->last_index) && h->data[idx]->frequency > h->data[idx * 2 + 1]->frequency))
        {
            if (h->data[idx * 2]->frequency <= h->data[idx * 2 + 1]->frequency)
            {
                sw(&h->data[idx], &h->data[idx * 2]);
                idx = idx * 2;
            }
            else
            {
                sw(&h->data[idx], &h->data[idx * 2 + 1]);
                idx = idx * 2 + 1;
            }
        }
        else
        {
            return;
        }
    }
}

void insert(heap_t *h)
{
    h->last_index++;
    int idx = h->last_index;
    // printf("acfasdc");
    node_t *t = (node_t *)malloc(sizeof(node_t));
    scanf("%s", t->str);
    scanf("%d", &t->frequency);
    t->left = NULL;
    t->right = NULL;
    h->data[idx] = t;
    up(h, idx);
}
void insertn(heap_t *h, node_t *t)
{
    h->last_index++;
    int idx = h->last_index;
    h->data[idx] = t;
    up(h, idx);
}

void delete_max(heap_t *h)
{
    h->data[1] = h->data[h->last_index];
    h->last_index--;
    int idx = 1;
    down(h, idx);
}

node_t *find_max(heap_t *h)
{
    return h->last_index >= 1 ? h->data[1] : NULL;
}

// void update_key(heap_t *h, int o, int n)
// {
//     int idx = 0;
//     while (h->data[idx] != o)
//     {
//         idx += 1;
//     }

//     h->data[idx] = n;
//     if (n > o)
//     {
//         up(h, idx);
//     }
//     else
//     {
//         down(h, idx);
//     }
// }

void bfs(heap_t *t)
{
    int i = 1;
    for (i = 1; i <= t->last_index; i++)
    {
        printf("%s %d.  ", t->data[i]->str, t->data[i]->frequency);
    }
    printf("\n");
}

void dfs(node_t *t, int d)
{
    if (t == NULL)
    {
        return;
    }
    ps[d] = '0';
    dfs(t->left, d + 1);
    ps[d] = '1';
    dfs(t->right, d + 1);

    if (t->str[0] != '\0')
    {
        printf("%s: ", t->str);
        int i;
        for (i = 0; i < d; i++)
        {
            printf("%c", ps[i]);
        }
        printf("\n");
    }
}

void print_tree_2(node_t *t, int depth, char pre)
{
    int i;

    if (t == NULL)
        return;
    for (i = 0; i < depth; i++)
        printf("    ");
    printf("%c%d%s\n", pre, t->frequency, t->str);
    print_tree_2(t->left, depth + 1, 'L');
    print_tree_2(t->right, depth + 1, 'R');
}

void print_tree(node_t *t)
{
    print_tree_2(t, 0, 'r');
}

int main(void)
{
    heap_t *min_heap = NULL;
    int n, i;
    int command;
    

    scanf("%d", &n);
    min_heap = init_heap(100005);

    for (i = 0; i < n; i++)
    {
        insert(min_heap);
    }
    while (min_heap->last_index != 1)
    {
        node_t *tmp1, *tmp2;
        tmp1 = find_max(min_heap);
        delete_max(min_heap);
        tmp2 = find_max(min_heap);
        delete_max(min_heap);

        node_t *new = (node_t *)malloc(sizeof(node_t));
        new->frequency = tmp1->frequency + tmp2->frequency;
        new->left = tmp1;
        new->right = tmp2;
        new->str[0] = '\0';
        insertn(min_heap, new);
    }
    dfs(min_heap->data[1], 0);

    return 0;
}