#pragma once
class CubeClass;

class CubeBoy
{
private:
	CubeClass* m_pRoot;

	D3DXMATRIXA16				m_matWorld;
	float						m_fRotY;
	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;
	D3DXMATRIXA16	matR, matT;

	int count;
	int speed;

public:
	CubeBoy();
	~CubeBoy();

	void Setup();
	void Update();
	void Render();

	float getDistance(float x1, float y1, float z1, float x2, float y2, float z2);
};

