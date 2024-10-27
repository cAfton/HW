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

	void Sleep(int hours) {
		cout << "Your parrot has slept for " << hours << " hours" << endl;
	}

	void Eat(string food) {
		cout << "Your parrot eat " << food << endl;
	}

	int Intelligence() {
		return getAge() * words; //let it be
	}

	friend ostream& operator<<(ostream& out, Parrot& parrot) {
		out << static_cast<Pet&>(parrot) << "\nKnow " << parrot.words << " words";
		return out;
	}
};