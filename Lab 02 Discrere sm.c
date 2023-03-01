#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SEED time(NULL)

int main() {

 srand( SEED ); // SEED is used for different random number generation every time and rand is the random number generation function
 int i, count, n; // count is the number of drops in circle and n is the time interval till which the drop of water falls
 double x,y,z,pi; // here x and y are the coordinate location points for any random position of water drop and d is the distance of the x,y coordinate from origin

 printf(" n = ");
 scanf("%d", &n);

 count = 0;

 for(i = 0; i < n; ++i) {

     x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
// here x and y are randomly generated
     z = x * x + y * y;

     if( z <= 1 ) count++;  // to check if raindrop is inside the circle, if it is inside then increase the count
 }

 pi = (double) count / n * 4;
 
 printf("Approximate PI = %g", pi);

 return(0);
}
