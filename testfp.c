#include <stdio.h>
#include <windows.h>

// 定義按鈕 ID
#define BUTTON1_ID 101
#define BUTTON2_ID 102
#define BUTTON3_ID 103
#define BUTTON4_ID 104
#define BUTTON5_ID 105
#define BUTTON6_ID 106
#define BUTTON7_ID 107
#define BUTTON8_ID 108

// 處理按鈕點擊事件
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_COMMAND:
            // 判斷事件來源是否是按鈕
            switch (LOWORD(wParam))
            {
                case BUTTON1_ID:{
                    printf("Hello World!\n");
                }
                case BUTTON2_ID:
                case BUTTON3_ID:
                case BUTTON4_ID:
                case BUTTON5_ID:
                case BUTTON6_ID:
                case BUTTON7_ID:
                case BUTTON8_ID:{
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
    // 係數 X軸 Y軸 上面的長度 旁邊的長度
    CreateWindow("BUTTON", "Create File 1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 110, 10, 100, 30,
                 hwnd, (HMENU)BUTTON1_ID, hInstance, NULL);
    CreateWindow("BUTTON", "Create File 2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 10, 50, 100, 30,
                 hwnd, (HMENU)BUTTON2_ID, hInstance, NULL);
    CreateWindow("BUTTON", "Create File 3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 10, 90, 100, 30,
                 hwnd, (HMENU)BUTTON3_ID, hInstance, NULL);
    CreateWindow("BUTTON", "Create File 4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 10, 130, 100, 30,
                 hwnd, (HMENU)BUTTON4_ID, hInstance, NULL);
    CreateWindow("BUTTON", "Create File 5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 10, 170, 100, 30,
                 hwnd, (HMENU)BUTTON5_ID, hInstance, NULL);
    CreateWindow("BUTTON", "Create File 6", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 10, 210, 100, 30,
                 hwnd, (HMENU)BUTTON6_ID, hInstance, NULL);
    CreateWindow("BUTTON", "Create File 7", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 10, 250, 100, 30,
                 hwnd, (HMENU)BUTTON7_ID, hInstance, NULL);
    CreateWindow("BUTTON", "Create File 8", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                 10, 290, 100, 30,
                 hwnd, (HMENU)BUTTON8_ID, hInstance, NULL);
    // 處理事件循環
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}