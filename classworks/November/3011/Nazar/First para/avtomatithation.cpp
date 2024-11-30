#include "avtomatithation.h"

void information::add(train newOne)
{
	this->trains.push_back(newOne);


}

train::train()
{
	this->name = "Null";
	this->time = 0.00;

}
