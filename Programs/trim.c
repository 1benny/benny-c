#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

void trim(char *s);

int main(int argc, char* argv[])
{
    char s[] = "    \n\n\t  This is the way.";

    printf("Before trim: %s\n", s);
    
    trim(s);

    printf("After trim: %s\n", s);

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