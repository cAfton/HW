#include <iostream>
#include "Car.h"

using namespace std;



int Car::Calc() const
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
	int a = car2.Calc();
	if (this->Calc() > a)
		return true;
	else
		return false;
}
bool Car::operator<(const Car& car2) const
{
	int a = car2.Calc();
	if (this->Calc() < a)
		return true;
	else
		return false;
}