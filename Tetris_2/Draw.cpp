#include "Draw.h"

void CDraw::TetrisBlock(eCells nBlock, int nRotation, int bX, int bY,eVis vis)
{
	int cColor;
	for(int i1 = bX,i2 = 0; i1 < bX + PIECE_BLOCKS; ++i1, ++i2){
		for(int j1 = bY,j2 = 0; j1 < bY + PIECE_BLOCKS; ++j1, ++j2){
			//Traverses the 5 x 5 matrix and filters the non-empty ones ie. the cells of the blocks
			if(cpBlocks->SetBlockType(eCells(nBlock),nRotation,j2,i2) != EMPTY){
				switch(cpBlocks->SetBlockType(eCells(nBlock),nRotation,j2,i2))
				{
					//Sets color for each type of blocks respectively
					case A:	cColor = YELLOW;	break;
					case B:	cColor = CYAN;		break;
					case C:	cColor = WHITE;		break;
					case D:	cColor = BLUE;		break;
					case E:	cColor = RED;		break;
					case F:	cColor = GREEN;		break;
					case G:	cColor = MAGENTA;	break;
					/*case PIVOT:	cColor = WHITE;	break;*/
				}
				{cell(i1*2,j1*2,vis,0,0,cColor);}
			}
		}
	}
}

//The 2x2 (pixel of char) cell to Draw
void CDraw::cell(int bX, int bY, eVis bVis, int xtendX, int xtendY, int cColor)
{
	txtBase::SetColor(bColor[cColor]);
	txtBase::MoveTo(bX + xtendX,bY + xtendY);		printf("%c%c",piece[bVis][0],piece[bVis][1]);
	txtBase::MoveTo(bX + xtendX,bY + xtendY + 1);	printf("%c%c",piece[bVis][2],piece[bVis][3]);
}