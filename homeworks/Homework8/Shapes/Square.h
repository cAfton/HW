#pragma once
#include "Rectangle.h"

class Square : public Rectangle {
public:

	Square() : Rectangle(1, 1) {}
	Square(int sideA) : Rectangle(sideA, sideA) {}
	string Print() {
		string ret = "Square: " + to_string(this->SideA) + "; " + to_string(this->SideB) + "; " + to_string(this->Angle);

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
		this->SideB = stoi(save);

	}

	float Area() {
		return this->SideA * this->SideB;
	}

	float Perimetr() {
		return this->SideA * 4;
	}
};