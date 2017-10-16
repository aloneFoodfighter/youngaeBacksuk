#pragma once

class mGrid
{
private:
	vector<ST_LT_VERTEX> m_vecGrid;

	vector<LPDIRECT3DTEXTURE9> vpTexture;

	IDirect3DTexture9* _tex;
	vector<ST_LT_VERTEX> m_sky;

	UINT texNum;

	D3DCOLOR	alpha;

public:
	mGrid();
	~mGrid();

	void Setup();
	void Update();
	void Render();

	void AddTexture(char* texName);
	void DrawGrid();
	void DrawSky();

	void SaveFile();
	void LoadFile();
};

