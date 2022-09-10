#include <stdio.h>

int main()
{
    int col = 4,row =4;
    int **matrix = (int **)malloc(col * sizeof(int *) * col);
    for (int i = 0; i < row;i++){
        matrix[i] = (int *)malloc(col * sizeof(int));
    }


}

poi