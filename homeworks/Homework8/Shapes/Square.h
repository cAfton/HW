#pragma once
#include "Rectangle.h"

class Square : public Rectangle {
public:

	Square() : Rectangle(1, 1) {}
	Square(int sideA) : Rectangle(sideA, sideA) {}
	string Print();

	void Save(string path);

	void Load(string path);

	float Area();

	float Perimetr();
};