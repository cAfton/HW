#pragma once
#include <iostream>
#include <vector>
using namespace std;



class train {
	string name;
	double dateTime;
	string from;
	string end;
public:
	train();
	train(string name, double time, string from, string end);

	string print();



};


class information
{
	vector<train> trains;
	int number;
	string meinStationName;
public:
	information();
	
	void add(train newOne);

	//ostream& operator<<(ostream& out, information& copy);
	
	~information();
};

