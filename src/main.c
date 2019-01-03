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
	const ButtonSize = (int)40;
	switch (uMsg) {
	case WM_CREATE: {
		CreateWindow(TEXT("BUTTON"), TEXT("7"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			5, 65, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("8"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			50, 65, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("9"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			95, 65, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("+"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			140, 65, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("4"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			5, 110, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("5"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			50, 110, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("6"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			95, 110, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("-"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			140, 110, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("1"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			5, 155, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("2"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			50, 155, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("3"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			95, 155, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("X"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			140, 155, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("0"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			5, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("."), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			50, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("="), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			95, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);
		CreateWindow(TEXT("BUTTON"), TEXT("/"), WS_TABSTOP | WS_VISIBLE | WS_CHILD,
			140, 200, ButtonSize, ButtonSize,
			hwnd, IDC_BUTTON_DOWN_7, NULL, NULL);


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

