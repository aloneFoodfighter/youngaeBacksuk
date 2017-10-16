#pragma once
#include "CubeClass.h"

class Body :
	public CubeClass
{
public:
	Body();
	~Body();

	virtual void Setup() override;
};
