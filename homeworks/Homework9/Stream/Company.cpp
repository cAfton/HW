#include "Company.h"

Company::Company()
{
	this->companyName = "ATB";
	this->director = "B. Markov";
	this->number = 380970102030;
	this->address = "Dnipro";
	this->typeOfActivity = "supermarket";
}

Company::Company(string companyName, string director, string number, string address, string typeOfActivity)
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

string Company::getNumber()
{
	return this->number;
}

string Company::getAdress()
{
	return this->address;
}

string Company::getTypeOfActivity()
{
	return this->typeOfActivity;
}

void Company::setCompanyName(string line)
{
	this->companyName = line;
}

void Company::setDirector(string line)
{
	this->director = line;
}

void Company::setNumber(string num)
{
	this->number = num;
}

void Company::setAdress(string line)
{
	this->address = line;
}

void Company::setTypeOfActivity(string line)
{
	this->typeOfActivity = line;
}

