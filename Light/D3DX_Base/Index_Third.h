#pragma once
#include "cCube.h"

class Index_Third : public cCube
{
public:
	Index_Third();
	~Index_Third();

	virtual void Setup(char* texture, BodyPart body) override;
};

