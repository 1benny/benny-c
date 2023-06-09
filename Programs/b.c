#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


// Doesn't work with windows 

int main(int argc, char* argv[])   {
    int fd[2];  // variable gets 2 file descriptors ~>
    // fd[0] -- read
    // fd[1] -- write

    if (pipe(fd) == -1) {
        printf("Error: Returned -1 when opening PIPE");    // If the pipe faiels to open, print this
            return 1;
    }
    
    int id = fork();    // fork() the file descriptors get copied over/ inherited by newly created process
    if (id == 0) {      // if returns 0 (sucessful)...
        close(fd[0]);   // close the reading end
        int x;       
        printf("Input a number: ");     // taking user input for a number
        scanf("%d", &x);    // We want the x to be sent from the child process, to the parent process
        write(fd[1], &x, sizeof(int));  // This is done by using the write() function. Writing from the location fd[1] (the write end of the pipe) to &x (where x is "at" (&)). Only write an integer (int)
        close(fd[1]);   // Housekeeping. Close the file similar to fclose() but speciftying that the writing end of the file, is closed and there is also no longer any file descriptor.

    } else {
        close(fd[1]);
        int y;
        read(fd[0], &y, sizeof(int));   // This is reading from id[0] the READ side of the pipe, into the address of y (&y)
        close(fd[0]);
        printf("Got from children process: %d\n", y);
    }   

    return 0;
}
