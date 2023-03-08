#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define INTERVALS 10 // number of intervals
#define tabulated_value 16.919 // we assumed LOS=5% and DF=9

int main(void)
{
	int x0=7,x1; //xo=seed, x1=next random number to be generated
    int a=5,c=3,m=100; //a=constant multiplier, c=increment, m=modulus 
    int n = 100; // size of the sample
    int lb[INTERVALS] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90}; // lower bounds of the intervals
    int ub[INTERVALS] = {9, 19, 29, 39, 49, 59, 69, 79, 89, 99}; // upper bounds of the intervals
    int observed[INTERVALS] = {0},expected,N=0;; // observed frequencies ,expected frequency,total of observed frequency
    int i,j,array[100]; //o store the random numbers generated 
    float final,calculation[20];
   
   /* Calculation is the value of (Oi-Ei)^2/Ei for each intervals and final is the total calculated value of all intervals */
   
   printf("The random numbers are:\n");

for (i = 0; i < n; i++) // generate random numbers between 0 and 99 using m=100 and mixed congruential method
{
  x1=(a*x0+c) %m; 
  array[i]=x1;
  x0=x1;
  printf("%d\t" ,array[i]);
}

for (i = 0; i < n; i++) // calculating observed frequency for each interval
{
  for (j = 0; j < INTERVALS; j++)
   {
     if (array[i]>= lb[j] && array[i] <= ub[j]) 
	 {
     observed[j]++;
     break;
     }
   }
}


//calculation of N(total frequency), Calculation(((Oi-Ei)^2/Ei)),final 
expected=n/INTERVALS;
  for(i=0;i<INTERVALS;i++)
	{
		calculation[i]=(float)((observed[i]-expected)*(observed[i]-expected))/expected;
		final=final+calculation[i];
		N=N+observed[i];
	}
	
//display in tabulated format
printf("\n---------------------------------------------------------------------");
printf("\nS.No \t\t Oi \t\t Ei \t\t((Oi-Ei)*(Oi-Ei))/Ei ");
printf("\n---------------------------------------------------------------------");
  for(i=0;i<10;i++)
	{
	    printf("\n%d \t\t %d \t\t %d\t\t %f",i+1,observed[i],expected,calculation[i]);
	}
printf("\n---------------------------------------------------------------------");
printf("\n \t\t%d \t\t\t\t %f",N,final);

//compare tabulated and calculated value and conclude if Ho is accepted.
  
if(final<=tabulated_value)
	{
		printf("\nThe calculated value = %f < Tabulated value= %f . So, the null hypothesis is not rejected and hence the random numbers are uniform .",final,tabulated_value);
	}
else
	{
		printf("\n The calculated value = %f > Tabulated value= %f . So, the null hypothesis is rejected and hence the random numbers are not uniform." ,final,tabulated_value);
	}
	return 0;

	}

