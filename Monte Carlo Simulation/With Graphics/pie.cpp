#include <iostream>
#include <cstdlib>
#include <ctime>
#include <graphics.h>

// Function to generate random x and y coordinates
// between -1 and 1
void generate_random_point(double &x, double &y) {
  x = (double) rand() / RAND_MAX * 2 - 1;
  y = (double) rand() / RAND_MAX * 2 - 1;
}

/*  
rand() generates a random integer between 0 and RAND_MAX, which is a constant defined in the C standard library.
(double) rand() converts the integer to a double precision floating-point number.
(double) rand() / RAND_MAX scales the double number to be between 0 and 1.
(double) rand() / RAND_MAX * 2 scales the double number to be between 0 and 2.
(double) rand() / RAND_MAX * 2 - 1 shifts the double number to be between -1 and 1.

*/

int main() {
  int i,circlepoints=0,squarepoints=0, iteration;
  double x, y;
std::cout << "Enter the number of iteration: "; // Type a number and press enter
std::cin >> iteration; 

  // Initialize the graphics window
  initwindow(600, 600);

  // Set the seed for the random number generator
  srand(time(0));

  circle(300, 300, 200);
  rectangle(100, 100, 500, 500);
  /*
  These draw a circle and a square in the graphics window. The circle has a center at (300,300) and a radius of 200,
   while the square has a top-left corner at (100,100) and a bottom-right corner at (500,500).   */

  // Perform the Monte Carlo simulation
  for (i = 0; i < iteration; i++) {
    generate_random_point(x, y);

    if (x*x + y*y <= 1) // checks whether the points lie within the circle
	 {
      circlepoints++; // to keep track of the number of points generated that fall inside the circle
      putpixel(300 + x * 200, 300 + y * 200, YELLOW); // point is drawn in yellow if it falls inside the circle and blue otherwise
     }
    else
      {
putpixel(300 + x * 200, 300 + y * 200, BLUE); //x&y coordinates of the point are scaled by a factor of 200 and added to 300 
                                               // to map them to the range of the graphics window.
	  }
    squarepoints++;// to keep track of the number of points generated that fall in the square

  }

 
 
  // Estimate the value of pi
  double pi_estimate = 4.0 * circlepoints /squarepoints;
  std::cout << "Estimated value of pi: " << pi_estimate << std::endl;

  // Wait for the user to press a key before closing the graphics window
  getch();
  closegraph();

  return 0;
}

