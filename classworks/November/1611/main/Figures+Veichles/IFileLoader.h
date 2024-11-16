#pragma once
#include <string>
#include <iostream>
#include <vector>
//#include "Elem.h"

using namespace std;

class IFileSaver {
public:
	virtual void printInFile(string filePath) = 0;
};

class IFileLoader {
public:
	//virtual void printFromFile(ifstream& file, vector<IFileLoader*>& v) = 0;
	virtual IFileLoader* read(ifstream& file) = 0;
};