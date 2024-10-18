#include "Printer.h"



Client::Client()
{
	this->name = "no_name";
	this->priority = -1;
	this->time_printed = "-1";
}

Client::Client(string name, int priority, string timePrinted)
{
	this->name = name;
	this->priority = priority;
	this->time_printed = timePrinted;
}

string Client::getName()
{
	return this->name;
}

int Client::getPriority()
{
	return this->priority;
}

string Client::getTime()
{
	return this->time_printed;
}

void Client::addToPriority()
{
	this->priority++;
}

Queue::Queue()
{
	arr = new Client[5];
	lengh = 0;
	size = 5;
	start = 0;
}

void Queue::push(Client elem)
{
	Client* newArr = new Client[size + 1];
	size += 1;
	bool isAdded = false;
	for (int i = start, k = 0; i < lengh; i++, k++)
	{

		if (!isAdded && elem.getPriority() <= this->arr[i].getPriority())
		{
			newArr[k] = elem;
			isAdded = true;
			k++;
		}
		newArr[k] = arr[i];
		if (isAdded)
		{
			newArr[k].addToPriority();
		}
	}
	if (!isAdded)
	{
		newArr[lengh] = elem;
	}
	start = 0;
	lengh++;
	delete[] arr;
	arr = newArr;
}

Client Queue::pop()
{

	if (lengh - start != 0)
	{
		Client temp = arr[start];
		start++;
		return temp;
	}
	else {
		throw invalid_argument("error while poping");
	}
}

Client Queue::peek()
{
	return arr[start];
}


ostream& operator<<(ostream& out, Queue& queue)
{
	for (size_t i = 0; i < queue.lengh; i++)
	{
		out << "Name: " << queue.arr[i].getName() << "\nPriority: " << queue.arr[i].getPriority() << "\nTime printed: " << queue.arr[i].getTime() << endl;
	}
	return out;
}


Queue::~Queue()
{
	delete[] arr;

}