#pragma once
#include "Car.h"

class Buss : public Car{
private:
	int BusNumber;
	int RouteNumber;
	int sits;
	string Driver;
public:
	Buss() {
		BusNumber = 1939;
		Driver = "Michail";
		RouteNumber = 9;
		sits = 30;
	}
	Buss(int BussNum, string name, int route, int Sits) {
		BussNum = BusNumber;
		name = Driver;
		route = RouteNumber;
		Sits = sits;
	}

	void Feed(int) {
		cout << ">:3" << endl;
	}

	friend ostream& operator<<(ostream& wiwod, Buss Bus) {
		wiwod << static_cast<Car&>(Bus) << "Bus Number: " << Bus.BusNumber << "\nDriver: " << Bus.Driver << "\nRoute Number: " << Bus.RouteNumber << "\nnum of sits: " << Bus.sits << " ";
		return wiwod;
	}

	friend istream& operator>>(istream& in, Buss& Bus) {
		int newBN, newRN, newS;
		string D;
		cout << "Bus number: ";
		in >> Bus.BusNumber;
		cout << "\n\nRoute number: ";
		in >> Bus.RouteNumber;
		cout << "\n\nDriver: ";
		in >> Bus.Driver;
		cout << "\n\nNumber of sits: ";
		in >> Bus.sits;

		return in;



	}

	bool operator > (Buss& bilshe) {
		if (this->BusNumber > bilshe.BusNumber) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator > (int bilshe) {
		if (this->BusNumber > bilshe) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator < (Buss& menshe) {
		if (this->BusNumber < menshe.BusNumber) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator < (int menshe) {
		if (this->BusNumber < menshe) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator == (Buss& rivne) {
		if (this->BusNumber == rivne.BusNumber) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator == (int Num) {
		if (Num == this->BusNumber) {
			return true;
		}
		else
		{
			return false;
		}
	}
	~Buss() {

	}
};
