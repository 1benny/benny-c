#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if user provided the argument
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    // Convert the argument to a double
    double input = atof(argv[1]);

    // Perform the scaling
    double result = input / 25.0;
    int squares = 

    // Print the result with 2 decimal places
    printf("Scaled result (1:100): %.2f\n", result);
    printf("Squares used: %d\n", squares);

    return 0;
}