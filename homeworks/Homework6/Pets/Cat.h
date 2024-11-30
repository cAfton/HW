#pragma once
#include "Pet.h"

class Cat : public Pet {
	double activity; // energy level
public:
	Cat();

	Cat(string name, int age, double activity);

	void Sleep(int hours); 


	void Eat(string food);

	int Intelligence();

	friend ostream& operator<<(ostream& out, Cat& cat);
};