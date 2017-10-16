#pragma once
#include "cCube.h"

class Little_Second : public cCube
{
public:
	Little_Second();
	~Little_Second();

	virtual void Setup(char* texture, BodyPart body) override;

};

