#include "Board.h"

void CBoard::InitBoard()
{
	for(int l = 0,X = 0;l < BOARD_HEIGHT; ++l){
		for(int w = 0;w < BOARD_WIDTH; ++w, ++X)
			if(customMap == 0)
				Board[w][l] = EMPTY;
			else if(customMap == 1)
				Board[w][l] = cpMaps->T_SpinMap1(X);
			else if(customMap == 2)
				Board[w][l] = cpMaps->T_SpinMap2(X);
			else if(customMap == 3)
				Board[w][l] = cpMaps->T_SpinMap3(X);
			else if(customMap == 4)
				Board[w][l] = cpMaps->I_SpinMap1(X);
			else if(customMap == 5)
				Board[w][l] = cpMaps->I_SpinMap2(X);
	}
}

void CBoard::InitXtendedBoard()
{
	for(int l = 0;l < 3; ++l){
		for(int w = 0;w < 10; ++w)
			XtendedBoard[w][l] = EMPTY;
	}
}

void CBoard::RedrawXtendedBoard()
{
	for(int l = 0;l < 3; ++l)
	{
		for(int w = 0;w < 10; ++w)
		{
			Draw.cell(w*2,l*2,OFF,BOARD_X + 2,10,CLEAR);
		}
	}
}

void CBoard::RedrawBoard()
{
	int cColor;
	for(int j = BOARD_HEIGHT - 1;j >= boardPeak; --j)
	{	
		for(int i = 0;i < BOARD_WIDTH; ++i)
		{
			//Filters the Board and Draw all recognized token
				switch(Board[i][j])
				{
					case A:	cColor = YELLOW;	break;
					case B:	cColor = CYAN;		break;
					case C:	cColor = WHITE;		break;
					case D:	cColor = BLUE;		break;
					case E:	cColor = RED;		break;
					case F:	cColor = GREEN;		break;
					case G:	cColor = MAGENTA;	break;
					/*case PIVOT:	cColor = WHITE;	break;*/
					case EMPTY: cColor = CLEAR;	break;
				}
				{ Draw.cell(i*2,j*2,xVis,BOARD_X + 2,16, cColor); }
		}
	}
	isLineDeleted = false;
}

void CBoard::FillBoxColor(int x1, int y1, int x2, int y2)
{
	for(int i = x1;i < x2; ++i){
		for(int j = y1;j < y2; ++j)
			txtBase::PrintText(i,j,0," ");
	}

}

void CBoard::CheckBoardPeak()
{
	//I added this function to reduce the calculation of redrawing the Board
	//it checks the highest position of Block from bottom to top
	//and also empty the Board when it is full
	for(int l = BOARD_HEIGHT - 1, x = 0;l > 0; --l, x++){
		for(int w = 0;w < BOARD_WIDTH; ++w)
		{
		if	(Board[w][0] != EMPTY){ ClearBoard();Info.BoardHeight = Info.LinesSent = 0;}
		if  (Board[w][l] != EMPTY){ boardPeak = l; Info.BoardHeight = x + 1; break;   }
		}
	}
}

void CBoard::ClearBoard()
{	boardPeak = 0; InitBoard();	RedrawBoard(); RedrawXtendedBoard(); Info.LinesSent = 0; Info.Print(); }

bool CBoard::CanMove (eCells bKind, int nRotation, int bX, int bY)
{
	/* Checks collision with blocks already stored in the Board or the Board limits
	*  This is just to check the 5x5 cells of a blocks with the appropriate area in the Board*/
	for (int i1 = bX, i2 = 0; i1 < bX + PIECE_BLOCKS; ++i1, ++i2)
	{
		for (int j1 = bY, j2 = 0; j1 < bY + PIECE_BLOCKS; ++j1, ++j2)
		{
			// Check if the Block have collided with a Block already stored in the Board
			if (j1 >= 0)
			{
				if ((cpBlocks->SetBlockType (bKind, nRotation, j2, i2) != EMPTY) &&
					(!IsFreeBlock (i1, j1))	)
					return false;
			}
			// Check if the Block is outside the limits of the Board
			if (i1 < 0				||
				i1 > BOARD_WIDTH - 1||
				j1 > BOARD_HEIGHT - 1)
			{
				if (cpBlocks->SetBlockType (bKind, nRotation, j2, i2) != EMPTY)
					return false;
			}
		}
	}
	return true;
}

bool CBoard::IsFreeBlock (int bX, int bY)
{
	return Board [bX][bY] == EMPTY;
}

void CBoard::StoreBlock (eCells nKind, int nRotation, int bX, int bY,int sX,int sY)
{
	// Makes possible to hold again
	isFull = false;
	// Store each cell of the Block into the Board
	for (int i1 = bX, i2 = 0; i1 < bX + PIECE_BLOCKS; ++i1, ++i2)
	{
		for (int j1 = bY, j2 = 0; j1 < bY + PIECE_BLOCKS; ++j1, ++j2)
		{
			// Store only the cells of the blocks that are not empty
			if (cpBlocks->SetBlockType (nKind, nRotation, j2, i2) != EMPTY)
				Board[i1][j1] = cpBlocks->SetBlockType (nKind, nRotation, j2, i2);
		}
	}
	Draw.TetrisBlock(eCells(nKind),nRotation,sX,sY,xVis);
}

void CBoard::DeleteLine(int bY)
{
	++Info.LinesSent;
	for (int row = bY; row > 0; --row)
	{
		for (int col = 0; col < BOARD_WIDTH; ++col)
			Board[col][row] = Board[col][row-1];
	}
}

void CBoard::DeletePossibleLines()
{
	CheckBoardPeak();
	int j = 0;
	for (int x,y = 0; y < BOARD_HEIGHT ; ++y)
	{
		for(x = 0; x < BOARD_WIDTH; ++x)
			if (Board[x][y] == EMPTY) break;
		if (x == BOARD_WIDTH)
		{
			ROWS_TO_CLEAR[++j] = y;
			DeleteLine (y);
			isLineDeleted = true;
		}
	}
	if(isLineDeleted) ClearRow(j);
}

void CBoard::ClearRow(int endPoint, int startPoint)
{
	int i,j;
	while(startPoint < endPoint)
	{
		j = ROWS_TO_CLEAR[++startPoint];
		for(i = 0;i < 10; ++i)
			Draw.cell(i * 2, j * 2, OFF, BOARD_X + 2, 16, 4);
	}
}