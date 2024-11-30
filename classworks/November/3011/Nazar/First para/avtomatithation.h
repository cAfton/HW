#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class train {
	string name;
	double time;
	string from;
	string end;
public:
	train();
	train(string name, double time, string from, string end);
	train(string line);

	string print();

};

class information
{
	vector<train> trains;
	
public:
	information();

	void add(train newOne);


	friend ostream& operator<<(ostream& out, information& copy);
};


