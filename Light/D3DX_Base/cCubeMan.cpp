#include "stdafx.h"
#include "cCubeMan.h"



cCubeMan::cCubeMan()
	:m_pRoot(NULL)
	,pPalm(NULL)
	,pIndex(NULL)
	,pMiddle(NULL)
	,pRing(NULL)
	,pLittle(NULL)
	,pIndex_S(NULL)
	,pMiddle_S(NULL)
	,pRing_S(NULL)
	,pLittle_S(NULL)
	,pThumb_S(NULL)
	,pIndex_T(NULL)
	,pMiddle_T(NULL)
	,pRing_T(NULL)
	,pLittle_T(NULL)
	,pJoint(NULL)
	,pWrist(NULL)
	,pTopPalm(NULL)
	,pSidePalm(NULL)
	,pBottomPalm(NULL)
{
}


cCubeMan::~cCubeMan()
{
	SAFE_DELETE(m_pRoot);

	SAFE_DELETE(pJoint);

	SAFE_DELETE(pTopPalm);
	SAFE_DELETE(pSidePalm);
	SAFE_DELETE(pBottomPalm);
	SAFE_DELETE(pPalm);

	SAFE_DELETE(pIndex);
	SAFE_DELETE(pIndex_S);
	SAFE_DELETE(pIndex_T);

	SAFE_DELETE(pMiddle);
	SAFE_DELETE(pMiddle_S);
	SAFE_DELETE(pMiddle_T);
	
	SAFE_DELETE(pRing);
	SAFE_DELETE(pRing_S);
	SAFE_DELETE(pRing_T);
	
	SAFE_DELETE(pLittle);
	SAFE_DELETE(pLittle_S);
	SAFE_DELETE(pLittle_T);

	SAFE_DELETE(pThumb);
	SAFE_DELETE(pThumb_S);

}


void cCubeMan::Setup()
{
	ANIMATION_CLASS->setDirection(STAY);

	pWrist = new Wrist;
	pWrist->Setup("image/tree.png", WRIST);
	//pJoint->AddChild(pWrist);
	pWrist->SetParentWorldTM(&m_matWorld);
	m_pRoot = pWrist;

	pJoint = new Joint;
	pJoint->Setup("image/tree.png", JOINT);
	pWrist->AddChild(pJoint);

	pPalm = new Palm;
	pPalm->Setup("image/tree.png", PALM);
	pJoint->AddChild(pPalm);
	//pPalm->SetParentWorldTM(&m_matWorld);
	//m_pRoot = pPalm;

	//======

	pTopPalm = new Top_Palm;
	pTopPalm->Setup("image/tree.png", TOP_PALM);
	pPalm->AddChild(pTopPalm);

	pSidePalm = new Side_Palm;
	pSidePalm->Setup("image/tree.png", SIDE_PALM);
	pPalm->AddChild(pSidePalm);

	pBottomPalm = new Bottom_Palm;
	pBottomPalm->Setup("image/tree.png", BOTTOM_PALM);
	pPalm->AddChild(pBottomPalm);

	//======

	pIndex = new IndexFinger;
	pIndex->Setup("image/simpson.jpg", INDEX);
	pTopPalm->AddChild(pIndex);


	pMiddle = new MiddleFinger;
	pMiddle->Setup("image/simpson.jpg", MIDDLE);
	pTopPalm->AddChild(pMiddle);

	pRing = new RingFinger;
	pRing->Setup("image/simpson.jpg", RING);
	pTopPalm->AddChild(pRing);


	pLittle = new LittleFinger;
	pLittle->Setup("image/simpson.jpg", LITTLE);
	pTopPalm->AddChild(pLittle);

	pThumb = new Thumb;
	pThumb->Setup("image/simpson.jpg", THUMB);
	pBottomPalm->AddChild(pThumb);

	//========

	pIndex_S = new Index_Second;
	pIndex_S->Setup("image/simpson.jpg", S_INDEX);
	pIndex->AddChild(pIndex_S);

	pMiddle_S = new Middle_Second;
	pMiddle_S->Setup("image/simpson.jpg", S_MIDDLE);
	pMiddle->AddChild(pMiddle_S);

	pRing_S = new Ring_Second;
	pRing_S->Setup("image/simpson.jpg", S_RING);
	pRing->AddChild(pRing_S);

	pLittle_S = new Little_Second;
	pLittle_S->Setup("image/simpson.jpg", S_LITTLE);
	pLittle->AddChild(pLittle_S);

	pThumb_S = new Thumb_Second;
	pThumb_S->Setup("image/simpson.jpg", S_THUMB);
	pThumb->AddChild(pThumb_S);

	//=========

	pIndex_T = new Index_Third;
	pIndex_T->Setup("image/simpson.jpg", T_INDEX);
	pIndex_S->AddChild(pIndex_T);

	pMiddle_T = new Middle_Third;
	pMiddle_T->Setup("image/simpson.jpg", T_MIDDLE);
	pMiddle_S->AddChild(pMiddle_T);

	pRing_T = new Ring_Third;
	pRing_T->Setup("image/simpson.jpg", T_RING);
	pRing_S->AddChild(pRing_T);

	pLittle_T = new Little_Third;
	pLittle_T->Setup("image/simpson.jpg", T_LITTLE);
	pLittle_S->AddChild(pLittle_T);

	m_vPosition.x = -40.0f;
	m_vPosition.y = 10.0f;
	m_vPosition.z = 0.0f;
	
	//g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
}

void cCubeMan::Update()
{

	D3DXMATRIXA16	matR, matT;
	D3DXMATRIXA16	roY;
	D3DXMatrixRotationY(&roY, D3DX_PI / 180 * 90);
	D3DXMatrixRotationY(&matR, m_fRotY);
	matR = matR * roY;
	m_vDirection = D3DXVECTOR3(0, 0, 1);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matR * matT;


	if (m_pRoot)
	{
		m_pRoot->Update();
	}


}
void cCubeMan::Render()
{
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

	light.Position.x = -30.0f;
	light.Position.y = 10.0f;
	light.Position.z = 0.0f;

	light.Falloff = 1.0f;
	light.Theta = D3DX_PI / 5.0f;
	light.Phi = D3DX_PI / 3.0f;

	vecDir = D3DXVECTOR3(-1.0f, 0.0f, 0.0f);

	D3DXVec3Normalize((D3DXVECTOR3*)&light.Direction, &vecDir);

	light.Range = 5000.0f;
	g_pD3DDevice->SetLight(2, &light);
	g_pD3DDevice->LightEnable(2, true);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);

	g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);
	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);



	if (m_pRoot)
	{
		m_pRoot->Render();
	}
}

