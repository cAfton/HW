#pragma once
#include "Figures.h"


class Circle : public Figures {
private:
	int R;
public:
	Circle();
	Circle(int r);
	string Print();

	void Save(string path);

	void Load(string path);

	float Area();

	float Perimetr();

};