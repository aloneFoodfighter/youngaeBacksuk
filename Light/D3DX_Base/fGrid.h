#pragma once

class fGrid
{
private:
	vector<ST_LT_VERTEX> f_vecGrid;

	IDirect3DTexture9* _tex;


public:
	fGrid();
	~fGrid();

	void Setup();
	void Render();
};

