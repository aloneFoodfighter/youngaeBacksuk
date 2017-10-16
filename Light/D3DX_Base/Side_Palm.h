#pragma once
#include "cCube.h"

class Side_Palm : public cCube
{
public:
	Side_Palm();
	~Side_Palm();

	virtual void Setup(char* texture, BodyPart body) override;
};

