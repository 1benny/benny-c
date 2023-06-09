#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

void trim(char* s);

int main(int argc, char *argv[])
{
    char* filename;
    char* search;
    char buffer[200];

    filename = argv[1];
    search = argv[2];

    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Failed to open %s", filename);
        return 1;
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if (strstr(buffer, search) != NULL) {
            trim(buffer);
            printf("\n%s\n", buffer);
        }
    }
    fclose(fp);
    return 0;
}

void trim(char *s)
{
    int count = 0;

    while (s[count] == ' ' ||
           s[count] == '\n' ||
           s[count] == '\t') count++;

    if (count != 0) 
    {
        int i = 0;
        while (s[i + count] != '\0')
        {
            s[i] = s[i + count];
            i++;
        }
        s[i] - '\0';
    }
}