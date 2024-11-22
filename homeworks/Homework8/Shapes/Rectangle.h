#pragma once
#include "Paralelogram.h"

class Rectangle : public Paralelogram {
public:
	Rectangle() : Paralelogram(1, 2, 90) {}
	Rectangle(int sideA, int sideB) : Paralelogram(sideA, sideB, 90) {}

	string Print();

	void Save(string path);

	void Load(string path);


	float Area();

	float Perimetr();
};
