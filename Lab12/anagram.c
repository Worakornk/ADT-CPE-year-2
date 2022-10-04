#include <stdio.h>

void main(){
    int m,check;
    scanf("%d %d",&m &check);
    char List_Word[m];
    int i;
    for ( i=0 ; i<m ; i++)
    {

    }

    return 0;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

/*
>>> Case1
-input-
8 3
final
fnali
fnial
fianl
title
ttile
tilte
equal
fanil
reply
title
-output-
final fnali fnial fianl 

title ttile tilte 

>>> Case2


