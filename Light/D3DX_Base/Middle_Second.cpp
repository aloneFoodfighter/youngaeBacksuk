#include "stdafx.h"
#include "Middle_Second.h"


Middle_Second::Middle_Second()
{
}


Middle_Second::~Middle_Second()
{
}

void Middle_Second::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 0.9f, 1.7f, 0.9f);
	D3DXMatrixTranslation(&matT, -0.9f, 1.7f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.y += 3.4f;
}
