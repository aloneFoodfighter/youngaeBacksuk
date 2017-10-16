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

	//��
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

	//��
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

	//��
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

	//��
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

	//��
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

	//�Ʒ�
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
	//���� ����
	D3DMATERIAL9 mtrl;		//���� ������ ����ü
	ZeroMemory(&mtrl, sizeof(D3DMATERIAL9));
	mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;	//�����
	mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;	//�����
	mtrl.Diffuse.b = mtrl.Ambient.b = 0.0f;
	mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;

	//������ ���� ����
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
	//����Ʈ ����
	//Point Light����
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(D3DLIGHT9));
	light.Type = D3DLIGHT_POINT;

	light.Diffuse.r = 1.0f;
	light.Diffuse.g = 1.0f;
	light.Diffuse.b = 1.0f;
	light.Attenuation0 = 0.000000001f; //�������κ��� �־��� ���� ���Ⱚ
	light.Range = 50.0f;			//������ ��ġ�� ����

	light.Position.x = 0.0f;			//������ ��ġ�ϴ� x��ǥ
	light.Position.y = 0.0f;			//������ ��ġ�ϴ� y��ǥ
	light.Position.z = 0.0f;			//������ ��ġ�ϴ� z��ǥ
	g_pD3DDevice->SetLight(1, &light);	//����Ʈ ��ȣ ����
	g_pD3DDevice->LightEnable(1, true);	//1�� ����Ʈ �ѱ�

	g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);

	//����Ʈ ��� ����� TRUE�� ��(�� ����� ���� ��� ����Ʈ ����� ������)
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);*/
	

	//Spot Light����
	/*D3DLIGHT9 spot;
	ZeroMemory(&spot, sizeof(D3DLIGHT9));
	spot.Type = D3DLIGHT_SPOT;		//������ ������ ����Ʈ����Ʈ�� ����

	spot.Diffuse.r = 1.0f;
	spot.Diffuse.g = 1.0f;
	spot.Diffuse.b = 1.0f;
	spot.Attenuation0 = 0.0000001f;		//���Ⱚ 0 ����
	spot.Attenuation1 = 0.0000001f;		//���Ⱚ 1 ����
	spot.Attenuation2 = 0.0000001f;		//���Ⱚ 2 ����
	spot.Range = 5000000.0f;			//������ ��ġ�� ���� ����

	spot.Position.x = 0.0f;
	spot.Position.y = 0.0f;
	spot.Position.z = 0.0f;
	spot.Falloff = 1.0f;				//������ �ܺο��ֿ��� ���ο��� ���� �� ������
	spot.Theta = D3DX_PI / 4.0f;		//������ ���� ��
	spot.Phi = D3DX_PI / 2.0f;			//������ �ܺ� ��
	D3DXVECTOR3 vecDir;					//���� ���� ���� ����
	vecDir = D3DXVECTOR3(-1.0f, 0.0f, 0.0f);
	D3DXVec3Normalize((D3DXVECTOR3*)&spot.Direction, &vecDir);	// ���� ����ȭ
	g_pD3DDevice->SetLight(2, &spot);	//����Ʈ ��ȣ�� 2������ ����
	g_pD3DDevice->LightEnable(2, TRUE);	//2�� ����Ʈ �ѱ�
	g_pD3DDevice->SetRenderState(D3DRS_AMBIENT, 0x00040404);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);*/


	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	g_pD3DDevice->SetFVF(ST_LT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_LT_VERTEX));

}
