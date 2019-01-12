#include <windows.h>
#include "main.h"

#define BUFFER_SIZE (128)

LPCWSTR WndClassName = TEXT("DefaultUserInterface");
char StringBuffer[BUFFER_SIZE];
UINT StringLength = 0;
int Value = 0, FirstValue = 0, SecondValue = 0;
long double Result = 0;
UINT CurrentExpression;
char temp[BUFFER_SIZE];
HWND hWndEditTextBox;

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
	switch (uMsg) {
	case WM_CREATE: {
		hWndEditTextBox = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | ES_LEFT | WS_BORDER,
			3, 10, 180, 40,
			hwnd, IDC_EDIT, NULL, NULL);
		CreateButton(hwnd);
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case IDC_BUTTON_DOWN_0: {
			fnInsertStrings(hWndEditTextBox, "0");
			Value = (Value * 10);
			break;
		}
		case IDC_BUTTON_DOWN_1: {
			fnInsertStrings(hWndEditTextBox, "1");
			Value = (Value * 10) + 1;
			break;
		}
		case IDC_BUTTON_DOWN_2: {
			fnInsertStrings(hWndEditTextBox, "2");
			Value = (Value * 10) + 2;
			break;
		}
		case IDC_BUTTON_DOWN_3: {
			fnInsertStrings(hWndEditTextBox, "3");
			Value = (Value * 10) + 3;
			break;
		}
		case IDC_BUTTON_DOWN_4: {
			fnInsertStrings(hWndEditTextBox, "4");
			Value = (Value * 10) + 4;
			break;
		}
		case IDC_BUTTON_DOWN_5: {
			fnInsertStrings(hWndEditTextBox, "5");
			Value = (Value * 10) + 5;
			break;
		}
		case IDC_BUTTON_DOWN_6: {
			fnInsertStrings(hWndEditTextBox, "6");
			Value = (Value * 10) + 6;
			break;
		}
		case IDC_BUTTON_DOWN_7: {
			fnInsertStrings(hWndEditTextBox, "7");
			Value = (Value * 10) + 7;
			break;
		}
		case IDC_BUTTON_DOWN_8: {
			fnInsertStrings(hWndEditTextBox, "8");
			Value = (Value * 10) + 8;
			break;
		}
		case IDC_BUTTON_DOWN_9: {
			fnInsertStrings(hWndEditTextBox, "9");
			Value = (Value * 10) + 9;
			break;		
		}
		case IDC_BUTTON_DOWN_ADD: {
			if (FirstValue == 0) {
				FirstValue = Value;
			}
			else {
				SecondValue = Value;
			}
			Value = 0;
			fnClearStrings(hWndEditTextBox);

			CurrentExpression = FLAG_ADD;
			break;
		}
		case IDC_BUTTON_DOWN_SUB: {
			if (FirstValue == 0) {
				FirstValue = Value;
			}
			else {
				SecondValue = Value;
			}
			Value = 0;
			fnClearStrings(hWndEditTextBox);
			CurrentExpression = FLAG_SUB;
			break;
		}
		case IDC_BUTTON_DOWN_MUL: {
			if (FirstValue == 0) {
				FirstValue = Value;
			}
			else {
				SecondValue = Value;
			}
			Value = 0;
			fnClearStrings(hWndEditTextBox);
			
			CurrentExpression = FLAG_MUL;
			break;
		}
		case IDC_BUTTON_DOWN_DIV: {
			if (FirstValue == 0) {
				FirstValue = Value;
			}
			else {
				SecondValue = Value;
			}
			Value = 0;
			fnClearStrings(hWndEditTextBox);
		
			CurrentExpression = FLAG_DIV;
			break;
		}
		case IDC_BUTTON_DOWN_DEL: {
			StringLength = GetWindowText(hWndEditTextBox, StringBuffer, BUFFER_SIZE);
			StringBuffer[(StringLength - 1) * 2] = NULL;
			SetWindowText(hWndEditTextBox, StringBuffer);
			break;
		}
		case IDC_BUTTON_DOWN_RESULT: {
			SecondValue = Value;
			switch (CurrentExpression) {
			case FLAG_ADD: {
				Result = FirstValue + SecondValue;
				break;
			}
			case FLAG_SUB: {
				Result = FirstValue - SecondValue;
				break;
			}
			case FLAG_MUL: {
				Result = FirstValue * SecondValue;
				break;
			}
			case FLAG_DIV: {
				Result = FirstValue / SecondValue;
				break;
			}
			default: {
				MessageBox(hwnd, TEXT("Error: please enter expression one or more"), TEXT("Calculator"), MB_OK);
			}
			}
			fnClearStrings(hWndEditTextBox);
			itoa(Result, temp, 10);
			fnInsertStrings(hWndEditTextBox, &temp);

			SecondValue = 0;
			FirstValue = Result;
			Result = 0;
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

UINT WINAPI fnRegisterClassButton(HINSTANCE hInstance)
{
	return 0;
}
