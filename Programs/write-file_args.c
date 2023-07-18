#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// First argument provides name for a text file, second argument provides content to write to file

int main(int argc, char *argv[])  
{   

    FILE* fPointer;
    fPointer = fopen(argv[1], "a");

    fprintf(fPointer, "%s\n", argv[2]);
    fclose(fPointer);

    return 0;
}