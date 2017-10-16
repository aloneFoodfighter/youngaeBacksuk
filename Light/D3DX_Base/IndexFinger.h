#pragma once
#include "cCube.h"

class IndexFinger : public cCube
{
public:
	IndexFinger();
	~IndexFinger();

	virtual void Setup(char* texture, BodyPart body) override;
};

