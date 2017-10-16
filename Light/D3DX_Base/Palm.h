#pragma once
#include "cCube.h"

class Palm : public cCube
{
public:
	Palm();
	~Palm();

	virtual void Setup(char* texture, BodyPart body) override;
};

