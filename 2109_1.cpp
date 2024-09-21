#include <iostream>
#include "CoffeMachine.h"

using namespace std;


int main()
{
	CoffeeMachine coffeeMachine(true, 200, 500, 500, 250);

	coffeeMachine.createCoffee(Latte);
	coffeeMachine.createCoffee(Capuchino);
	coffeeMachine.createCoffee(Americano);
	coffeeMachine.Refill(300, 0, 0);
	coffeeMachine.createCoffee(Americano_with_milk);
	coffeeMachine.createCoffee(Glace);
	coffeeMachine.createCoffee(Espresso);
	coffeeMachine.PrintLeft();

}