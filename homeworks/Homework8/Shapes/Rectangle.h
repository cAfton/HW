#pragma once
#include "Paralelogram.h"

class Rectangle : public Paralelogram {
public:
	Rectangle() : Paralelogram(1, 2, 90, 0, 0) {}
	Rectangle(int sideA, int sideB, int x, int y) : Paralelogram(sideA, sideB, 90, x, y) {}
	
	string Print();

	void Save(string path);

	void Load(string path);


	float Area();

	float Perimetr();
};
