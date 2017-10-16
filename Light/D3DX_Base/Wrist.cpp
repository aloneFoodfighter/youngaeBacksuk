#include "stdafx.h"
#include "Wrist.h"


Wrist::Wrist()
{
}


Wrist::~Wrist()
{
}

void Wrist::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 4.0f, 3.0f, 1.0f);
	D3DXMatrixTranslation(&matT, 0.0f, -8.5f, 0.0f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

}
