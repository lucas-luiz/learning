#include <stdio.h>

#pragma warning(push, 0) // disable all warnings
#include <windows.h>     //enable all warnings
#pragma warning(pop)

LRESULT CALLBACK WndProc(HWND unnamedParam1, UINT unnamedParam2, WPARAM unnamedParam3, LPARAM unnamedParam4)
{
}
// FORMAL PARAMETERS
// h - handler (memory adress)
// hInstance = handle to de instance of this program
// hPrevInstance = old leftover, never used
// PSTR = pointer to command line string used to start aplication(lp for long pointer)
// nCmdShow = minimized, maximized etc
// APIENTRY = alias do WINAPI
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    HANDLE z = hInstance; // program adress
    printf("%i", z);
    WNDCLASSEXA WindowClass = {0}; // window class
    HWND WindowHandle = {0};       // handler
    MSG Msg = {0};                 // message, {0} mean all zeros in the data structure

    // window class registration
    WindowClass.cbSize = sizeof(WNDCLASSEXA); // cb (count in bytes)
    WindowClass.style = 0;
    WindowClass.lpfnWndProc = WndProc; // long pointer to window procedure function
    WindowClass.cbClsExtra = 0;
    WindowClass.cbWndExtra = 0;
    WindowClass.hInstance = hInstance;
    WindowClass.hIcon = LoadIconA(NULL, IDI_APPLICATION);
    WindowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
    WindowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    WindowClass.lpszMenuName = NULL;
    WindowClass.lpszClassName = "C_GAME"; // long pointer to string
    WindowClass.hIconSm = LoadIconA(NULL, IDI_APPLICATION);

    // window class registration fail
    if (RegisterClassExA(&WindowClass) == 0) // if fails
    {
        MessageBox(NULL, "window registration failed", "error",
                   MB_ICONEXCLAMATION | MB_OK);
        return (0);
    }

    // window creation
    WindowHandle = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        WindowClass.lpszClassName,
        "Title",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        240,
        120,
        NULL,
        NULL,
        hInstance,
        NULL);

    // window creaion fail
    if (WindowHandle == NULL)
    {
        MessageBox(NULL, "window creation failed", "error", MB_ICONEXCLAMATION | MB_OK);
        return (0);
    }

    // messages loop
    while (GetMessageA(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessageA(&Msg); // dispatch to the window procedure linked to the windowclass (WindowClass.lpfnWndProc)
    }
    return (0);
}