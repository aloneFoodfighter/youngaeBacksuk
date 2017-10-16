#pragma once
class cCube;

#include "Palm.h"
#include "IndexFinger.h"
#include "MiddleFinger.h"
#include "RingFinger.h"
#include "LittleFinger.h"
#include "Thumb.h"

#include "Index_Second.h"
#include "Middle_Second.h"
#include "Ring_Second.h"
#include "Little_Second.h"
#include "Thumb_Second.h"

#include "Index_Third.h"
#include "Middle_Third.h"
#include "Ring_Third.h"
#include "Little_Third.h"

#include "Joint.h"
#include "Wrist.h"

#include "Top_Palm.h"
#include "Side_Palm.h"
#include "Bottom_Palm.h"

class cCubeMan
{
private:
	cCube* m_pRoot;

	D3DXMATRIXA16				m_matWorld;
	float						m_fRotY;
	D3DXVECTOR3					m_vPosition;
	D3DXVECTOR3					m_vDirection;



	Palm * pPalm;
	IndexFinger * pIndex;
	MiddleFinger * pMiddle;
	RingFinger * pRing;
	LittleFinger * pLittle;
	Thumb * pThumb;

	Index_Second * pIndex_S;
	Middle_Second * pMiddle_S;
	Ring_Second * pRing_S;
	Little_Second * pLittle_S;
	Thumb_Second * pThumb_S;

	Index_Third * pIndex_T;
	Middle_Third * pMiddle_T;
	Ring_Third * pRing_T;
	Little_Third * pLittle_T;

	Joint * pJoint;
	Wrist * pWrist;

	Top_Palm * pTopPalm;
	Side_Palm * pSidePalm;
	Bottom_Palm * pBottomPalm;

	D3DMATERIAL9 red;


public:
	cCubeMan();
	~cCubeMan();

	void Setup();
	void Update();
	void Render();
};

