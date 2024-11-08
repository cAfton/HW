#include "Dog.h"

void Dog::Sleep(int hours)
{
	cout << "Your dog has slept for " << hours << " hours" << endl;
}

void Dog::Eat(string food)
{
	cout << "Your dog eat " << food << endl;
}

int Dog::Intelligence()
{
	return getAge() + guarding_qualities; //let it be
}

ostream& operator<<(ostream& out, Dog& dog)
{
	out << static_cast<Pet&>(dog) << "\nCan guard you: " << dog.guarding_qualities << "/10";
	return out;
}
