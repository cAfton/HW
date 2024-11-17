#pragma once
#include "BaseClass.h"

class quadratic : public roots{
public:
	quadratic();
	quadratic(int a, int b, int c);
	void calculation() override;
};