#pragma once
#include "cCube.h"

class MiddleFinger : public cCube
{
public:
	MiddleFinger();
	~MiddleFinger();

	virtual void Setup(char* texture, BodyPart body) override;
};

