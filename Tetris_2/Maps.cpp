#include "Maps.h"

#define O EMPTY
enum {V,Z,S,H,R,Q,K};

const int Map1[] =
{
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,1,1,O,O,
	1,1,1,1,1,1,1,O,O,O,
	1,1,1,1,1,1,1,O,1,1,
	1,1,1,1,1,1,1,O,O,1,
	1,1,1,1,1,1,1,O,1,1,
	1,1,1,1,1,1,1,O,O,1,
	1,1,1,1,1,1,1,O,1,1,
	1,1,1,1,1,1,1,O,O,1,
	1,1,1,1,1,1,1,O,1,1,
	1,1,1,1,1,1,1,O,O,1,
	1,1,1,1,1,1,1,O,1,1,
	1,1,1,1,1,1,1,O,O,1,
	1,1,1,1,1,1,1,O,1,1,
	1,1,1,1,1,1,1,O,O,1,
	1,1,1,1,1,1,1,O,1,1,
	1,1,1,1,1,1,1,O,O,1,
	1,1,1,1,1,1,1,O,1,1
};

const int Map2[] =
{
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,1,1,O,O,O,O,O,O,
	O,O,O,1,1,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1,
	1,O,O,1,1,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1,
	1,O,O,1,1,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1,
	1,O,O,1,1,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1,
	1,O,O,1,1,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1,
	1,O,O,1,1,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1,
	1,O,O,1,1,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1,
	1,O,O,1,1,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1
};

const int Map3[] =
{
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,1,1,1,1,1,1,1,1,
	O,O,O,1,1,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1,
	1,O,O,1,1,1,1,1,1,1,
	1,O,O,O,1,1,1,1,1,1,
	1,1,1,O,1,1,1,1,1,1,
	1,1,O,O,1,1,1,1,1,1,
	1,1,O,O,O,1,1,1,1,1,
	1,1,O,1,1,1,1,1,1,1,
	O,O,O,1,5,5,1,5,5,1,
	1,O,O,5,4,4,5,4,4,5,
	1,O,O,1,5,4,4,4,5,1,
	1,O,O,O,1,5,4,5,1,1,
	1,1,1,O,1,1,5,1,1,1,
	1,1,O,O,1,1,1,1,1,1,
	1,1,O,O,O,1,1,1,1,1
};

const int Map4[] =
{
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	O,O,O,O,O,O,O,O,O,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,O,O,O,O,O,O,O,O,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
};

const int Map5[] =
{
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	O,O,O,O,O,O,O,O,O,O,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,O,O,O,O,O,O,O,O,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	1,1,1,1,1,1,1,1,O,1,
	O,O,O,O,O,O,O,O,O,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
	1,O,1,1,1,1,1,1,1,1,
};

const int SSD[10][5][5] =
{
	//0
	{
		{0,1,1,1,0},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{0,1,1,1,0},
	},
	//1
	{
		{0,0,0,0,1},
		{0,0,0,1,1},
		{0,0,0,0,1},
		{0,0,0,0,1},
		{0,0,0,0,1}
	},
	//2
	{
		{0,1,1,1,0},
		{0,0,0,0,1},
		{0,1,1,1,0},
		{1,0,0,0,0},
		{0,1,1,1,0}
	},
	//3
	{
		{0,1,1,1,0},
		{0,0,0,0,1},
		{0,1,1,1,0},
		{0,0,0,0,1},
		{0,1,1,1,0}
	},
	//4
	{
		{1,0,0,0,1},
		{1,0,0,0,1},
		{0,1,1,1,0},
		{0,0,0,0,1},
		{0,0,0,0,1}
	},
	//5
	{
		{0,1,1,1,1},
		{1,0,0,0,0},
		{0,1,1,1,0},
		{0,0,0,0,1},
		{1,1,1,1,0}
	},
	//6
	{
		{0,1,1,1,1},
		{1,0,0,0,0},
		{1,1,1,1,0},
		{1,0,0,0,1},
		{0,1,1,1,0}
	},
	//7
	{
		{1,1,1,1,1},
		{0,0,0,1,0},
		{0,0,1,0,0},
		{0,1,0,0,0},
		{1,0,0,0,0}
	},
	//8
	{
		{0,1,1,1,0},
		{1,0,0,0,1},
		{0,1,1,1,0},
		{1,0,0,0,1},
		{0,1,1,1,0}
	},
	//9
	{
		{0,1,1,1,0},
		{1,0,0,0,1},
		{0,1,1,1,1},
		{0,0,0,0,1},
		{0,0,0,0,1}
	}
};

int CMaps::Decimal(int num, int x, int y)
{
	return SSD[num][y][x];
}

int CMaps::T_SpinMap1(int x)
{
	return Map1[x];
}

int CMaps::T_SpinMap2(int x)
{
	return Map2[x];
}

int CMaps::T_SpinMap3(int x)
{
	return Map3[x];
}

int CMaps::I_SpinMap1(int x)
{
	return Map4[x];
}

int CMaps::I_SpinMap2(int x)
{
	return Map5[x];
}

void CMaps::Timer(int tim1, int tim2, int tim3, int vis)
{
	for(int j = 0;j < 5; ++j){
		for(int i = 0;i < 5; ++i){
			Num(12,tim1,vis,i,j,32,3);
			Num(15,tim2,vis,i,j,39,3);
			Num(15,tim3,vis,i,j,46,3);
		}
	}
}

void CMaps::Num(int color,int num, int vis, int x1, int y1, int x2, int y2)
{
	if(Decimal(num,x1,y1) != 0)
		txtBase::PrintText(x1+x2,y1+y2,color,circle[vis]);
}
