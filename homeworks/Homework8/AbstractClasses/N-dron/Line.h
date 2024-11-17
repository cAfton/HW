#pragma once
#include "BaseClass.h"

class Line : public roots
{

public:
	Line();
	Line(int a, int b);
	void calculation() override;
};
