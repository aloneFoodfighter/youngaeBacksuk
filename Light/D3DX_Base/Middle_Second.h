#pragma once
#include "cCube.h"

class Middle_Second : public cCube
{
public:
	Middle_Second();
	~Middle_Second();

	virtual void Setup(char* texture, BodyPart body) override;
};

