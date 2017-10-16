#pragma once
#include "cCube.h"

class Ring_Third : public cCube
{
public:
	Ring_Third();
	~Ring_Third();

	virtual void Setup(char* texture, BodyPart body) override;
};

