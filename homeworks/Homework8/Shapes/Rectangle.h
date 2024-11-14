#pragma once
#include "Paralelogram.h"

class Rectangle : public Paralelogram {
public:
	Rectangle() : Paralelogram(1, 2, 90) {}
	Rectangle(int sideA, int sideB) : Paralelogram(sideA, sideB, 90) {}

	string Print() {
		string ret = "Rectangle: " + to_string(this->SideA) + "; " + to_string(this->SideB) + "; " + to_string(this->Angle);

		return ret;
		
	}

	void Save(string path) {
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

	void Load(string path) {
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


	float Area() {
		return this->SideA * this->SideB * sin(this->Angle);
	}

	float Perimetr() {
		return (this->SideA + this->SideB) * 2;
	}
};
