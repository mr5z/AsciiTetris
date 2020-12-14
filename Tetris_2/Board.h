//====================================================================================================
//* Author:
//* - mr5
//*
//* File:
//* - Board.h
//*
//* Description:
//* - Board of the game. A matrix of n x n holes.
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

#include "Blocks.h"
#include "Draw.h"
#include "Base.h"
#include "Maps.h"
#include "Info.h"

class CBoard : public CBase
{
public:
	CBoard()					: isLineDeleted(isFull = false),customMap(0)
								{ InitBoard(); RedrawBoard();InitXtendedBoard();};
	void StoreBlock				(eCells, int, int, int,int,int);
	void DeletePossibleLines	();
	bool CanMove				(eCells, int, int, int);
	bool IsFreeBlock			(int,int);
	void RedrawBoard			();
	void CheckBoardPeak			();
	void ClearBoard				();
	void ClearRow				(int, int = 0);
	void FillBoxColor(int,int,int,int);
	bool isFull;
	bool isLineDeleted;
	int customMap;
	CInfo	Info;
private:
	int	XtendedBoard			[BOARD_WIDTH]
								[3];
	int Board					[BOARD_WIDTH]
								[BOARD_HEIGHT];
	void InitBoard();
	void InitXtendedBoard();
	void RedrawXtendedBoard();
	void DeleteLine				(int);
	int  ROWS_TO_CLEAR			[4];
	CBlocks *cpBlocks;
	CMaps   *cpMaps;
	CDraw   Draw;
};