#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double Pow(double x,int n){
    double ans = 1;
    int i;
    if (n == 0){
        return 1.0;
    }
    for (i=0;i<n;i++){
        ans = ans * x;
    }
    return ans;
}

double fac(int x){
    if (x == 0){
        return 1.0;
    }
    return x*fac(x-1);
}

double Sin(double x){
    double Ans = 0;
    int i;
    for (i=1;i<=10;i++){
        if (i%2==1){
            Ans += Pow(x,1+(i-1)*2)/fac(1+(i-1)*2);
        }
        else {
            Ans += Pow(x,1+(i-1)*2)*(-1)/fac(1+(i-1)*2);
        }
    }
    return Ans;
}

double Cos(double x){
    return sqrt(1-Pow(Sin(x),2));
}

double Tan(double x){
    return Sin(x)/Cos(x);
}

int main(){
    double degree, rad;
    scanf("%lf",&degree);
    rad = M_PI * degree / 180;
    printf("%.14lf %.14lf %.14lf",Sin(rad),Cos(rad),Tan(rad));
    return 0;
}
