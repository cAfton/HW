#include "DateTimeHeader.h"

DateTime::DateTime()
{
	this->year = 1970;
	this->month = 1;
	this->day = 1;

	this->hour = 1;
	this->minute = 1;
	this->seconds = 1;
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int seconds) : year(year), month(month), day(day), hour(hour), minute(minute), seconds(seconds) {}

int DateTime::Year()
{
	return this->year;
}

int DateTime::Month()
{
	return this->month;
}

int DateTime::Day()
{
	return this->day;
}

int DateTime::Hour()
{
	return this->hour;
}

int DateTime::Minute()
{
	return this->minute;
}

int DateTime::Seconds()
{
	return this->seconds;
}

string DateTime::Date()
{
	string ret = to_string(this->year) + "-" + to_string(this->month) + "-" + to_string(this->day);
	return ret;
}

string DateTime::Time()
{
	string ret = to_string(this->hour) + ":" + to_string(this->minute) + ":" + to_string(this->seconds);
}

ostream& operator<<(ostream& out, const DateTime& date)
{
	out << date.year << "-" << date.month << "-" << date.day << "  " << date.hour << ":" << date.minute << ":" << date.seconds;
	return out;
}

istream& operator>>(istream& in, DateTime& date)
{
	cout << "Year: ";
	in >> date.year;

	cout << "Month: ";
	in >> date.month;

	cout << "Day: ";
	in >> date.day;

	cout << "Hour: ";
	in >> date.hour;

	cout << "Minute: ";
	in >> date.minute;

	cout << "Second: ";
	in >> date.seconds;

	return in;
}
