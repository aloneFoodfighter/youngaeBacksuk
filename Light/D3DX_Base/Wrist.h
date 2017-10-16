#pragma once
#include "cCube.h"

class Wrist : public cCube
{
public:
	Wrist();
	~Wrist();

	virtual void Setup(char* texture, BodyPart body) override;
};

