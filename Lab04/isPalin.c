#include <stdio.h>
#include <stdlib.h>
int isPalin(char* text, int beginPos, int endPos){
    if(beginPos == endPos){
        return 1;
    }
    else if(beginPos +1 == endPos){
        return text[beginPos] == text[endPos];
    }
    else if (text[beginPos] != text[endPos]);{
        return 0;
    }
    return isPalin(text,beginPos + 1, endPos-1);
}

int main(){
    int length;
    char* text;
    scanf("%d",&length);
    text = (char*)malloc(sizeof(char)*(length+1));
    scanf("%s",text);
    printf("%d\n",isPalin(text,0,length-1));
    return 0;
}