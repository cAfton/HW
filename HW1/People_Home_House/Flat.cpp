#include "Flat.h"

Flat::Flat()
{
	this->people = nullptr;
	this->rooms = 1;
	this->area = 10;
	this->bedrooms = 1;
	this->bathrooms = 1;
}

Flat::Flat(Human* people, int rooms, double area, int bedrooms, int bathrooms)
{
	this->people = people;
	this->rooms = rooms;
	this->area = area;
	this->bedrooms = bedrooms;
	this->bathrooms = bathrooms;
}

Flat::~Flat()
{
	delete[] this->people;
	cout << "-----------\ndestructed\n-----------" << endl;
}
