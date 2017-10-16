#include "stdafx.h"
#include "Side_Palm.h"


Side_Palm::Side_Palm()
{
}


Side_Palm::~Side_Palm()
{
}

void Side_Palm::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 1.5f, 5.0f, 1.1f);
	D3DXMatrixTranslation(&matT, 3.0f, 0.0f, -0.15f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}
