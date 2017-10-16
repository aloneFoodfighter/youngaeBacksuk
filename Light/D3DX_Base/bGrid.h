#pragma once
class bGrid
{
private:
	vector<ST_PC_VERTEXT> m_vecVertex;


public:
	bGrid();
	~bGrid();

	void Setup(int nNumHalfTile = 15, float fInterval = 1.0f);
	void Render();

};

