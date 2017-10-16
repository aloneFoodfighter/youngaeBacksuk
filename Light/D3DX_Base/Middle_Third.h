#pragma once
#include "cCube.h"

class Middle_Third : public cCube
{
public:
	Middle_Third();
	~Middle_Third();

	virtual void Setup(char* texture, BodyPart body) override;
};

