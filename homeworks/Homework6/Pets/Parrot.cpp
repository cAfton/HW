#include "Parrot.h"

Parrot::Parrot() : Pet() {
	this->words = 0;
	this->wordsList = nullptr;
}

Parrot::Parrot(string name, int age, int words, string* list) : Pet(name, age) {
	this->words = words;
	this->wordsList = new string[words];
	for (int i = 0; i < words; i++) {
		this->wordsList[i] = list[i];
	}
}

void Parrot::learnedNewWord(string word)
{
	if (this->wordsList != nullptr)
	{
		string* temp = new string[this->words + 1];
		for (size_t i = 0; i < this->words; i++)
		{
			temp[i] = this->wordsList[i];
		}
		temp[this->words] = word;

		delete[] wordsList;
		this->wordsList = temp;
		words++;
	}
	else {
		this->words++;
		this->wordsList = new string[words];
		this->wordsList[words - 1] = word;

	}
}

void Parrot::Talk()
{
	for (size_t i = 0; i < this->words; i++)
	{
		cout << this->wordsList[i] << endl;
	}
}

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
