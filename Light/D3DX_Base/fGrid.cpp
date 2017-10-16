#include "stdafx.h"
#include "fGrid.h"

#define MaxTextureCount (int)7

fGrid::fGrid()
{
}


fGrid::~fGrid()
{
	_tex->Release();
}

void fGrid::Setup()
{
	D3DXCreateTextureFromFile(g_pD3DDevice, "image/ground.png", &_tex);

	ST_LT_VERTEX v;

	for (int i = -50; i <= 50; i += 2)
	{
		for (int j = -50; j <= 50; j += 2)
		{
			v.p = D3DXVECTOR3(i - 1, -0.5, j - 1);
			v.t = D3DXVECTOR2(0, 1);
			f_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i - 1, -0.5, j + 1);
			v.t = D3DXVECTOR2(0, 0);
			f_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i + 1, -0.5, j + 1);
			v.t = D3DXVECTOR2(1, 0);
			f_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i - 1, -0.5, j - 1);
			v.t = D3DXVECTOR2(0, 1);
			f_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i + 1, -0.5, j + 1);
			v.t = D3DXVECTOR2(1, 0);
			f_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i + 1, -0.5, j - 1);
			v.t = D3DXVECTOR2(1, 1);
			f_vecGrid.push_back(v);
		}
	}

	for (int i = 0; i < f_vecGrid.size(); i += 3)
	{
		D3DXVECTOR3 p1 = f_vecGrid[i + 1].p - f_vecGrid[i].p;
		D3DXVECTOR3 p2 = f_vecGrid[i + 2].p - f_vecGrid[i].p;
		D3DXVECTOR3 pNormal;
		D3DXVec3Cross(&pNormal, &p1, &p2);

		f_vecGrid[i].n = pNormal;
		f_vecGrid[i + 1].n = pNormal;
		f_vecGrid[i + 2].n = pNormal;
	}
}

void fGrid::Render()
{

	//현재 텍스처 지정 -> 텍스처 활성화
	g_pD3DDevice->SetTexture(0, _tex);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_LT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		f_vecGrid.size() / 3,
		&f_vecGrid[0],
		sizeof(ST_LT_VERTEX));
}