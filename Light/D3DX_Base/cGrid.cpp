#include "stdafx.h"
#include "cGrid.h"


cGrid::cGrid()
{
}


cGrid::~cGrid()
{
	_ground->Release();
}

void cGrid::Setup()
{
	D3DXCreateTextureFromFile(g_pD3DDevice, "image/ground.jpg", &_ground);


	ST_LT_VERTEX t;

	for (int i = -50; i < 50; i++)
	{
		for (int j = -50; j < 50; j++)
		{
			t.p = D3DXVECTOR3(i, 0, j);
			t.t = D3DXVECTOR2(0, 1);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(i, 0, j + 1);
			t.t = D3DXVECTOR2(0, 0);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(i + 1, 0, j + 1);
			t.t = D3DXVECTOR2(1, 0);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(i, 0, j);
			t.t = D3DXVECTOR2(0, 1);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(i + 1, 0, j + 1);
			t.t = D3DXVECTOR2(1, 0);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(i + 1, 0, j);
			t.t = D3DXVECTOR2(1, 1);
			m_TexVec.push_back(t);
		}
	}

	// 벽 그리드
	for (int i = 0; i < 50; i++)
	{
		for (int j = -50; j < 50; j++)
		{
			t.p = D3DXVECTOR3(-50, i, j);
			t.t = D3DXVECTOR2(0, 1);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(-50, i + 1, j);
			t.t = D3DXVECTOR2(0, 0);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(-50, i + 1, j + 1);
			t.t = D3DXVECTOR2(1, 0);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(-50, i, j);
			t.t = D3DXVECTOR2(0, 1);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(-50, i + 1, j + 1);
			t.t = D3DXVECTOR2(1, 0);
			m_TexVec.push_back(t);

			t.p = D3DXVECTOR3(-50, i, j + 1);
			t.t = D3DXVECTOR2(1, 1);
			m_TexVec.push_back(t);

		}
	}

	for (int i = 0; i < m_TexVec.size(); i += 3)
	{
		D3DXVECTOR3 p1 = m_TexVec[i + 1].p - m_TexVec[i].p;
		D3DXVECTOR3 p2 = m_TexVec[i + 2].p - m_TexVec[i].p;
		D3DXVECTOR3 pNormal;
		D3DXVec3Cross(&pNormal, &p1, &p2);
	
		m_TexVec[i].n = pNormal;
		m_TexVec[i + 1].n = pNormal;
		m_TexVec[i + 2].n = pNormal;
	}

	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);

	g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
}
void cGrid::Render()
{
	//현재 텍스처 지정 -> 텍스처 활성화
	g_pD3DDevice->SetTexture(0, _ground);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_LT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_TexVec.size() / 3,
		&m_TexVec[0],
		sizeof(ST_LT_VERTEX));
}