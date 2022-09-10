#include <stdio.h>
#include <string.h>  

// use recursion function
void revstr(char *str1)
{
    static int i, len, temp;
    len = strlen(str1); 

    if (i < len / 2)
    {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
        i++;
        revstr(str1); 
    }
}

int main()
{
    char str1[100000];
    gets(str1); 

    revstr(str1);
    char * token = strtok(str1, " ");
    while( token != NULL ) {
      printf( "%s ", strrev(token) ); //printing each token
      token = strtok(NULL, " ");
   }
   return 0;
}