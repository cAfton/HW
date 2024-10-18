#include "Date.h"

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1970;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

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

Date Date::addDay() {
	switch (this->month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
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
	
	case 4:
	case 6:
	case 9:
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

	return Date(this->day, this->month, this->year);
}

Date Date::minusDay()
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
		case 4:
		case 6:
		case 8:
		case 9:
		case 11:

			this->day = 31;
			this->month--;
			break;
		case 3:
			this->day = 28;
			this->month--;
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			this->day = 30;
			this->month--;
			break;
		}
	}
	else {
		this->day--;
	}

	return Date(this->day, this->month, this->year);
}

void Date::sort()
{
	if (Day() > 31) {
		Month(Month() + (Day() / 31));
		Day(Day() % 31);
	}
	if (Month() > 12) {
		Year(Year() + (Month() / 12));
		Month(Month() % 12);
	}
	if (Day() < 1) {
		Month(Month() - 1);
		Day(31 + Day());
	}
	if (Month() < 1) {
		Year(Year() - 1);
		Month(12 + Month());
	}
}

Date Date::operator++(int post)
{
	Date temp = Date(this->day, this->month, this->year);
	addDay();
	return temp;
}

Date Date::operator++()
{
	return addDay();
}

Date Date::operator--(int post)
{
	Date temp = Date(this->day, this->month, this->year);
	minusDay();
	return temp;
}

Date Date::operator--()
{
	return minusDay();
}

Date Date::operator+(Date date)
{
	Date ret;

	ret.year = this->year + date.Year();

	if (this->month + date.Month() > 12)
	{
		ret.month = (this->month + date.Month()) - 12;
	}
	else {
		ret.month = this->month + date.Month();
	}

	switch (ret.month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
		if (this->day + date.day > 31)
		{
			ret.day = (this->day + date.Day()) - 31;
		}
		else {
			ret.day = this->day + date.Day();
		}
		break;
	case 2:
		if (this->day + date.day > 28)
		{
			ret.day = (this->day + date.Day()) - 28;
		}
		else {
			ret.day = this->day + date.Day();
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (this->day + date.day > 30)
		{
			ret.day = (this->day + date.Day()) - 30;
		}
		else {
			ret.day = this->day + date.Day();
		}
		break;
	case 12:
		if (this->day + date.day > 31)
		{
			ret.day = (this->day + date.Day()) - 31;
			this->year++;
		}
		else {
			ret.day = this->day + date.Day();
		}
		break;
	}

	return ret;

}

Date Date::operator-(Date date)
{
	Date ret;

	ret.year = this->year - date.Year();

	if (this->month - date.Month() < 1)
	{
		ret.month = 12 + (this->month - date.Month());
	}
	switch (ret.month)
	{
	case 1:
		if (this->day - date.Day() < 1)
		{
			ret.day = 31 + (this->day - date.Day());
			this->year--;
		}
		else {
			ret.day = this->day - date.Day();
		}
		break;
	case 2:
		if (this->day - date.Day() < 1)
		{
			ret.day = 28 + (this->day - date.Day());
		}
		else {
			ret.day = this->day - date.Day();
		}
		break;
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (this->day - date.Day() < 1)
		{
			ret.day = 31 + (this->day - date.Day());
		}
		else {
			ret.day = this->day - date.Day();
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (this->day - date.Day() < 1)
		{
			ret.day = 30 + (this->day - date.Day());
		}
		else {
			ret.day = this->day - date.Day();
		}
		break;

	}

	return ret;
}

ostream& operator<<(ostream& out, const Date& date)
{
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}

istream& operator>>(istream& in, Date& date)
{
	cout << "Date: ";
	in >> date.day;
	cout << "\nMonth: ";
	in >> date.month;
	cout << "\nYear: ";
	in >> date.year;
	return in;
}
///////////////

bool Date::operator!=(const Date& date) const {
	return day != date.day || month != date.month || year != date.year;
}

bool Date::operator==(const Date& date) const {
	return day == date.day && month == date.month && year == date.year;
}


bool Date::operator>(const Date& date) const {
	if (year > date.year)
		return true;
	else if (year == date.year && month > date.month)
		return true;
	else if (month == date.month && day > date.day)
		return true;
	else
		return false;
}

bool Date::operator<(const Date& date) const {
	if (year < date.year)
		return true;
	else if (year == date.year && month < date.month)
		return true;
	else if (month == date.month && day < date.day)
		return true;
	else
		return false;
}


bool Date::operator>=(const Date& date) const {
	return year >= date.year || (year >= date.year && month >= date.month) || (year >= date.year && month >= date.month && day >= date.day);
}
bool Date::operator<=(const Date& date) const {
	return year <= date.year || (year <= date.year && month <= date.month) || (year <= date.year && month <= date.month && day <= date.day);
}


void Date::operator=(const Date& date)
{
	Year(date.year);
	Month(date.month);
	Day(date.day);
}


void Date::operator+=(const Date& date)
{
	Year(Year() + date.year);
	Month(Month() + date.month);
	Day(Day() + date.day);
	sort();
}

void Date::operator-=(const Date& date)
{
	Year(Year() - date.year);
	Month(Month() - date.month);
	Day(Day() - date.day);
	sort();
}

void Date::operator()(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	sort();
}


