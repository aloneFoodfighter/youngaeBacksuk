#include "stdafx.h"
#include "mCube.h"

#define CubeTexture (int)7

mCube::mCube()
{
}

mCube::~mCube()
{
	for (int i = 0; i < vpTexture.size(); i++)
	{
		if (vpTexture[i] == NULL) return;
		SAFE_RELEASE(vpTexture[i]);
	}

	vpTexture.clear();
}

void mCube::Setup()
{
	AddCube();

	vpTexture.resize(CubeTexture);
	for (int i = 0; i < CubeTexture; i++)
	{
		vpTexture[i] = NULL;
	}

	AddTexture("image/minecraft_texture.png");
	AddTexture("image/minecraft_texture2.png");
	AddTexture("image/minecraft_texture3.png");
	AddTexture("image/minecraft_texture4.png");
	AddTexture("image/minecraft_texture5.png");
	AddTexture("image/minecraft_texture6.png");
	AddTexture("image/minecraft_texture7.png");
}

void mCube::Update()
{
	for (int i = 0; i < _cube.size(); i++)
	{
		D3DXMatrixTranslation(&_cube[i].m_Trans, _cube[i].GetPos().x, _cube[i].GetPos().y, _cube[i].GetPos().z);

		_cube[i].m_World = _cube[i].m_Rot * _cube[i].m_Trans;
	}

	SettingCube(_cube[_cube.size() - 1]);
}

void mCube::Render()
{
	for (int i = 0; i < _cube.size(); i++)
	{
		g_pD3DDevice->SetRenderState(D3DRS_TEXTUREFACTOR, _cube[i].alpha);

		g_pD3DDevice->SetTexture(0, vpTexture[_cube[i].texNum]);

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &_cube[i].m_World);
		g_pD3DDevice->SetFVF(ST_LT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
			_cube[i].m_vecCube.size() / 3,
			&_cube[i].m_vecCube[0],
			sizeof(ST_LT_VERTEX));
	}
}

void mCube::AddCube()
{
	tagCube c;

	if (_cube.size() == 0)
	{
		c.texNum = 0;
	}

	else
	{
		c.texNum = _cube[_cube.size() - 1].texNum;
	}

	ST_LT_VERTEX	v;

	D3DXVECTOR3 p(0, 0, 0);

	//앞
	v.t = D3DXVECTOR2(ONE_XPER, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER, ONE_YPER);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y + 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 2, ONE_YPER);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);

	v.t = D3DXVECTOR2(ONE_XPER, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 2, ONE_YPER);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 2, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y - 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);

	//뒤
	v.t = D3DXVECTOR2(1, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 3, ONE_YPER);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(1, ONE_YPER);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y + 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);

	v.t = D3DXVECTOR2(1, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 3, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y - 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 3, ONE_YPER);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);

	//왼
	v.t = D3DXVECTOR2(0, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(0, ONE_YPER);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y + 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER, ONE_YPER);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y + 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);

	v.t = D3DXVECTOR2(0, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER, ONE_YPER);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y + 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);

	//오
	v.t = D3DXVECTOR2(ONE_XPER * 2, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y - 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 2, ONE_YPER);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 3, ONE_YPER);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);

	v.t = D3DXVECTOR2(ONE_XPER * 2, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y - 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 3, ONE_YPER);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 3, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y - 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);

	//위
	v.t = D3DXVECTOR2(ONE_XPER, ONE_YPER);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y + 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER, 0);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y + 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 2, 0);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);

	v.t = D3DXVECTOR2(ONE_XPER, ONE_YPER);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y + 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 2, 0);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 2, ONE_YPER);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y + 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);

	//아래
	v.t = D3DXVECTOR2(ONE_XPER * 2, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER * 2, 1);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER, 1);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y - 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);

	v.t = D3DXVECTOR2(ONE_XPER * 2, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x - 1.0f, p.y - 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER, 1);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y - 1.0f, p.z - 1.0f); c.m_vecCube.push_back(v);
	v.t = D3DXVECTOR2(ONE_XPER, ONE_YPER * 2);
	v.p = D3DXVECTOR3(p.x + 1.0f, p.y - 1.0f, p.z + 1.0f); c.m_vecCube.push_back(v);

	for (int i = 0; i < c.m_vecCube.size(); i += 3)
	{
		D3DXVECTOR3 p1 = c.m_vecCube[i + 1].p - c.m_vecCube[i].p;
		D3DXVECTOR3 p2 = c.m_vecCube[i + 2].p - c.m_vecCube[i].p;
		D3DXVECTOR3 pNormal;
		D3DXVec3Cross(&pNormal, &p2, &p1);

		c.m_vecCube[i].n = pNormal;
		c.m_vecCube[i + 1].n = pNormal;
		c.m_vecCube[i + 2].n = pNormal;
	}

	D3DXMatrixIdentity(&c.m_World);
	D3DXMatrixIdentity(&c.m_Rot);
	D3DXMatrixIdentity(&c.m_Trans);


	c.alphaNum = 150;
	c.alpha = D3DCOLOR_ARGB(c.alphaNum, 255, 255, 255);

	c.SetPos(p);

	_cube.push_back(c);
}

