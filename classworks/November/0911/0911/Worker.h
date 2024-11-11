#pragma once
#include "Employer.h"


class Worker : public Employer {
private:
	double bronze;
public:
	Worker() : Employer() {
		this->bronze = 1;
	}

	Worker(string Name, int Age, double Bronze) : Employer(Name, Age) {
		this->bronze = Bronze;
	}

	string Print() override;

	void Work(int works);

	friend ostream& operator<< (ostream& out, Worker& worker);
};