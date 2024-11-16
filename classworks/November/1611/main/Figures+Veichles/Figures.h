#pragma once
#include "Elem.h"

using namespace std;

class Figures : public Elem {
public:
	virtual string Print() = 0;

	virtual void Save(string path) = 0;

	virtual void Load(string path) = 0;

	virtual float Area() = 0;

	virtual float Perimetr() = 0;

};