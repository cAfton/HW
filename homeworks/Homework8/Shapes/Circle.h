#pragma once
#include "Figures.h"


class Circle : public Figures {
private:
	int R;
	int X;
	int Y;
public:
	Circle();
	Circle(int r, int x, int y);
	string Print();

	void Save(string path);

	void Load(string path);

	float Area();

	float Perimetr();

};