#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"

int main()
{
	Parrot parrot("Chuya", 1, 0);
	Dog dog("Boni", 7, 4);
	Cat cat("Musia", 10, 6);

	cout << "parrot: \n" << parrot << endl;
	cout << "\nDog: \n" << dog << endl;
	cout << "\nCat: \n" << cat << endl;

	cout << endl;
	cout << endl;

	parrot.Eat("seed");
	parrot.Sleep(12);
	cout << "Parrot: " << parrot.Intelligence() << endl;

	cout << endl;
	cout << endl;

	dog.Eat("feed");
	dog.Sleep(10);
	cout << "Dog: " << dog.Intelligence() << endl;

	cout << endl;
	cout << endl;

	cat.Eat("fish");
	cat.Sleep(16);
	cout << "Cat: " << cat.Intelligence() << endl;

}