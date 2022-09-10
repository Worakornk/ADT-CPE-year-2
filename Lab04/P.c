#include <stdio.h>
int count = 0;
int P(int x,int n){
    int y;
    if (n == 0){
        count += 1;
        return 1;
    }
    if (n%2==1){
        count += 1;
        y = P(x,(n-1)/2);
        return x*y*y;
    } else {
        count += 1;
        y = P(x,n/2);
        return y*y;
    }

}


int main(void){
    int x,n;
    scanf("%d %d",&x,&n);
    printf("%d\n", P(x,n));
    printf("%d",count);
    return 0;
}