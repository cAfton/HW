#include <iostream>
#include "Car.h"

using namespace std;



int Car::calc()
{
	return (this->pistonCount * (this->fulerType * this->tankVolume)) / this->engineVolume - (this->sitCount * this->weight);
}

int main()
{

}


