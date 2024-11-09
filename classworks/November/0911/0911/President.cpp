#include "President.h"

string President::Print()
{
    string res = "Gold: " + to_string(this->gold);
	return res;
}

void President::Work(int works)
{
	cout << "President is working for " << works << endl;
	this->gold += (works / 100.);
}

ostream& operator<<(ostream& out, President& pres)
{
	out << static_cast<Employer&>(pres) << "\nPresident" << endl;
	out << pres.Print() << endl;

	return out;
}
