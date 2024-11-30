#pragma once
#include "Figures.h"

class Paralelogram : public Figures {
protected:
	int SideA;
	int SideB;
	int Angle;
	int X;
	int Y;
public:
	Paralelogram();
	Paralelogram(int sideA, int sideB, int angle, int x, int y);


	string Print();

	void Save(string path);

	void Load(string path);

	float Area();

	float Perimetr();
};
