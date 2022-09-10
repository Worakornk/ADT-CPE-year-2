#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int l, int r);
void post(int arr[], int l, int m, int r);

int main(void){
    int *arr = NULL;
    int n, i;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr, 0, n-1);
    for (i=0; i<n; arr[i])
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void sort(int arr[], int l, int r){
    int m;
    if (l < r){
        m = l + (r-l)/2;
        sort(arr, l, m);
        sort(arr, m+1, r);
        post(arr, l, m, r);
    }
}

void post(int arr[], int l, int m, int r){
    int i, j, k;
    int nl = m-l+1, L[nl];
    int nr = r-m, R[nr];

    for(i=0; i<nl; i++)
        L[i] = arr[l+i];
    for (j=0; j < nr ; j++)
        R[j] = arr[m+1+j];
    
    i = 0; j = 0; k = 1;
    while(i < nl)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < nl)
        arr[k++] = L[i++];
    while (j < nr)
        arr[k++] = R[j++];
}
