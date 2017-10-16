#include "stdafx.h"
#include "CubeBoy.h"
#include "Body.h"
#include "Head.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"


CubeBoy::CubeBoy()
	: m_pRoot(NULL)
	,count(0)
	,speed(300)
	,m_fRotY(0)
{
	D3DXMatrixIdentity(&matT);
	D3DXMatrixIdentity(&matR);
}


CubeBoy::~CubeBoy()
{
	SAFE_DELETE(m_pRoot);
}


void CubeBoy::Setup()
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
	m_vDirection = D3DXVECTOR3(0, 0, -1);

}
void CubeBoy::Update()
{
	//선 따라 다니기
	if (count <= speed)
	{
		m_vPosition = BEZIER->getLinear(BEZIER->getA(), BEZIER->getB(), speed, count);
	}

	else if (count <= speed * 2)
	{
		m_vPosition = BEZIER->getLinear(BEZIER->getB(), BEZIER->getC(), speed, count - speed);
	}

	else if (count <= speed * 3)
	{
		m_vPosition = BEZIER->getLinear(BEZIER->getC(), BEZIER->getD(), speed, count - speed * 2);
	}

	else if (count <= speed * 4)
	{
		m_vPosition = BEZIER->getLinear(BEZIER->getD(), BEZIER->getE(), speed, count - speed * 3);
	}

	else if (count <= speed * 5)
	{
		m_vPosition = BEZIER->getLinear(BEZIER->getE(), BEZIER->getF(), speed, count - speed * 4);
	}

	else if (count <= speed * 6)
	{
		m_vPosition = BEZIER->getLinear(BEZIER->getF(), BEZIER->getA(), speed, count - speed * 5);
	}

	if (count > speed * 6) count = 0;

	D3DXMatrixRotationY(&matR, D3DX_PI / 180 * m_fRotY);
	m_vDirection = D3DXVECTOR3(0, 0, -1);
	//D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matR * matT;

	count++;

	//==================

	//float distance;
	//distance = getDistance(m_vPosition.x, m_vPosition.y, m_vPosition.z, 5.0f, 5.0f, 0.0f);

	//if (distance < 6.0f)
	//{
	//	ANIMATION_CLASS->setLight(true);
	//}
	//
	//else
	//{
	//	ANIMATION_CLASS->setLight(false);
	//}




	if (m_pRoot)
	{
		m_pRoot->Update();
	}
}
void CubeBoy::Render()
{


	/*
	//재질 설정
	D3DMATERIAL9 mtrl;		//재질 설정용 구조체
	ZeroMemory(&mtrl, sizeof(D3DMATERIAL9));
	mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;	//노란색
	mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;	//노란색
	mtrl.Diffuse.b = mtrl.Ambient.b = 1.0f;
	mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;

	//설정한 재질 적용
	g_pD3DDevice->SetMaterial(&mtrl);

	D3DXVECTOR3 vecDir;
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(D3DLIGHT9));
	light.Type = D3DLIGHT_SPOT;
	light.Diffuse.r = 1.0f;
	light.Diffuse.g = 1.0f;
	light.Diffuse.b = 1.0f;
	light.Attenuation0 = 0.1f;
	light.Attenuation1 = 0.000000001f;
	light.Attenuation2 = 0.000000001f;

	light.Position.x = m_vPosition.x;
	light.Position.y = m_vPosition.y + 4.0f;
	light.Position.z = m_vPosition.z;

	light.Falloff = 1.0f;
	light.Theta = D3DX_PI / 12.0f;
	light.Phi = D3DX_PI / 6.0f;

	//vecDir = D3DXVECTOR3(-1.0f, 0.0f, 0.0f);
	vecDir = m_vDirection;

	D3DXVec3Normalize((D3DXVECTOR3*)&light.Direction, &vecDir);

	light.Range = 100.0f;
	g_pD3DDevice->SetLight(3, &light);
	g_pD3DDevice->LightEnable(3, true);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

	g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);
	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);

	*/
	if (m_pRoot)
	{
		m_pRoot->Render();
	}
}

float CubeBoy::getDistance(float x1, float y1, float z1, float x2, float y2, float z2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}
