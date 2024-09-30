#include "Date.h"

int Date::Day()
{
    return this->day;
}

int Date::Month()
{
    return this->month;
}

int Date::Year()
{
    return this->year;
}

void Date::Day(int day)
{
    this->day = day;
}

void Date::Month(int month)
{
    this->month = month;
}

void Date::Year(int year)
{
    this->year = year;
}

void Date::addDay() {
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

void Date::minusDay()
{
	if (this->day == 1)
	{
		switch (this->month)
		{
		case 1:
			this->day = 31;
			this->month = 12;
			this->year--;
			break;
		case 2:
			this->day = 31;
			this->month--;
			break;
		case 3:
			this->day = 28;
			this->month--;
			break;
		case 4:
			this->day = 31;
			this->month--;
			break;
		case 5:
			this->day = 30;
			this->month--;
			break;
		case 6:
			this->day = 31;
			this->month--;
			break;
		case 7:
			this->day = 30;
			this->month--;
			break;
		case 8:
			this->day = 31;
			this->month--;
			break;
		case 9:
			this->day = 31;
			this->month--;
			break;
		case 10:
			this->day = 30;
			this->month--;
			break;
		case 11:
			this->day = 31;
			this->month--;
			break;
		case 12:
			this->day = 30;
			this->month--;
			break;
		}
	}
	else {
		this->day--;
	}
}

void Date::operator++(int post)
{
	addDay();
}

void Date::operator++()
{
	addDay();
}

void Date::operator--(int post)
{
	minusDay();
}

void Date::operator--()
{
	minusDay();
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}

ifstream& operator>>(ifstream& in, Date& date)
{
	return in;
}
