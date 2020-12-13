//====================================================================================================
//* Author:
//* - M.A. Laureta
//*
//* File:
//* - Game.h
//*
//* Description:
//* - General class for the game
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

#include "Base.h"
#include "Blocks.h"
#include "Board.h"
#include "Draw.h"
#include "GameMenu.h"
#include "Info.h"
#include "Maps.h"

class CGame : public CBase
{
public:
	CGame() : Info(Board.Info) {}
	void InitGame();
	void CreateNewBlock();
	void HoldBlock();
	void DrawAll();
protected:
	CBlocks *cpBlocks;
	CDraw   *cpDraw;
public:
	void SetTimer(int&,int&,int&);
	int bhType;
	int bhRotation;
	bool isEmpty;
	int tempType, tempRotation;
	//Classes
	CBlocks Block;
	CDraw   Draw;
	CBoard  Board;
	CMaps	Maps;
	CMenu   Menu;
	CInfo&	Info;
};