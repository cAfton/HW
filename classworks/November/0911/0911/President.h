#pragma once
#include "Employer.h"

class President : public Employer {
private:
	double gold;	
public:
	President() : Employer(){
		this->gold = 1;
	}

	President(string Name, int Age, double Gold) : Employer(Name, Age) {
		this->gold = Gold;
	}

	string Print() override;

	void Work(int works);

	friend ostream& operator<< (ostream& out, President& pres);
};