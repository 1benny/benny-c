// Tue Feb 06 09:29:12 2024
// bdxves
//
// t-report.c
//
//
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() 
{
    ShellExecute(NULL, "open", "chrome.exe", "https://destinytrialsreport.com/report/3/4611686018532287175", NULL, SW_SHOWNORMAL);

	return 0;
}