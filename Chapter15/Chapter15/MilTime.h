#pragma once
#include "Time.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class MilTime :  public Time
{
protected: 
	int milHours;
	int milSeconds;

public:
	MilTime();		// Default Constructor

	MilTime(int newMilHours, int newMilSeconds);	// Constructor #1;

	void setTime(int milHours, int milSeconds);

	string getHour() const;

	string getStandHr() const;

	friend ostream& operator<< (ostream& out, const MilTime& obj);
};

