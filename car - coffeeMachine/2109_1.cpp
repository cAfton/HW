#include <iostream>
#include "Car.h"
#include "CoffeMachine.h"

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
	if (car2 < car1) {//чи потужніша машина 1 за машину 2
		cout << "\nThe first car is more powerful than the second";
	}
	else
		cout << "\nThe second machine is more powerful than the first";
	cout << endl;
	CoffeeMachine coffeeMachine(true, 200, 500, 500, 250);

	coffeeMachine.createCoffee(Latte);
	coffeeMachine.createCoffee(Capuchino);
	coffeeMachine.createCoffee(Americano);
	coffeeMachine.Refill(300, 0, 0);
	coffeeMachine.createCoffee(Americano_with_milk);
	coffeeMachine.createCoffee(Glace);
	coffeeMachine.createCoffee(Espresso);

	cout << coffeeMachine << endl;
}