//====================================================================================================
//* Author:
//* - mr5
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

#include "Draw.h"
#include "Base.h"
#include <ctime>

class CMenu : public CBase
{
public:
	void ShowIntro();
	void MainMenu();
private:
	inline void Delay(int delay)
	{ clock_t timer; timer = clock () + delay; while (clock() < timer);}
	CDraw draw_;
};
