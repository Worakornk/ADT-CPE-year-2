#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int data;
    int mem_addr;
} cell_t;

typedef struct hash
{
    cell_t *table;
    int cache_size;
} hash_t;

typedef hash_t cache_t;
typedef int memory_t;

memory_t *init_memory(int size)
{
    memory_t *memory = (memory_t *)malloc(sizeof(memory_t) * size);
    int i = 0;
    for (i = 0; i < size; i++)
    {
        memory[i] = rand();
    }
    return memory;
}

unsigned int Cache_index(int memory_addr, int cache_size)
{
    return memory_addr % cache_size;
}

cache_t *init_cache(int cache_size)
{
    cache_t * cache = (cache_t *)malloc(sizeof(cache_t));
    cache->cache_size = cache_size;
    cache->table = (cell_t *)malloc(sizeof(cell_t) * cache_size);
    int i = 0;
    for (i = 0; i < cache_size; i++)
    {
        cache->table[i].data = 0;
        cache->table[i].mem_addr = -1;
    }
    return cache;
}

void get_data(int addr, memory_t * memmory, cache_t *cache)
{
    int i = 0, j = 0;
    int index = cache_index(addr, cache->cache_size);
    if (memmory[addr] == cache->table[index].data)
    {
        printf("Address %d is loaded\n", addr);
    }
    else
    {
        if (cache->table[index].data == -1 && cache->table[index].mem_addr == -1)
        {
            printf("Load from memory\n");
        }
        else
        {
            printf("Index: %d is used\n", index);
            printf("Load from memory\n");
        }
        cache->table[index].data = memmory[addr];
        cache->table[index].mem_addr = addr;
    }
    printf("Data: %d\n", cache->table[index].data);
}


int main(void)
{
    memory_t *memory = NULL;
    cache_t *cache = NULL;
    int memory_size, cache_size;
    int i, n, addr;

    scanf("%d %d %d", &memory_size, &cache_size, &n);
    memory = init_memory(memory_size);
    cache = init_cache(cache_size);

    for (i = 0; i < n; i++)
    {
        printf("Load address: ");
        scanf("%d", &addr);
        get_data(addr, memory, cache);
    }
    return 0;
}