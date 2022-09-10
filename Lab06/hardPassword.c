#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Palindrome(char *A, char *B) {
  if (strlen(A) != strlen(B)) {
    return 0;
  } else {
    int indA = 0, indB = strlen(B) - 1;
    while (1) {
      if (indA == strlen(A) || indB == 0) {
        break;
      }
      if (A[indA] == B[indB]) {
        indA++;
        indB--;
      } else {
        return 0;
      }
    }
  }
  return 1;
}

int main(void) {
  char password[10000], *A = "", *B = "";
  int startY;
  scanf("%[^\n]%*c", password);

  char *x,*y;
  x = strchr(password, 'x');
  y = strchr(password, 'y');

  if ((x!=NULL) && (y!=NULL)) {
    A = strtok(password,"x");
    B = strtok(NULL, "y");
    int check = Palindrome(A, B);
    printf("%d", check);
  } else {
    printf("%d",0);
  }
}