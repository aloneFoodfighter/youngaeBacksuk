#include "stdafx.h"
#include "CubePerson.h"
#include "Body.h"
#include "Head.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"


CubePerson::CubePerson()
	: m_pRoot(NULL)
	,count(0)
	,speed(300)
{
	D3DXMatrixIdentity(&matT);
	D3DXMatrixIdentity(&matR);
}


CubePerson::~CubePerson()
{
	SAFE_DELETE(m_pRoot);
}


void CubePerson::Setup()
{
	Body* pBody = new Body;
	pBody->Setup();
	pBody->SetParentWorldTM(&m_matWorld);
	m_pRoot = pBody;

	Head* pHead = new Head;
	pHead->Setup();
	m_pRoot->AddChild(pHead);

	cLeftArm* pLeftArm = new cLeftArm;
	pLeftArm->Setup();
	pLeftArm->SetroX(0.02f);
	m_pRoot->AddChild(pLeftArm);

	cRightArm* pRightArm = new cRightArm;
	pRightArm->Setup();
	pRightArm->SetroX(-0.02f);
	m_pRoot->AddChild(pRightArm);

	cLeftLeg* pLeftLeg = new cLeftLeg;
	pLeftLeg->Setup();
	pLeftLeg->SetroX(-0.02f);
	m_pRoot->AddChild(pLeftLeg);

	cRightLeg* pRightLeg = new cRightLeg;
	pRightLeg->Setup();
	pRightLeg->SetroX(0.02f);
	m_pRoot->AddChild(pRightLeg);

	m_vPosition = BEZIER->getA();

}
void CubePerson::Update()
{
	if (GetKeyState('A') & 0x8000)
	{
		m_fRotY -= 0.1f;
	}
	if (GetKeyState('D') & 0x8000)
	{
		m_fRotY += 0.1f;
	}

	if (GetKeyState('W') & 0x8000)
	{
		m_vPosition = m_vPosition + (m_vDirection * 0.1f);
	}

	if (GetKeyState('S') & 0x8000)
	{
		m_vPosition = m_vPosition - (m_vDirection * 0.1f);
	}


	//베지어 공식 따라 다니기
	if (count <= speed)
	{
		m_vPosition = BEZIER->getBezier(BEZIER->getA(), BEZIER->getB(), BEZIER->getC(), speed, count);
	}

	else if (count <= speed * 2)
	{
		m_vPosition = BEZIER->getBezier(BEZIER->getC(), BEZIER->getD(), BEZIER->getE(), speed, count - speed);
	}

	else if (count <= speed * 3)
	{
		m_vPosition = BEZIER->getBezier(BEZIER->getE(), BEZIER->getF(), BEZIER->getA(), speed, count - speed * 2);
	}

	if (count > speed * 3) count = 0;

	D3DXMatrixRotationY(&matR, m_fRotY);
	m_vDirection = D3DXVECTOR3(0, 0, -1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matR * matT;

	count++;

	//==================

	float distance;
	distance = getDistance(m_vPosition.x, m_vPosition.y, m_vPosition.z, 5.0f, 5.0f, 0.0f);

	if (distance < 6.0f)
	{
		ANIMATION_CLASS->setLight(true);
	}

	else
	{
		ANIMATION_CLASS->setLight(false);
	}




	if (m_pRoot)
	{
		m_pRoot->Update();
	}
}
void CubePerson::Render()
{

	if (m_pRoot)
	{
		m_pRoot->Render();
	}
}

float CubePerson::getDistance(float x1, float y1, float z1, float x2, float y2, float z2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}