void mCube::SettingCube(tagCube& cube)
{
	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		D3DXVECTOR3 c = cube.GetPos();
		if(c.z < 50.0f) c.z += 2.0f;
		cube.SetPos(c);
	}

	else if (KEYMANAGER->isOnceKeyDown('S'))
	{
		D3DXVECTOR3 c = cube.GetPos();
		if (c.z > -50.0f) c.z -= 2.0f;
		cube.SetPos(c);
	}

	else if (KEYMANAGER->isOnceKeyDown('A'))
	{
		D3DXVECTOR3 c = cube.GetPos();
		if (c.x > -50.0f) c.x -= 2.0f;
		cube.SetPos(c);
	}

	else if (KEYMANAGER->isOnceKeyDown('D'))
	{
		D3DXVECTOR3 c = cube.GetPos();
		if (c.x < 50.0f) c.x += 2.0f;
		cube.SetPos(c);
	}

	else if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		D3DXVECTOR3 c = cube.GetPos();
		if (c.y < 50.0f) c.y += 2.0f;
		cube.SetPos(c);
	}

	else if (KEYMANAGER->isOnceKeyDown('E'))
	{
		D3DXVECTOR3 c = cube.GetPos();
		if (c.y >= 2.0f) c.y -= 2.0f;
		cube.SetPos(c);
	}

	else if (KEYMANAGER->isOnceKeyDown('K'))
	{
		if (cube.texNum > 0)
		{
			cube.texNum--;
		}
	}

	else if (KEYMANAGER->isOnceKeyDown('L'))
	{		
		if(cube.texNum < vpTexture.size() - 1)
		{
			cube.texNum++;
		}
	}

	else if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if(_cube.size() > 0)
		{
			for (int i = 0; i < _cube.size() - 1; i++)
			{
				if (_cube[i].GetPos() == cube.GetPos())
				{
					D3DXVECTOR3 d;
					d = cube.GetPos();
					if (d.y < 50)
					{
						d.y += 2;
					}
					cube.SetPos(d);
				}
			}
		}
		cube.alphaNum = 255;
		cube.alpha = D3DCOLOR_ARGB(cube.alphaNum, 255, 255, 255);
		AddCube();
	}
} 

void mCube::AddTexture(char* texName)
{
	for (int i = 0; i < vpTexture.size(); i++)
	{
		if (vpTexture[i] == NULL)
		{
			D3DXCreateTextureFromFile(g_pD3DDevice, texName, &vpTexture[i]);
			return;
		}
	}

}

void mCube::SaveFile()
{
	FILE * fp;
	fopen_s(&fp, "save/cube.txt", "w");

	for (int i = 0; i < _cube.size() - 1; i++)
	{
		fprintf(fp, "%d ", i);

		fprintf(fp, "%f ", _cube[i].GetPos().x);
		fprintf(fp, "%f ", _cube[i].GetPos().y);
		fprintf(fp, "%f ", _cube[i].GetPos().z);
		fprintf(fp, "%d ", _cube[i].texNum);
		fprintf(fp, "%d\n", _cube[i].alphaNum);
	}
	fclose(fp);
}

void mCube::LoadFile()
{
	_cube.clear();


	FILE * fp;
	int cubeIndex;	//큐브 인덱스 번호
	int cubeSize;	//저장된 큐브 사이즈
	int cubeTex;	//큐브 텍스트 번호
	int cubeAlpha;	//큐브 알파값

	D3DXVECTOR3	pos;	//저장된 큐브의 포지션값
	num = 0;
	count = 0;
	fopen_s(&fp, "save/cube.txt", "r");

	while (!feof(fp))
	{
		AddCube();

		fscanf_s(fp, "%d", &cubeIndex);
		
		fscanf_s(fp, "%f", &pos.x);
		fscanf_s(fp, "%f", &pos.y);
		fscanf_s(fp, "%f", &pos.z);
		_cube[cubeIndex].SetPos(pos);
	
		fscanf_s(fp, "%d", &cubeTex);
		_cube[cubeIndex].texNum = cubeTex;

		fscanf_s(fp, "%d", &cubeAlpha);
		_cube[cubeIndex].alphaNum = cubeAlpha;
		_cube[cubeIndex].alpha = D3DCOLOR_ARGB(_cube[cubeIndex].alphaNum, 255, 255, 255);
	}
	fclose(fp);

}

