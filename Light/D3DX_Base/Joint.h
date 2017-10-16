#pragma once
#include "cCube.h"

class Joint : public cCube
{
public:
	Joint();
	~Joint();

	virtual void Setup(char* texture, BodyPart body) override;
};

