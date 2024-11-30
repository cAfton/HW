#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"

int main()
{
	string* words = new string[3];
	words[0] = "Chuya";
	words[1] = "Hi";
	words[2] = "Eat!";

	Parrot parrot("Chuya", 1, 3, words);
	Dog dog("Boni", 7, 4);
	Cat cat("Musia", 10, 6);

	cout << "parrot: \n" << parrot << endl;
	cout << "\nDog: \n" << dog << endl;
	cout << "\nCat: \n" << cat << endl;

	cout << endl;
	cout << endl;

	cout << "talks: " << endl;
	parrot.Talk();
	parrot.Eat("seed");
	parrot.Sleep(12);
	cout << "Parrot: " << parrot.Intelligence() << endl;

	cout << endl;
	cout << endl;

	dog.Eat("feed");
	dog.Sleep(10);
	dog.Guard(5);
	cout << "Dog: " << dog.Intelligence() << endl;

	cout << endl;
	cout << endl;

	cat.Eat("fish");
	cat.Sleep(16);
	cout << "Cat: " << cat.Intelligence() << endl;

}