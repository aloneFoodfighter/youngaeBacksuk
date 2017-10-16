#pragma once
class cGrid
{
private:
	vector<ST_LT_VERTEX> m_TexVec;

	IDirect3DTexture9* _ground;

public:
	cGrid();
	~cGrid();

	void Setup();
	void Render();
};

