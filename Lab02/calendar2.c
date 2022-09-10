#include <stdio.h>

char *days[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
char *months[] ={ "January", "February","March","April","May","June","July","August","September","October","November","December" };
int DaY[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(void) {
  int d=1,y,m, first_day=0;

  printf("Enter year: ");
  scanf("%d",&y);
  printf("Enter month: ");
  scanf("%d",&m);  
  printf("====================\n");
  printf("%s %d\n",months[m-1],y);
   for (int i=0;i<7;i++){
    printf("%s\t",days[i]);
  }
  printf("\n");
  int weekday  = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7; 
  for(int i = 0; i < weekday ; i ++ ) {
      printf("\t");
  }
  for(int i = 0; i <= DaY[m-1]; i++) {
    if (i==0) continue;
    printf("%3d", i);
    if((i + weekday)%7 > 0)
    {
        printf("\t");
    } 
    else 
    {
        printf("\n");
    }
  }
  return 0;
}