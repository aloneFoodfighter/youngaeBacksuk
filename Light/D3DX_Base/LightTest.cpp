#include "stdafx.h"
#include "LightTest.h"


LightTest::LightTest()
{
	D3DXMatrixIdentity(&m_matWorldTM);

}


LightTest::~LightTest()
{
}

void LightTest::Setup()
{

	ST_LT_VERTEX	v;

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

	for (int i = 0; i < m_vecVertex.size(); i += 3)
	{
		D3DXVECTOR3 p1 = m_vecVertex[i + 1].p - m_vecVertex[i].p;
		D3DXVECTOR3 p2 = m_vecVertex[i + 2].p - m_vecVertex[i].p;
		D3DXVECTOR3 pNormal;
		D3DXVec3Cross(&pNormal, &p2, &p1);

		m_vecVertex[i].n = pNormal;
		m_vecVertex[i + 1].n = pNormal;
		m_vecVertex[i + 2].n = pNormal;
	}

	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);

}

void LightTest::Update()
{
	D3DXMatrixTranslation(&m_matWorldTM, 5.0f, 1.0f, 5.0f);
}

void LightTest::Render()
{
	//재질 설정
	D3DMATERIAL9 mtrl;		//재질 설정용 구조체
	ZeroMemory(&mtrl, sizeof(D3DMATERIAL9));
	mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;	//노란색
	mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;	//노란색
	mtrl.Diffuse.b = mtrl.Ambient.b = 0.0f;
	mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;

	//설정한 재질 적용
	g_pD3DDevice->SetMaterial(&mtrl);

	D3DXVECTOR3 vecDir;
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(D3DLIGHT9));
	light.Type = D3DLIGHT_POINT;
	light.Diffuse.r = 1.0f;
	light.Diffuse.g = 1.0f;
	light.Diffuse.b = 1.0f;
	light.Attenuation0 = 0.1f;

	light.Position.x = 5.0f;
	light.Position.y = 1.0f;
	light.Position.z = 5.0f;


	//vecDir = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	//D3DXVec3Normalize((D3DXVECTOR3*)&light.Direction, &vecDir);

	light.Range = 10.0f;
	if (ANIMATION_CLASS->getLight())
	{
		g_pD3DDevice->SetLight(4, &light);
		g_pD3DDevice->LightEnable(4, true);

		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	}
	
	else
	{
		g_pD3DDevice->LightEnable(4, false);
	}

	g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);
	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);


	/*
	//라이트 설정
	//Point Light설정
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(D3DLIGHT9));
	light.Type = D3DLIGHT_POINT;

	light.Diffuse.r = 1.0f;
	light.Diffuse.g = 1.0f;
	light.Diffuse.b = 1.0f;
	light.Attenuation0 = 0.000000001f; //광원으로부터 멀어질 때의 감쇄값
	light.Range = 50.0f;			//조명이 미치는 범위

	light.Position.x = 0.0f;			//조명이 위치하는 x좌표
	light.Position.y = 0.0f;			//조명이 위치하는 y좌표
	light.Position.z = 0.0f;			//조명이 위치하는 z좌표
	g_pD3DDevice->SetLight(1, &light);	//라이트 번호 지정
	g_pD3DDevice->LightEnable(1, true);	//1번 라이트 켜기

	g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);

	//라이트 사용 기능을 TRUE로 함(이 기능을 끄면 모든 라이트 사용은 중지됨)
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);*/
	

	//Spot Light설정
	/*D3DLIGHT9 spot;
	ZeroMemory(&spot, sizeof(D3DLIGHT9));
	spot.Type = D3DLIGHT_SPOT;		//조명의 종류는 스포트라이트로 설정

	spot.Diffuse.r = 1.0f;
	spot.Diffuse.g = 1.0f;
	spot.Diffuse.b = 1.0f;
	spot.Attenuation0 = 0.0000001f;		//감쇄값 0 설정
	spot.Attenuation1 = 0.0000001f;		//감쇄값 1 설정
	spot.Attenuation2 = 0.0000001f;		//감쇄값 2 설정
	spot.Range = 5000000.0f;			//조명이 미치는 범위 설정

	spot.Position.x = 0.0f;
	spot.Position.y = 0.0f;
	spot.Position.z = 0.0f;
	spot.Falloff = 1.0f;				//조명의 외부원주에서 내부원주 간의 빛 감쇄율
	spot.Theta = D3DX_PI / 4.0f;		//조명의 내부 각
	spot.Phi = D3DX_PI / 2.0f;			//조명의 외부 각
	D3DXVECTOR3 vecDir;					//방향 벡터 변수 선언
	vecDir = D3DXVECTOR3(-1.0f, 0.0f, 0.0f);
	D3DXVec3Normalize((D3DXVECTOR3*)&spot.Direction, &vecDir);	// 벡터 정규화
	g_pD3DDevice->SetLight(2, &spot);	//라이트 번호를 2번으로 설정
	g_pD3DDevice->LightEnable(2, TRUE);	//2번 라이트 켜기
	g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00040404);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);*/


	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	g_pD3DDevice->SetFVF(ST_LT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_LT_VERTEX));

}
