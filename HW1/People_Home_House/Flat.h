#pragma once
#include "Human.h"

class Flat {
private:
	Human* people;
	int rooms;
	double area;
	int bedrooms;
	int bathrooms;
public:

	Flat();
	Flat(Human* people, int rooms, double area, int bedrooms, int bathrooms);
	~Flat();
};