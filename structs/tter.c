#include <stdio.h>
#include <stdlib.h> // For atoi

int main(int argc, char* argv[]) {
    int N;

    if (argc > 1) {
        N = atoi(argv[1]); // Convert the first argument to an integer
    } else {
        N = 10; // Default value if no argument is provided
    }

    printf("%d\n", N); // Print the integer value
    return 0;
}