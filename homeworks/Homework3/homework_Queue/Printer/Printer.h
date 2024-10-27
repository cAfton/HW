#pragma once
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Client {
	string name;
	int priority;
	string time_printed;
public:
	Client();

	Client(string name, int priority, string timePrinted);

	string getName();

	int getPriority();

	string getTime();

	void addToPriority();
};

class Queue {
	Client* arr;
	int lengh;
	int size;
	int start;
public:
	Queue();

	void push(Client elem);

	Client pop();

	Client peek();

	friend ostream& operator<<(ostream& out, Queue& queue);

	~Queue();
};
