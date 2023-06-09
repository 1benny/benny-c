#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Takes first argument for file name, second argument for the name of a program to Popen and writes the output of the Popened program to the file, but doesn't write it in ACSII. ?? 

int main(int argc, char* argv[])  {
    int status;
    char path[4096];
    
    char command[50];
    FILE* fp;

    if (argc < 2)   {
        printf("Not running anything. No supplied args.");
    }
    else {
        fp = popen(argv[1], "r");
        
        while (fgets(command, sizeof(command), fp) != NULL) {
            printf("%s", command);
        }

        // FILE* write_file;
      
        // char* txt = ".txt";
 
        // write_file = fopen(strcat(argv[1], txt), "w");
        // fprintf(write_file, "%s\n", fp);

        pclose(fp);
    }
    
    return 0;
}