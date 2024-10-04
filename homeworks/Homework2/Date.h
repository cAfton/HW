#pragma once
#include <iostream>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);

	int Day();
	int Month();
	int Year();

	void Day(int day);
	void Month(int month);
	void Year(int year);

	void addDay();
	void minusDay();

	friend ostream& operator<<(ostream& out, const Date& date);
	friend ifstream& operator>>(ifstream& in, Date& date);

	void operator++(int post);
	void operator++();

	void operator--(int post);
	void operator--();

	Date operator+(Date date);
	Date operator-(Date date);
	//Nazar
	/*
	Date operator!=(Date& date);
	Date operator==(Date& date);
*/


};
