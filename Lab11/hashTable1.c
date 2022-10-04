#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item
{
  char *text;
  struct item *next;
} item_t;

typedef struct hash
{
  item_t **table;
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

unsigned int hash(char *text, int hash_key, int size)
{
  return f(text, strlen(text) - 1, hash_key) % size;
}

/*--------------------------------------------*/

// 1
hash_t *init_hashtable(int m, int hash_key)
{
  hash_t *hash = (hash_t *)malloc(sizeof(hash_t));
  hash->size = m;
  hash->hash_key = hash_key;
  hash->table = (item_t **)malloc(sizeof(item_t *) * m);
  for (int i = 0; i < m; i++)
  {
    hash->table[i] = NULL;
  }
  return hash;
}

// 2
void insert(hash_t *h, char * text)
{
  int index = hash(text, h->hash_key, h->size);

  // create new item
  item_t *item = (item_t *)malloc(sizeof(item_t));
  char * Word = (char *)malloc(sizeof(char)*TEXTSIZE);
  strcpy(Word,text);
  item->text = Word;
  item->next = NULL;

  // insert new item
  // no item
  if (h->table[index] == NULL)
  {
    h->table[index] = item;
  }
  // has item
  else
  {
    item_t *temp = h->table[index];
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = item;
  }
}

int search(hash_t * h, char *text)
{
  int index = hash(text, h->hash_key, h->size);
  item_t * temp = h->table[index];
  while (temp != NULL)
  {
    if (strcmp(temp->text,text) == 0)
    {
      return index;
    }
    temp = temp->next;
  }
  return -1;
}

int main(void)
{
  hash_t *hashtable = NULL;
  char *text = NULL;
  int m, n, i, hash_key;
  int command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char) * TEXTSIZE);

  for (i = 0; i < n; i++)
  {
    scanf("%d %s", &command, text);
    switch (command)
    {
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