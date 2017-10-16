#pragma once

enum BodyPart
{
	PALM, SIDE_PALM, TOP_PALM, BOTTOM_PALM,
	THUMB, S_THUMB,
	INDEX, S_INDEX, T_INDEX,
	MIDDLE, S_MIDDLE, T_MIDDLE,
	RING, S_RING, T_RING,
	LITTLE, S_LITTLE, T_LITTLE,
	JOINT, WRIST
};

class cCube
{
protected:
	vector<ST_LT_VERTEX>	m_vecVertex;

	//vector<ST_PC_VERTEXT> m_vecVertex;

	D3DXMATRIXA16				m_matLocalTM;
	D3DXMATRIXA16				m_matWorldTM;

	D3DXVECTOR3					m_vLocalPos;


	std::vector<cCube*>			m_vecChild;

	D3DXMATRIXA16	_matR, _matT;
	
	
	D3DXMATRIXA16 roX, roY, roZ;
	float angleX, angleY, angleZ;


	BodyPart bodyP;

	bool bend;

	SYNTHESIZE(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM)


	IDirect3DTexture9* _skin;
	

public:
	cCube();
	virtual ~cCube();

	void AddChild(cCube* pChild);
	void Destroy();

	virtual void Setup(char* texture, BodyPart body);
	void Update();
	void Render();
	virtual void Animation();
	void PartAni(BodyPart body, bool ani, float _angleX, float _angleY, float _angleZ, float range);
	
};

