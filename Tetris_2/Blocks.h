//====================================================================================================
//* Author:
//* - mr5
//*
//* File:
//* - Blocks.h
//*
//* Description:
//* - All the Tetris blocks with their respective rotations and displacements for the hotspot
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

class CBlocks : public CBase
{
public:
	int SetBlockType			(eCells, int, int, int);
	//The unseen
	int GetXInitialPosition		(eCells, int);
	int GetYInitialPosition		(eCells, int);
	//The virtual
	int GetmXInitialPosition	(eCells, int);
	int GetmYInitialPosition	(eCells, int);
};