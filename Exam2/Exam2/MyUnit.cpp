#include "MyUnit.h"

// Default Constructor
MyUnit::MyUnit()	
{
	value = 0;
    strncpy_s(description, "unknown", sizeof(description) - 1);
}

// Pre-condition: An int value
// Post-condition: Assign a value to private member value
void MyUnit::setValue(int newValue)
{
	value = static_cast<unsigned short>(newValue);
}

// Pre-condition: None
// Post-condition: Return the value of private member value
int MyUnit::getValue() const
{
	return static_cast<int>(value);
}


// Pre-condition: A valid string
// Post-condition: Assign a string to private member description
void MyUnit::setDescription(string newDescription)
{
	strncpy_s(description, newDescription.c_str(), sizeof(description) - 1);
}


// Pre-condition: None
// Post-condition: Return the value of private member description
string MyUnit::getDescription() const
{
	return string(description);
}

// Overload the operator<<
ostream& operator<< (ostream& out, const MyUnit& obj)
{
	out << "\n\tValue      : " << obj.getValue();
	out << "\n\tDescription: " << obj.getDescription();

	return out;
}
