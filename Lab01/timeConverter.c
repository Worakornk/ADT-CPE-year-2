#include <stdio.h>
int main(){
    int Time,d=0,h=0,m=0,s=0;
    scanf("%d",&Time);
    d += Time/86400;
    h += (Time-d*86400)/3600;
    m += (Time-d*86400-h*3600)/60;
    s += (Time-d*86400-h*3600-m*60);
    printf("%d %d %d %d\n",d,h,m,s);
    return 0;
}