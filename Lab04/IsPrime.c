#include <stdio.h>
#include <math.h>

int main(){
    int m,i,n=0,isPrime = 1;
    scanf("%d",&n);
    m = pow(n,0.5);
    if (n <= 1){ 
        isPrime = 0;
    
    else {
        for (i=2;i<=m;i++){
        if (n%i==0){
            isPrime = 0;
            break;
        }
        }
    }
    printf("%d",isPrime); 
    return 0; 
}
// Big-oh Notation is : O(N**0.5)