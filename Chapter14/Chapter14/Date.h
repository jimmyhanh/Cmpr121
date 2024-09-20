#pragma once
#include <string>
#include <iostream>
#include "input.h"
#include <cmath>

using namespace std;

class Date
{
	const string monthNames[13] = { "unknown", "January", "February", "March" , "April", "May", "June", "July", "August", "September", "October" ,"November", "December" };
	const int maxDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31 };

private:
	int month;
	int day;
	int year;

public:
	Date();
	Date(int newMonth, int newDay, int newYear);
	Date(const Date& obj);	// Copy Constructor


	void setMonth(int newMonth);
	int getMonth() const;

	void setDay(int newDay);
	int getDay() const;

	void setYear(int newYear);
	int getYear() const;

	string getDateFormat1() const;
	string getDateFormat2() const;
	string getDateFormat3() const;


	Date operator++();	    // prefix(++)
	Date operator++(int);	// postfix(++)

	Date operator--();	    // prefix(--)
	Date operator--(int);	// postfix(--)

	int operator-(const Date& right);	// Overload the - operator

	// Overload the << operator
	friend ostream& operator<<(ostream& out, const Date& obj);

	// Overload the >> operator
	friend istream& operator>>(istream& in, Date& obj);

};

