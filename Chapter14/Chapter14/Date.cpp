#include "Date.h"

bool isLeapYear(int year);
int JulianConverter(const Date& s);


// Default Constructor
Date::Date()
{
	month = 0;
	day = 0;
	year = 0;
}

// Constructor#1
Date::Date(int newMonth, int newDay, int newYear)
{
	month = newMonth;
	day = newDay;
	year = newYear;
}


Date::Date(const Date& obj)
{
	day = obj.getDay();
	month = obj.getMonth();
	year = obj.getYear();
}


// pre-condition: none
// post-condition: return value of private member month
int Date::getDay() const
{
	return day;
}


// pre-condition: none
// post-condition: return value of private member month
int Date::getMonth() const
{
	return month;
}


// pre-condition: none
// post-condition: return value of private member month
int Date::getYear() const
{
	return year;
}


// pre-condition: valid int
// post-condition: set value to the private member day
void Date::setDay(int newDay)
{
	day = newDay;	
}


// pre-condition: valid int
// post-condition: set value to the private member month
void Date::setMonth(int newMonth)
{		
	month = newMonth;
}


// pre-condition: valid int
// post-condition: set value to the private member year
void Date::setYear(int newYear)
{
	year = newYear;
}


// pre-condition: none
// post-condition: return string in Date Format MM/DD/YYYY
string Date::getDateFormat1() const
{
	return to_string(getMonth()) + "/" + to_string(getDay()) + "/" + to_string(getYear());
}

// pre-condition: none
// post-condition: return string in Format Month Date, Year 
string Date::getDateFormat2() const
{
	return monthNames[month] + " " + to_string(day) + ", " + to_string(year);
}

// pre-condition: none
// post-condition: return string in format Date Month Year
string Date::getDateFormat3() const
{
	return to_string(day) + " " + monthNames[month] + " " + to_string(year);
}

// Overload the prefix-increment to the date object
Date Date::operator++()
{
	day++;

	// The allowed day is the maximum day for each month
	int maxAllowedDay = maxDay[month];
	if (isLeapYear(year) && month == 2)
		maxAllowedDay = 29;

	// If the increment make the day exceed the max day each month
	if (day > maxAllowedDay)
	{
		day = 1;	// Change the day to 1
		month++;	// Change the month to next month

		if (month > 12)	// If the increment make the month > 12
		{
			month = 1;	// Change the month to 1
			year++;		// And forward the following year
		}
	}

	return *this;
}

// Overload the postfix-increment to the date object
Date Date::operator++(int)
{
	Date temp(*this); // Copy constructor

	day++;	

	// The allowed day is the maximum day for each month
	int maxAllowedDay = maxDay[month];
	if (isLeapYear(year) && month == 2)
		maxAllowedDay = 29;

	// If the increment cause the day exceed the max day of the month
	if (day > maxAllowedDay)
	{
		day = 1;	// Change the day to 1
		month++;	// And change the month to next month

		if (month > 12)	// If the increment cause the day > 12
		{
			month = 1;	// Change the month to 1
			year++;		// And forward the following year
		}
	}

	return temp;
}

Date Date::operator--()	    // prefix(--)
{
	day--;	// Decrement the day

	// If the decrement cause the day lower than 1
	if (day < 1)
	{
		month--;	// Decrease the month by 1

		// If this is leap year and the month after decrement become 2
		if (isLeapYear(year) && month == 2)
		{
			day = 29;
			return *this;
		}

		// If the dereament make the month lower than 0
		if (month < 1) 
		{
			month = 12;	// Set it back to 12
			day = 31;	// Set the day to 31
			year--;		// And Subtract the year
			return *this;
		}

		day = maxDay[month];	// Set the day to the highest day of the month
	}

	return *this;

}


Date Date::operator--(int)	// postfix(--)
{
	Date temp(*this); // Copy constructor

	day--;	// Decrement the day

	// If the decrement cause the day lower than 1
	if (day < 1)
	{
		month--;	// Decrease the month by 1

		// If this is leap year and the month become 2
		if (isLeapYear(year) && month == 2)
		{
			day = 29;
			return temp;
		}

		// If the dereament cause the month lower than 0
		if (month < 1)
		{
			month = 12;	// Set it back to 12
			day = 31;
			year--;		// And Subtract the year
			return temp;
		}

		day = maxDay[month];	// Otherwise, set the day to the highest day of the month
	}

	return temp;
}

// Pre-condition: A date object
// Post-condition: Convert Gregorian calendar to Julian calendar 
int JulianConverter(const Date& s)
{
	int d = s.getDay();
	int m = s.getMonth();
	int y = s.getYear();

	// Formula from sciencedirect.com
	return d + ((153 * m + 2 )/5) + (365 * y) + (y/4) - (y/100) + (y/400) - 32045;
}

// Overload the - operator
// Return the difference between two days, return negative value if date1 is older than date2
int Date::operator-(const Date& right)
{
	return JulianConverter(*this) - JulianConverter(right) ;
}


// Overload the << operator
ostream& operator<<(ostream& out, const Date& obj)
{

	// Display in format 2 such as April 18, 2018
	out << obj.monthNames[obj.getMonth()] << " " << obj.getDay() << ", " << obj.getYear();

	return out;
}


istream& operator>>(istream& in, Date& obj)
{
	int month = 0;
	int day = 0;
	int year = 0;

	year = inputInteger("\n\tEnter the year (1...9999) : ", 1, 9999);

	month = inputInteger("\n\tEnter the month (1...12): ", 1, 12);

	int allowedDay = obj.maxDay[month];

	// If the year is leap and the month is 2, change the maxAllowedDay to 29
	if (isLeapYear(year) && month == 2)
		allowedDay = 29;
	

	day = inputInteger("\n\tEnter the date (1..." + to_string(allowedDay) + "): ", 1, allowedDay);

	obj.day = day;
	obj.month = month;
	obj.year = year;
	
	return in;
}

// Pre-condition: A valid int
// Post-condition: return true if the year is leap
bool isLeapYear(int year)
{
	// Check if the year is leap year
	if (year % 4 == 0)
	{
		// If it's divisible by 100, it should also be divisible by 400 to be a leap year
		if (year % 100 == 0)
		{
			return (year % 400 == 0) ? true : false;
		}
		else
			return true;
	}

	return false;
}

