#include "Game.h"
#include "Info.h"
#include "GameMenu.h"
#include <stdlib.h>

void CGame::InitGame()
{
	// Init random numbers
	srand ((unsigned int) time(NULL));

	// First Block
	isEmpty		= true;
	bType		= GetRand (7,7,0);
	bRotation	= GetRand (4,4,1);
	nX 			= cpBlocks->GetXInitialPosition (eCells(bType), bRotation) + (BOARD_WIDTH / 2);
	nY 			= cpBlocks->GetYInitialPosition (eCells(bType), bRotation);
	mX			= cpBlocks->GetmXInitialPosition(eCells(bType), bRotation) + (BOARD_WIDTH / 2);
	mY			= cpBlocks->GetmYInitialPosition(eCells(bType), bRotation);
	//  Next Block
	nxtType 	= GetRand (bType,7,0);
	nxtRotation = GetRand (bRotation,4,1);
	timer1		= clock();
	timer2		= clock();
	timer3		= clock();
	DrawAll();
}

void CGame::CreateNewBlock()
{
	//Clear the old piece in the box
	Draw.TetrisBlock (eCells(nxtType), nxtRotation, BOARD_X, BOARD_Y, OFF);

	// The new Block
	bType		= nxtType;
	bRotation	= nxtRotation;
	nX 			= cpBlocks->GetXInitialPosition (eCells(bType), bRotation) + (BOARD_WIDTH / 2);
	nY 			= cpBlocks->GetYInitialPosition (eCells(bType), bRotation);
	mX			= cpBlocks->GetmXInitialPosition(eCells(bType), bRotation) + (BOARD_WIDTH / 2);
	mY			= cpBlocks->GetmYInitialPosition(eCells(bType), bRotation);

	// Random next Block
	nxtType = GetRand (bType,7,0);
	nxtRotation	= GetRand (bRotation,4,1);

	// Hold values
	if(isEmpty){
		bhType		= nxtType;
		bhRotation	= nxtRotation;
	}

	// Draw the next Block
	Draw.TetrisBlock (eCells(nxtType), nxtRotation, BOARD_X, BOARD_Y, xVis);
	timer3 = clock();
}

void CGame::HoldBlock()
{
	if(!Board.isFull){

		Board.isFull = true;

		if(isEmpty){
			tempType		= bType;
			bType			= nxtType;
			bhType			= tempType;
	
			tempRotation	= bRotation;
			bRotation		= nxtRotation;
			bhRotation		= tempRotation;
			isEmpty			= false;

			// Clear the next Block
			Draw.TetrisBlock (eCells(nxtType), nxtRotation, BOARD_X, BOARD_Y,OFF);
			// Random next Block
			nxtType 	= GetRand (nxtType,7,0);
			nxtRotation	= GetRand (nxtRotation,4,1);
			// Draw the next Block
			Draw.TetrisBlock (eCells(nxtType), nxtRotation, BOARD_X, BOARD_Y,xVis);
		}
		else{
			//Clear the old hold Block
			Draw.TetrisBlock (eCells(bhType), bhRotation, 7, BOARD_Y,OFF);

			tempType		= bhType;
			bhType			= bType;
			bType			= tempType;

			tempRotation	= bhRotation;
			bhRotation		= bRotation;
			bRotation		= tempRotation;
		}

		// Draw the holded Block
		Draw.TetrisBlock (eCells(bhType), bhRotation, 7, BOARD_Y,xVis);

		nX 			= cpBlocks->GetXInitialPosition (eCells(bType), bRotation) + (BOARD_WIDTH / 2);
		nY 			= cpBlocks->GetYInitialPosition (eCells(bType), bRotation);
		mX			= cpBlocks->GetmXInitialPosition(eCells(bType), bRotation) + (BOARD_WIDTH / 2);
		mY			= cpBlocks->GetmYInitialPosition(eCells(bType), bRotation);

	}
}

void CGame::SetTimer(int& min,int& msec,int& lsec)
{
	if(unsigned(clock()) > timer2 + CLOCKS_PER_SEC){
		Maps.Timer(min,msec,lsec,0);
		timer2 = clock();
		--lsec;
		if(lsec < 0){
			lsec = 9;
			--msec;
			if(msec < 0){
				msec = 5;
				--min;
				if(min < 0){
					min = 2; msec = 0; lsec = 0;
				}
			}
		}
		Maps.Timer(min,msec,lsec,1);
	}	
}

void CGame::DrawAll()
{
	/************ Some additional stuffs ************/
	Board.ClearBoard();

	//Fill the color of the box in the left
	txtBase::PrintText(18,18,15,"HOLD");
	//MoveTo(18,18); SetColor(bColor[WHITE]); printf("HOLD");
	Board.FillBoxColor(13,BOARD_Y*2,26,BOARD_X);

	//Fill the color of the box in the right
	txtBase::PrintText(63,18,15,"NEXT");
	//MoveTo(63,18); SetColor(bColor[WHITE]); printf("NEXT");

	Board.FillBoxColor(58,BOARD_Y*2,71,BOARD_X);
	//Draws the next piece*
	Draw.TetrisBlock (eCells(nxtType), nxtRotation, BOARD_X, BOARD_Y, xVis);
	//Draw the playing Block*
	Draw.TetrisBlock (eCells(bType),bRotation,mX,mY,xVis);
	//Draw the timer once
	Maps.Timer(2,0,0,1);
}
