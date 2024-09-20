#include "MyScheduleDay.h"


// Default Constructor
MyScheduleDay::MyScheduleDay()		
{
	Type = 'U';
}


// Pre-condition: A valid char
// Post-condition: Assign char to private member Type
void MyScheduleDay::setType(char newType)
{
	Type = newType;
}

// Pre-condition: None
// Post-condition: return value of private member Type
char MyScheduleDay::getType() const
{
	return Type;
}

// Overloading the << Operator
ostream& operator<<(ostream& out, const MyScheduleDay& obj)
{
	out << "\n\tValue	   : " << obj.getValue();
	out << "\n\tType       : " << obj.getType();
	out << "\n\tDescription: " << obj.getDescription();

	return out;
}
