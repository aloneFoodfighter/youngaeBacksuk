#include "stdafx.h"
#include "Thumb.h"


Thumb::Thumb()
{
}


Thumb::~Thumb()
{
}

void Thumb::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matR, matWorld;
	D3DXMATRIXA16 roX, roY, roZ;
	D3DXMatrixIdentity(&roX);
	D3DXMatrixIdentity(&roY);
	D3DXMatrixIdentity(&roZ);

	D3DXMatrixScaling(&matS, 1.1f, 1.5f, 1.1f);
	D3DXMatrixTranslation(&matT, -1.0f, 0.0f, 0.9f);
	D3DXMatrixRotationZ(&roZ, D3DX_PI / 180 * 35);

	matR = roZ * roX * roY;
	matWorld = matS * matR * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	//m_vLocalPos.y -= 0.75f;
	m_vLocalPos.x -= 5.2f;
	m_vLocalPos.z -= 1.0f;
}
