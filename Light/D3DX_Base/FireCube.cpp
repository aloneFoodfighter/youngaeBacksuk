#include "stdafx.h"
#include "FireCube.h"

FireCube::FireCube()
	: fire(false)
	, cracker(false)
	, c_height(0)
	, count(0)
{
}

FireCube::~FireCube()
{
	_tex->Release();
}

void FireCube::Setup()
{
	D3DXCreateTextureFromFile(g_pD3DDevice, "image/ground6.png", &_tex);

	CreateCube(0, 0, 0, 1, 1, 1, true);

}

void FireCube::Update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		fire = true;
		c_height = RANDOM->GetFromFloatTo(5.0f, 15.0f);
	}

	CubeFire();

	for (int i = 0; i < _cube.size(); i++)
	{
		D3DXMatrixTranslation(&_cube[i].matT, _cube[i].GetPos().x, _cube[i].GetPos().y, _cube[i].GetPos().z);

		_cube[i].World = _cube[i].matS * _cube[i].matR * _cube[i].matT;
	}

	count++;
}

void FireCube::Render()
{
	for (int i = 0; i < _cube.size(); i++)
	{
		g_pD3DDevice->SetTexture(0, _tex);

		g_pD3DDevice->SetTransform(D3DTS_WORLD, &_cube[i].World);
		g_pD3DDevice->SetFVF(ST_LT_VERTEX::FVF);
		//g_pD3DDevice->SetFVF(ST_PC_VERTEXT::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
			_cube[i].cubeVex.size() / 3,
			&_cube[i].cubeVex[0],
			sizeof(ST_LT_VERTEX));
	}
}

void FireCube::CreateCube(float x, float y, float z, float width, float height, float depth, bool _owner)
{
	tagFire c;

	ST_LT_VERTEX v;

	//앞
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(x - (width / 2), y + (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);

	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(x + (width / 2), y - (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);

	//뒤
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x - (width / 2), y + (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);

	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x + (width / 2), y - (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);

	//왼
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(x - (width / 2), y + (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x - (width / 2), y + (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);

	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x - (width / 2), y + (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);

	//오
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x + (width / 2), y - (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);

	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x + (width / 2), y - (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(x + (width / 2), y - (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);

	//위
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x - (width / 2), y + (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(x - (width / 2), y + (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);

	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x - (width / 2), y + (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(x + (width / 2), y + (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);

	//아래
	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(1, 1);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x + (width / 2), y - (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);

	v.t = D3DXVECTOR2(1, 0);
	v.p = D3DXVECTOR3(x - (width / 2), y - (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 1);
	v.p = D3DXVECTOR3(x + (width / 2), y - (height / 2), z - (depth / 2)); c.cubeVex.push_back(v);
	v.t = D3DXVECTOR2(0, 0);
	v.p = D3DXVECTOR3(x + (width / 2), y - (height / 2), z + (depth / 2)); c.cubeVex.push_back(v);

	D3DXMatrixIdentity(&c.World);
	D3DXMatrixIdentity(&c.matT);
	D3DXMatrixIdentity(&c.matS);
	D3DXMatrixIdentity(&c.matR);

	D3DXVECTOR3 pos(x, y, z);

	c.SetPos(pos);

	c.owner = _owner;

	_cube.push_back(c);
}

void FireCube::CubeFire()
{
	D3DXVECTOR3 upCube = _cube[0].GetPos();

	if (fire)
	{
		if (upCube.y < c_height && _cube[0].owner)
		{
			upCube.y += 0.1;
			_cube[0].SetPos(upCube);
		}

		else
		{
			if (!cracker)
			{
				int num = RANDOM->GetFromIntTo(3, 6);

				for (int i = 0; i < num; i++)
				{
					CreateCube(upCube.x, upCube.y, upCube.z, 0.3f, 0.3f, 0.3f, false);
				}

				eraseCube(0);
				cracker = true;
			}
			else
			{
				for (int i = 0; i < _cube.size(); i++)
				{
					_cube[i].from = upCube;
					_cube[i].via = D3DXVECTOR3(RANDOM->GetFromFloatTo(_cube[i].GetPos().x - 1.0f, _cube[i].GetPos().x + 1.0f), RANDOM->GetFromFloatTo(_cube[i].GetPos().y - 1.0f, _cube[i].GetPos().y + 1.0f), RANDOM->GetFromFloatTo(_cube[i].GetPos().z - 1.0f, _cube[i].GetPos().z + 1.0f));
					_cube[i].to = D3DXVECTOR3(RANDOM->GetFromFloatTo(-5.0f, 5.0f), RANDOM->GetFromFloatTo(0.5f, 3.0f), RANDOM->GetFromFloatTo(-5.0f, 5.0f));
				}

				for (int i = 0; i < _cube.size(); i++)
				{
					calBezier(i);
				}
			}
		}
	}

}

void FireCube::calBezier(int index)
{
	if (cracker)
	{
		//if (count <= 1000)
		//{
		//	_cube[index].SetPos(BEZIER->getBezier(_cube[index].from, _cube[index].via, _cube[index].to, 1000, count));
		//}
	}
}

void FireCube::eraseCube(int index)
{
	_cube.erase(_cube.begin() + index);
}
