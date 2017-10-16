#include "stdafx.h"
#include "Bottom_Palm.h"


Bottom_Palm::Bottom_Palm()
{
}


Bottom_Palm::~Bottom_Palm()
{
}

void Bottom_Palm::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matR, matWorld;
	D3DXMATRIXA16 roX, roY, roZ;
	D3DXMatrixIdentity(&roX);
	D3DXMatrixIdentity(&roY);
	D3DXMatrixIdentity(&roZ);

	D3DXMatrixScaling(&matS, 1.5f, 3.0f, 1.1f);
	D3DXMatrixTranslation(&matT, -3.0f, -2.2f, 0.35f);
	D3DXMatrixRotationZ(&roZ, D3DX_PI / 180 * 60);

	matR = roZ * roX * roY;

	matWorld = matS * matR * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}
	m_vLocalPos.z -= 0.5f;
}
