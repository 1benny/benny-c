#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(int argc, char* argv[]) {
    FILE* process;
    char cmd[4096] = "curl -s https://pubs.opengroup.org/onlinepubs/009696799/functions/";
    char pipe[200] = " | pandoc -f html -t plain";
    // Uses the program "pandoc" to convert html to plain text after curl downloads the web page.

    // If the program receives any argument it attempts to run the search and convert
    if (argc > 1) {
    
        strcat(cmd, argv[1]);
        strcat(cmd, ".html");
        strcat(cmd, pipe);

        process = popen(cmd, "w");
        pclose(process);
    // If the program receives no arguments it exits
    } else {
        printf("-------------------------------------------------------\npubs utilizes curl to get from pubsopengroup's and uses\nPandoc to format it as plain text\n\n  Usage: pubs [FUNCTION NAME].\n");
    }
}