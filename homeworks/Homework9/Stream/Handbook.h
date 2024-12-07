#pragma once
#include "Company.h"
#include <fstream>
#include <string>

string fileName = "data.txt";
fstream File;

using namespace std;
class Handbook
{
	Company* companies;
	int size;
	int lenght;

public:
	Handbook();

	Handbook(Company* c, int l, int s);

	void addNew(Company addNew);

	Company findByName(string name);

	Company findByDirector(string director);
	
	Company findByNumber(long unsigned int num);
	
	Company findByActivity(string activity);


	void saveToFile();

	void readFromFile();
	
};