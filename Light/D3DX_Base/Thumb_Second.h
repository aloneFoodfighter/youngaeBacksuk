#pragma once
#include "cCube.h"

class Thumb_Second : public cCube
{
public:
	Thumb_Second();
	~Thumb_Second();

	virtual void Setup(char* texture, BodyPart body) override;

};

