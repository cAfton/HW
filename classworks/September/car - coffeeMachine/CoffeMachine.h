#pragma once
#include <iostream>

using namespace std;

enum CoffeeModes {
	Latte,
	Capuchino,
	Americano,
	Americano_with_milk,
	Glace,
	Espresso
};

class CoffeeMachine {
private:
	CoffeeModes coffeeMode;
	int modeCount;
	bool capuchinator;
	double coffeeCount;
	double milkCount;
	double waterCount;
	double sizeOfCup;
public:
	CoffeeMachine(bool capuchinator, double coffeeCount, double milkCount, double waterCount, double sizeOfCup) : modeCount(6), capuchinator(capuchinator), coffeeCount(coffeeCount), milkCount(milkCount), waterCount(waterCount), sizeOfCup(sizeOfCup){}
	CoffeeMachine(): modeCount(6), capuchinator(false), coffeeCount(0), milkCount(0), waterCount(0), sizeOfCup(0){}

	void Refill(double coffee, double water, double milk);
	void createCoffee(CoffeeModes coffeeMode);

	friend std::ostream& operator<<(std::ostream& out, const CoffeeMachine machine);

};