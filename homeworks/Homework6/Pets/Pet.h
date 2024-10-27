#pragma once
#include <iostream>

using namespace std;

class Pet
{
	string name;
	int age;
public:
	Pet() {
		this->name = "a cool name";
		this->age = 1;
	}

	Pet(string name, int age) {
		this->name = name;
		this->age = age;
	}

	int getAge() {
		return this->age;
	}

	virtual void Sleep(int hours) = 0;

	virtual void Eat(string food) = 0;

	virtual int Intelligence() = 0;

	friend ostream& operator<<(ostream& out, Pet& pet) {
		out << "Name: " << pet.name << "\nAge: " << pet.age;
		return out;
	}

};