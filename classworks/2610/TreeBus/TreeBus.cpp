#include <iostream>
using namespace std;

class Bus
{
public:
	Bus() {
		BusId = 1488;
		Driver = "Michail";
		RouteNumber = 99;
		Sits = 22;
	}
	Bus(int id, string name, int route, int sit) {
		BusId = id;
		Driver = name;
		RouteNumber = route;
		Sits = sit;
	}
	friend ostream& operator << (ostream& wiwod, Bus& Elektron) {
		wiwod << Elektron.BusId;
		wiwod << Elektron.Driver;
		wiwod << Elektron.RouteNumber;
		wiwod << Elektron.Sits;
	}
	bool operator > (Bus& bilshe) {
		if (this->BusId > bilshe.BusId) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator < (Bus& menshe) {
		if (this->BusId < menshe.BusId) {
			return false;
		}
		else {
			return true;
		}
	}
	bool operator == (Bus& rivne) {
		if (this->BusId == rivne.BusId) {
			return true;
		}
		else {
			return false;
		}
	}
private:
	int BusId;
	string Driver;
	int RouteNumber;
	int Sits;
};

int main() {

}