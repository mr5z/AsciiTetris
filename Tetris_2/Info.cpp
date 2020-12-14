#include "Info.h"

void CInfo::Print()
{
	txtBase::PrintText(58,40,15,"Lines Sent   = ", LinesSent);
	txtBase::PrintText(58,42,15,"Board Height = ", BoardHeight);
}