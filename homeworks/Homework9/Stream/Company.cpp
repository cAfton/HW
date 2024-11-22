#include "Company.h"

Company::Company()
{
	this->companyName = "ATB";
	this->director = "B. Markov";
	this->number = 380970102030;
	this->address = "Dnipro";
	this->typeOfActivity = "supermarket";
}

Company::Company(string companyName, string director, long unsigned int number, string address, string typeOfActivity)
{
	this->companyName = companyName;
	this->director = director;
	this->number = number;
	this->address = address;
	this->typeOfActivity = typeOfActivity;
}

string Company::getCompanyName()
{
	return this->companyName;
}

string Company::getDirector()
{
	return this->director;
}

long unsigned int Company::getNumber()
{
	return this->number;
}

string Company::GetTypeOfActivity()
{
	return this->typeOfActivity;
}

