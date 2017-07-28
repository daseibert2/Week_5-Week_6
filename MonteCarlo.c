#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define exact M_PI
#define it (pow(10,30))

int main()                   //estimate to 2,4,8,and 16 decimal places
{
   int i,k,arc,sq;
   double x,y,z,pi,diff;

   /* initialize random numbers */
   //time_t t;

   //srand(&t);

   for(k=2;k<=16;k+=2)
   {
        arc=0;
        sq=0;

        for(i=0;i<it;i++)
        {
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
            if(diff<pow(10,-k-1))
            {
                break;
            }

        }
        if(k==2||k==4||k==8||k==16)
        {
            printf("# of Points Needed to Estimate to %d decimal places: %d\n\n",k,sq);
            printf("Estimated Pi: %.20lf\n\n",pi);
            printf("Actual Pi:    %.20lf\n\n",exact);
            printf("Difference:   %.20lf\n\n\n\n",diff);
        }
   }

   return 0;
}
