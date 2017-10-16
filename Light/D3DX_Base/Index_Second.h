#pragma once
#include "cCube.h"

class Index_Second : public cCube
{
public:
	Index_Second();
	~Index_Second();

	virtual void Setup(char* texture, BodyPart body) override;
};

