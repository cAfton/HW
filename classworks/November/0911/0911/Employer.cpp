#include "Employer.h"

string Employer::workPlace = "JC_Janson in spaaaaaaaace";

Employer::Employer()
{
	this->name = "Anton";
	this->age = 3;
}

Employer::Employer(string Name, int Age)
{
	this->name = Name;
	this->age = Age;
}

ostream& operator<<(ostream& out, Employer& emp)
{
	out <<  "Name: " << emp.name << "\nAge: " << to_string(emp.age) << "\nWork place : " << emp.workPlace;
	return out;
}
