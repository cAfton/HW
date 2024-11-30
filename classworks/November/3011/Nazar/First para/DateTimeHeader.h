#pragma once
#include <iostream>
#include <string>

using namespace std;

class DateTime {
	int year;
	int month;
	int day;

	int hour;
	int minute;
	int seconds;

public:

	DateTime();

	DateTime(int year, int month, int day, int hour, int minute, int seconds);

	int Year();

	int Month();

	int Day();

	int Hour();

	int Minute();

	int Seconds();

	string Date();

	string Time();

	friend ostream& operator<<(ostream& out, const DateTime& date);

	friend istream& operator>>(istream& in, DateTime& date);
};