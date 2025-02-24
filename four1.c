#define Doub double
#define Int int
#include <math.h>
#include <stdio.h>

int SWAP(double a, double b)
{double tempr;
    tempr=a;
    a=b;
    b=tempr;
    return 0;
}

void four1(Doub *data, Int n, Int isign) {
/*Replaces data[0..2*n-1] by its discrete Fourier transform, if isign is input as 1; or replaces
data[0..2*n-1] by n times its inverse discrete Fourier transform, if isign is input as 1. data
is a complex array of length n stored as a real array of length 2*n. n must be an integer power
of 2.*/

Int nn,mmax,m,j,istep,i;
Doub wtemp,wr,wpr,wpi,wi,theta,tempr,tempi;
if (n<2 || n&(n-1)) printf("n must be power of 2 in four1");
nn = n << 1;
j = 1;
for (i=1;i<nn;i+=2) { //This is the bit-reversal section of the routine
if (j > i) { 
SWAP(data[j-1],data[i-1]); //Exchange the two complex numbers.
SWAP(data[j],data[i]);
}
m=n;
while (m >= 2 && j > m) {
j -= m;
m >>= 1;
}
j += m;
}
//Here begins the Danielson-Lanczos section of the routine.
mmax=2;
while (nn > mmax) { //Outer loop executed log2 n times.
istep=mmax << 1;
theta=isign*(6.28318530717959/mmax); //Initialize the trigonometric recurrence.
wtemp=sin(0.5*theta);
wpr = -2.0*wtemp*wtemp;
wpi=sin(theta);
wr=1.0;
wi=0.0;
for (m=1;m<mmax;m+=2) { //Here are the two nested inner loops.
for (i=m;i<=nn;i+=istep) {
j=i+mmax; //This is the Danielson-Lanczos formula
tempr=wr*data[j-1]-wi*data[j];
tempi=wr*data[j]+wi*data[j-1];
data[j-1]=data[i-1]-tempr;
data[j]=data[i]-tempi;
data[i-1] += tempr;
data[i] += tempi;
}
wr=(wtemp=wr)*wpr-wi*wpi+wr; // Trigonometric recurrence.
wi=wi*wpr+wtemp*wpi+wi;
}
mmax=istep;
}
}



