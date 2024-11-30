#pragma once
#include "Pet.h"

class Dog : public Pet {
	int guarding_qualities; //dog's ability to guard its owners
public:
	Dog();

	Dog(string name, int age, int guarding_qualities);

	void Sleep(int hours);

	void Eat(string food);

	void Guard(int hours);

	int Intelligence();

	friend ostream& operator<<(ostream& out, Dog& dog);
};