#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000000

int Check(int x,int k){
    while (x!=0){
        if (x % 10 == k){
            return 1;
        }
        x = x/10;
    }
    return 0;
}

int main(void){
    int n, k, i, j;
    scanf("%d %d", &n, &k);
    int * player = (int*)malloc(sizeof(int) * n);
    for (i=0 ; i<n ; i++) { 
        scanf("%d", player+i); 
    } 

    j = 0;
    int count = 0, ZeroCount = 0;
    while (ZeroCount < n-1){
        for (i=0;i<n;i++) {
            if (player[i] > -1) {
                count++;
                if (count % k == 0 || Check(count, k)) {
                    player[i]--;
                }
                if (player[i] == -1) {
                    ZeroCount++;
                }
            }
            if (ZeroCount >= n-1) {
                break;
            }
        }
    }

    //     if (player[i] != 0){
    //         count += 1;
    //         if (count % k == 0 || Check(count,k)){
    //             player[i] -= 1;
    //             if (player[i] == -1){
    //                 ZeroCount += 1;   
    //             }
    //         }
    //         i++;
    //         if (i > n-1){
    //             i = 0;
    //         }
    //     } else {
    //         i++;
    //         if (i > n-1){
    //             i = 0;
    //         }
    //         continue;
    //     }
    // }


    while (n_out < n - 1) {
    for (i=0;i<n;i++) {
      if (limit[i] > -1) {
        count++;
        if (count % k == 0 || contains(count, k)) {
          limit[i]--;
        }

        if (limit[i] == -1) {
          n_out++;
        }
      }
        if (n_out >= n-1) {
          break;
        }
    }
  }
    for (i=0;i<n;i++){
        printf("%d ",player[i]);
    }
    for (i=0;i<n;i++){
        if (player[i] != 0){
            printf("%d\n",i+1);
            break;
        }
    }
    return 0;
}
