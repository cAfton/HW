#include "Paralelogram.h"

Paralelogram::Paralelogram() {
	SideA = 1;
	SideB = 2;
	Angle = 45;
}

Paralelogram::Paralelogram(int sideA, int sideB, int angle, int x, int y) {
	this->SideA = sideA;
	this->SideB = sideB;
	this->Angle = angle;
	this->X = x;
	this->Y = y;
}

string Paralelogram::Print() {
	string ret = "Paralelogram: " + to_string(this->SideA) + "; " + to_string(this->SideB) + "; " + to_string(this->Angle);

	return ret;
}

void Paralelogram::Save(string path)
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

void Paralelogram::Load(string path)
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

float Paralelogram::Area()
{
	float S = (SideA * SideB) * sin(Angle);
	return S;
}

float Paralelogram::Perimetr()
{
	float P = 2 * SideA + 2 * SideB;
	return P;
}
