#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265
#define MAXDIM 256

void printOutputVectorToFile(int n, double *a)  
{
	FILE *fp;
	char filestring[] = "raw_sine_output_data_(test).dat"; 
	fp=fopen(filestring,"w");
	for (int j=0; j<n; j++)
	{
		fprintf(fp,"%lf  \n",*(a+j));
		printf("%lf  \n",*(a+j));
	}
	fclose(fp);
	printf("Data successfully written to %s\n", filestring);
}

void print_sine(void)
{
	int i; double *y, argument;
	y=(double*)malloc(MAXDIM*sizeof(double)); // I use my cpp compiler so this definition is necessary
	printf("y= %p\n", y);
	for (i=0; i<MAXDIM; i++)
	{
		argument=i*2*PI/MAXDIM;
		y[i]=sin(argument);
		printf("i= %d, y[i] = %lf\n", i, y[i]);
	}
	printOutputVectorToFile(MAXDIM,y);
}
