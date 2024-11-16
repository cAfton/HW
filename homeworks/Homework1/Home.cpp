#include "Home.h"

Home::Home()
{
	this->flats = new Flat[1];
	this->street = "";
	this->numberOfFloors = 1;
}

Home::Home(Flat* flats, string street, int numberOfFloors)
{
	this->flats = flats;
	this->street = street;
	this->numberOfFloors = numberOfFloors;
}

Home::Home(const Home& copy)
{
	this->numberOfFloors = copy.numberOfFloors;
	this->street = copy.street;
	this->flats = new Flat[this->numberOfFlats];
	for (size_t i = 0; i < this->numberOfFlats; i++)
	{
		this->flats[i] = copy.flats[i];
	}
}

void Home::setFlat(Flat* flats)
{
	this->flats = flats;
}

int Home::NumberOfApartmentsPerFloor(int flats) const
{
	return flats/numberOfFloors;
}

int Home::NumberOfParkingSpaces(int flats)const
{
	return (flats * numberOfFloors) / (3 * NumberOfApartmentsPerFloor(flats));
}

Home::~Home()
{
	delete[] this->flats;
	cout << "-----------\ndestructed\n-----------" << endl;
}

istream& operator>>(istream& in, Home& home)
{
	cout << "Number Of Floors: ";
	in >> home.numberOfFloors;
	cout << "Street: ";
	in >> home.street;
	cout << "Number of flats: ";
	in >> home.numberOfFlats;

	return in;
}

ostream& operator<<(ostream& out, const Home& home)
{
	out << "Number Of Floors: " << home.numberOfFloors << "\nStreet: " << home.street << "\nNumber of flats" << home.numberOfFlats << endl;

	return out;
}
