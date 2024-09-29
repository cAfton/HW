#include "Flat.h"

Flat::Flat()
{
	this->people = new Human[0];
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

void Flat::setPeople(Human* people)
{
	this->people = people;
}

Flat::~Flat()
{
	delete[] this->people;
	cout << "-----------\ndestructed\n-----------" << endl;
}

istream& operator>>(istream& in, Flat& flat)
{
	cout << "Rooms: ";
	in >> flat.rooms;
	cout << "Area: ";
	in >> flat.area;
	cout << "Bedrooms: ";
	in >> flat.bedrooms;
	cout << "Bathrooms: ";
	in >> flat.bathrooms;

	return in;
}

ostream& operator<<(ostream& out, const Flat& flat)
{
	out << "Area: " << flat.area << "\nRooms: " << flat.rooms << "\nBedrooms: " << flat.bedrooms << "\nBathrooms" << flat.bathrooms << endl;

	return out;
}
