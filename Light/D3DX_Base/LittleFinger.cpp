#include "stdafx.h"
#include "LittleFinger.h"


LittleFinger::LittleFinger()
{
}


LittleFinger::~LittleFinger()
{
}

void LittleFinger::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.7f, 1.2f, 0.7f);
	D3DXMatrixTranslation(&matT, 3.8f, 1.2f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.y += 5.0f;
}
