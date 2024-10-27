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

	void Sleep(int hours) {
		cout << "Your dog has slept for " << hours << " hours" << endl;
	}

	void Eat(string food) {
		cout << "Your dog eat " << food << endl;
	}

	int Intelligence() {
		return getAge() * guarding_qualities * 2; //let it be
	}

	friend ostream& operator<<(ostream& out, Dog& dog) {
		out << static_cast<Pet&>(dog) << "\nCan guard you: " << dog.guarding_qualities << "/10";
		return out;
	}
};