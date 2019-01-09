#include <windows.h>
#include "main.h"

LPCWSTR WndClassName = TEXT("DefaultUserInterface");
char EditBuffer[32] = { NULL };
UINT length = 0;
long double temp = 0, result = 0;

HWND hWndEdit = NULL;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR CmdLine, int CmdShow)
{
	FuncRegisterClass(hInstance);

	HWND hwnd = CreateWindowEx(
		NULL,
		WndClassName,
		TEXT("Calculator"),
		WS_OVERLAPPED | WS_SYSMENU,
		1000, 500, WIDTH, HEIGHT, NULL, NULL,
		hInstance, NULL
	);

	ShowWindow(hwnd, CmdShow);

	MSG msg = { NULL };
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	const ButtonSize = (int)40;
	switch (uMsg) {
	case WM_CREATE: {
		hWndEdit = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER,
			3, 10, 180, 40,
			hwnd, IDC_EDIT, NULL, NULL);

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
		CreateWindow(TEXT("BUTTON"), TEXT("."), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			50, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_DOT, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("="), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			95, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_RESULT, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("/"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			140, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_DIV, NULL, NULL);
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case IDC_BUTTON_DOWN_0: {
			InsertString(HEX_NUMBER_0);
			break;
		}
		case IDC_BUTTON_DOWN_1: {
			InsertString(HEX_NUMBER_1);
			break;
		}
		case IDC_BUTTON_DOWN_2: {
			InsertString(HEX_NUMBER_2);
			break;
		}
		case IDC_BUTTON_DOWN_3: {
			InsertString(HEX_NUMBER_3);
			break;
		}
		case IDC_BUTTON_DOWN_4: {
			InsertString(HEX_NUMBER_4);
			break;
		}
		case IDC_BUTTON_DOWN_5: {
			InsertString(HEX_NUMBER_5);
			break;
		}
		case IDC_BUTTON_DOWN_6: {
			InsertString(HEX_NUMBER_6);
			break;
		}
		case IDC_BUTTON_DOWN_7: {
			InsertString(HEX_NUMBER_7);
			break;
		}
		case IDC_BUTTON_DOWN_8: {
			InsertString(HEX_NUMBER_8);
			break;
		}
		case IDC_BUTTON_DOWN_9: {
			InsertString(HEX_NUMBER_9);
			break;
		}
		case IDC_BUTTON_DOWN_ADD: {
			InsertString(HEX_EXPRESSION_ADD);
			break;
		}
		case IDC_BUTTON_DOWN_SUB: {
			InsertString(HEX_EXPRESSION_SUB);
			break;
		}
		case IDC_BUTTON_DOWN_MUL: {
			InsertString(HEX_EXPRESSION_MUL);
			break;
		}	
		case IDC_BUTTON_DOWN_DIV: {
			InsertString(HEX_EXPRESSION_DIV);
			break;
		}
		case IDC_BUTTON_DOWN_DOT: {
			InsertString(HEX_EXPRESSION_DOT);
			break;
		}
		case IDC_BUTTON_DOWN_RESULT: {
			break;
		}
		}
		break;
	}
	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}
	default: {
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	}
	UpdateWindow(hwnd);
	return 0;
}

int WINAPI FuncRegisterClass(HINSTANCE hInstance)
{
	WNDCLASS wc = { NULL };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WndClassName;
	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	return RegisterClass(&wc);
}

UINT WINAPI InsertString(UINT str) {
	length = GetWindowText(hWndEdit, EditBuffer, 20);
	EditBuffer[length * 2] = str;
	EditBuffer[(length * 2) + 1] = NULL;

	SetWindowText(hWndEdit, EditBuffer);
	return 0;
}
