#include<stdio.h>

typedef struct datetime {
  int date; // 1-31
  int month; // 1-12
  int year; // 1970++
  int dayOfWeek; //0-6
  int hour; //0-23
  int minute; //0-59
  int second; //0-59
} datetime_t;

int isleap(int y){
    return (y%4==0 && y%100!=0) || y%400==0;
}

datetime_t createDate(unsigned int timestamp) {
  int totalSecwoD = timestamp%(60*60*24),year=1970,month = 1,dayOfWeek=4,hour=0,minute=0,second=0;
  int totalDays = timestamp/(60*60*24) + 1;
  int DaysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int DaysInMonth2[] = {31,29,31,30,31,30,31,31,30,31,30,31};
  int i,j;

  dayOfWeek = (totalDays+4) % 7;

  if (totalDays>365){
    for (;1;++year){
      if(totalDays<365+isleap(year)){
        break;
      } else {
        totalDays -= 365+isleap(year);
      }
    }
  }
  
  for (j = 0 ; j < 12 ; j++){
    if (totalDays-DaysInMonth[j] <= 0){
      month = j;
      break;
    }
    if (isleap(year) == 1){
        totalDays -= DaysInMonth2[j];
    } else {
      totalDays-=DaysInMonth[j];
    }
  }

  hour = totalSecwoD/3600;
  minute = (totalSecwoD%3600)/60;
  second = (totalSecwoD%3600)%60;
  
  if (totalDays>31){
    totalDays = 31;
  }
  datetime_t data = {totalDays,month,year,dayOfWeek,hour,minute,second};
  return data;
}

void printDate(datetime_t d) {
  char* months[] = {"NULL","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
  char* days[] = {"NUL","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
  printf("%s %d %s %d %02d:%02d:%02d\n",days[d.dayOfWeek],d.date,months[d.month+1],d.year,d.hour,d.minute,d.second);
}

int main() {
  datetime_t inputDate;
  int timestamp;
  scanf("%d",&timestamp);
  inputDate = createDate(timestamp);
  printDate(inputDate);
  return 0;
}