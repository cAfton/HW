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

	void addDay() {
		switch (this->month)
		{
		case 1:
			if (this->day == 31)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 2:
			if (this->day == 28)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 3:
			if (this->day == 31)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 4:
			if (this->day == 30)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 5:
			if (this->day == 31)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 6:
			if (this->day == 30)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 7:
			if (this->day == 31)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 8:
			if (this->day == 31)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 9:
			if (this->day == 30)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 10:
			if (this->day == 31)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 11:
			if (this->day == 30)
			{
				this->day = 1;
				this->month++;
			}
			else {
				this->day++;
			}
			break;
		case 12:
			if (this->day == 31)
			{
				this->day = 1;
				this->month = 1;
				this->year++;
			}
			else {
				this->day++;
			}
			break;
		default:
			cout << "month went over" << endl;
			break;
		}
	}
};
