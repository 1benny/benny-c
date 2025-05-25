#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>


void randNameGen(int N, int complexity)
{
    int i = 0;
    int randomizer = 0;

    srand((unsigned int)(time(NULL)));

    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    char LETTERS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$^&*?";

    char name[N];

    randomizer = rand() % complexity;

    for (i = 0; i < N; i++) {
        if (randomizer == 1) {
            name[i] = LETTERS[rand() % 26];
            randomizer = rand() % complexity;
            printf("%c", name[i]);
        }
        else if (randomizer == 2) {
            name[i] = numbers[rand() % 10];
            randomizer = rand() % complexity;
            printf("%c", name[i]);
        }
        else if (randomizer == 3) {
            name[i] = symbols[rand() % 8];
            randomizer = rand() % complexity;
            printf("%c", name[i]);
        }
        else {
            name[i] = letters[rand() % 26];
            randomizer = rand() % complexity;
            printf("%c", name[i]);
        }
    }
}

bool check(const char* arg) {
    char* endptr;
    long int lenValue;
    return strtol(arg, &endptr, 10);
}

int main(int argc, char* argv[]) {
    int N;
    int complexity;

    if (argc > 2 && check(argv[2]) != '\0') {
        N = atoi(argv[2]);
        if (strcmp(argv[1], "weak") == 0) {
            complexity = 2;
        } else if (strcmp(argv[1], "mid") == 0) {
            complexity = 3;
        } else if (strcmp(argv[1], "complex") == 0) {
            complexity = 4;
        } else {
            printf("Complexity level must be 'weak', 'mid' or 'complex'.");
            exit(0);
        }

    } else if (argc > 2 && check(argv[2]) == '\0') {
        printf("Length argument must be an integer.");
        exit(0);

    } else if (argc < 3 && argc > 1) {
        N = 10;
        if (strcmp(argv[1], "weak") == 0) {
            complexity = 2;
        } else if (strcmp(argv[1], "mid") == 0) {
            complexity = 3;
        } else if (strcmp(argv[1], "complex") == 0) {
            complexity = 4;
        } else if (argv[1] == NULL) {
            printf("arg is null gang.");
            exit(0);
        } else {
            printf("Complexity level must be 'weak', 'mid' or 'complex'.");
            exit(0);
        }
    } else if (argc < 2) {
        N = 10;
        complexity = 2;
    }
    
    randNameGen(N, complexity);

    return 0;
    
}