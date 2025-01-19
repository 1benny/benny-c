#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc > 2) {
        printf("No. args: %d\n", argc);
        for (int i = 0; i < argc; i++) {
            printf("arg: %s\n", argv[i]);
        }
    } else if (argc < 3) {
        printf("Less than 2 args nigga");
    }

    return 0;
//    printf("No. args: %d\nArgs:%s, %s, %s, %s", argc, argv[0], argv[1], argv[2], argv[3]);
}