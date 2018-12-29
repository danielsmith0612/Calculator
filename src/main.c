#include <windows.h>

#define WIDTH  (500)
#define HEIGHT (800)

LPCWSTR WndClassName = TEXT("DefaultUserInterface");

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI FuncRegisterClass(HINSTANCE hInstance);
HWND WINAPI FuncCreateButton(LPSTR WndButtonContext, UINT x, UINT y, UINT w, UINT h, HWND hWndParent);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR CmdLine, int CmdShow)
{	
	FuncRegisterClass(hInstance);

	HWND hwnd = CreateWindowEx(
		NULL,
		WndClassName,
		TEXT("Calculator"),
		WS_OVERLAPPEDWINDOW,
		0, 0, WIDTH, HEIGHT, NULL, NULL,
		hInstance, NULL
	);

	ShowWindow(hwnd, CmdShow);

	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	COLORREF color;
	switch (uMsg) {
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, (WIDTH / 2), 0, TEXT("Calculator"), sizeof("Calculator"));
		EndPaint(hwnd, &ps);
		FuncCreateButton(TEXT("Shit"), 10, 10, 50, 20, hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
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
	wc.hbrBackground = GetStockObject(WHITE_BRUSH);
	return RegisterClass(&wc);
}

HWND WINAPI FuncCreateButton(LPSTR WndButtonContext, UINT x, UINT y, UINT w, UINT h, HWND hWndParent)
{
	HWND hWndButton = CreateWindow(
		TEXT("BUTTON"),
		WndButtonContext,
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
		x, y, w, h,
		hWndParent,
		NULL, NULL, NULL);
	return hWndButton;
}
