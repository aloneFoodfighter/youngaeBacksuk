#pragma once
#include "cCube.h"

class LeftForearm : public cCube
{
private:

public:
	LeftForearm();
	~LeftForearm();

	virtual void Setup(char* texture, BodyPart body) override;
};

