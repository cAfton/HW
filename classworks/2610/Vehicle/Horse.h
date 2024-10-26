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

	void Feed(int food) {
		cout << ">:3" << endl;
	}
	void Sleep(int sleep) {
		cout << "|o" << endl;
	}
};
