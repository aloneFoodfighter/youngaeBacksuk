#include "stdafx.h"
#include "cCube.h"


cCube::cCube()
	: m_vLocalPos(0, 0, 0)
	, m_pParentWorldTM(NULL)
	,angleX(0)
	,angleY(0)
	,angleZ(0)
	,bend(false)
{
	D3DXMatrixIdentity(&m_matLocalTM);
	D3DXMatrixIdentity(&m_matWorldTM);
	D3DXMatrixIdentity(&roX);
	D3DXMatrixIdentity(&roY);
	D3DXMatrixIdentity(&roZ);
	D3DXMatrixIdentity(&_matR);
	D3DXMatrixIdentity(&_matT);
}


cCube::~cCube()
{
	_skin->Release();
}


void cCube::AddChild(cCube* pChild)
{
	pChild->m_pParentWorldTM = &m_matWorldTM;
	m_vecChild.push_back(pChild);
}

void cCube::Destroy()
{
	for each (auto p in m_vecChild)
	{
		p->Destroy();
	}
	delete this;
}

void cCube::Setup(char* texture, BodyPart body)
{
	ST_LT_VERTEX	v;

	//ST_PC_VERTEXT v;

	bodyP = body;
	ANIMATION_CLASS->setFifth(false);
	ANIMATION_CLASS->setSecond(false);
	ANIMATION_CLASS->setThird(false);
	ANIMATION_CLASS->setFourth(false);
	ANIMATION_CLASS->setFifth(false);
	ANIMATION_CLASS->setHead(false);

	D3DXCreateTextureFromFile(g_pD3DDevice, texture, &_skin);

	//앞
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);

	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	//뒤
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	//왼
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);

	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	//오
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);

	//위
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);

	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(1.0f, 1.0f, -1.0f); m_vecVertex.push_back(v);

	//아래
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);

	for (int i = 0; i < m_vecVertex.size(); i+=3)
	{
		D3DXVECTOR3 p1 = m_vecVertex[i + 1].p - m_vecVertex[i].p;
		D3DXVECTOR3 p2 = m_vecVertex[i + 2].p - m_vecVertex[i].p;
		D3DXVECTOR3 pNormal;
		D3DXVec3Cross(&pNormal, &p2, &p1);

		m_vecVertex[i].n = pNormal;
		m_vecVertex[i + 1].n = pNormal;
		m_vecVertex[i + 2].n = pNormal;
	}

	//라이트 사용 기능을 TRUE로 함(이 기능을 끄면 모든 라이트 사용은 중지됨)
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);



	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);

}

void cCube::Update()
{
	D3DXMatrixIdentity(&m_matWorldTM);

	D3DXMatrixTranslation(&_matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);

	Animation();
	

	m_matLocalTM = _matR * _matT;
	m_matWorldTM = m_matLocalTM;

	if (m_pParentWorldTM)
	{
		m_matWorldTM *= (*m_pParentWorldTM);
	}

	for each (auto p in m_vecChild)
	{
		p->Update();
	}
}

void cCube::Render()
{
	g_pD3DDevice->SetTexture(0, _skin);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	g_pD3DDevice->SetFVF(ST_LT_VERTEX::FVF);
	//g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_LT_VERTEX));

	//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
	//	m_vecVertex.size() / 3,
	//	&m_vecVertex[0],
	//	sizeof(ST_PC_VERTEXT));

	for each (auto p in m_vecChild)
	{
		p->Render();
	}
}

void cCube::Animation()
{

	PartAni(PALM, ANIMATION_CLASS->getHead(), 0.003f, 0, 0, -D3DX_PI / 180 * 10);
	PartAni(JOINT, ANIMATION_CLASS->getHead(), 0.001f, 0, 0, -D3DX_PI / 180 * 10);

	PartAni(BOTTOM_PALM, ANIMATION_CLASS->getFirst(), 0.001f, 0, 0, -D3DX_PI / 180 * 15);
	PartAni(THUMB, ANIMATION_CLASS->getFirst(), 0.002f, 0.002, 0.002, -D3DX_PI / 6);
	PartAni(S_THUMB, ANIMATION_CLASS->getFirst(), 0.002f, 0.002, 0.002, -D3DX_PI / 6);

	PartAni(INDEX, ANIMATION_CLASS->getSecond(), 0.004f, 0, 0, -D3DX_PI / 2);
	PartAni(S_INDEX, ANIMATION_CLASS->getSecond(), 0.004f, 0, 0, -D3DX_PI / 3);
	PartAni(T_INDEX, ANIMATION_CLASS->getSecond(), 0.004f, 0, 0, -D3DX_PI / 2);

	PartAni(MIDDLE, ANIMATION_CLASS->getThird(), 0.004f, 0, 0, -D3DX_PI / 2);
	PartAni(S_MIDDLE, ANIMATION_CLASS->getThird(), 0.004f, 0, 0, -D3DX_PI / 3);
	PartAni(T_MIDDLE, ANIMATION_CLASS->getThird(), 0.004f, 0, 0, -D3DX_PI / 2);

	PartAni(RING, ANIMATION_CLASS->getFourth(), 0.004f, 0, 0, -D3DX_PI / 2);
	PartAni(S_RING, ANIMATION_CLASS->getFourth(), 0.004f, 0, 0, -D3DX_PI / 3);
	PartAni(T_RING, ANIMATION_CLASS->getFourth(), 0.004f, 0, 0, -D3DX_PI / 2);

	PartAni(LITTLE, ANIMATION_CLASS->getFifth(), 0.004f, 0, 0, -D3DX_PI / 2);
	PartAni(S_LITTLE, ANIMATION_CLASS->getFifth(), 0.004f, 0, 0, -D3DX_PI / 3);
	PartAni(T_LITTLE, ANIMATION_CLASS->getFifth(), 0.004f, 0, 0, -D3DX_PI / 2);
}

void cCube::PartAni(BodyPart body, bool ani, float _angleX, float _angleY, float _angleZ, float range)
{
	if (bodyP == body)
	{
		if (ani)
		{
			if (angleX > range)
			{
				angleX -= _angleX;
				angleY -= _angleY;
				angleZ -= _angleZ;
			}
		}

		else
		{
			if (angleX < 0)
			{
				angleX += _angleX;
				angleY += _angleY;
				angleZ += _angleZ;
			}
		}

		D3DXMatrixRotationX(&roX, angleX);
		D3DXMatrixRotationY(&roY, angleY);
		D3DXMatrixRotationZ(&roZ, angleZ);
		_matR = roZ * roX * roY;
	}
}
