#pragma once
#include "Vehicle.h"
#include <fstream>


using namespace std;

class Car : public Vehicle {
	string color;
	int hp;
public:
	Car() : Vehicle() {
		this->color = "color";
	}

	Car(int speed, int dis, int weig, int hp, int col) : Vehicle(speed, dis, weig) {
		this->color = col;
		this->hp = hp;
	}

	void Feed(int food) {
		cout << ">:3" << endl;
	};

	void printInFile() {
		ofstream file(fileName);
		if (!file.is_open())
		{
			return;
		}

		file << "Car: " << endl;
		file << this->max_speed << endl;
		file << this->distance << endl;
		file << this->weight << endl;
		file << this->color << endl;
		file << this->hp << endl;

		file.close();
	}

	friend ostream& operator<<(ostream& out, Car& car) {
		out << static_cast<Vehicle&>(car) << "\nhorse power: " << car.hp << "\ncolor: " << car.color;

		return out;
	}
};