#include "Pet.h"

Pet::Pet()
{
	this->name = "a cool name";
	this->age = 1;
}

Pet::Pet(string name, int age)
{
	this->name = name;
	this->age = age;
}

int Pet::getAge()
{
	return this->age;
}

ostream& operator<<(ostream& out, Pet& pet)
{
	out << "Name: " << pet.name << "\nAge: " << pet.age << " years";
	return out;
}
