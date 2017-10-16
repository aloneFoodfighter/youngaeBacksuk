#pragma once

#define BEZIER	BezierClass::GetInstance()		

class BezierClass
{
	SINGLETONE(BezierClass)

private:
	vector<ST_PC_VERTEXT> m_vecVertex;

	D3DXVECTOR3 a;
	D3DXVECTOR3 b;
	D3DXVECTOR3 c;
	D3DXVECTOR3 d;
	D3DXVECTOR3 e;
	D3DXVECTOR3 f;

public:
	/*void Setup();
	void Update();
	void Render();*/

	D3DXVECTOR3 getA() { return a; }
	D3DXVECTOR3 getB() { return b; }
	D3DXVECTOR3 getC() { return c; }
	D3DXVECTOR3 getD() { return d; }
	D3DXVECTOR3 getE() { return e; }
	D3DXVECTOR3 getF() { return f; }

	void setA(D3DXVECTOR3 bezier) { a = bezier; }
	void setB(D3DXVECTOR3 bezier) { b = bezier; }
	void setC(D3DXVECTOR3 bezier) { c = bezier; }
	void setD(D3DXVECTOR3 bezier) { d = bezier; }
	void setE(D3DXVECTOR3 bezier) { e = bezier; }
	void setF(D3DXVECTOR3 bezier) { f = bezier; }

	D3DXVECTOR3 getBezier(D3DXVECTOR3 i, D3DXVECTOR3 j, D3DXVECTOR3 k, int weight, int count)
	{
		//a에서 b까지의 거리를 1이라고 잡는다.
		D3DXVECTOR3 o;
		o.x = i.x + (j.x - i.x) / weight * count;
		o.y = i.y + (j.y - i.y) / weight * count;
		o.z = i.z + (j.z - i.z) / weight * count;

		//b에서 c까지의 거리를 1이라고 잡는다.
		D3DXVECTOR3 p;
		p.x = j.x + (k.x - j.x) / weight * count;
		p.y = j.y + (k.y - j.y) / weight * count;
		p.z = j.z + (k.z - j.z) / weight * count;

		//점 o와 점 p까지를 선분을 또 이음
		D3DXVECTOR3 r;
		r.x = o.x + (p.x - o.x) / weight * count;
		r.y = o.y + (p.y - o.y) / weight * count;
		r.z = o.z + (p.z - o.z) / weight * count;
		
		return r;
	}

	D3DXVECTOR3 getLinear(D3DXVECTOR3 i, D3DXVECTOR3 j, int weight, int count)
	{
		D3DXVECTOR3 o;
		o.x = i.x + (j.x - i.x) / weight * count;
		o.y = i.y + (j.y - i.y) / weight * count;
		o.z = i.z + (j.z - i.z) / weight * count;

		return o;
	}

};

