#pragma once
#include "cCube.h"

class Ring_Second : public cCube
{
public:
	Ring_Second();
	~Ring_Second();

	virtual void Setup(char* texture, BodyPart body) override;
};

