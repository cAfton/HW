#pragma once
#include "Employer.h"


class Manager : public Employer {
private:
	double silver;
public:
	Manager() : Employer() {
		this->silver = 1;
	}

	Manager(string Name, int Age, double Silver) : Employer(Name, Age) {
		this->silver = Silver;
	}

	string Print() override;

	void Work(int works);

	friend ostream& operator<< (ostream& out, Manager& man);
};