The C program generates pseudo random numbers using two methods: Linear Congruential and Arithmetic Congruential.

The Linear Congruential method uses a linear equation to generate a sequence of numbers that appears random. It requires three parameters: a seed value, a multiplier, and an increment. The seed value is used to initialize the sequence, and the multiplier and increment are used to generate subsequent values in the sequence.

The Arithmetic Congruential method is similar to the Linear Congruential method, but it uses an arithmetic equation instead of a linear equation. It also requires three parameters: a seed value, a multiplier, and an increment.

To generate pseudo random numbers using these methods, the C program first prompts the user to enter the seed value, multiplier, and increment. It then uses these values to initialize the Linear Congruential and Arithmetic Congruential generators. The program generates a series of pseudo random numbers using both methods and displays them on the screen.

The C program also includes error checking to ensure that the user-entered values are valid and within the acceptable range for each method. If the values are not valid, the program displays an error message and prompts the user to enter new values.



#   P s e u d o - R a n d o m - N u m b e r s - G e n e r a t i o n  
 