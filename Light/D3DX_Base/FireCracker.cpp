#include "stdafx.h"
#include "FireCracker.h"


FireCracker::FireCracker()
	: f_Grid(NULL)
	, f_Cube(NULL)
{
}


FireCracker::~FireCracker()
{
	SAFE_DELETE(f_Grid);
	SAFE_DELETE(f_Cube);
}

void FireCracker::Setup()
{
	f_Grid = new fGrid;
	f_Grid->Setup();

	f_Cube = new FireCube;
	f_Cube->Setup();
}

void FireCracker::Update()
{
	if (f_Cube) f_Cube->Update();

}

void FireCracker::Render()
{
	if (f_Grid)	f_Grid->Render();

	if (f_Cube)	f_Cube->Render();
}
