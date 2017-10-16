#include "stdafx.h"
#include "Palm.h"


Palm::Palm()
{
}


Palm::~Palm()
{
}

void Palm::Setup(char* texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 4.5f, 5.0f, 1.0f);
	D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	//m_vLocalPos.y -= 10.0f;
}
