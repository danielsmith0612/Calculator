#pragma once
#ifndef MAIN_H
#define MAIN_H

#define WIDTH  (500)
#define HEIGHT (700)

#define IDC_BUTTON_DOWN_1 (1)
#define IDC_BUTTON_DOWN_2 (2)
#define IDC_BUTTON_DOWN_3 (3)
#define IDC_BUTTON_DOWN_4 (4)
#define IDC_BUTTON_DOWN_5 (5)
#define IDC_BUTTON_DOWN_6 (6)
#define IDC_BUTTON_DOWN_7 (7)
#define IDC_BUTTON_DOWN_8 (8)
#define IDC_BUTTON_DOWN_9 (9)

int WINAPI FuncRegisterClass(HINSTANCE hInstance);
HWND WINAPI FuncCreateButton(LPSTR string, UINT x, UINT y, UINT w, UINT h, HWND hParent);
HWND WINAPI FuncCreateButton(LPSTR string, UINT x, UINT y, UINT w, UINT h, HWND hParent, int idC);

#endif

