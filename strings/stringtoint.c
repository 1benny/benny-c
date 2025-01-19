#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc > 1) {
        char* endptr;
        long val = strtol(argv[1], &endptr, 10);

        if (*endptr == '\0') {
            printf("'%s' is valid: %ld\n", argv[1], val);
        }

    }

    return 0;
}