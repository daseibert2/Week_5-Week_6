#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int n=3;

int randInt( int min, int max )
{
  return ((rand()*(max-min+1))/(RAND_MAX+1) + min) ;
}

void printMatrix(a[n][n])
{
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
           printf("%d ",a[i][j]);;
       }
       printf("\n");
    }
}

void ijk(int a[n][n],int b[n][n],int c[n][n])
{
    int i,j,k;

    double sum;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum=0.0;
            for(k=0;k<n;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
}

void jik(int a[n][n],int b[n][n],int c[n][n])
{
    int i,j,k;

    double sum;

    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            sum=0.0;
            for(k=0;k<n;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
}

void kij(int a[n][n],int b[n][n],int c[n][n])
{
    int i,j,k;

    double r[n][n];

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            r=a[i][k];
            for(j=0;j<n;i++)
            {
                c[i][j]+=r*b[k][j];
            }
        }
    }
}

void ikj(int a[n][n],int b[n][n],int c[n][n])
{
    int i,j,k;

    double r[n][n];

    for(i=0;i<n;i++)
    {
        for(k=0;k<n;k++)
        {
            r=a[i][k];
            for(j=0;j<n;i++)
            {
                c[i][j]+=r*b[k][j];
            }
        }
    }
}

void jki(int a[n][n],int b[n][n],int c[n][n])
{
    int i,j,k;

    double r[n][n];

    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            r=b[k][j];
            for(i=0;i<n;i++)
            {
                c[i][j]+=a[i][k]*r;
            }
        }
    }
}

void kji(int a[n][n],int b[n][n],int c[n][n])
{
    int i,j,k;

    double r[n][n];

    for(k=0;k<n;k++)
    {
        for(j=0;j<n;j++)
        {
            r=b[k][j];
            for(i=0;i<n;i++)
            {
                c[i][j]+=a[i][k]*r;
            }
        }
    }
}

int main()
{
    int i,j,count1=0;

    int a[n][n],b[n][n],c[n][n];

    time_t t;

    printf("Enter value of N for number of rows and columns: ");
    scanf("%d",&n);

    /* Initialize the random number generator */
    srand( time(&t));

    for(i=0;i<n;i++)  //filling arrays
    {
       for(j=0;j<n;j++)
       {
           a[i][j]=randInt(0,9);
           b[i][j]=randInt(0,9);
           c[i][j]=randInt(0,9);
       }
       printf("\n");
    }

    printf("\n\nInitial A Matrix:\n\n %d ",a[i][j]);
    printMatrix(a);
    printf("\n\nInitial B Matrix:\n\n %d ",b[i][j]);
    printMatrix(b);
    printf("\n\nInitial C Matrix:\n\n %d ",c[i][j]);
    printMatrix(c);

    FILE *ijk;
    FILE *jik;
    FILE *kij;
    FILE *ikj;
    FILE *jki;
    FILE *kji;
    ijk=fopen("ijk.csv","w");
    jik=fopen("jik.csv","w");
    kij=fopen("kij.csv","w");
    ikj=fopen("ikj.csv","w");
    jki=fopen("jki.csv","w");
    kji=fopen("kji.csv","w");



    return 0;
}
