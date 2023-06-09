#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
        char choice[1];
        printf("\n] shutdown  ::  1)   Power off system via regular shutdown procedure \n] reboot    ::  2)   Restart system via regular reboot procedure \n] halt      ::  3)   Bring system and kernel to complete halt. Please don't use this option\n[\n] exit      ::  4)   Do nothing and exit\n");

    printf(">> ");
    scanf("%s", choice);

    if (strcmp(choice, "1") == 0) {
        printf("Powering the system off...");
        system("sudo poweroff");
    }
    else if (strcmp(choice, "2") == 0) {
        printf("Rebooting the system...");
        system("sudo reboot");
    }
    else if (strcmp(choice, "3") == 0) {
        printf("Bringing the system to a halt...");
        system("sudo halt");
    }
    else if (strcmp(choice, "4") == 0) {
        printf("Exiting.\n");
        return 0;
    }
}