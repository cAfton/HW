#pragma once
#include "Flat.h"

class Home
{
private:
	Flat* flats;
	string street;
	int numberOfFloors;
	int numberOfFlats;

public:
	Home();
	Home(Flat* flats, string street, int numberOfFloors);
	Home(const Home& copy);

	void setFlat(Flat* flats);

	int NumberOfApartmentsPerFloor(int numberOfFlats)const;

	int NumberOfParkingSpaces(int numberOfFlats)const;

	friend istream& operator>>(istream& in, Home& home);
	friend ostream& operator<<(ostream& out, const Home& home);

	~Home();
};