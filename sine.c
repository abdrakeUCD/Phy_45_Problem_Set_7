#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265

void printOutputVectorToFile(int maxdim, double *a, const char *filename)  
{
	FILE *fp;
	//char filestring[] = "raw_sine_output_data_(test2).dat";
	fp=fopen(filename,"w");
	for (int j=0; j<maxdim; j++)
	{
		fprintf(fp,"%lf  \n",*(a+j));
		printf("%lf  \n",*(a+j));
	}
	fclose(fp);
	printf("Data successfully written to %s\n", filename);
}

void print_sine(int maxdim, const char *filename)
{
	int i; 
	double *y, argument;
	y=(double*)malloc(maxdim*sizeof(double)); // I use my cpp compiler so this definition is necessary
	printf("y= %p\n", y);
	for (i=0; i<maxdim; i++)
	{
		argument=i*2*PI/maxdim;
		y[i]=sin(argument);
		printf("i= %d, y[i] = %lf\n", i, y[i]);
	}
	printOutputVectorToFile(maxdim, y, filename);
}
