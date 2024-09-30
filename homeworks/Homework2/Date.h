#pragma once
#include <iostream>

using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
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
