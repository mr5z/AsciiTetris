#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>


#ifndef _SHITTY_CODES_
 #define _SHITTY_CODES_

//varies among platforms
//CHANGE THIS

#define F1			59
#define F2			60
#define F3			61
#define F4			62
#define F5			63

#define UP			0x48
#define DOWN		0x50
#define LEFT		0x4B
#define RIGHT		0x4D

#define SBAR		32
#define TAB			9
#define HOLD		'c'
#define ENTER		13
#define ESC			27

#define ROTATE_CW	'z'
#define ROTATE_CCW	'x'

static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

namespace txtBase
{
	static void SetColor(int color)
	{
		SetConsoleTextAttribute(handle, color);
	}

	static void MoveTo(int x, int y)
	{
		COORD coord = { x, y };
		SetConsoleCursorPosition(handle, coord);
	}

	static void PrintText(int x, int y, int color, int num)
	{
		MoveTo(x, y);
		SetColor(color);
		printf("%c", num);
	}

	static void PrintText(int x, int y, int color, const char* str)
	{
		MoveTo(x, y);
		SetColor(color);
		printf("%s", str);
	}

	static void PrintText(int x, int y, int color, const char* str, int num)
	{
		MoveTo(x, y);
		SetColor(color);
		printf("%s%*d", str, 2, num);
	}

	static void RemoveBlinkingCursor()
	{
		CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(handle, &cursorInfo);
		cursorInfo.bVisible = FALSE; // set the cursor visibility
		cursorInfo.dwSize = 1;
		SetConsoleCursorInfo(handle, &cursorInfo);
	}

	static void SetFontSize(int size)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = size;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		std::wcscpy(cfi.FaceName, L"Lucida Console"); // Choose your font
		SetCurrentConsoleFontEx(handle, FALSE, &cfi);
	}

	static void SetWindowSize(SHORT width, SHORT height)
	{
		SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
		COORD coord = { width - 1, height - 1 };
		SetConsoleWindowInfo(handle, TRUE, &rect);
		SetConsoleScreenBufferSize(handle, coord);
	}

	static void InitActiveScreenBuffer()
	{
		CONSOLE_SCREEN_BUFFER_INFO SBInfo;
		COORD NewSBSize;

		GetConsoleScreenBufferInfo(handle, &SBInfo);
		NewSBSize.X = SBInfo.dwSize.X - 2;
		NewSBSize.Y = SBInfo.dwSize.Y;

		SetConsoleScreenBufferSize(handle, NewSBSize);
	}

};

#endif