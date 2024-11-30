#include "avtomatithation.h"

information::information()
{
	this->trains = vector<train>();	
}



void information::add(train newOne)
{
	this->trains.push_back(newOne);
}


train::train()
{
	this->name = "Null";
	this->time = 0.0;
	this->from = "void";
	this->end = "abyss";

}

train::train(string name, double time, string from, string end)
{
	this->name = name;
	this->time = time;
	this->from = from;
	this->end = end;
}

string train::print()
{
	string tmp;
	tmp = this->name + ';' + to_string(this->time) + ';' + this->from + this->end;
	return tmp;
}
