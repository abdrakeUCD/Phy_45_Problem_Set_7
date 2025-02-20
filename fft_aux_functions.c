#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include "fft_aux_functions_datashape.h"






















/*
 * DATA STUFF
*/


// bit shifted power of 2 computation. ONLY WORKS FOR INTEGERS
int pow_2(int k)
{
	return 1 << k;
}


// test if an integer n is bisectable (\exists k\in\mathbb{N} such that n=2^k)
bool is_bisectable(int n)
{
	return (ceil(log2(n)) == floor(log2(n)));
}

/*
below are defined functions to amke sure that the fft alg can work in cases where is_bisectable fails. 
They are not important for this lab but I would like this code to be functional in the future
*/

int minimum(int n)
{
	// analyze minimum data points needed to make the data set bisectable
	
	double difference = log2(n) - floor(log2(n))
	double inf_db = n/(pow(2, difference)) // supremum numbers that are bisectable and less than the number of samples
	
	// turning inf_db into an integer:
	if(is_bisectable(floor(inf_db)))
	{
		int inf = floor(inf_bisectable);
		return inf;
	}
	if(is_bisectable(ceil(inf_db)))
	{
		int inf = ceil(inf_bisectable);
		return inf;
	}
	else
	{
		printf("\nData bisectability algorithm failed to determine the infimum of bisectable data points.\n");
		return 1;
	}
}

int maximum(int minimum)
{
	int ub = pow_2(minimum + 1);
	return ub;
}

int distance_to_minmax(int n, int minmax)
{
	int dist = abs(n - minmax);
	return dist;
}

void terminal_prompts(int n, double *data)
{
	if is_bisectable(n)
	{
		printf("\nThe data set provided is bisectable with data points %d. Proceeding with Fast Fourier Transform as normal.");
	}
	else
	{
		char response;
		printf("\nThe data set provided is not bisectable with data points %d.\nWould you like to change the data shape to make it bisectable? (y/n)\n", n);
		scanf("%c", &response);

		response = tolower(response); // in case of typos

		if(response == 'n')
		{
			printf("\nYou have chosen not to modify this data set. Ending algorithm.");
			return 1;
		}
		if(response == 'y')
		{
			int minimum = minimum(n);
			int maximum = maximum(n);
			int distance_to_min = distance_to_minmax(n, minimum);
			int distance_to_max = distance_to_minmax(n, maximum);

			printf("\nYou have chosen to modify this data set.");
			printf("\nThe two closest powers of 2 to %d are %d (lower bound) and %d (upper bound).", n, minimum, maximum)
			printf("\nFor the data to be bisectable for the Fast Fourier Transform (FFT) algorithm, you will need to remove a minimum of %d data points or add %d data points.", distance_to_min, distance_to_max);

			printf("Would you like to change the data shape by making it larger or smaller? (l/s)");
			scanf("%c", &response);

			response = tolower(response); // in case of typos
			
			if(response == 's')
			{
				// change_datashape_min(n, distance_to_min, &data);
			}
			if(response == 'l')
			{
				// change_datashape_max(n, distance_to_min, &data);
			}
		}

	}
}

void change_datashape_min(int n, int distance_to_min, double *data) // change the data shape 
{
	// terminal prompts to user
	char response1;

	printf("\nWould you like to\n(a.) remove points on a given interval, or\n(b.) remove points using a probability distribution?\n(a/b)\n");
	scanf("%c", &response1);

	response1 = tolower(response1)

	if(response1 == 'a')
	{
		char response2;
		
		printf("\nYou haveselected to remove points on a given interval.\n");
		printf("\nWould you like to \n(a.) remove the first %d points,\n(b.) remove the last %d points,\n(c.) remove the middle %d points, or \n(d.) remove %d points on an interval you define?\n(a/b/c/d)\n", );
		scanf("%c", &response2);
		
		response2 = tolower(response2);
		
		if(response2 == 'a')
		{
			// call void remove_first(int n, int distance_to_min);
		}
		if(response2 == 'b')
		{
			// call void remove_last(int n, int distance_to_min);
		}
		if(response2 == 'c')
		{
			// if it can be split perfectly down the middle:
				// call remove_middle_lb(int n, int distance_to_min)
			// if it cannot:
				// ask user if they want the upper bound or the lower bound removed
					// if they want the upper bound removed:
						// call remove_middle_ub(int n, int distance_to_min)
					// if they want the lower bound removed:
						// call remove_middle_lb(int n, int distance_to_min)
		}
		if(response2 == 'd')
		{
			// call void remove_ud(int n, int distance_to_min)
		}
	}	

void change_datashape_max(int n, int distance_to_max)
{

}

	// randomly select an amount of distance_to_minmax(n, minimum) points that will be removed from the data set
	


	// randomly select distance_to_minmax(n, minimum) points that will be removed from the data set using a user-defined probability distribution, with a set of distributions for them to choose from
	


	// remove last distance_to_minmax(n, minimum) points from the data set
	


	// remove first distance_to_minmax(n, minimum) points from the data set
	


	// remove middle distance_to_minmax(n, minimum) points from the data set
	


	// remove distance_to_minmax(n, minimum) points on a user-defined interval
