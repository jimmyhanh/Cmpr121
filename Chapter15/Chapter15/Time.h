#pragma once
class Time
{
protected:
	int hour;
	int min;
	int sec;
public:

	Time();	// Default Constructor

	Time(int h, int m, int s);	// Constructor #1

	// Accessor 
	int getHour() const;
	int getMin() const;
	int getSec() const;
};

