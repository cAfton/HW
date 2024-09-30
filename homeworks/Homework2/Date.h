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



	int Day() {
		return this->day;
	}
	int Month() {
		return this->month;
	}
	int Year() {
		return this->year;
	}

	void Day(int day) {
		this->day = day;
	}
	void Month(int month) {
		this->month = month;
	}
	void Year(int year) {
		this->year = year;
	}
};
