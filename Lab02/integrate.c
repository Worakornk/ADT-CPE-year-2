#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    double a,b,A,B,sum=0,dx,i,Trapezoid;
    int n;
    scanf("%lf %lf %lf %lf %ld",&a,&b,&A,&B,&n);
    dx = (b-a)/n;
    for (i=0;i<n;i++){
        Trapezoid = (A*sin(M_PI*(a+dx*i)/B) + A*sin(M_PI*(a+dx*(i+1))/B)) / 2.0 * dx;
        sum += Trapezoid;
    }
    printf("%.5lf",sum);
    return 0;
}