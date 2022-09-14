#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void main(int argc, char* argv[])
{
    double time_spent = 0.0;
    clock_t begin = clock();
    double niter = 1000000000;
    double x,y;
    int i;
    int count=0;
    double z;
    double pi;
    srand(time(NULL));
    //main loop
    for (i=0; i<niter; ++i)
    {
        //get random points
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        z = sqrt((x*x)+(y*y));
        //check to see if point is in unit circle
        if (z<=1)
        {
            ++count;
        }
    }
    pi = ((double)count/(double)niter)*4.0;          //p = 4(m/n)
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Pi: %f\n", pi);
    printf("The elapsed time is %f seconds\n", time_spent);
}