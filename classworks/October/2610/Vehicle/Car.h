#pragma once
#include "Vehicle.h"
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

	friend ostream& operator<<(ostream& out, Car& car) {
		out << static_cast<Vehicle&>(car) << "\nhorse power: " << car.hp << "\ncolor: " << car.color;

		return out;
	}
};