#include "Cat.h"

Cat::Cat() : Pet()
{
	this->activity = 0;
}

Cat::Cat(string name, int age, double activity)  : Pet(name, age)
{
	this->activity = activity;
}

void Cat::Sleep(int hours)
{
	cout << "Your cat has slept for " << hours << " hours" << endl;
	if (this->activity + (hours / 15) < 10)
	{
		this->activity += hours / 15;
	}
}

void Cat::Eat(string food)
{
	cout << "Your cat eat " << food << endl;
	if (this->activity + 1 < 10)
	{
		this->activity += 1;
	}
}

int Cat::Intelligence()
{
	return getAge() + activity; //let it be
}

ostream& operator<<(ostream& out, Cat& cat)
{
	out << static_cast<Pet&>(cat) << "\nEnergy level: " << cat.activity << "/10";
	return out;
}
