#include "stdafx.h"
#include "Top_Palm.h"


Top_Palm::Top_Palm()
{
}


Top_Palm::~Top_Palm()
{
}

void Top_Palm::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matWorld;
	D3DXMatrixScaling(&matS, 4.5f, 1.5f, 1.1f);
	D3DXMatrixTranslation(&matT, 0.0f, 3.5f, -0.15f);

	matWorld = matS * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

}
