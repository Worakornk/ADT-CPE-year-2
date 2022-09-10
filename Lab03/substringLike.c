/*
18 3 0
acabababababcbabab
aba

15 4 2
AAAGTGTGTCTGATT
GTAT

18 3 1
acabababababcabbab
abc

18 3 1
acabababababcbabab
aba
*/

#include <stdio.h>
#include <stdlib.h>

int substring(char a[], char b[], int p, int n)
{
    int status = 1;
    int i, count = 0;
    for (i = 0; i < p; i++)
    {
        if (a[i] != b[i])
        {
            a[i] = '?';
            count += 1;
        }
    }
    // printf("count= %d ",count);
    if (count > n)
    {
        status = 0;
    }
    return status;
}

void main()
{
    int m, p, n;
    char *a, *b, *cut;
    scanf("%d %d %d", &m, &p, &n);
    a = (char *)malloc(sizeof(char) * m);
    b = (char *)malloc(sizeof(char) * p);
    cut = (char *)malloc(sizeof(char) * p);

    scanf("%s", a);
    scanf("%s", b);
    for (int j = 0; j < m; j++)
    {
        if (j + p > m)
        {
            printf("%c", a[j]);
            continue;
        }
        for (int i = 0; i < p; i++)
        {
            cut[i] = a[i + j];
        }
        // printf("%s\n",cut);
        if (substring(cut, b, p, n))
        {
            printf("[%s]", cut);
            j += p - 1;
        }
        else
        {
            printf("%c", a[j]);
        }
    }
    free(a);
    free(b);
}
