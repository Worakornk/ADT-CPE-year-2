#include <stdio.h>
#include <string.h>
#include <math.h>

// FFRFFRFLFRFFRFLFRF
// RRRR
int main() {
  int x1=0,y1=0,x2=0,y2=0;
  int x=1,y=0;
  int input=0;
  double distance=0.0;
  char current='E';
  printf("");
  scanf("%d\n",&input);
  char moves[input];
  scanf("%s",moves);

  for (int i=0; i<strlen(moves);i++) {
    if (moves[i] == 'F') {
      x2+=x;
      y2+=y;
    } 
    else if (moves[i] == 'L' || moves[i] == 'R') {
      if (current=='E') {
        if (moves[i] == 'L') {  
          x=0;
          y=1; 
          current='N';
        }
        else if (moves[i] == 'R') {
          x=0;
          y=-1;
          current='S';
        }
      } 
      else if (current=='W') {
        if (moves[i] == 'L') {
          x=0;
          y=-1;
          current='S';
        }
        else if (moves[i] == 'R') {
          x=0;
          y=1; 
          current='N';
        }
      } 
      else if (current=='N') {
        if (moves[i] == 'L') {
          x=-1;
          y=0; 
          current='W';
        }
        if (moves[i] == 'R') {
          x=1;
          y=0; 
          current='E';
        }
      } 
      else if (current=='S') {
        if (moves[i] == 'L') {
          x=1;
          y=0;
          current='E';
        }
        if (moves[i] == 'R') {
          x=-1;
          y=0; 
          current='W';
        }
      }
    }
  }
  distance = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
  // printf("%d %d %d %d\n",x1,y1,x2,y2);
  printf("%.4lf",distance);
  return 0;
}