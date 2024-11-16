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
