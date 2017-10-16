#pragma once
#include "cCube.h"

class RightForearm : public cCube
{
public:
	RightForearm();
	~RightForearm();

	virtual void Setup(char* texture, BodyPart body) override;
};

