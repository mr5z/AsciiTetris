/*
 * I design this main function to implement the most minimal usage of the function that draws the Block
 * as well as minimum CPU usage as it could be.
 * As you can see, there are 3 implementations of drawblocks here
 *
 */

//----Includes all the classes holding the information to make the game---//
#include "Game.h"


#ifndef	WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

void DrawBox(int x, int y, int color, int width, int height);

void InitWindowLayout(CGame Game)
{
	extern bool EXIT;

	// make explicitly use my functions
	using namespace txtBase;
	// windows console with and height	
	int width = 85, height = 58;
	COORD coord = {width,height};
	// windows console title
	SetConsoleTitle(L"Tetris");
	// Sets the size
	SetWindowSize(width, height);
	// initialize the new windows console size
	//InitWindowSize();
	// adapt the screen buffer to new windows console screen size
	//InitScreenBufferSize(coord);
	// eliminate unused screen buffer
	InitActiveScreenBuffer();
	// auto maximizes the win console
	//AutoMaximizeWindow();
	// set the console cursor to invisible
	RemoveBlinkingCursor();
	// disables the close button
	//DisableCloseButton();
	// the pretending "loading"
	Game.Menu.ShowIntro();
	// not yet done with Menu selection
	Game.Menu.MainMenu();
	//checks if user quits the game, if so, terminates the app immediately
	if(EXIT) exit(EXIT_SUCCESS);

	// draws the boundaries of the Board
	DrawBox(31, 9, 22, 48, 11);
	// draws a box on the right of the Board
	DrawBox(56, 19, 17, 12, 7);
	//// draws a box on the left of the Board
	DrawBox(11, 19, 17, 12, 7);

}

