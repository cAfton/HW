#pragma once
#include "Pet.h"

class Cat : public Pet {
	double activity; // energy level
public:
	Cat() : Pet() {
		this->activity = 0;
	}

	Cat(string name, int age, double activity) : Pet(name, age) {
		this->activity = activity;
	}

	void Sleep(int hours); 


	void Eat(string food);

	int Intelligence();

	friend ostream& operator<<(ostream& out, Cat& cat);
};