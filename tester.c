// Wed Jul 05 22:26:28 2023
// bdxves
//
// gui.c
//
//
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")


void playIdiot(int spawn);

void spawnBox();

int main(int argc, char* argv[])
{
    LPCWSTR message = L"Are you an idiot?";
    LPCWSTR caption = L"Attention";

    int ask = MessageBoxW(NULL, message, caption, MB_YESNO | MB_ICONASTERISK);

    if (ask == IDNO) {
        spawnBox();
    } else {
        exit(0);
    }
	
	return 0;
}

void spawnBox()
{
    int status = 0;

    for (int result = MessageBoxA(NULL, "Are you sure?", "Warning", MB_YESNO | MB_ICONERROR); result == IDNO; status++) {
        playIdiot(status);
    }

}

void playIdiot(int spawn)
{
    if (spawn < 5) {
        BOOL sound = PlaySound(TEXT("idiot.wav"), NULL, SND_FILENAME);
    }
}