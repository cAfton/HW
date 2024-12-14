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

	void Load(string path);

	void Save(string path);

	Company findByName(string name);

	Company findByDirector(string director);
	
	Company findByNumber(string num);
	
	Company findByActivity(string activity);


	void saveToFile();

	void readFromFile();
	
};