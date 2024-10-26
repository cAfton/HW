#pragma once
#include "Vehicle.h"

class Train: public Vehicle {
	int WagonCount;
public:
	Train() : Vehicle() {
		WagonCount = 1;
	}
	Train(int speed, int dis, int weig, int wag) : Vehicle(speed, dis, weig) {
		this->WagonCount = wag;
	}

	friend ostream& operator<<(ostream& out, Train& train) {
		out << static_cast<Vehicle&>(train) << "\nWagons: " << train.WagonCount;

		return out;
	}

	void AddWagon() {
		this->WagonCount++;
	}

	void MinusWagon() {
		if (WagonCount != 0)
		{
			this->WagonCount--;
		}
	}


};