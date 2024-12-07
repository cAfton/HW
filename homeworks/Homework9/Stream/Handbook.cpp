#include "Handbook.h"

Handbook::Handbook()
{
	this->companies = nullptr;
	this->lenght = 0;
	this->size = 10;
}

Handbook::Handbook(Company* c, int l, int s)
{
	this->companies = c;
	this->lenght = l;
	this->size = s;
}

void Handbook::addNew(Company addNew)
{
	if (this->companies == nullptr)
	{
		this->companies = new Company[this->size];
		this->companies[this->lenght] = addNew;
		this->lenght++;
	}
	else if(this->lenght == this->size){
		Company* newArr = new Company[size * 2];
		size *= 2;
		for (size_t i = 0; i < this->lenght; i++)
		{
			newArr[i] = this->companies[i];
		}
		newArr[this->lenght] = addNew;
		this->lenght++;
		delete[] this->companies;
		this->companies = newArr;
	}
	else {
		this->companies[this->lenght] = addNew;
		this->lenght++;
	}
}

void Handbook::Save(string path) {
	ofstream file;
	file.open(path);

	if (!file.is_open())
	{
		throw runtime_error("");
	}

	file << this->size << endl;
	file << this->lenght << endl;

	for (size_t i = 0; i < this->lenght; i++)
	{
		file << companies[i].getCompanyName() << endl;
		file << companies[i].getDirector() << endl;
		file << companies[i].getNumber() << endl;
		file << companies[i].getAdress() << endl;
		file << companies[i].getTypeOfActivity() << endl;
	}

	file.close();
}

void Handbook::Load(string path) {
	ifstream file;
	file.open(path);

	if (!file.is_open())
	{
		throw runtime_error("");
	}

	string line;

	getline(file, line);
	this->size = stoi(line);
	getline(file, line);
	this->lenght = stoi(line);

	Company* temp = new Company[size];

	for (size_t i = 0; i < this->lenght; i++)
	{
		getline(file, line);
		temp[i].setCompanyName(line);

		getline(file, line);
		temp[i].setDirector(line);

		getline(file, line);
		temp[i].setNumber(line);

		getline(file, line);
		temp[i].setAdress(line);

		getline(file, line);
		temp[i].setTypeOfActivity(line);

	}

	delete[] this->companies;
	this->companies = temp;

}

Company Handbook::findByName(string name)
{
	for (size_t i = 0; i < this->lenght; i++)
	{
		if (this->companies[i].getCompanyName() == name)
		{
			return this->companies[i];
		}
	}

	throw runtime_error("");
}

Company Handbook::findByDirector(string director)
{
	for (size_t i = 0; i < this->lenght; i++)
	{
		if (this->companies[i].getDirector() == director)
		{
			return this->companies[i];
		}
	}

	throw runtime_error("");

}

Company Handbook::findByNumber(string num)
{
	for (size_t i = 0; i < this->lenght; i++)
	{
		if (this->companies[i].getNumber() == num)
		{
			return this->companies[i];
		}
	}

	throw runtime_error("");

}

Company Handbook::findByActivity(string activity)
{
	for (size_t i = 0; i < this->lenght; i++)
	{
		if (this->companies[i].getTypeOfActivity() == activity)
		{
			return this->companies[i];
		}
	}

	throw runtime_error("");

}


Company Handbook::saveToFile() {
	File.open(fileName, ios::app);
	if (!outFile) {
		cout << "Error opening file!" << endl;
		return;
	}
	for (int i = 0; i < lenght; i++)
	{
		outFile << companies[i].getCompanyName << '|' << companies[i].getDirector << '|' << companies[i].getNumber << '|' << companies[i].GetTypeOfActivity;
	}
}


Company Handbook::readFromFile() {
	if (!File) {
		std::cerr << "Error opening file!" << std::endl;
		return;
	}
	string line;

	while (getline(File, line)) {
		istringstream lineStream(line);
		string part1, part2, part3, part4, part5;

		getline(lineStream, part1, '|');
		getline(lineStream, part2, '|');
		getline(lineStream, part3, '|');
		getline(lineStream, part4, '|');
		getline(lineStream, part5, '|');
	}

	Company tmp(part1, part2, part3, part4, part5);
	this->addNew(tmp);
}