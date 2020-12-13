
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
