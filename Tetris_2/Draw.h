//====================================================================================================
//* Author:
//* - M.A. Laureta
//*
//* File:
//* - Draw.h
//*
//* Description:
//* - Serves as the graphical drawing of the cells.
//*
//* Acknowledgement:
//* - thanks to gametuto.com
//* - with the help from "tetris_tutorial_sdl"
//*	  by Mr. Javier López López (javilop.com)
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

class CDraw : public CBase
{
public:
	void cell			(int bX, int bY, eVis bVis, int xtendX, int xtendY, int cColor);

	void PivotColor		(eCells);
	void TetrisBlock	(eCells, int, int,int,eVis);

	CBlocks *cpBlocks;

};

