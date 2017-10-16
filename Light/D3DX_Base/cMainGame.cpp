#include "stdafx.h"
#include "cMainGame.h"
#include "cCube.h"
#include "cGrid.h"
#include "cCamera.h"
#include "cCubeMan.h"
#include "CubeBoy.h"
#include "CubePerson.h"

#include "LightTest.h"

#include "bGrid.h"

//¸ÊÅø
#include "mapTool.h"
//ºÒ²É³îÀÌ
#include "FireCracker.h"

cMainGame::cMainGame()
	: m_pCube(NULL)
	, m_pGrid(NULL)
	, m_pCamera(NULL)
	, m_pCubeMan(NULL)
	, _bowling(NULL)
	, _pin(NULL)
	, _light(NULL)
	, m_pCubeBoy(NULL)
	, m_pBGrid(NULL)
	, m_pCubePerson(NULL)
	, _mapTool(NULL)
	, _fireCracker(NULL)
{
}


cMainGame::~cMainGame()
{
	SAFE_DELETE(m_pCube);
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pCubeMan);
	SAFE_DELETE(_bowling);
	SAFE_DELETE(_pin);
	SAFE_DELETE(_light);
	SAFE_DELETE(m_pCubeBoy);
	SAFE_DELETE(m_pBGrid);
	SAFE_DELETE(m_pCubePerson);
	SAFE_DELETE(_mapTool);
	SAFE_DELETE(_fireCracker);
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup()
{

/*
	ST_PC_VERTEXT v;
	v.p = D3DXVECTOR3(0, 0, 0);
	v.c = D3DCOLOR_XRGB(255, 0, 0);

	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0, 1, 0);
	v.c = D3DCOLOR_XRGB(0, 255, 0);

	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(1, 0, 0);
	v.c = D3DCOLOR_XRGB(0, 0, 255);

	m_vecVertex.push_back(v);*/

	m_pCamera = new cCamera;
	m_pCamera->Setup();

	//m_pBGrid = new bGrid;
	//m_pBGrid->Setup();


	//m_pCube = new cCube;
	//m_pCube->Setup();

	//m_pGrid = new cGrid;
	//m_pGrid->Setup();

	/*m_pCubeMan = new cCubeMan;
	m_pCubeMan->Setup();

	_light = new LightTest;
	_light->Setup();*/

	/*m_pCubeBoy = new CubeBoy;
	m_pCubeBoy->Setup();

	m_pCubePerson = new CubePerson;
	m_pCubePerson->Setup();*/


	//¸ÊÅø
	_mapTool = new mapTool;
	_mapTool->Setup();

	//ºÒ²É³îÀÌ
	//_fireCracker = new FireCracker;
	//_fireCracker->Setup();


	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{
	if (m_pCamera)
	{
		m_pCamera->Update();
	}
	/*if (m_pCubeMan)
	{
		m_pCubeMan->Update();
	}

	if (_light)
	{
	_light->Update();
	}*/

	/*if (m_pCubeBoy)
	{
		m_pCubeBoy->Update();
	}

	if (m_pCubePerson)
	{
		m_pCubePerson->Update();
	}*/


	//¸ÊÅø
	if (_mapTool)
	{
		_mapTool->Update();
	}

	//ºÒ²É³îÀÌ
	//if (_fireCracker)
	//{
	//	_fireCracker->Update();
	//}
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(124, 170, 254),
		1.0f, 0);

	g_pD3DDevice->BeginScene();

	// Draw
	/*D3DXMATRIXA16	matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);

	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEXT));*/

	/*if (m_pCubeMan)
	{
		m_pCubeMan->Render();
	}

	if (_light)
	{
		_light->Render();
	}

	if (m_pBGrid)
	{
		m_pBGrid->Render();
	}

	if (m_pCubeBoy)
	{
		m_pCubeBoy->Render();
	}

	if (m_pCubePerson)
	{
		m_pCubePerson->Render();
	}

	if (m_pGrid)
	{
		m_pGrid->Render();
	}*/

	//¸ÊÅø
	if (_mapTool)
	{
		_mapTool->Render();
	}

	//ºÒ²É³îÀÌ
	//if (_fireCracker)
	//{
	//	_fireCracker->Render();
	//}



	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
	{
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
	}
}