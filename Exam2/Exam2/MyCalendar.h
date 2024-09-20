#pragma once
#include "MyScheduleDay.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


class MyCalendar
{
	const string monthNames[13] = { "unknown", "January", "February", "March" , "April", "May", "June", "July", "August", "September", "October" ,"November", "December" };
	const int maxDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

private:
	unsigned short currentYear;
	unsigned short currentMonth;
	unsigned short currentDay;
	MyScheduleDay scheduleDay[12][31];

public:

	MyCalendar();						// Default Constructor

	MyCalendar(const MyCalendar& obj);	// Copy Constructor
	
	// Accessor and Mutator

	void setCurrentYear(int newCurrentYear);
	int getCurrentYear() const;

	void setCurrentMonth(int newCurrentMonth);
	int getCurrentMonth() const;

	void setCurrentDay(int newCurrentDay);
	int getCurrentDay() const;

	void setScheduleDay(const MyScheduleDay& ScheduleDay);
	MyScheduleDay getScheduleDay() const;

	// Other public member function

	int maxDayOfTheMonth() const;

	string getMonthName() const;

	string getYearName() const;

	string getOrdinalDay() const;

	string getAwarenessMonth() const;

	string dayOfTheWeek() const;

	string dateFormat1() const;			

	string dateFormat2() const;

	void displayDateFormat() const;

	void displayYearSchedule() const;

	void displayMonthSchedule(int month) const;

	void displayDaySchedule(int month, int day) const;

	bool isLeap() const;				

	MyCalendar jumpforward(int jump);		

	MyCalendar jumpbackward(int jump);

	// Operator overloading
	MyCalendar operator++();		// Prefix (++)
	MyCalendar operator++(int);		// Postfix(++)

	MyCalendar operator--();		// Prefix (--)
	MyCalendar operator--(int);		// Postfix(--)

	friend ostream& operator<<(ostream& out, const MyCalendar& obj);	// Operator <<
};

