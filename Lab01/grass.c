#include <stdio.h>

int main(void) {
  double length,width;
  printf("length(m.):\n");
  scanf("%lf",&length);
  printf("width(m.):\n");
  scanf("%lf",&width);
  printf("Use %.5lf seconds.\n",length*width*3.28084*3.28084/2.0);
  return 0;
}