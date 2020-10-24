#ifndef DATE
#define DATE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

/**

This class represent The Expiary Date of a Product

**/
class Date
{
	int day, month, year;

public:
	//Default constructor //
	Date();

	// 3-Arguments Constructor //
	Date(int day, int month, int year);

	// Copy Constructor //
	Date(const Date& other);

	// operator = //
	const Date & operator=(const Date& other);

	// operator == //
	bool operator ==(const Date &other) const;

	// operator << //
	friend ostream & operator <<(ostream& out, const Date & p);

	// operator < //
	bool operator < (const Date &other)const;

	// Methode to set date //
	void InitDate(int day, int month, int year = 2020) throw(const char*);

	// Method to get the Day //
	int getDay()const { return day; };

	// Method to get the Month //
	int getMonth()const { return month; };

	// Method to get the Year //
	int getYear()const { return year; };

	// Method To Show The Date Details //
	void show();

	// Destructor //
	~Date();
};


#endif 
