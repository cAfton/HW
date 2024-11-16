#pragma once
#include "Vehicle.h"

class Horse : public Vehicle
{
	string color;
public:
	Horse() : Vehicle() {
		this->color = "color";
	}

	Horse(int speed, int dis, int weig, string color) : Vehicle(speed, dis, weig) {
		this->color = color;
	}

	friend ostream& operator<<(ostream& out, Horse& horse) {
		out << static_cast<Vehicle&>(horse) << "\ncolor: " << horse.color;

		return out;
	}

	void printInFile(string filePath)  {
		ofstream file(filePath, ios::app);
		if (!file.is_open())
		{
			return;
		}

		file << "Horse: " << endl;
		file << this->max_speed << endl;
		file << this->distance << endl;
		file << this->weight << endl;
		file << this->color << endl;

		file.close();
	}

	//void printFromFile(ifstream& file, vector<IFileLoader*>& v)override {
	//	string read;
	//	getline(file, read);
	//	this->max_speed = stoi(read);

	//	getline(file, read);
	//	this->distance = stoi(read);

	//	getline(file, read);
	//	this->weight = stoi(read);

	//	getline(file, this->color);

	//	v.push_back(this);
	//}
	Horse* read(ifstream& file) {
		Horse* newHorse = new Horse;
		string read;
		getline(file, read);
		newHorse->max_speed = stoi(read);

		getline(file, read);
		newHorse->distance = stoi(read);

		getline(file, read);
		newHorse->weight = stoi(read);

		getline(file, newHorse->color);

		return newHorse;
	}

	void Feed(int food) {
		setDis(getDis() + food);
		cout << ">:3" << endl;
		cout << getDis() << endl;
	}
	void Sleep(int sleep) {
		setDis(getDis() + sleep);
		cout << "|o" << endl;
		cout << getDis() << endl;

	}
};
