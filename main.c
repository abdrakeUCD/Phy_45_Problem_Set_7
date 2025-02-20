#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fft_aux_functions.h"
#include "fft_aux_functions_datashape.h"
#include "sine.h"
#include "four1.h"

int main()
{
	int maxdim = 256; // its just easier to do it this way such that ist accessible by the new main func
	
	char sine_filename[] = "raw_sine_output_data_(test3).dat"; 
	
	// run sine generative data
	print_sine(maxdim, sine_filename);
	
	// count the number of entries in y (defined in sine.c)
	int n_y; 

	// create pointer to data
	double *data;
	//data = malloc()

	// make new data file that arranges the outputs from print_sine into an array
	
	
	
	// test functions (currently partially depriciated)
	
	
	
	// 









	return 0;
}
