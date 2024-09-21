#include <iostream>
#include "Car.h"

using namespace std;

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