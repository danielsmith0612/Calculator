#pragma once
#ifndef MAIN_H
#define MAIN_H

#define WIDTH  (201)
#define HEIGHT (285)

#define HEX_NUMBER_0 (0x30)
#define HEX_NUMBER_1 (0x31)
#define HEX_NUMBER_2 (0x32)
#define HEX_NUMBER_3 (0x33)
#define HEX_NUMBER_4 (0x34)
#define HEX_NUMBER_5 (0x35)
#define HEX_NUMBER_6 (0x36)
#define HEX_NUMBER_7 (0x37)
#define HEX_NUMBER_8 (0x38)
#define HEX_NUMBER_9 (0x39)

#define HEX_EXPRESSION_ADD (0x2B)
#define HEX_EXPRESSION_SUB (0x2D)
#define HEX_EXPRESSION_MUL (0x2A)
#define HEX_EXPRESSION_DIV (0x2F)
#define HEX_EXPRESSION_DOT (0x2E)

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

#define IDC_EDIT (16)

int WINAPI FuncRegisterClass(HINSTANCE hInstance);
HWND WINAPI FuncCreateButton(LPSTR string, UINT x, UINT y, UINT w, UINT h, HWND hParent);
HWND WINAPI FuncCreateButton(LPSTR string, UINT x, UINT y, UINT w, UINT h, HWND hParent, int idC);

UINT WINAPI InsertString(UINT str);

#endif

