#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_anagram(char a[], char b[])
{
    int first_word_list[26] = {0}, second_word_list[26] = {0};

    // Calculating frequency of character of the string
    int i = 0;
    while (a[i] != '\0')
    {
        first_word_list[a[i] - 'a']++;
        i++;
    }
    i = 0;
    while (b[i] != '\0')
    {
        second_word_list[b[i] - 'a']++;
        i++;
    }
    // Computing the frequency of characters
    for (i = 0; i < 26; i++)
    {
        if (first_word_list[i] != second_word_list[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n_words, n_search;
    scanf("%d %d", &n_words, &n_search);
    int i;
    char **list_word = (char **)malloc(sizeof(char *) * n_words);
    for (i = 0; i < n_words; i++)
    {
        list_word[i] = (char *)malloc(sizeof(char) * 51);
        scanf("%s",list_word[i] );
    }
    for (i = 0; i < n_search; i++)
    {
        char Input[1000];
        scanf("%s", Input);
        for (int j = 0; j < n_words; j++)
        {
            char c[1000];
            strcpy(c, list_word[j]);
            if (check_anagram(Input, c) == 1)
            {
                printf("%s ", list_word[j]);
            }
        }
        printf("\n");
    }

    return 0;
}