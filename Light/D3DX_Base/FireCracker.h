#pragma once

#include "fGrid.h"
#include "FireCube.h"

class FireCracker
{
private:
	fGrid* f_Grid;
	FireCube* f_Cube;

public:
	FireCracker();
	~FireCracker();

	void Setup();
	void Update();
	void Render();
};

