#pragma once
#include "cCube.h"

class LeftCalf : public cCube
{
public:
	LeftCalf();
	~LeftCalf();

	virtual void Setup(char* texture, BodyPart body) override;
};

