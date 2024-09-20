#pragma once
#include "MyUnit.h"

class MyScheduleDay : public MyUnit
{
private:
	char Type;

public:

	MyScheduleDay();		// Default Constructor
	
	void setType(char newType);		
	char getType() const;

	friend ostream& operator<<(ostream& out, const MyScheduleDay& obj);
};

