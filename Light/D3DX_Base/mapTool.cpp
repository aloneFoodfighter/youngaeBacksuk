#include "stdafx.h"
#include "mapTool.h"


mapTool::mapTool()
	: m_mGrid(NULL)
	, wire(false)
{
}


mapTool::~mapTool()
{
	SAFE_DELETE(m_mGrid);
	SAFE_DELETE(m_mCube);
}

void mapTool::Setup()
{
	m_mGrid = new mGrid;
	m_mGrid->Setup();

	m_mCube = new mCube;
	m_mCube->Setup();

	//텍스처 설정
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TFACTOR);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_TEXTURE);

	//알파 블렌딩 설정
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);



}

void mapTool::Update()
{

	if (m_mGrid) m_mGrid->Update();

	if (m_mCube)m_mCube->Update();

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		if (wire) wire = false;
		else wire = true;
	}

	if(wire) g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	else g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		SaveFile();
	}
	
	if (KEYMANAGER->isOnceKeyDown('Y'))
	{
		LoadFile();
	}
}

void mapTool::Render()
{
	if (m_mGrid) m_mGrid->Render();

	if (m_mCube) m_mCube->Render();
}

void mapTool::SaveFile()
{
	m_mGrid->SaveFile();
	m_mCube->SaveFile();
}

void mapTool::LoadFile()
{
	m_mGrid->LoadFile();
	m_mCube->LoadFile();
}
