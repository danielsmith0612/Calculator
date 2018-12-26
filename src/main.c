#include <windows.h>

#define WIDTH (500)
#define HEIGHT (800)

LPCSTR WndClassName = TEXT("MyCalculator");

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR CmdLine, int CmdShow)
{
	WNDCLASS wc = { NULL };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WndClassName;
	wc.hbrBackground = GetStockObject(WHITE_BRUSH);
	RegisterClass(&wc);
	
	HWND hCalculator = CreateWindowEx(
		NULL,
		WndClassName,
		TEXT("Calculator"),
		WS_OVERLAPPEDWINDOW,
		0, 0, WIDTH, HEIGHT, NULL, NULL,
		hInstance, NULL
	);

	ShowWindow(hCalculator, CmdShow);

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
		color = RGB(255, 0, 0);
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, (WIDTH / 2), 0, TEXT("Calculator"), sizeof("Calculator"));
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}
