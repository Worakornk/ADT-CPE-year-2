#include <stdio.h>
#include <math.h>

int planner(int m, int n){
    if (n < m){
        return planner(n,m);
    }
    int count = 0,i,area,pow2;
    if (m == 0 || n ==0){
        return 0;
    }
    else if (m == 1 || n == 1){
        return m*n;
    }
    area = m * n;
    // find highest possible i; for i in 2^i
    for (i = 0; i <= 20; i ++){
        if (pow(2,i) == m){
            break;
        }
        else if (pow(2,i)>m){
            i -= 1;
            break;
        }
    }
    pow2 = pow(2,i);
    count += 1;
    return count + planner(n-pow2,pow2) + planner(m-pow2,n);
}

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d",planner(m,n));
    return 0;
}










// int Planner(int m,int n,int i){
//     int count = 0;
//     if (m % 2 ==1){
//         count += 1 * n;

//     }


    
// }

// int main()
// {
//     int i, j, m, n, totalArea=0, countLand=0;
//     printf("Enter m x n : ");
//     scanf("%d %d", &m, &n);
//     totalArea = m * n;
//     printf("Total area is %d\n", totalArea);
//     // find max 2^i
//     for (i = 0; i <= 100; i++)
//     {
//         if (pow(2, i) == totalArea)
//         {
//             i = 1;
//             break;
//         }
//         else if (pow(2, i) > totalArea)
//         {
//             i -= 1;
//             break;
//         }
//     }
    
//     // contunuously reduce value of i while checking for area
//     for (j = i; j >= 0; j--)
//     {
//         int p;
//         p = pow(2, j);
//         if (p > totalArea){
//             continue;
//         }
//         else if (j == 0){
//             countLand += totalArea;
//             break;
//         }
//         countLand += (totalArea - (totalArea%p))/p;
//         totalArea -= (totalArea - (totalArea%p));
//     }
//     printf("%d", countLand);
//     return 0;
// }