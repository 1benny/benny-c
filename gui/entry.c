#include <Windows.h>

#define ID_EDIT 101

// Dialog procedure to handle messages for the custom dialog box
LRESULT CALLBACK DialogProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE: {
        // Create an input text box control
        HWND hEdit = CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
                                  10, 10, 200, 25, hWnd, NULL, NULL, NULL);
        // Set the focus to the input text box
        SetFocus(hEdit);
        break;
    }
    
    case WM_COMMAND: {
        // Check for button clicks
        if (LOWORD(wParam) == IDOK) {
            char buffer[256];
            // Retrieve the text from the input text box
            GetWindowText(GetDlgItem(hWnd, ID_EDIT), buffer, sizeof(buffer));
            MessageBoxA(NULL, buffer, "Input Text", MB_OK | MB_ICONINFORMATION);
            EndDialog(hWnd, 0); // Close the dialog box
        }
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int main() {
    // Register the custom dialog box class
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = DialogProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MyDialog";
    RegisterClass(&wc);

    // Create the dialog box
    HWND hWnd = CreateWindow("MyDialog", "Custom Dialog Box", WS_OVERLAPPEDWINDOW,
                             100, 100, 300, 240, NULL, NULL, GetModuleHandle(NULL), NULL);

    // Show the dialog box
    ShowWindow(hWnd, SW_SHOWNORMAL);

    // Run the message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
