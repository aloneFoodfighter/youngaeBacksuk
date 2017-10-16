#pragma once
#include "cCube.h"

class Bottom_Palm : public cCube
{
public:
	Bottom_Palm();
	~Bottom_Palm();

	virtual void Setup(char* texture, BodyPart body) override;
};

