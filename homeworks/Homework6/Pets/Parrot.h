#pragma once
#include "Pet.h"

class Parrot : public Pet {
	int words; // how many words know
	string* wordsList;
public:
	Parrot();

	Parrot(string name, int age, int words, string* list);

	void learnedNewWord(string word);

	void Talk();

	void Sleep(int hours);

	void Eat(string food);

	int Intelligence();

	friend ostream& operator<<(ostream& out, Parrot& parrot);

	~Parrot() {
		delete[] wordsList;
	}
};