#include "Dog.h"

void Dog::Sleep(int hours)
{
	cout << "Your dog has slept for " << hours << " hours" << endl;
}

void Dog::Eat(string food)
{
	cout << "Your dog eat " << food << endl;
}

void Dog::Guard(int hours)
{
	cout << "your dog has guarded you for " << hours << " hours. " << (rand() % 11 < this->guarding_qualities ? "Your dog guarded you well" : "Your dog didn't manage to guard you") << endl;
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
