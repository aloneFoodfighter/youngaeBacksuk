#pragma once
class CubeClass
{
protected:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;

	D3DXMATRIXA16				m_matLocalTM;
	D3DXMATRIXA16				m_matWorldTM;

	D3DXVECTOR3					m_vLocalPos;


	std::vector<CubeClass*>			m_vecChild;

	SYNTHESIZE(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM)
		SYNTHESIZE(float, dX, roX)

		float angleX;



public:
	CubeClass();
	virtual ~CubeClass();

	void AddChild(CubeClass* pChild);
	void Destroy();

	virtual void Setup();
	void Update();
	void Render();
};

