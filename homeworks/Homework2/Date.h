#pragma once
#include <iostream>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date() {
		this->day = 1;
		this->month = 1;
		this->year = 1970;
	}
	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

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

};
