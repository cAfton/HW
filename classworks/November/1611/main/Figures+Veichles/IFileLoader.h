#pragma once
#include <string>
#include <iostream>


using namespace std;



class IFileSaver {
public:
	const string fileName = "File.txt";

	virtual void printInFile() = 0;
};