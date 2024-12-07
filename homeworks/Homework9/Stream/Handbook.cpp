#include "Handbook.h"

Handbook::Handbook()
{
	this->companies = nullptr;
	this->lenght = 0;
	this->size = 10;
}

Handbook::Handbook(Company* c, int l, int s)
{
	this->companies = c;
	this->lenght = l;
	this->size = s;
}

void Handbook::addNew(Company addNew)
{
	if (this->companies == nullptr)
	{
		this->companies = new Company[this->size];
		this->companies[this->lenght] = addNew;
		this->lenght++;
	}
	else if(this->lenght == this->size){
		Company* newArr = new Company[size * 2];
		size *= 2;
		for (size_t i = 0; i < this->lenght; i++)
		{
			newArr[i] = this->companies[i];
		}
		newArr[this->lenght] = addNew;
		this->lenght++;
		delete[] this->companies;
		this->companies = newArr;
	}
	else {
		this->companies[this->lenght] = addNew;
		this->lenght++;
	}
}

Company Handbook::findByName(string name)
{
	for (size_t i = 0; i < this->lenght; i++)
	{
		if (this->companies[i].getCompanyName() == name)
		{
			return this->companies[i];
		}
	}
}

Company Handbook::findByDirector(string director)
{
	for (size_t i = 0; i < this->lenght; i++)
	{
		if (this->companies[i].getDirector() == director)
		{
			return this->companies[i];
		}
	}
}

Company Handbook::findByNumber(long unsigned int num)
{
	for (size_t i = 0; i < this->lenght; i++)
	{
		if (this->companies[i].getNumber() == num)
		{
			return this->companies[i];
		}
	}
}

Company Handbook::findByActivity(string activity)
{
	for (size_t i = 0; i < this->lenght; i++)
	{
		if (this->companies[i].GetTypeOfActivity() == activity)
		{
			return this->companies[i];
		}
	}
}


Company Handbook::saveToFile() {
	outFile.open(fileName, ios::app);
	if (!outFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	for (int i = 0; i < lenght; i++)
	{
		outFile << companies[i].getCompanyName << '|' << companies[i].getDirector << '|' << companies[i].getNumber << '|' << companies[i].GetTypeOfActivity;
	}
}