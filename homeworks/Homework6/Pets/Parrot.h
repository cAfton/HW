#pragma once
#include "Pet.h"

class Parrot : public Pet {
	int words; // how many words know
	string* wordsList;
public:
	Parrot() : Pet() {
		this->words = 0;
		this->wordsList = nullptr;
	}

	Parrot(string name, int age, int words, string* list) : Pet(name, age) {
		this->words = words;
		this->wordsList = new string[words];
		for (int i = 0; i < words; i++) {
			this->wordsList[i] = list[i];
		}
	}

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