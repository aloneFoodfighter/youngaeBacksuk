#include "stdafx.h"
#include "LeftCalf.h"


LeftCalf::LeftCalf()
{
}


LeftCalf::~LeftCalf()
{
}

void LeftCalf::Setup(char* texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.4f, 0.8f, 0.4f);
	D3DXMatrixTranslation(&matT, -0.4f, -4.0f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
}
