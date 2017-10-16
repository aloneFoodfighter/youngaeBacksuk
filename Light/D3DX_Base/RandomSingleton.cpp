#include "stdafx.h"
#include "RandomSingleton.h"


RandomSingleton::RandomSingleton()
{
	srand(GetTickCount());
}


RandomSingleton::~RandomSingleton()
{
}
