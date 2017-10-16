#include "stdafx.h"
#include "BezierClass.h"


BezierClass::BezierClass()
{
}


BezierClass::~BezierClass()
{
}

/*void BezierClass::Setup()
{
	//a = D3DXVECTOR3(1, 0, 1);
	//b = D3DXVECTOR3(4, 0, 4);
	//c = D3DXVECTOR3(6, 0, 2);

	//ST_PC_VERTEXT v;
	//v.c = D3DCOLOR_XRGB(0, 0, 0);
	//v.p = a; m_vecVertex.push_back(v);
	//v.p = b; m_vecVertex.push_back(v);
	//v.p = b; m_vecVertex.push_back(v);
	//v.p = c; m_vecVertex.push_back(v);

}

void BezierClass::Update()
{
	if (count <= 1000)
	{
		//a에서 b까지의 거리를 1이라고 잡는다.
		D3DXVECTOR3 o;
		o.x = a.x + (b.x - a.x) / 1000 * count;
		o.y = a.y + (b.y - a.y) / 1000 * count;
		o.z = a.z + (b.z - a.z) / 1000 * count;

		//b에서 c까지의 거리를 1이라고 잡는다.
		D3DXVECTOR3 p;
		p.x = b.x + (c.x - b.x) / 1000 * count;
		p.y = b.y + (c.y - b.y) / 1000 * count;
		p.z = b.z + (c.z - b.z) / 1000 * count;

		//점 o와 점 p까지를 선분을 또 이음
		D3DXVECTOR3 r;
		r.x = o.x + (p.x - o.x) / 1000 * count;
		r.y = o.y + (p.y - o.y) / 1000 * count;
		r.z = o.z + (p.z - o.z) / 1000 * count;

		ST_PC_VERTEXT v;
		v.c = D3DCOLOR_XRGB(255, 0, 0);
		v.p = r; m_vecVertex.push_back(v);
	}
	count++;
}

void BezierClass::Render()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST,
		m_vecVertex.size() / 2,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEXT));
}*/

