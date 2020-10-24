#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"

using namespace std;

//Default constructor //
Date::Date()
{
	InitDate(1, 1, 2020);
}

// 3-Arguments Constructor //
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

// operator = //
const Date & Date::operator=(const Date & other)
{
	if (this != &other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}

// Copy Constructor //
Date::Date(const Date& other) 
{
	*this = other;
}

// Methode to Initiate date //
void Date::InitDate(int day, int month, int year) throw(const char*)
{
	if (day < 1 || day >31)
		throw "invalid day";
	else if ((month < 1 || month > 12))
		throw "invalid month";
	this->day = day;
	this->month = month;
	this->year = year;

}

// operator == //
bool Date::operator==(const Date& other) const
{
	return ((day == other.day) && (month == other.month) && (year == other.year));
}

// operator << //
ostream & operator<<(ostream & out, const Date & p)
{
	out << p.day << "/" << p.month << "/" << p.year;
	return out;
}

// operator < //
bool Date::operator<(const Date & other) const
{
	if (this->year < other.year)
		return false;
	if (this->year > other.year)
		return true;

	if (this->month < other.month)
		return false;
	if (this->month > other.month)
		return true;

	if (this->day < other.day)
		return false;
	else return true;
}

// Show Method//
void Date::show()
{
	cout << this->day << "/" << this->month << "/" << this->year;
}


// Destructor //
Date::~Date()
{

}
