#pragma once
#include <string>

using namespace std;

class Employer {
private:
	string name;
	int age;
public:
	Employer() {
		this->name = "Anton";
		this->age = 3;
	}

	Employer(string Name, int Age) {
		this->name = Name;
		this->age = Age;
	}

	virtual string Print() = 0;
};