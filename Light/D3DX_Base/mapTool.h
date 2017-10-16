#pragma once

#include "mGrid.h"
#include "mCube.h"

class mapTool
{
private:
	mGrid * m_mGrid;

	mCube * m_mCube;

	bool wire;

public:
	mapTool();
	~mapTool();

	void Setup();
	void Update();
	void Render();
	
	void SaveFile();
	void LoadFile();
};

