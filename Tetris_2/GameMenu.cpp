#include "GameMenu.h"
#include <conio.h>

bool EXIT = false;

#define O SINGLE_LINE
#define X OFF

char dots[4][4] = {"   ", ".  ", ".. ", "..."};

int ax[] = {2,3,4,5,6,6,6,6,6,6,6,6,6,6,6,7,8,8,8,8,8,8,8,8,7,6,6,6,6,6,6,6,6,6,6,6,6,6};
int bx[] = {2,2,2,2,2,2,2,3,4,4,4,4,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,4,4,4,4,3,2,2,2,2};
int cx[] = {4,4,4,4,4,4,4,4,4,4,4,4,5,6,6,6,6,6,6,6,7,8,8,8,8,8,8,8,7,6,6,6,6,5,4,4,4,4};
int dx[] = {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,4,4,4,4,4,4,4,4,4,4,4,4,3,2,2,2,2,2,2,2,2,2};

int ay[] = {2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,4};
int by[] = {4,4,4,4,4,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
int cy[] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
int dy[] = {4,4,4,4,4,4,4,4,4,4,5,6,6,6,6,6,6,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,2,2,2,2};

void CMenu::ShowIntro()
{
	for(int i = 0, j = 6, k = 0, l = 0;true;++i, ++k){
		//animations
		txtBase::PrintText(35,30,15,"Loading");
		for(int m = 0;m < 4; ++m)
		{ printf("%c",dots[l][m]); }
		draw_.cell(ax[i],ay[i],O,33,22,j);		draw_.cell(bx[i],by[i],O,33,22,j);
		draw_.cell(cx[i],cy[i],O,33,22,j);		draw_.cell(dx[i],dy[i],O,33,22,j);
		Delay(100);
		//clearing
		draw_.cell(ax[i],ay[i],X,33,22,j);		draw_.cell(bx[i],by[i],X,33,22,j);
		draw_.cell(cx[i],cy[i],X,33,22,j);		draw_.cell(dx[i],dy[i],X,33,22,j);
		//effects
		if(i % 4 == 0) l = (l + 1) % 4;			if(i == 37) i = 0;
		if(i % 6 == 0) j = (j + 1) % 7;			if(k > 114 || _kbhit()){ txtBase::PrintText(35,30,15,"          "); break; }
	}
}

void CMenu::MainMenu()
{
	int bwColor[3] = {240,15,15};
	int i(0);
	bool done(false);
	while(!done)
	{
		txtBase::PrintText(35,22,bwColor[(i+3)%3],"  Start Game  ");
		txtBase::PrintText(35,24,bwColor[(i+5)%3],"Customize Game");
		txtBase::PrintText(35,26,bwColor[(i+4)%3],"  Exit Game   ");
		switch(_getch())
		{
		case UP:
			i = (i - 1)%3;
			break;
		case DOWN:
			i = (i + 1)%3;
			break;
		case ESC:
			EXIT = true;
		case ENTER:
			done = true;
			
		}
	}
	if(i == 2 || i == -1)
		EXIT =  true;
	else if(i == 1 || i == - 2){
		printf("Coming soon!"); Delay(1000); EXIT =  true; }
}