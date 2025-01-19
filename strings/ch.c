#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

bool check(char* arg) {
    char* endptr;
    long int lenValue;
    return strtol(arg, &endptr, 10);
}


int main(int argc, char* argv[])
{
    if (check(argv[1]) == 1) {
        printf("%s is an integer.", argv[1]);
    } else if (check(argv[1]) == 0) {
        printf("%s is not an integer.", argv[1]);
    }
    /*
    if (check(argv[1]) == '\0') {
        printf("Is int");
    } else if (check(argv[1]) != '\0') {
        printf("Isn't int");
    }
    */
}