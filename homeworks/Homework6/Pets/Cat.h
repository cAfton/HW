#pragma once
#include "Pet.h"

class Cat : public Pet {
	int activity; // energy level
public:
	Cat() : Pet() {
		this->activity = 0;
	}

	Cat(string name, int age, int activity) : Pet(name, age) {
		this->activity = activity;
	}

	void Sleep(int hours) {
		cout << "Your cat has slept for " << hours << " hours" << endl;
	}

	void Eat(string food) {
		cout << "Your cat eat " << food << endl;
	}

	int Intelligence() {
		return getAge() * activity; //let it be
	}

	friend ostream& operator<<(ostream& out, Cat& cat) {
		out << static_cast<Pet&>(cat) << "\nEnergy level: " << cat.activity << "/10";
		return out;
	}
};