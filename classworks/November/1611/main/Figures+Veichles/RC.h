#pragma once
#include "IFileLoader.h"

class RC : public IFileSaver {
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

	void printInFile() {
		ofstream file(fileName);
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

	bool IsCollected() {
		return this->isCollected;
	}

};