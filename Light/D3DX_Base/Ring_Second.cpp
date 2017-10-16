#include "stdafx.h"
#include "Ring_Second.h"


Ring_Second::Ring_Second()
{
}


Ring_Second::~Ring_Second()
{
}

void Ring_Second::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.8f, 1.5f, 0.8f);
	D3DXMatrixTranslation(&matT, 1.6f, 1.5f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
	m_vLocalPos.y += 3.0f;
}
