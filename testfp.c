#include <stdio.h>
#include <windows.h>
// 關閉原本的視窗 DestroyWindow(hwnd);
// 係數 X軸 Y軸 上面的長度 旁邊的長度
// 定義按鈕 ID
#define BUTTON_START 109
#define BUTTON_AD_MODE 110
#define BUTTON_RE_MODE 120
#define BUTTON1_ID 101
#define BUTTON2_ID 102
#define BUTTON3_ID 103
#define BUTTON4_ID 104
#define BUTTON5_ID 105

// 處理按鈕點擊事件
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_COMMAND:
            // 判斷事件來源是否是按鈕
            switch (LOWORD(wParam))
            {
                case BUTTON_AD_MODE: {
                // 創建新的窗口
                HWND newHwnd;
                WNDCLASS wc = {0};
                wc.lpfnWndProc = WindowProc;
                wc.hInstance = GetModuleHandle(NULL);
                wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
                wc.lpszClassName = "NewWindowClass";
                RegisterClass(&wc);
                newHwnd = CreateWindow("NewWindowClass", "administrators", WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
                            NULL, NULL, GetModuleHandle(NULL), NULL);
                ShowWindow(newHwnd, SW_SHOW);
                UpdateWindow(newHwnd);
                // 關閉原本的視窗
                DestroyWindow(hwnd);
                MSG msg;
                while (GetMessage(&msg, NULL, 0, 0))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
                HWND new_button;
                new_button = CreateWindow("BUTTON", "EXIT", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                        10, 10, 100, 30,
                                        newHwnd, (HMENU)BUTTON_START, wc.hInstance, NULL);
                break;
            }
                case BUTTON_RE_MODE:{
                    HWND newHwnd;
                    WNDCLASS wc = {0};
                    wc.lpfnWndProc = WindowProc;
                    wc.hInstance = GetModuleHandle(NULL);
                    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
                    wc.lpszClassName = "NewWindowClass";
                    RegisterClass(&wc);
                    newHwnd = CreateWindow("NewWindowClass", "readers", WS_OVERLAPPEDWINDOW,
                                CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
                                NULL, NULL, GetModuleHandle(NULL), NULL);
                    ShowWindow(newHwnd, SW_SHOW);
                    UpdateWindow(newHwnd);
                    // 關閉原本的視窗
                    DestroyWindow(hwnd);
                    CreateWindow("BUTTON", "readers", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,10, 50, 100, 30,
                    hwnd, (HMENU)BUTTON_RE_MODE, GetModuleHandle(NULL), NULL);
                    MSG msg;
                    while (GetMessage(&msg, NULL, 0, 0)){
                        TranslateMessage(&msg);
                        DispatchMessage(&msg);
                    }
                    break;
                }
                case BUTTON_START:{
                    DestroyWindow(hwnd);
                    // 創建主窗口
                    HWND hwnd;
                    WNDCLASS wc = {0};
                    wc.lpfnWndProc = WindowProc;
                    wc.hInstance = GetModuleHandle(NULL);
                    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
                    wc.lpszClassName = "ExampleWindowClass";
                    RegisterClass(&wc);
                    hwnd = CreateWindow("ExampleWindowClass", "READER", WS_OVERLAPPEDWINDOW,
                                        CW_USEDEFAULT, CW_USEDEFAULT, 1000,1000,
                                        NULL, NULL, wc.hInstance, NULL);
                    ShowWindow(hwnd, SW_SHOW);
                    UpdateWindow(hwnd);

                    // 創建按鈕 
                    // 係數 X軸 Y軸 上面的長度 旁邊的長度
                    CreateWindow("BUTTON", "administrators", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                110, 10, 100, 30,
                                hwnd, (HMENU)BUTTON_AD_MODE, wc.hInstance, NULL);
                    CreateWindow("BUTTON", "readers", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                                10, 50, 100, 30,
                                hwnd, (HMENU)BUTTON_RE_MODE, wc.hInstance, NULL);
                    // 處理事件循環
                    MSG msg;
                    while (GetMessage(&msg, NULL, 0, 0))
                    {
                        TranslateMessage(&msg);
                        DispatchMessage(&msg);
                    }
                    break;
                }
                case BUTTON4_ID:
                case BUTTON5_ID:{
                    // 創建檔案
                    char filename[20];
                    sprintf(filename, "example%d.txt", LOWORD(wParam) - BUTTON1_ID + 1);
                    FILE *fptr;
                    fptr = fopen(filename, "w");
                    fprintf(fptr, "This is example %d.\n", LOWORD(wParam) - BUTTON1_ID + 1);
                    fclose(fptr);
                    break;
                }
                default:
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 創建主窗口
    HWND hwnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wc.lpszClassName = "ExampleWindowClass";
    RegisterClass(&wc);
    hwnd = CreateWindow("ExampleWindowClass", "READER", WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT, 1000,1000,
                        NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 創建按鈕 
    CreateWindow("BUTTON", "administrators", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 110, 10, 100, 30,
                 hwnd, (HMENU)BUTTON_AD_MODE, hInstance, NULL);
    CreateWindow("BUTTON", "readers", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 10, 50, 100, 30,
                 hwnd, (HMENU)BUTTON_RE_MODE, hInstance, NULL);
    // 處理事件循環
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}