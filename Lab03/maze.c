#include<stdio.h>


int size;
char maze[100][100];
char visit[100][100];
int walkrow[]={1,0,-1,0};
int walkcol[]={0,1,0,-1};
int succeed=0;


void main(){
    int i,j,s=0;
    scanf("%d\n",&size);
    for (s; s<size ;s++)
    {
        fgets(maze[s], 100, stdin);
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if (maze[i][j]=='S')
            {
                traverseMaze(i,j);
            }
        }
    }
    for (i=0;i<size;i++){
        printf("%s",maze[i]);
    }
}


void traverseMaze(int i,int j){
    int t;
    if (i<0||i>=size||j<0||j>=size)
    {   
        return;
    }
    if (maze[i][j]=='#')
    {
        return;
    }
    if (visit[i][j]==1)
    {
        return;
    }
    if (maze[i][j]=='G')
    {   
        succeed=1;
        return;
    }
    visit[i][j]=1;
    for (t=0;t<4;t++){
        traverseMaze(i+walkrow[t],j+walkcol[t]);
        if (succeed)
        {   
            if (maze[i][j]=='S'){
                break;
            }else{
                maze[i][j]='.';
                return ;
            }
        }
    }
}