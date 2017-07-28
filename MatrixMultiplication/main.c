#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int n=3;

clock_t start_t,end_t,total_t;

void printMatrix(int s[n][n])
{
    int i,j;

    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
           printf("%d ",s[i][j]);
       }
       printf("\n");
    }
}

double ijk_1(int a[n][n],int b[n][n],int c[n][n])
{
    start_t=clock();
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
    end_t=clock();

    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;

    //printf("%lf\n\n\n",total_t);

    return total_t;
}

double jik_1(int a[n][n],int b[n][n],int c[n][n])
{
    start_t=clock();
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
    end_t=clock();

    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;

    return total_t;
}

double kij_1(int a[n][n],int b[n][n],int c[n][n])
{
    start_t=clock();
    int i,j,k;

    double r;

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            r=a[i][k];
            for(j=0;j<n;j++)
            {
                c[i][j]+=r*b[k][j];
            }
        }
    }
    end_t=clock();

    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;

    return total_t;
}

double ikj_1(int a[n][n],int b[n][n],int c[n][n])
{
    start_t=clock();
    int i,j,k;

    double r;

    for(i=0;i<n;i++)
    {
        for(k=0;k<n;k++)
        {
            r=a[i][k];
            for(j=0;j<n;j++)
            {
                c[i][j]+=r*b[k][j];
            }
        }
    }
    end_t=clock();

    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;

    return total_t;
}

double jki_1(int a[n][n],int b[n][n],int c[n][n])
{
    start_t=clock();
    int i,j,k;

    double r;

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
    end_t=clock();

    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;

    return total_t;
}

double kji_1(int a[n][n],int b[n][n],int c[n][n])
{
    start_t=clock();
    int i,j,k;

    double r;

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
    end_t=clock();

    total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;

    return total_t;
}

int main()
{
    int i,j,w,h,test,num=0;
    int a[n][n],b[n][n],c[n][n];
    double IJK[800],JIK[800],KIJ[800],IKJ[800],JKI[800],KJI[800];
    /*char tests[6]=["ijk","jik","kij","ikj","jki","kji"];
    char ans[6]=["IJK","JIK","KIJ","IKJ","JKI","KJI"];*/

    printf("Enter value of N for number of rows and columns: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)  //filling arrays
    {
       for(j=0;j<n;j++)
       {
           a[i][j]=num;
           b[i][j]=num;
           c[i][j]=num;
           num++;
       }
    }

    printf("\n\nInitial A Matrix:\n\n");
    printMatrix(a);
    printf("\n\nInitial B Matrix:\n\n");
    printMatrix(b);
    printf("\n\nInitial C Matrix:\n\n");
    printMatrix(c);
    printf("\n\n");

    FILE *fptr;
    FILE *ijk;
    FILE *jik;
    FILE *kij;
    FILE *ikj;
    FILE *jki;
    FILE *kji;

    /*for(int h=0;h<6;h++)
    {
        char name=tests[h];
        FILE *name;
    }
    FILE *fptr;*/

    fptr=fopen("MatrixMultiplication.csv","w");
    ijk=fopen("ijk.csv","w");
    jik=fopen("jik.csv","w");
    kij=fopen("kij.csv","w");
    ikj=fopen("ikj.csv","w");
    jki=fopen("jki.csv","w");
    kji=fopen("kji.csv","w");

    fprintf(fptr,"ijk,jik,kij,ikj,jki,kji\n");

    /*for(h=0;h<6;h++)
    {
        char name=tests[h];
        fprintf(fptr,"%c,",name);
    }
    fprintf(fptr,"\n");*/


    for(w=0;w<800;w++)
    {
        IJK[w]=ijk_1(a,b,c);
        JIK[w]=jik_1(a,b,c);
        KIJ[w]=kij_1(a,b,c);
        IKJ[w]=ikj_1(a,b,c);
        JKI[w]=jki_1(a,b,c);
        KJI[w]=kji_1(a,b,c);

        test=w%50;

        if(w!=0&&test==0)
        {
            //fprintf values from the functions
            fprintf(fptr,"%lf,%lf,%lf,%lf,%lf,%lf\n",IJK[w],JIK[w],KIJ[w],IKJ[w],JKI[w],KJI[w]);
            fprintf(ijk,"%lf,",IJK[w]);
            fprintf(jik,"%lf,",JIK[w]);
            fprintf(kij,"%lf,",KIJ[w]);
            fprintf(ikj,"%lf,",IKJ[w]);
            fprintf(jki,"%lf,",JKI[w]);
            fprintf(kji,"%lf,",KJI[w]);

            /*for(h=0;h<6;h++)
            {
                char sect=tests[h];
                char op[w]=ans[h];

                fprintf(sect,"%lf,",op[w]);

                fprintf(fptr,"%lf,",op[w]);
            }
            fprintf(fptr,"\n");*/

            printf("Total Time(ijk): %lf\n",IJK[w]);
            printf("Total Time(jik): %lf\n",JIK[w]);
            printf("Total Time(kij): %lf\n",KIJ[w]);
            printf("Total Time(ikj): %lf\n",IKJ[w]);
            printf("Total Time(jki): %lf\n",JKI[w]);
            printf("Total Time(kji): %lf\n",KJI[w]);
            printf("\n\n");

            /*for(h=0;h<6;h++)
            {
                char sect=tests[h];
                char op[w]=ans[h];

                printf("Total Time(%c): %lf\n",sect,op[w]);
            }*/
        }
    }

    return 0;
}
