//This is a garbage classssssssssssss

#pragma once
#include "Base.h"

class CInfo : public CBase
{
public:
	CInfo() : BoardHeight(0), LinesSent(0),Spins(0)
	{}
	void Print();
	int LinesSent;
	int Spins;
	int BoardHeight;
};

