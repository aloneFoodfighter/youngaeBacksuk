#include "stdafx.h"
#include "RightForearm.h"


RightForearm::RightForearm()
{
}


RightForearm::~RightForearm()
{
}

void RightForearm::Setup(char* texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMATRIXA16 matR;

	D3DXMatrixScaling(&matS, 0.3f, 0.8f, 0.4f);

	D3DXMatrixIdentity(&matR);
	D3DXMatrixTranslation(&matT, 1.15f, -2.0f, 0.0f);
	matWorld = matS * matR * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.y += 0.8f;
}