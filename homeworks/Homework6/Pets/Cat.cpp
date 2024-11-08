#include "Cat.h"

void Cat::Sleep(int hours)
{
	cout << "Your cat has slept for " << hours << " hours" << endl;
}

void Cat::Eat(string food)
{
	cout << "Your cat eat " << food << endl;

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
