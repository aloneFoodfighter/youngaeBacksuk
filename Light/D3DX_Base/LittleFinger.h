#pragma once
#include "cCube.h"

class LittleFinger : public cCube
{
public:
	LittleFinger();
	~LittleFinger();

	virtual void Setup(char* texture, BodyPart body) override;

};

