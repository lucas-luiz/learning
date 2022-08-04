#include <windows.h>

/* função chamada pelo windows95, recebe as mensagens da fila*/
/*
    h -> handle
    w -> window
*/
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY: /*fechar programa*/
        PostQuitMessage(0);
        break;
    default: /*mensagens não especificadas*/
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

char szWinName[] = "MinhaJan"; /*Classe da janela*/

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
    HWND hwnd;
    MSG msg;
    WNDCLASS wcl;
    /*1. definir uma classe de janela */
    wcl.hInstance = hThisInst;
    wcl.lpszClassName = szWinName;
    wcl.lpfnWndProc = WindowFunc; /* função da janela */
    wcl.style = 0;

    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); /*icon style*/
    wcl.hCursor = LoadCursor(NULL, IDC_ARROW);   /*cursor style*/
    wcl.lpszMenuName = NULL;
    wcl.cbClsExtra = 0;                                      /*nenhuma info*/
    wcl.cbWndExtra = 0;                                      /*extra é necessária*/
    wcl.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH); /*backgound da janela*/

    if (!RegisterClass(&wcl))
        return 0; /*registra a classe*/

    /*3. a partir da classe, criar uma janela*/
    hwnd = CreateWindow(
        szWinName, /* name da class da janela*/
        "Blank Window",
        WS_OVERLAPPEDWINDOW, /*estilo da janela- normal*/
        CW_USEDEFAULT,       /*coordenada X - default do windows*/
        CW_USEDEFAULT,       /*coordenada Y - idem*/
        CW_USEDEFAULT,       /*largura - idem*/
        CW_USEDEFAULT,       /*altura - idem*/
        HWND_DESKTOP,        /*nenhuma janela pai*/
        NULL,                /*sem menu*/
        hThisInst,           /*handle*/
        NULL                 /*sem argumento adicional*/
    );

    /*4. exibir a janela*/
    ShowWindow(hwnd, nWinMode);
    UpdateWindow(hwnd);

    /*5. repetição de mensagens*/
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); /*permitir uso do teclado*/
        DispatchMessage(&msg);  /*retornar controle ao windows*/
    }
    return msg.wParam;
}