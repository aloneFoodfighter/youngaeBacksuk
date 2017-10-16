#pragma once

#define MAX_XPIXEL   1536
#define MAX_YPIXEL   1152
#define ONE_XPIXEL   MAX_XPIXEL / 4
#define ONE_YPIXEL   MAX_YPIXEL / 3
#define ONE_XPER   (float)ONE_XPIXEL / (float)MAX_XPIXEL
#define ONE_YPER   (float)ONE_YPIXEL / (float)MAX_YPIXEL

struct tagCube
{
	vector<ST_LT_VERTEX>	m_vecCube;

	//IDirect3DTexture9*	_tex;

	int texNum;

	D3DXMATRIXA16		m_World;
	D3DXMATRIXA16		m_Rot;
	D3DXMATRIXA16		m_Trans;

	D3DCOLOR			alpha;
	int					alphaNum;

	SYNTHESIZE(D3DXVECTOR3, m_Position, Pos)
};


class mCube
{
private:
	vector<LPDIRECT3DTEXTURE9> vpTexture;
	vector<tagCube> _cube;

	int num;
	int count;


public:
	mCube();
	~mCube();

	void Setup();
	void Update();
	void Render();

	void AddCube();
	void SettingCube(tagCube& cube);
	void AddTexture(char* texName);

	void SaveFile();
	void LoadFile();
};

