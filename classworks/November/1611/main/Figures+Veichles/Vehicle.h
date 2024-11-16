#pragma once
#include "Elem.h"


using namespace std;

class Vehicle : public Elem{
protected:
	int max_speed;
	int distance;
	int weight;

	void setDis(int dis) {
		this->distance = dis;
	}
	int getDis() {
		return this->distance;
	}
public:
	Vehicle() {
		this->max_speed = 1;
		this->distance = 1;
		this->weight = 1;
	}
	Vehicle(int speed, int dis, int weig) {
		this->max_speed = speed;
		this->distance = dis;
		this->weight = weig;
	}

	int Time(int Dis) {
		return Dis / this->max_speed;
	}
	
	virtual void Feed(int food) = 0;

	friend ostream& operator<<(ostream& out, Vehicle& vehicle) {
		out << "max speed: " << vehicle.max_speed << "\ndistance: " << vehicle.distance << "\nweight: " << vehicle.weight;

		return out;
	}
};