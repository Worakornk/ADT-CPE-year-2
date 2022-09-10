#include <stdio.h>
#include <stdlib.h>


void findStats(int * data, double * avg,int * maxi,int * mini,int n){
    double sum=0;
    int max=-9999999, min=9999999, length = 0,i;
    for (i = 0 ; i < n; i++){
        if (data[i] >= max){
            max = data[i];
        }
        if (data[i] <= min){
            min = data[i];
        }
        sum += data[i];
    }
    * avg = sum / n;
    * maxi = max;
    * mini = min;
}

int main(void){
    int n, i, maxi, mini;
    double avg;
    int * nums;

    scanf("%d", &n);
    nums = (int *)malloc(sizeof(int) * n);
    for (i=0; i<n; i++)
        scanf("%d", nums + i);
    findStats(nums,&avg,&maxi,&mini,n);
    printf("%.2f %d %d", avg, maxi, mini);

    return 0;
}

// int main(void){
//     int n, i, maxi, mini;
//     double avg;
//     int * nums;

//     scanf("%d", &n);
//     nums = (int *)malloc(sizeof (int) * n);
//     for (i=0; i<n; i++)
//         scanf("%d", nums + i);
//     findStats(nums);
//     printf("%.2f %d %d", avg, maxi, mini);
//     return 0;
// }