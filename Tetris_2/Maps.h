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