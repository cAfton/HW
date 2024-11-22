#include "Dog.h"

Dog::Dog() : Pet()
{
	this->guarding_qualities = 0;
}

Dog::Dog(string name, int age, int guarding_qualities) : Pet(name, age) {
	this->guarding_qualities = guarding_qualities;
}

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
	srand(time(NULL));
	int r = rand() % 11;
	cout << "your dog has guarded you for " << hours << " hours. " << (r < this->guarding_qualities ? "Your dog guarded you well" : "Your dog didn't manage to guard you") << endl;
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
