#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_SIZE 1000

double expected_frequencies[] = { 0.0001, 0.015, 0.12, 0.3, 0.45, 0.3, 0.12, 0.015, 0.0001 };

int main()
{
    srand(time(NULL)); // Seed the random number generator
    int digits[4],i,j;
    int observed_frequencies[9] = { 0 };
    double chi_squared = 0.0;

    // Generate 1000 random 4-digit numbers and count the observed frequencies of each digit combination
    for ( i = 0; i < SAMPLE_SIZE; i++) {
        for ( j = 0; j < 4; j++) {
            digits[j] = rand() % 9 + 1;
        }
        int index = (digits[0] - 1) * 729 + (digits[1] - 1) * 81 + (digits[2] - 1) * 9 + (digits[3] - 1);
        observed_frequencies[index]++;
    }

    // Calculate the chi-squared statistic
    for ( i = 0; i < 9; i++) {
        double diff = observed_frequencies[i] - (expected_frequencies[i] * SAMPLE_SIZE);
        chi_squared += (diff * diff) / (expected_frequencies[i] * SAMPLE_SIZE);
    }

    // Print results
    printf("Results after 1000 samples:\n");
    printf("Observed frequencies:\n");
    for ( i = 0; i < 9; i++) {
        printf("%d: %d\n", i+1, observed_frequencies[i]);
    }
    printf("Expected frequencies:\n");
    for ( i = 0; i < 9; i++) {
        printf("%d: %.2f\n", i+1, expected_frequencies[i] * SAMPLE_SIZE);
    }
    printf("Chi-squared statistic: %.2f\n", chi_squared);

    return 0;
}

