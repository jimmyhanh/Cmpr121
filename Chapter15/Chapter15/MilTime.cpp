#include "MilTime.h"

// Default Constructor
MilTime::MilTime() : Time(), milHours(0), milSeconds(0)
{}	

// Constructor #1
MilTime::MilTime(int newMilHours, int newMilSeconds)	
{
	setTime(newMilHours, newMilSeconds);
}

// Pre-condition: A valid int 
// Post-condition: Converted to standard store
void MilTime::setTime(int milHours, int milSeconds)
{
	// The value are stored in milHours and milSeconds member variable
	this->milHours = milHours;
	this->milSeconds = milSeconds;

	// The value are then converted to hour, min, sec
	(milHours / 100 > 12) ? hour = (milHours / 100) - 12 : hour = milHours / 100;

	min = milHours % 100;
	sec = milSeconds;
}

// Pre-condition: None
// Post-condition: Return the hour in military format (0000)
string MilTime::getHour() const
{
	return to_string(milHours);
}

// Pre-condition: None
// Post-condition: Return the hour in standard format (1:30 am)
string MilTime::getStandHr() const
{
	string shiftIndicator = (milHours/100 > 12) ? "PM" : "AM";

	return to_string(hour) + ":" + to_string(min)  + ":" + to_string(sec) + " " + shiftIndicator;
}

// Overloading the operator
ostream& operator<< (ostream& out, const MilTime& obj)
{
	out << "\n\tMilitary Format: " << setfill('0') << setw(4) << obj.getHour();
	out << "\n\tStandard Format: " << obj.getStandHr();

	return out;
}
