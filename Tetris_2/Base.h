//====================================================================================================
//* Author:
//* - M.A. Laureta
//*
//* File:
//* - Base.h
//*
//* Description:
//* - Global resources of variables and functions of the classes
//*
//* Acknowledgement:
//* - thanks to gametuto.com
//* - with the help from "tetris_tutorial_sdl"
//*	 by Mr. Javier López López (javilop.com)
//*
//* About the program:
//* - This is an ASCII-based tetris
//*	- Each cells are made of 4 ASCII characters w/c
//*	  occupies four pixels of the console
//*
//* Comments:
//* - The collision detection is not mine
//*   but I understand its implementation
//*	- This program is free of distribution
//*
//*	Attribution:
//* - You must attribute the work in the manner specified by the author or licensor 
//*  (but not in any way that suggests that they endorse you or your use of the work).
//====================================================================================================

#pragma once


//----Includes SDK's and my own reusable functions()----//
#include "MyFunctions.h"

#define		BOARD_WIDTH			10
#define		BOARD_HEIGHT		20
#define		GAME_SPEED			1300
#define		CLEAR_DELAY			400

#define		INIT_X				19
#define		INIT_Y				2

#define		BOARD_X				30
#define		BOARD_Y				10

#define		BOX_COLOR1			153
#define		BOX_COLOR2			118

#define ROTATE_CCW		122
#define ROTATE_CW		120
#define HOLD			99

/*============Do not change this============*/
/**/const int PIECE_BLOCKS = 5;
/**/const int EMPTY = 32;
/**/const int PIVOT = 7;
/**/enum eCells	{A,B,C,D,E,F,G};
/**/enum eVis	{OFF, SINGLE_LINE, DOUBLE_LINE};
/*============Do not change this============*/

class CBase
{
public:
	CBase()				: xVis(xVis = SINGLE_LINE), boardPeak(BOARD_HEIGHT), bgColor(BG_BLACK)
						{ InitColors(); InitPieceTypes(); }
	enum BackGroundColor{BG_BLACK	= 0x09, BG_GRAY		= 0x89, BG_BLUE		= 0x99,//Just to confuse the decimal experts
						 BG_GREEN	= 0xA9, BG_CYAN		= 0xB9, BG_RED		= 0xC9,
						 BG_MAGENTA = 0xD9, BG_YELLOW	= 0xE9, BG_WHITE	= 0xF9};
	enum eColor			{BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE, CLEAR, CMAX};
protected:
	eColor bColor[CMAX];
	void InitColors		();
	void InitPieceTypes	();
	char piece[3][4];
public:
	int bgColor;
	int boardPeak;
	int GetRand			(int,int,int, int = 0);
	unsigned bType, bRotation;
	unsigned nxtType, nxtRotation;
	//coordinates of the unseen moving blocks
	int nX, nY;
	//coordinates of the seen blocks
	int mX,mY;
	//visibility of the current Block
	eVis xVis;
	//timers
	unsigned long timer1;
	unsigned long timer2;
	unsigned long timer3;
};