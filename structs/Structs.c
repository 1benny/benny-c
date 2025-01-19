#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>


int main(int argc, char* argv[]) {

    int valid_change;
    int pfd;
    FILE *fpfd;
    struct passwd *p;
    char user[65];
    char oldpasswd[64];
    char newpasswd[64];
    char savepasswd[64];

    valid_change = 0;

    while ((p = getpwent()) != NULL) {
        if (strcmp(p->pw_name, user))
    }
}