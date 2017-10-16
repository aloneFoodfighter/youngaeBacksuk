#pragma once
#include "cCube.h"

class Thumb : public cCube
{
public:
	Thumb();
	~Thumb();

	virtual void Setup(char* texture, BodyPart body) override;
};

