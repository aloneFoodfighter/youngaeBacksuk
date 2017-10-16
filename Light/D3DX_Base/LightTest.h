#pragma once
class LightTest
{
private:
	vector<ST_LT_VERTEX> m_vecVertex;

	D3DXMATRIXA16				m_matWorldTM;


public:
	LightTest();
	~LightTest();

	void Setup();
	void Update();
	void Render();
};

