#include <stdio.h>
#include <string.h>

int getCharValue(char *s, int idx) {
    if (idx < strlen(s))
        return s[strlen(s) - idx - 1] - 48; 
    return 0;
}

int main(){
    char ans[10000];
    char a[10000];
    scanf("%s",a);
    char b[10000];
    scanf("%s",b);
    
    int i, wa = strlen(a), wb = strlen(b),width,sum,carry;
    width = wa > wb ? wa : wb;

    for (i = 0 ; i < width; i++){
        char ca = getCharValue(a, i);
        char cb = getCharValue(b, i);
        sum = ca + cb + carry; // carry from the last digit calculation
        carry = 0;
        if (sum > 9){
            carry = 1;
            sum -= 10;
        }
        ans[i] = sum + 48;
    }
    if (carry) ans[i++] = carry + 48;
    ans[i] = 0;

    for (i = 0; i < strlen(ans) / 2; i++) {
        char t = ans[i];
        ans[i] = ans[strlen(ans) - i - 1]; 
        ans[strlen(ans) - i - 1] = t;
    }
    printf("%s",ans);
}