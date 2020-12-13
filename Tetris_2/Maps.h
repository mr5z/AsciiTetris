//====================================================================================================
//* Author:
//* - M.A. Laureta
//*
//* File:
//* - Base.h
//*
//* Description:
//* - Contains Maps for tetris' Block spins test
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

class CMaps : public CBase
{
public:
	CMaps() { circle[0] = 0; circle[1] = 4; }
	int T_SpinMap1(int);
	int T_SpinMap2(int);
	int T_SpinMap3(int);
	int I_SpinMap1(int);
	int I_SpinMap2(int);
	int Decimal(int,int,int);
	void Timer(int,int,int,int);
	void Num(int,int,int,int,int,int,int);
	int circle[2];
};