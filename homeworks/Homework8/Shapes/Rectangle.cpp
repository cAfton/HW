#include "Rectangle.h"

string Rectangle::Print()
{
	string ret = "Rectangle: " + to_string(this->SideA) + "; " + to_string(this->SideB) + "; " + to_string(this->Angle);

	return ret;

}

void Rectangle::Save(string path)
{
	ofstream file(path, ios::trunc);
	if (!file.is_open())
	{
		throw runtime_error("coudn't open file");
	}

	file << this->SideA << endl;
	file << this->SideB << endl;
	file << this->Angle << endl;

	file.close();

}

void Rectangle::Load(string path)
{
	ifstream file(path);
	if (!file.is_open())
	{
		throw runtime_error("coudn't open file");
	}
	string save;
	getline(file, save);
	this->SideA = stoi(save);

	getline(file, save);
	this->SideB = stoi(save);

	getline(file, save);
	this->Angle = stoi(save);
}

float Rectangle::Area()
{
	return this->SideA * this->SideB * sin(this->Angle);
}

float Rectangle::Perimetr()
{
	return (this->SideA + this->SideB) * 2;

}
