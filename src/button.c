#include <windows.h>
#include "main.h"

static const ButtonSize = (UINT)40;

UINT WINAPI CreateButton(HWND hwnd) 
{
		CreateWindow(TEXT("BUTTON"), TEXT("7"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			5, 65, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("8"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			50, 65, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_8, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("9"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			95, 65, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_9, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("+"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			140, 65, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_ADD, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("4"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			5, 110, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_4, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("5"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			50, 110, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_5, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("6"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			95, 110, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_6, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("-"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			140, 110, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_SUB, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("1"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			5, 155, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_1, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("2"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			50, 155, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_2, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("3"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			95, 155, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_3, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("X"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			140, 155, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_MUL, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("0"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			5, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_0, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("DEL"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			50, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_DEL, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("="), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			95, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_RESULT, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("/"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			140, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_DIV, NULL, NULL);
}
