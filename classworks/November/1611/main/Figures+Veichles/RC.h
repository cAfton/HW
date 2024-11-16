#pragma once
#include "Elem.h"

class RC : public Elem {
	int numOfSquares;
	int numOfFaces;
	bool isCollected;
public:
	RC() {
		this->numOfSquares = 3;
		this->numOfFaces = 6;
		this->isCollected = true;
	}
	RC(int NOS, int NOF, bool iC) {
		this->numOfSquares = NOS;
		this->numOfFaces = NOF;
		this->isCollected = iC;
	}

	void printInFile(string filePath) {
		ofstream file(filePath, ios::app);
		if (!file.is_open())
		{
			return;
		}
		file << "RC: " << endl;
		file << this->numOfSquares << endl;
		file << this->numOfFaces << endl;
		file << this->isCollected << endl;

		file.close();
	}

	/*void printFromFile(ifstream& file, vector<IFileLoader*>& v) override {
		string read;

		getline(file, read);
		this->numOfSquares = stoi(read);

		getline(file, read);
		this->numOfFaces = stoi(read);

		getline(file, read);
		this->isCollected = stoi(read);

		v.push_back(this);
	}*/

	RC* read(ifstream& file) {
		RC* newRc = new RC;
		string read;
		getline(file, read);
		newRc->numOfSquares = stoi(read);

		getline(file, read);
		newRc->numOfFaces = stoi(read);

		getline(file, read);
		newRc->isCollected = stoi(read);

		return newRc;
	}

	bool IsCollected() {
		return this->isCollected;
	}

};