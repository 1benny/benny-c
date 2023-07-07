// Wed Jul 05 22:26:28 2023
// bdxves
//
// gui.c
//
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>

int main(int argc, char* argv[])
{
    LPCWSTR message = L"Unicode message box, with MessageBoxW";
    LPCWSTR caption = L"Example Box";

    int result = MessageBoxA(NULL, "Hi Sisters", "Warning", MB_YESNO | MB_ICONERROR);

    if (result == IDYES) {
        int test = MessageBoxW(NULL, message, caption, MB_OK | MB_ICONINFORMATION);
        if (test == IDOK) {
            exit(0);
        } else {
            exit(0);
        }
    } else if (result == IDNO) {
        printf("You clicked 'No'.\n");
    }
	
	return 0;
}