#pragma once
#include "cCube.h"

class Top_Palm : public cCube
{
public:
	Top_Palm();
	~Top_Palm();

	virtual void Setup(char* texture, BodyPart body) override;
};

