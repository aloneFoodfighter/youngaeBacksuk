#pragma once

struct tagFire
{
	vector<ST_LT_VERTEX> cubeVex;

	SYNTHESIZE(D3DXVECTOR3, m_Position, Pos)

	D3DXMATRIXA16 World;
	D3DXMATRIXA16 matT, matS, matR;

	D3DXVECTOR3 from, via, to;

	bool owner;
};

class FireCube
{
	IDirect3DTexture9* _tex;
	
	vector<tagFire> _cube;

	int c_height;

	bool fire;
	bool cracker;

	int count;
public:
	FireCube();
	~FireCube();

	void Setup();
	void Update();
	void Render();

	void CreateCube(float x, float y, float z, float width, float height, float depth, bool _owner);
	void CubeFire();
	void calBezier(int index);

	void eraseCube(int index);
};

