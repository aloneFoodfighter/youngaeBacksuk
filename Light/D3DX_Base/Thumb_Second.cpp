#include "stdafx.h"
#include "Thumb_Second.h"


Thumb_Second::Thumb_Second()
{
}


Thumb_Second::~Thumb_Second()
{
}

void Thumb_Second::Setup(char * texture, BodyPart body)
{
	cCube::Setup(texture, body);

	D3DXMATRIXA16 matS, matT, matR, matWorld;
	D3DXMATRIXA16 roX, roY, roZ;
	D3DXMatrixIdentity(&roX);
	D3DXMatrixIdentity(&roY);
	D3DXMatrixIdentity(&roZ);

	D3DXMatrixScaling(&matS, 1.0f, 1.4f, 1.0f);
	D3DXMatrixTranslation(&matT, -0.5f, 2.4f, 1.0f);
	D3DXMatrixRotationZ(&roZ, D3DX_PI / 180 * 30);

	matR = roZ * roX * roY;
	matWorld = matS * matR * matT;

	for (int i = 0; i < m_vecVertex.size(); i++)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &matWorld);
	}

	m_vLocalPos.x -= 2.0f;
}
