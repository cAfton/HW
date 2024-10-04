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

	void sort();

	friend ostream& operator<<(ostream& out, const Date& date);
	friend ifstream& operator>>(ifstream& in, Date& date);

	void operator++(int post);
	void operator++();

	void operator--(int post);
	void operator--();

	Date operator+(Date date);
	Date operator-(Date date);

	bool operator!=(const Date& date) const;
	bool operator==(const Date& date) const;

	bool operator>(const Date& date) const;
	bool operator<(const Date& date) const;

	bool operator>=(const Date& date) const;
	bool operator<=(const Date& date) const;

	void operator=(const Date& date);

	void operator+=(const Date& date);
	void operator-=(const Date& date);

	void operator()(int y, int m, int d);
};
