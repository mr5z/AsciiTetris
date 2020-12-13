#include <Windows.h>
#include <stdio.h>
#include <conio.h>


#ifndef _SHITTY_CODES_
 #define _SHITTY_CODES_

//varies among platforms
//CHANGE THIS

#define UP			0x48
#define DOWN		0x50
#define LEFT		0x4B
#define RIGHT		0x4D

#define SBAR		32
#define TAB			1
#define HOLD		'c'
#define ENTER		13
#define ESC			27

#define ROTATE_CW	'z'
#define ROTATE_CCW	'x'

#define KEY		_getch()


HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO info;
COORD coord;

namespace txtBase
{

	void SetColor(int color)
	{
		SetConsoleTextAttribute(handle, color);
	}

	void MoveTo(int x, int y)
	{
		coord.X = x;
		coord.Y = y;
	}

	void PrintText(int x, int y, int color, int num)
	{
		MoveTo(x, y);
		SetColor(color);
		printf("%d", num);
	}

	void PrintText(int x, int y, int color, const char* str, int num)
	{
		MoveTo(x, y);
		SetColor(color);
		printf("%s%d", str, num);
	}

	void PrintText(int x, int y, int color, const char* str)
	{
		MoveTo(x, y);
		SetColor(color);
		printf(str);
	}

	void RemoveBlinkingCursor()
	{
		info.bVisible = FALSE;
		info.dwSize = 1;
		SetConsoleCursorInfo(handle, &info);
	}

	void SetWindowSize(SHORT width, SHORT height)
	{
		_SMALL_RECT rect;
		rect.Top = 0;
		rect.Left = 0;
		rect.Bottom = height - 1;
		rect.Right = width - 1;

		SetConsoleScreenBufferSize(handle, coord);

		SetConsoleWindowInfo(handle, TRUE, &rect);

	}

	void InitActiveScreenBuffer()
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