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

	void setPeople(Human* people);

	friend istream& operator>>(istream& in, Flat& flat);
	friend ostream& operator<<(ostream& out, const Flat& flat);

	~Flat();
};