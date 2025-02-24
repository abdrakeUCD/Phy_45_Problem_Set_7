#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "four1.h"

#define PI 3.14159265
#define MAXDIM 256

void printOutputVectorToFile(int n, double *a);  


int main()
{int i; double *y, argument;
    y=(double*)malloc(2*MAXDIM*sizeof(double));
    printf("y= %p\n", y);
for (i=0; i<MAXDIM; i++)
{argument=i*2*PI/MAXDIM;
    y[2*i]=((1*sin(argument)) + (0.4*sin(argument)));
    y[2*i+1]=0.0;
    printf("i= %d, y[i] = %lf ", i, y[i]);

    four1(y, MAXDIM, 1);

    

}
printOutputVectorToFile(MAXDIM,y);


}

void printOutputVectorToFile(int n, double *a)   
{FILE *fp;
fp=fopen("MatrixOutputFile2","w");
for (int j=0; j<n; j++)
    {
        {fprintf(fp,"%lf  \n",*(a+j));
        printf("%lf  \n",*(a+j));
        }
    }
fclose(fp);
printf("Wrote MatrixOutputFile2\n");
}
