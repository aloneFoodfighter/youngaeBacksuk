#include "stdafx.h"
#include "Index_Third.h"


Index_Third::Index_Third()
{
}


Index_Third::~Index_Third()
{
}

void Index_Third::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.7f, 1.3f, 0.7f);
	D3DXMatrixTranslation(&matT, -3.6f, 1.5f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
	m_vLocalPos.y += 2.6f;
}
