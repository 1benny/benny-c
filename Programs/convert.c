#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

void usd(float usd)
{
    float aud = usd * 1.48806;
    printf("%.2f USD    :   %.2f AUD\n", usd, aud);
    
}

int main(int argc, char* argv[])
{
    char* num = argv[1];

    usd(atof(num));
 
    return 0;
}