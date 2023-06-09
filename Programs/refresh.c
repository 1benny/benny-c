#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

void c_file(char* cfname) {
    FILE* cfile;
    char cpath[256] = "C:\\Users\\Ben\\Projects\\bdives-c\\";
    strcat(cpath, cfname);

    cfile = fopen(cpath, "w");
    fprintf(cfile, "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include <limits.h>\n#include <unistd.h>\n \nint main(int argc, char* argv[])\n{\n \n \n    return 0;\n}");
    fclose(cfile);
    
    if (access(cpath, F_OK) == 0) {
        printf("Successfully created .c file in %s", cpath);
    } else { 
        printf("Couldn't create file in path. Try again");
    }
}

void py_file(char* pyfname) {
    FILE* pyfile;
    char pypath[256] = "C:\\Users\\Ben\\Projects\\bdives-py\\";
    strcat(pypath, pyfname);

    pyfile = fopen(pypath, "w");
    fprintf(pyfile, "import customtkinter as ttkk\nimport requests\nimport os\nimport subprocess as sub\nfrom time import sleep\nimport threading\n \n");
    fclose(pyfile);
    
    if (access(pypath, F_OK) == 0) {
        printf("Successfully created .py file in %s", pypath);
    } else {
        printf("Couldn't create file in path. Try again");
    }

}

int main(int argc, char* argv[])
{
    char* c_name;
    char* py_name;


    if (strcmp(argv[1], "c") == 0) {
        if (argc > 2) {
            c_name = strcat(argv[2], ".c");
        } else {
            c_name = "new_1.c";
        }
        c_file(c_name);
    }
    
    else if (strcmp(argv[1], "py") == 0) {
        if (argc > 2) {
            py_name = strcat(argv[2], ".py");
        } else {
            py_name = "new_1.py";
        }
        py_file(py_name);

    } else {
        printf("Couldn't create file in path.");
    }

}
