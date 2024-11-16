#pragma once
#include "Figures.h"
#include <fstream>



class Paralelogram : public Figures {
protected:
	int SideA;
	int SideB;
	int Angle;
public:
	Paralelogram() {
		SideA = 1;
		SideB = 2;
		Angle = 45;
	}
	Paralelogram(int sideA, int sideB, int angle) {
		this->SideA = sideA;
		this->SideB = sideB;
		this->Angle = angle;
	}


	string Print() {
		string ret = "Paralelogram: " + to_string(this->SideA) + "; " + to_string(this->SideB) + "; " + to_string(this->Angle);

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
		float S = (SideA * SideB) * sin(Angle);
		return S;
	}
	float Perimetr() {
		float P = 2 * SideA + 2 * SideB;
		return P;
	}
};
