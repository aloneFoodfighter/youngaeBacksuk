#pragma once
#include "cCube.h"

class Little_Third : public cCube
{
public:
	Little_Third();
	~Little_Third();

	virtual void Setup(char* texture, BodyPart body) override;
};

