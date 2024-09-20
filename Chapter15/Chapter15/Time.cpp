#include "Time.h"

// Default Constructor
Time::Time() : hour(0), min(0), sec(0) {};

// Constructor #1
Time::Time(int h, int m, int s) : hour(h), min(m), sec(m) {};

// Pre-Condition: None
// Post-Condition: Return the value of protected member hour
int Time::getHour() const
{
	return hour;
}

// Pre-Condition: None
// Post-Condition: Return the value of protected member min
int Time::getMin() const
{
	return min;
}

// Pre-Condition: None
// Post-Condition: Return the value of protected member sec
int Time::getSec() const
{
	return sec;
}