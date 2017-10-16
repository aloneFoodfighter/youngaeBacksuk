#pragma once

class cCube;
class cGrid;
class cCamera;
class cCubeMan;
class CubeBoy;
class CubePerson;
class Bowling;
class PinClass;

class LightTest;

class bGrid;

//∏ ≈¯
class mapTool;
//∫“≤…≥Ó¿Ã
class FireCracker;

class cMainGame
{
private:
	std::vector<ST_PC_VERTEXT>	m_vecVertex;
	cCube*		m_pCube;
	cGrid*		m_pGrid;
	cCamera*	m_pCamera;
	cCubeMan*	m_pCubeMan;
	CubeBoy*	m_pCubeBoy;
	CubePerson* m_pCubePerson;
	Bowling*	_bowling;
	PinClass*	_pin;

	LightTest* _light;

	bGrid* m_pBGrid;

	// ∏ ≈¯
	mapTool *_mapTool;
	FireCracker* _fireCracker;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

