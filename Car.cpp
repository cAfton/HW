#include <iostream>
#include "Car.h"

using namespace std;



int Car::Сalc() const
{
	int a;
	if (this->fulerType == gasoline)
		a = 5;
	else if (this->fulerType == diedel)
		a = 3;
	else
		a = 1;
	return (this->pistonCount * (a * this->tankVolume)) / this->engineVolume - (this->sitCount * this->weight);
}

bool Car::operator>(const Car& car2) const
{
	int a = car2.Сalc();
	if (this->Сalc() > a)
		return true;
	else
		return false;
}



int main()
{
	Car car2(50, 1500, 6, gasoline, 4, 300);
	Car car1 = {};
	if (car1 > car2) {//чи потужніша машина 1 за машину 2
		cout << "The first car is more powerful than the second";
	}
	else
		cout << "The second machine is more powerful than the first";
}


