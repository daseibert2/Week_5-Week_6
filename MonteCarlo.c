#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define exact M_PI

int main()                   //estimate to 2,4,8,and 16 decimal places
{
   int test,i,k,arc,sq;
   double x,y,z,pi,diff;

   /* initialize random numbers */
   time_t t;

   srand((unsigned)time(&t));

   for(k=2;k<=16;k+=2)
   {
        arc=0;
        sq=0;
        diff=1.0;
       // test=0;
        while(diff>pow(10,-k-1))
        {
            //test++;

            x=(double)rand()/RAND_MAX;
            y=(double)rand()/RAND_MAX;
            z=x*x+y*y;

            if(z<=1)
            {
                arc++;
            }
            sq++;

            pi=(double)4*arc/sq;

            diff=fabs(pi-exact);

            //if(test%100000000==0)
              //  printf("%d\n",test);
        }
        if(k==2||k==4||k==8||k==16)
        {
            printf("# of Points Needed to Estimate to %d decimal places: %d\n\n",k,sq);
            printf("Estimated Pi: %.20lf\n\n",pi);
            printf("Actual Pi:    %.20lf\n\n",exact);
            printf("Difference:   %.20lf\n\n\n\n",diff);
            //getch();
        }
   }

   return 0;
}
