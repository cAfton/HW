#include "Parrot.h"

void Parrot::Sleep(int hours)
{
	cout << "Your parrot has slept for " << hours << " hours" << endl;
}

void Parrot::Eat(string food)
{
	cout << "Your parrot eat " << food << endl;
}

int Parrot::Intelligence()
{
	return (getAge() * 10) + words; //let it be
}

ostream& operator<<(ostream& out, Parrot& parrot)
{
	out << static_cast<Pet&>(parrot) << "\nKnow " << parrot.words << " words";
	return out;
}
