#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char * item_t;

typedef struct hash {
  item_t * table;
  int size;
  int hash_key;
} hash_t;

/*--------------------------------------------*/

unsigned int f(char *text, int n, int hash_key)
{
  if (n == 0)
  {
    return text[0];
  }
  return (f(text, n - 1, hash_key) * hash_key + text[n]);
}

// Implicit Rule
unsigned int hash(char *text, int hash_key, int size)
{
  return f(text, strlen(text) - 1, hash_key) % size;
}

// Collision Resolution Function : Quadratic Probing (size 2^n)
int F(int i)
{
  return (i + i*i)/2;
}

/*--------------------------------------------*/

//1
hash_t * init_hashtable(int m, int hash_key)
{
  hash_t * hash = (hash_t *)malloc(sizeof(hash_t));
  hash->size = m;
  hash->hash_key = hash_key;
  hash->table = (item_t *)malloc(sizeof(item_t) * m);
  int i;
  for (i = 0; i < m; i++)
  {
    hash->table[i] = NULL;
  }
  return hash;
}

//2
void insert(hash_t * h, char * text)
{
  unsigned int index = hash(text,h->hash_key,h->size);
  if (h->table[index] == NULL)
  {
    h->table[index] = (item_t)malloc(sizeof(item_t) * TEXTSIZE);
    strcpy(h->table[index],text);
  }
  else 
  {
    int i = 1;
    while (h->table[(index + F(i)) % h->size] != NULL)
    {
      i++;
    }
    h->table[(index + F(i)) % h->size] = (item_t)malloc(sizeof(item_t) * TEXTSIZE);
    strcpy(h->table[(index + F(i)) % h->size],text);
  }
}


//3
int search(hash_t *desk, char *text)
{
    unsigned int hashed = hash(text, desk->hash_key, desk->size);
    int found = 0;
    int temp = 0;
    int x;
    if (desk->table[hashed] != NULL && !strcmp(desk->table[hashed], text))
    {
        return hashed;
    }
    else
    {
        int i = 0;
        int summation = (desk->size - 1) * (desk->size) / 2;
        while (summation > temp)
        {
            temp += (hashed + F(i)) % desk->size;
            if (desk->table[(hashed + F(i)) % desk->size] != NULL)
            {
                if (strcmp(text, desk->table[(hashed + F(i)) % desk->size]) == 0)
                {
                    found = 1;
                    x = (hashed + F(i)) % desk->size;
                    break;
                }
            }
            i++;
        }
    }
    if (found)
    {
        return x;
    }
    return -1;
}

int main(void) {
  hash_t *hashtable = NULL;
  char *text = NULL;
  int m, n, i, hash_key;
  int command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char) * TEXTSIZE);

  for (i = 0; i < n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
    case 1:
      insert(hashtable, text);
      break;
    case 2:
      printf("%d\n", search(hashtable, text));
      break;
    }
  }
  return 0;
}