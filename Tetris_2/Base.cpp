#include "Base.h"
#include <Windows.h>

void CBase::InitColors()
{
	for(int i = 0;i < CMAX; ++i){
		if(i == CMAX - 1) bColor[i] = eColor(bgColor - 9);
		else bColor[i] = eColor(i+bgColor);
	}
}

void CBase::InitPieceTypes()
{
	int P_[] = {0x20,0x20,0x20,0x20,	//Empty blocks
				0xDA,0xBF,0xC0,0xD9,	//Single line blocks
				0xC9,0xBB,0xC8,0xBC};	//Double line blocks

	for(int type(0),X(0);type < 3; ++type){
		for(int i(0);i < 4; ++i,++X)
			piece[type][i] = P_[X];
	}
}

int bKinds	[ ]		=	{0,1,2,3,4,5,6};
int bCounter[ ][7]	=	{{0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0}};//bCounter[1][4-6] are not used

//well, I just make this because I want all
//the blocks appear once in every 7 sequence
//of occurence as well as the rotations.
//sometimes it seems don't work well and
//still not sure if working all the time (can't figure it out)
int CBase::GetRand(int nBase, int nValue, int nX, int i)
{
	//counts the type of Block that has been loaded
	for(i = 0;i < nValue; ++i){
		if(bKinds[i] == nBase && bCounter[nX][i] == 0)
			++bCounter[nX][i];
	}
	//checks if bCounter is full of 1s already, if so, it resets it to 0s
	for(i = 0;i < nValue; ++i){
		if(bCounter[nX][i] == 0)
			break;
		else if(i == nValue - 1){
			for(i = 0;i < nValue; ++i)
				bCounter[nX][i] = 0;
		}

	}
	//loads the type of the Block that hasn't been loaded yet
	while(true){
		if(bCounter[nX][(i = (rand() % nValue))] == 0)
			return i;
	}
}