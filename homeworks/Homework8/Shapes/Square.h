#pragma once
#include "Rectangle.h"

class Square : public Rectangle {
public:

	Square() : Rectangle(1, 1, 0, 0) {}
	Square(int sideA, int x, int y) : Rectangle(sideA, sideA, x, y) {}
	string Print();

	void Save(string path);

	void Load(string path);

	float Area();

	float Perimetr();
};