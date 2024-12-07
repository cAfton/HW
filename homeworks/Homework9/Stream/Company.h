#pragma once
#include <iostream>

using namespace std;

class Company
{
protected:
	string companyName;
	string director;
	string number;
	string address;
	string typeOfActivity;
public:
	Company();

	Company(string companyName, string director, string number, string address, string typeOfActivity);

	string getCompanyName();
	string getDirector();
	string getNumber();
	string getAdress();
	string getTypeOfActivity();

	void setCompanyName(string line);
	void setDirector(string line);
	void setNumber(string numb);
	void setAdress(string line);
	void setTypeOfActivity(string line);
};