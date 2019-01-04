#pragma once
#ifndef MAIN_H
#define MAIN_H

#define WIDTH  (201)
#define HEIGHT (285)

#define IDC_BUTTON_DOWN_0 (0)
#define IDC_BUTTON_DOWN_1 (1)
#define IDC_BUTTON_DOWN_2 (2)
#define IDC_BUTTON_DOWN_3 (3)
#define IDC_BUTTON_DOWN_4 (4)
#define IDC_BUTTON_DOWN_5 (5)
#define IDC_BUTTON_DOWN_6 (6)
#define IDC_BUTTON_DOWN_7 (7)
#define IDC_BUTTON_DOWN_8 (8)
#define IDC_BUTTON_DOWN_9 (9)

#define IDC_BUTTON_DOWN_ADD (10)
#define IDC_BUTTON_DOWN_SUB (11)
#define IDC_BUTTON_DOWN_MUL (12)
#define IDC_BUTTON_DOWN_DIV (13)
#define IDC_BUTTON_DOWN_DOT (14)
#define IDC_BUTTON_DOWN_RESULT (15)

int WINAPI FuncRegisterClass(HINSTANCE hInstance);
HWND WINAPI FuncCreateButton(LPSTR string, UINT x, UINT y, UINT w, UINT h, HWND hParent);
HWND WINAPI FuncCreateButton(LPSTR string, UINT x, UINT y, UINT w, UINT h, HWND hParent, int idC);

#endif

