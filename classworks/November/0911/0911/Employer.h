#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employer {
	string name;
	int age;
	static string workPlace;
public:
	Employer();

	Employer(string Name, int Age);

	virtual string Print() = 0;

	virtual void Work(int works) = 0;

	friend ostream& operator<<(ostream& out, Employer& emp);
};