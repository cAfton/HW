#pragma once
#include "Pet.h"

class Dog : public Pet {
	int guarding_qualities; //dog's ability to guard its owners
public:
	Dog() : Pet() {
		this->guarding_qualities = 0;
	}

	Dog(string name, int age, int guarding_qualities) : Pet(name, age) {
		this->guarding_qualities = guarding_qualities;
	}

	void Sleep(int hours);

	void Eat(string food);

	void Guard(int hours);

	int Intelligence();

	friend ostream& operator<<(ostream& out, Dog& dog);
};