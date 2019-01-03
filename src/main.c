#include <windows.h>
#include "main.h"

LPCWSTR WndClassName = TEXT("DefaultUserInterface");

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
	int ButtonGridWidth = WIDTH / 5;
	int ButtonGridHeight = (HEIGHT / 7) + 50;
	switch (uMsg) {
	case WM_CREATE: {
		FuncCreateButton(TEXT("7"), ButtonGridWidth, ButtonGridHeight, 70, 50, hwnd, IDC_BUTTON_DOWN_7);
		FuncCreateButton(TEXT("8"), ButtonGridWidth * 2, ButtonGridHeight, 70, 50, hwnd, IDC_BUTTON_DOWN_8);
		FuncCreateButton(TEXT("9"), ButtonGridWidth * 3, ButtonGridHeight, 70, 50, hwnd, IDC_BUTTON_DOWN_9);

		FuncCreateButton(TEXT("4"), ButtonGridWidth, ButtonGridHeight * 2, 70, 50, hwnd, IDC_BUTTON_DOWN_4);
		FuncCreateButton(TEXT("5"), ButtonGridWidth * 2, ButtonGridHeight * 2, 70, 50, hwnd, IDC_BUTTON_DOWN_5);
		FuncCreateButton(TEXT("6"), ButtonGridWidth * 3, ButtonGridHeight * 2, 70, 50, hwnd, IDC_BUTTON_DOWN_6);

		FuncCreateButton(TEXT("1"), ButtonGridWidth, ButtonGridHeight * 3, 70, 50, hwnd, IDC_BUTTON_DOWN_1);
		FuncCreateButton(TEXT("2"), ButtonGridWidth * 2, ButtonGridHeight * 3, 70, 50, hwnd, IDC_BUTTON_DOWN_2);
		FuncCreateButton(TEXT("3"), ButtonGridWidth * 3, ButtonGridHeight * 3, 70, 50, hwnd, IDC_BUTTON_DOWN_3);
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) { // button event process
		case IDC_BUTTON_DOWN_1:

			break;
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

HWND WINAPI FuncCreateButton(LPSTR string, UINT x, UINT y, UINT w, UINT h, HWND hParent, int idC)
{
	HWND hButton = CreateWindow(
		TEXT("BUTTON"),
		string,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD,
		x, y, w, h,
		hParent,
		idC, NULL, NULL);
	return hButton;
}
