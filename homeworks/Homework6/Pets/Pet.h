#pragma once
#include <iostream>

using namespace std;

class Pet
{
	string name;
	int age;
public:
	Pet();

	Pet(string name, int age);

	int getAge();

	virtual void Sleep(int hours) = 0;

	virtual void Eat(string food) = 0;

	virtual int Intelligence() = 0;

	friend ostream& operator<<(ostream& out, Pet& pet);

};