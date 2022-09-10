#include <stdio.h>

int main(){
    double Weight, Height, BMI=0;
    scanf("%lf %lf", &Weight, &Height);
    BMI += Weight/((Height/100)*(Height/100));
    if (BMI >= 30) {
        printf("BMI: %.4lf and you are obese\n",BMI);
    } else if (BMI >= 25) {
        printf("BMI: %.4lf and you are overweight\n",BMI);
    } else if (BMI >= 18.6) {
        printf("BMI: %.4lf and you are healthy\n",BMI);
    } else if (0 <= BMI < 18.6) {
        printf("BMI: %.4lf and you are underweight\n",BMI);
    }
    return 0;
}
