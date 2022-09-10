#include <stdio.h>
#include <math.h>

int main(){
    int n,checkD=1;
    double distance = 0,horizontal = 0,vertical = 0;
    scanf("%d",&n);

    char inputChar[n];
    scanf("%s", &inputChar);

    char *p = inputChar;

    while (*p != '\0') {
        printf ("%c ", *p);

        if (*p == 'L'){
            checkD -= 1;
        }
        if (*p == 'R'){
            checkD += 1;
        }





        p++; 
    }



    return 0;
}

