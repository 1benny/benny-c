#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void put_in_file(filename, content)
{
    char* filename, content;
    FILE* file_p;
    
    strcat(filename, ".txt");
    file_p = fopen(filename, "a");
    fprintf(file_p, content);
    fclose(file_p);
}

int main(int argc, char* argv[])
{
    FILE* file_p;
    char* filename;

    if (argc < 2)   {
        printf("usage: put [text] in [filename]\n");
    } else {
        switch (strcmp(argv[2], "in")) {
            case 0:
                filename = strcat(argv[3], ".txt");
                file_p = fopen(argv[3], "a");
                
                strcat(argv[1], "\n");
                fprintf(file_p, argv[1]);
                fclose(file_p);

                printf("Wrote to '%s' in current directory", argv[3]);                
                break;
        }
    }
}