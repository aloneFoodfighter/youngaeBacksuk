#include "stdafx.h"
#include "Little_Third.h"


Little_Third::Little_Third()
{
}


Little_Third::~Little_Third()
{
}

void Little_Third::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.5f, 1.0f, 0.5f);
	D3DXMatrixTranslation(&matT, 3.8f, 1.4f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
	m_vLocalPos.y += 2.0f;
}
