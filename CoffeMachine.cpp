#include "CoffeMachine.h"
#include <iostream>
using namespace std;


void CoffeeMachine::PrintLeft()
{
	cout << "Coffee: " << this->coffeeCount << "\nMilk: " << this->milkCount << "\nWater: " << this->waterCount << "\nCapuchinator: " << (this->capuchinator ? "avalible\n" : "not avalible\n");
}

void CoffeeMachine::Refill(double coffee, double milk, double water)
{
	this->coffeeCount += coffee;
	this->waterCount += water;
	this->milkCount += milk;
}

void CoffeeMachine::createCoffee(CoffeeModes coffeeMode)
{

	switch (coffeeMode)
	{
	case Latte:
		if (this->coffeeCount >= sizeOfCup * (1 / 4) && this->milkCount >= sizeOfCup * (3 / 4))
		{
			this->coffeeCount -= (sizeOfCup * (1 / 4));
			this->milkCount -= (sizeOfCup * (3 / 4));

		}
		else {
			cout << "refill coffee machine" << endl;
		}
		break;
	case Capuchino:
		if (capuchinator && this->coffeeCount >= sizeOfCup * (1 / 4) && this->milkCount >= sizeOfCup * (3 / 4))
		{
			this->coffeeCount -= (sizeOfCup * (1 / 4));
			this->milkCount -= (sizeOfCup * (3 / 4));
		}
		else {
			cout << "refill coffee machine" << endl;
		}
		break;
	case Americano:
		if (this->waterCount >= sizeOfCup * (3 / 4) && this->coffeeCount >= sizeOfCup * (1 / 4))
		{
			this->waterCount -= (sizeOfCup * (3 / 4));
			this->coffeeCount -= (sizeOfCup * (1 / 4));
		}
		else {
			cout << "refill coffee machine" << endl;
		}
		break;
	case Americano_with_milk:
		if (this->waterCount >= sizeOfCup * (2 / 4) && this->coffeeCount >= sizeOfCup * (1 / 4) && this->milkCount >= sizeOfCup * (1 / 4))
		{
			this->waterCount -= (sizeOfCup * (2 / 4));
			this->coffeeCount -= (sizeOfCup * (1 / 4));
			this->milkCount -= (sizeOfCup * (1 / 4));
		}
		else {
			cout << "refill coffee machine" << endl;
		}
		break;
	case Glace:
		if (coffeeCount >= sizeOfCup * (2 / 3))
		{
			this->coffeeCount -= (sizeOfCup * (2 / 3));
		}
		else {
			cout << "refill coffee machine" << endl;
		}
		break;
	case Espresso:
		if (this->coffeeCount >= sizeOfCup * (1 / 4))
		{
			this->coffeeCount -= (sizeOfCup * (1 / 4));
		}
		else {
			cout << "refill coffee machine" << endl;
		}
		break;

	default:
		break;
	}
}
