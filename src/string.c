#include <windows.h>
#include "main.h"

#define BUFFER_SIZE (128)

static UINT LoopVar;
static UINT StringLength;
char StringBuffer[128];

UINT WINAPI fnInsertStrings(static HWND hwnd, static char String[BUFFER_SIZE])
{
	StringLength = GetWindowText(hwnd, StringBuffer, BUFFER_SIZE);
	for (LoopVar = 0; LoopVar < strlen(String); LoopVar++) {
		*(StringBuffer + (LoopVar * 2) + (StringLength * 2)) = *(String + LoopVar);
		*(StringBuffer + ((LoopVar * 2) + 2) + (StringLength * 2)) = NULL;
	}
	SetWindowText(hwnd, StringBuffer);
	return 0;
}

UINT WINAPI fnClearStrings(static HWND hwnd)
{
	StringLength = GetWindowText(hwnd, StringBuffer, BUFFER_SIZE);
	memset(&StringBuffer, NULL, BUFFER_SIZE);
	SetWindowText(hwnd, StringBuffer);
	return 0;
}
