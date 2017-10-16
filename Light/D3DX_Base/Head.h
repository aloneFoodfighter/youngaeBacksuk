#pragma once
#include "CubeClass.h"

class Head :
	public CubeClass
{
public:
	Head();
	~Head();

	virtual void Setup() override;
};
