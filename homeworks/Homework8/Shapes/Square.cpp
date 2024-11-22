#include "Square.h"

string Square::Print()
{
	string ret = "Square: " + to_string(this->SideA) + "; " + to_string(this->SideB) + "; " + to_string(this->Angle);

	return ret;

}

void Square::Save(string path)
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

void Square::Load(string path)
{
	ifstream file(path);
	if (!file.is_open())
	{
		throw runtime_error("coudn't open file");
	}
	string save;
	getline(file, save);
	this->SideA = stoi(save);
	this->SideB = stoi(save);
}

float Square::Area()
{
	return this->SideA * this->SideB;
}

float Square::Perimetr()
{
	return this->SideA * 4;

}
