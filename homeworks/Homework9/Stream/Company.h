#pragma once
#include <iostream>

using namespace std;

class Company
{
protected:
	string companyName;
	string director;
	long unsigned int number;
	string address;
	string typeOfActivity;
public:
	Company();

	Company(string companyName, string director, long unsigned int number, string address, string typeOfActivity);

	string getCompanyName();
	string getDirector();
	long unsigned int getNumber();
	string GetTypeOfActivity();
};