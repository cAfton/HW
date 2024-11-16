#pragma once
#include "IFileLoader.h"

using namespace std;

class Figures : public IFileSaver {
public:
	virtual string Print() = 0;

	virtual void Save(string path) = 0;

	virtual void Load(string path) = 0;

	virtual float Area() = 0;

	virtual float Perimetr() = 0;

};