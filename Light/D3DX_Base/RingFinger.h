#pragma once
#include "cCube.h"

class RingFinger : public cCube
{
public:
	RingFinger();
	~RingFinger();

	virtual void Setup(char* texture, BodyPart body) override;

};

