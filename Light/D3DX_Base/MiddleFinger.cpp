#include "stdafx.h"
#include "MiddleFinger.h"


MiddleFinger::MiddleFinger()
{
}


MiddleFinger::~MiddleFinger()
{
}

void MiddleFinger::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 1.0f, 1.7f, 1.0f);
	D3DXMatrixTranslation(&matT, -0.9f, 1.7f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.y += 5.0f;
}
