// Tue Jun 06 05:42:54 2023
// bdxves
//
// nd.c
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

bool exists(char* name) {
    return (access(name, F_OK));
}

int main(int argc, char* argv[])
{
    time_t current;
    time(&current);
    
    FILE* TEMPLATE;
    FILE* newfile;

    char* HOMEPATH = strcat(getenv("USERPROFILE"), "\\TEMPLATES\\");
        strcat(HOMEPATH, argv[1]);
    
    char* USERNAME = "bdxves";  //~ Needs functionality for being able to pick username. Maybe read from .conf file
    char buffer[256];
    char path[256];
    char* fname = argv[2];

  //~ Handles missing argument for name of file. Not able to utilize default filename for lack of argument at argv[2] some reason. bozo moves
    if (argc < 3) {     
        printf("You need to specify a name for the document.\n");
        exit(0);
    } else {
        strcat(fname, ".");
    }
  
  // Dictates the path for which the file will be created in. This will always be pwd until added functionality for specifying path.
    char* finalpath = getcwd(path, sizeof(path));   

  // Concatenation block because im lacking in knowledge for C. Builds the files final path in a string.
    strcat(finalpath, "\\");
    strcat(fname, argv[1]);     
    strcat(path, fname);
    strcat(HOMEPATH, ".txt");

  // Handles checking the existance of template file. Exits 1 with failure
    if (exists(HOMEPATH) != 0) {      
        printf("Couldn't find template file."); 
        exit(1);
    // Otherwise:
    } else {
        char* templateFile = HOMEPATH;

    // Open the template file to read from + handle if it won't open and exit
        TEMPLATE = fopen(templateFile, "r");
        if (TEMPLATE == NULL) {
            printf("Failed to open template file.\n");
            return 1;
        }
    // Simultaneously open new file stream to write to + handle if failure to open
        newfile = fopen(path, "w");
        if (newfile == NULL) {
            printf("Failed to open file.\n");
        }
    // Write head of file
        if (strcmp(argv[1], "html") == 0) {
            fprintf(newfile, "<!--\n// %s// %s\n//\n// %s\n//\n//\n-->\n", ctime(&current), USERNAME, fname);

        } else if (strcmp(argv[1], "c") == 0) {
            fprintf(newfile, "// %s// %s\n//\n// %s\n//\n//\n", ctime(&current), USERNAME, fname);

        } else if (strcmp(argv[1], "py") == 0) {
            fprintf(newfile, "# %s# %s\n#\n# %s\n#\n#\n", ctime(&current), USERNAME, fname);
        }
    
    // Write template to new file    
        while (fgets(buffer, sizeof(buffer), TEMPLATE) != NULL)
        {
            if (buffer != NULL) {
                fprintf(newfile, "%s", buffer);
            }
        }

    // Close when finished
        fclose(newfile);
        fclose(TEMPLATE);
    }

    // Checks existance of newly written file. Lets you know if it didn't work.
    if (exists(path) == 0) {
        printf("Successfully created %s in current directory.\n", fname);
    } else {
        printf("Failed to create file.\n");
    }

    return 0;
}
