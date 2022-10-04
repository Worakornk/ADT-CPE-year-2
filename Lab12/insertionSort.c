#include <stdio.h>
/*
case 1 :
8
4 3 2 10 12 1 5 6

case 2 :
9
54 26 93 17 77 31 44 55 20

case 3 :
16 
9 15 8 1 4 11 7 12 13 6 5 3 16 2 10 14
*/
void printArray(int arr[], int n);
void insertionSort(int arr[], int n);

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertionSort(a,n);
    return 0;
}

void printArray(int a[], int n)
{
    int i;
    for ( i=0 ; i<n ; i++ )
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i<n;i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = key;
        printArray(a,n);
    }
}
  


