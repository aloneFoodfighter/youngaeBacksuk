#pragma once
#include "cCube.h"

class RightCalf : public cCube
{
public:
	RightCalf();
	~RightCalf();

	virtual void Setup(char* texture, BodyPart body) override;
};

