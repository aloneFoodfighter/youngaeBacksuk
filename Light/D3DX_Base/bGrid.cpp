#include "stdafx.h"
#include "bGrid.h"


bGrid::bGrid()
{
}


bGrid::~bGrid()
{
}

void bGrid::Setup(int nNumHalfTile, float fInterval)
{
	float fMax = nNumHalfTile * fInterval;
	float fMin = -nNumHalfTile * fInterval;

	ST_PC_VERTEXT v;

	for (int i = 1; i <= nNumHalfTile; i++)
	{
		v.c = D3DCOLOR_XRGB(255, 255, 255);
		v.p = D3DXVECTOR3(fMin, 0, i * fInterval);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, i * fInterval);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(fMin, 0, -i * fInterval);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, -i * fInterval);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(-i * fInterval, 0, fMin);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-i * fInterval, 0, fMax);
		m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(i * fInterval, 0, fMin);
		m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(i * fInterval, 0, fMax);
		m_vecVertex.push_back(v);
	}

	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(fMin, 0, 0);	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(fMax, 0, 0);	m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, fMin, 0);	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, fMax, 0);	m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0, 0, fMin);	m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, 0, fMax);	m_vecVertex.push_back(v);

	BEZIER->setA(D3DXVECTOR3(10, 0, 20));
	BEZIER->setB(D3DXVECTOR3(20, 0, 0));
	BEZIER->setC(D3DXVECTOR3(10, 0, -20));
	BEZIER->setD(D3DXVECTOR3(-10, 0, -20));
	BEZIER->setE(D3DXVECTOR3(-20, 0, 0));
	BEZIER->setF(D3DXVECTOR3(-10, 0, 20));

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = BEZIER->getA(); m_vecVertex.push_back(v);
	v.p = BEZIER->getB(); m_vecVertex.push_back(v);
	v.p = BEZIER->getB(); m_vecVertex.push_back(v);
	v.p = BEZIER->getC(); m_vecVertex.push_back(v);
	v.p = BEZIER->getC(); m_vecVertex.push_back(v);
	v.p = BEZIER->getD(); m_vecVertex.push_back(v);
	v.p = BEZIER->getD(); m_vecVertex.push_back(v);
	v.p = BEZIER->getE(); m_vecVertex.push_back(v);
	v.p = BEZIER->getE(); m_vecVertex.push_back(v);
	v.p = BEZIER->getF(); m_vecVertex.push_back(v);
	v.p = BEZIER->getF(); m_vecVertex.push_back(v);
	v.p = BEZIER->getA(); m_vecVertex.push_back(v);

}

void bGrid::Render()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST,
		m_vecVertex.size() / 2,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEXT));
}
