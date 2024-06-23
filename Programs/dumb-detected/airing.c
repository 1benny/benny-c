#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <unistd.h>
#include <stdbool.h>

int spawnPopup();

int main()
{
    int dumbDetected;

    int initialPopup = MessageBoxW(
        NULL,
        L"dumb detected!",
        L"Warning",
        MB_YESNO | MB_ICONWARNING
    );

    if (initialPopup == IDNO)
    {
//  ... spawnPopup()
        if (spawnPopup() == 1) {
            for (int kid = 1; spawnPopup() == 1; kid++) {
                spawnPopup();
            }
        }
    } else {
        for (dumbDetected = MessageBoxW(NULL, L"aired unfortunately", L"Attention", MB_OK | MB_ICONINFORMATION); dumbDetected == IDOK; NULL) {
            int Idiot = MessageBoxW(NULL, L"aired unfortunately", L"Attention", MB_OK | MB_ICONINFORMATION);
        }
    }
    return 1;
}


int spawnPopup() 
{

    HWND parentWindow = FindWindow(NULL, "Attention");

    int msgboxID = MessageBoxW(
        parentWindow,
        L"Are you sure?",
        L"Warning",
        MB_ICONERROR | MB_YESNO
    );

    if (msgboxID == IDNO) {
        return 1;
    } else {
        return 1;
    }

}