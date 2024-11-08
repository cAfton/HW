#pragma once
#include "Pet.h"

class Parrot : public Pet {
	int words; // how many words know
public:
	Parrot() : Pet() {
		this->words = 0;
	}

	Parrot(string name, int age, int words) : Pet(name, age) {
		this->words = words;
	}

	void Sleep(int hours);

	void Eat(string food);

	int Intelligence();

	friend ostream& operator<<(ostream& out, Parrot& parrot);
};