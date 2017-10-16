#include "stdafx.h"
#include "mGrid.h"

#define MaxTextureCount (int)7

mGrid::mGrid()
	:texNum(0)
{
}


mGrid::~mGrid()
{
	for (int i = 0; i < vpTexture.size(); i++)
	{
		if (vpTexture[i] == NULL) return;
		SAFE_RELEASE(vpTexture[i]);
	}
	vpTexture.clear();
	
	_tex->Release();
}

void mGrid::Setup()
{
	vpTexture.resize(MaxTextureCount);
	for (int i = 0; i < MaxTextureCount; i++) {
		vpTexture[i] = NULL;
	}

	AddTexture("image/ground.png");
	AddTexture("image/ground2.png");
	AddTexture("image/ground3.png");
	AddTexture("image/ground4.png");
	AddTexture("image/ground5.png");
	AddTexture("image/ground6.png");
	AddTexture("image/ground7.png");

	DrawGrid();
	DrawSky();

	alpha = D3DCOLOR_ARGB(255, 255, 255, 255);
}

void mGrid::Update()
{
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		if (texNum > 0)
		{
			texNum--;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		if (texNum < vpTexture.size() - 1)
		{
			texNum++;
		}
	}
}

void mGrid::Render()
{

	g_pD3DDevice->SetRenderState(D3DRS_TEXTUREFACTOR, alpha);


	//현재 텍스처 지정 -> 텍스처 활성화
	g_pD3DDevice->SetTexture(0, vpTexture[texNum]);

	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_LT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecGrid.size() / 3,
		&m_vecGrid[0],
		sizeof(ST_LT_VERTEX));

	//skybox
	g_pD3DDevice->SetTexture(0, _tex);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_sky.size() / 3,
		&m_sky[0],
		sizeof(ST_LT_VERTEX));
}

void mGrid::AddTexture(char* texName)
{
	for (UINT i = 0; i < vpTexture.size(); i++) {
		if (vpTexture[i] == NULL) {
			D3DXCreateTextureFromFile(g_pD3DDevice, texName, &vpTexture[i]);
			return;
		}
	}

	MessageBox(g_hWnd, "텍스쳐 넣을 자리가 읍습니다!\n", 0, MB_OK);
}

void mGrid::DrawGrid()
{
	ST_LT_VERTEX v;

	for (int i = -50; i <= 50; i += 2)
	{
		for (int j = -50; j <= 50; j += 2)
		{
			v.p = D3DXVECTOR3(i - 1, -1, j - 1);
			v.t = D3DXVECTOR2(0, 1);
			m_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i - 1, -1, j + 1);
			v.t = D3DXVECTOR2(0, 0);
			m_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i + 1, -1, j + 1);
			v.t = D3DXVECTOR2(1, 0);
			m_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i - 1, -1, j - 1);
			v.t = D3DXVECTOR2(0, 1);
			m_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i + 1, -1, j + 1);
			v.t = D3DXVECTOR2(1, 0);
			m_vecGrid.push_back(v);

			v.p = D3DXVECTOR3(i + 1, -1, j - 1);
			v.t = D3DXVECTOR2(1, 1);
			m_vecGrid.push_back(v);
		}
	}

	for (int i = 0; i < m_vecGrid.size(); i += 3)
	{
		D3DXVECTOR3 p1 = m_vecGrid[i + 1].p - m_vecGrid[i].p;
		D3DXVECTOR3 p2 = m_vecGrid[i + 2].p - m_vecGrid[i].p;
		D3DXVECTOR3 pNormal;
		D3DXVec3Cross(&pNormal, &p1, &p2);

		m_vecGrid[i].n = pNormal;
		m_vecGrid[i + 1].n = pNormal;
		m_vecGrid[i + 2].n = pNormal;
	}
}

void mGrid::DrawSky()
{
	D3DXCreateTextureFromFile(g_pD3DDevice, "image/sky2.png", &_tex);

	ST_LT_VERTEX t;
	//위
	t.p = D3DXVECTOR3(-50, 50, 50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 50, -50);
	t.t = D3DXVECTOR2(0, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 50, -50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 50, 50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 50, -50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 50, 50);
	t.t = D3DXVECTOR2(1, 1);
	m_sky.push_back(t);

	//앞
	t.p = D3DXVECTOR3(-50, 0, 50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 50, 50);
	t.t = D3DXVECTOR2(0, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 50, 50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 0, 50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 50, 50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 0, 50);
	t.t = D3DXVECTOR2(1, 1);
	m_sky.push_back(t);

	//뒤
	t.p = D3DXVECTOR3(50, 0, -50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 50, -50);
	t.t = D3DXVECTOR2(0, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 50, -50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 0, -50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 50, -50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 0, -50);
	t.t = D3DXVECTOR2(1, 1);
	m_sky.push_back(t);



	//왼
	t.p = D3DXVECTOR3(-50, 0, -50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 50, -50);
	t.t = D3DXVECTOR2(0, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 50, 50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 0, -50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 50, 50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(-50, 0, 50);
	t.t = D3DXVECTOR2(1, 1);
	m_sky.push_back(t);

	//오
	t.p = D3DXVECTOR3(50, 0, 50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 50, 50);
	t.t = D3DXVECTOR2(0, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 50, -50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 0, 50);
	t.t = D3DXVECTOR2(0, 1);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 50, -50);
	t.t = D3DXVECTOR2(1, 0);
	m_sky.push_back(t);

	t.p = D3DXVECTOR3(50, 0, -50);
	t.t = D3DXVECTOR2(1, 1);
	m_sky.push_back(t);

	for (int i = 0; i < m_sky.size(); i += 3)
	{
		D3DXVECTOR3 p1 = m_sky[i + 1].p - m_sky[i].p;
		D3DXVECTOR3 p2 = m_sky[i + 2].p - m_sky[i].p;
		D3DXVECTOR3 pNormal;
		D3DXVec3Cross(&pNormal, &p1, &p2);

		m_sky[i].n = pNormal;
		m_sky[i + 1].n = pNormal;
		m_sky[i + 2].n = pNormal;
	}

}

void mGrid::SaveFile()
{
	FILE * fp;
	fopen_s(&fp, "save/grid.txt", "w");

	fprintf(fp, "%d", texNum);

	fclose(fp);
}

void mGrid::LoadFile()
{
	FILE * fp;
	int gridTexNum;	//그리드 텍스쳐 넘버

	fopen_s(&fp, "save/grid.txt", "r");

	while (!feof(fp))
	{
		fscanf_s(fp, "%d", &gridTexNum);
		texNum = gridTexNum;
	}
	fclose(fp);
}
