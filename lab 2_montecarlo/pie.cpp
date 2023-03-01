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

int main() {
  int i,circlepoints=0,squarepoints=0, iteration;
  double x, y;
std::cout << "Enter the number of iteration: "; // Type a number and press enter
std::cin >> iteration; 

  // Initialize the graphics window
  initwindow(600, 600);

  // Set the seed for the random number generator
  srand(time(0));

  // Draw the circle and square
  circle(300, 300, 200);
  rectangle(100, 100, 500, 500);

  // Perform the Monte Carlo simulation
  for (i = 0; i < iteration; i++) {
    generate_random_point(x, y);

    // Check if the point lies inside the circle
    if (x*x + y*y <= 1)
	 {
      circlepoints++;
      putpixel(300 + x * 200, 300 + y * 200, GREEN);
     }
    else
      {
	  putpixel(300 + x * 200, 300 + y * 200, RED);
	  }
    squarepoints++;

  }

  // Estimate the value of pi
  double pi_estimate = 4.0 * circlepoints /squarepoints;
  std::cout << "Estimated value of pi: " << pi_estimate << std::endl;

  // Wait for the user to press a key before closing the graphics window
  getch();
  closegraph();

  return 0;
}

