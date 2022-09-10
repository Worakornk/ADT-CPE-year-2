#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char Sentense[100][100];
    int i, j, cnt;
    scanf("%[^\n]s", str);
    j = 0;
    cnt = 0;
    for (i = 0; i <= (strlen(str)); i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            Sentense[cnt][j] = '\0';
            cnt++;
            j = 0; 
        }
        else {
            Sentense[cnt][j] = str[i];
            j++;
        }
    }
    for (i = cnt; i >= 0; i--)
        printf("%s", Sentense[i]);
    
    return 0;
}