int main()
{
	//2 minutes
	int num1 = 2,
		num2 = 0,
		num3 = 0;

	// True when ESC is hitted
	bool Quit = false;
	// Declares the game class object
	CGame MyGame;
	// Initializes my preferred console layout
	InitWindowLayout(MyGame);

	//Initializes variables
	MyGame.InitGame();

	while(!Quit)
	{

		MyGame.SetTimer(num1,num2,num3);

		if(_kbhit())
		{

			//Redraws the invisible Block
			MyGame.Draw.TetrisBlock (eCells(MyGame.bType),MyGame.bRotation,MyGame.mX,MyGame.mY,OFF);

			switch(KEY)
			{

			case UP:
			case ROTATE_CW:
				{
					if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation + 1) % 4),MyGame.nX, MyGame.nY))
						MyGame.bRotation = (MyGame.bRotation + 1) % 4;

					// Maximum CW spins:
					// -T-Spin 1
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation + 1) % 4),MyGame.nX, MyGame.nY + 1))
					{MyGame.bRotation = (MyGame.bRotation + 1) % 4;MyGame.mY ++; MyGame.nY ++;}
					// -T-Spin 2
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation + 1) % 4),MyGame.nX - 1, MyGame.nY))
					{MyGame.bRotation = (MyGame.bRotation + 1) % 4;MyGame.mX --; MyGame.nX --;}
					// -T-Spin 3
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation + 1) % 4),MyGame.nX - 1, MyGame.nY + 1))
					{MyGame.bRotation = (MyGame.bRotation + 1) % 4;MyGame.mX --; MyGame.nX --;MyGame.mY ++; MyGame.nY ++;}
					// -T-Spin 4
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation + 1) % 4),MyGame.nX - 1, MyGame.nY + 2))
					{MyGame.bRotation = (MyGame.bRotation + 1) % 4;MyGame.mY += 2; MyGame.nY += 2; MyGame.mX --; MyGame.nX --;}
					// -L-Spin
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation + 1) % 4),MyGame.nX + 1, MyGame.nY + 1))
					{MyGame.bRotation = (MyGame.bRotation + 1) % 4;MyGame.mY ++; MyGame.nY ++; MyGame.mX ++; MyGame.nX ++;}

					break;
				}

			case ROTATE_CCW:
				{
					if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation - 1) % 4),MyGame.nX, MyGame.nY))
						MyGame.bRotation = (MyGame.bRotation - 1) % 4;

					// Maximum C-CW spins:
					// -T-Spin 1
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation - 1) % 4),MyGame.nX, MyGame.nY + 1))
					{MyGame.bRotation = (MyGame.bRotation - 1) % 4;MyGame.mY ++; MyGame.nY ++;}
					// -T-Spin 2
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation - 1) % 4),MyGame.nX + 1, MyGame.nY))
					{MyGame.bRotation = (MyGame.bRotation - 1) % 4;MyGame.mX ++; MyGame.nX ++;}
					// -T-Spin 3
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation - 1) % 4),MyGame.nX + 1, MyGame.nY + 1))
					{MyGame.bRotation = (MyGame.bRotation - 1) % 4;MyGame.mY ++; MyGame.nY ++; MyGame.mX ++; MyGame.nX ++;}
					// -T-Spin 4
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation - 1) % 4),MyGame.nX + 1, MyGame.nY + 2))
					{MyGame.bRotation = (MyGame.bRotation - 1) % 4;MyGame.mY += 2; MyGame.nY += 2; MyGame.mX ++; MyGame.nX ++;}
					// -L-Spin
					else if(MyGame.Board.CanMove(eCells(MyGame.bType),((MyGame.bRotation - 1) % 4),MyGame.nX - 1, MyGame.nY + 1))
					{MyGame.bRotation = (MyGame.bRotation - 1) % 4;MyGame.mY ++; MyGame.nY ++; MyGame.mX --; MyGame.nX --;}

					break;
				}

			case DOWN:
				{
					if(MyGame.Board.CanMove(eCells(MyGame.bType),MyGame.bRotation,MyGame.nX, MyGame.nY + 1))
					{ MyGame.mY ++; MyGame.nY ++; }
					
					break;
				}

			case LEFT:
				{
					if(MyGame.Board.CanMove(eCells(MyGame.bType),MyGame.bRotation,MyGame.nX - 1, MyGame.nY))
					{ MyGame.mX --; MyGame.nX --; }

					break;
				}

			case RIGHT:
				{
					if(MyGame.Board.CanMove(eCells(MyGame.bType),MyGame.bRotation,MyGame.nX + 1, MyGame.nY))
					{ MyGame.mX ++; MyGame.nX ++; }

					break;
				}

			case SBAR:
				{
					while(MyGame.Board.CanMove(eCells(MyGame.bType),MyGame.bRotation,MyGame.nX, MyGame.nY+1))
					{ MyGame.mY ++; MyGame.nY ++; }

					MyGame.Board.StoreBlock(eCells(MyGame.bType),MyGame.bRotation,MyGame.nX, MyGame.nY, MyGame.mX, MyGame.mY);

					MyGame.CreateNewBlock();

					MyGame.Board.DeletePossibleLines();

					MyGame.Info.Print();

					break;
				}

			case TAB:
				{
					(MyGame.xVis == DOUBLE_LINE) ? MyGame.xVis = SINGLE_LINE : MyGame.xVis = DOUBLE_LINE;

					break;
				}

			case ESC:
				{
					BOOL msg;
					msg = MessageBox(GetConsoleWindow(),L"Exit the Game?",L"ASCII Tetris",1);
					if(msg == 1)
						Quit = true;
					break;
				}

			case HOLD:
				{MyGame.HoldBlock();break;}

			case ENTER:
				{MyGame.Board.ClearBoard();break;}

			}

			//Draws the playing Block
			MyGame.Draw.TetrisBlock (eCells(MyGame.bType),MyGame.bRotation,MyGame.mX,MyGame.mY,MyGame.xVis);

		}

		//Redraw the Board with delay
		if(unsigned(clock()) > MyGame.timer3 + CLEAR_DELAY)
		{

			if(MyGame.Board.isLineDeleted)
			{	MyGame.Board.RedrawBoard();	}

		}

		if(unsigned(clock()) > MyGame.timer1 + GAME_SPEED)
		{

			MyGame.Draw.TetrisBlock (eCells(MyGame.bType),MyGame.bRotation,MyGame.mX,MyGame.mY,OFF);

			MyGame.timer1 = clock();

			if(MyGame.Board.CanMove(eCells(MyGame.bType),MyGame.bRotation,MyGame.nX, MyGame.nY + 1))
			{ MyGame.mY ++; MyGame.nY ++; }

			else
			{	
						MyGame.Board.StoreBlock(eCells(MyGame.bType),MyGame.bRotation,MyGame.nX, MyGame.nY, MyGame.mX, MyGame.mY);

						MyGame.CreateNewBlock();

						MyGame.Board.DeletePossibleLines();

						MyGame.Info.Print();
			}

			//Redraws the playing Block
			MyGame.Draw.TetrisBlock (eCells(MyGame.bType),MyGame.bRotation,MyGame.mX,MyGame.mY,MyGame.xVis);
			
		}

	}

	return 0;

}

void DrawBox(int x, int y, int width, int height, int color)
{
	int top_left = 201;
	int top_right = 187;
	int bottom_right = 188;
	int bottom_left = 200;
	int h = 205;
	int v = 186;
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			txtBase::MoveTo(x + col, y + row);
			txtBase::SetColor(color);
			if (col == 0 && row == 0) {
				printf("%c", top_left);
			}
			else if (col == width - 1 && row == height - 1) {
				printf("%c", bottom_right);
			}
			else if (row == 0 && col == width - 1) {
				printf("%c", top_right);
			}
			else if (col == 0 && row == height - 1) {
				printf("%c", bottom_left);
			}
			else if (col == 0 || col == width - 1) {
				printf("%c", v);
			}
			else if (row == 0 || row == height - 1) {
				printf("%c", h);
			}
		}
	}
}