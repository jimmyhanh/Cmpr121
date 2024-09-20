#include "Month.h"

// Default Constructor
Month::Month()
{
	monthNumber = 0;
	name = months[monthNumber];
}

// Arg Constructor #1
Month::Month(string newName)
{
	setName(newName);
}


// Arg Constructor #1
Month::Month(int newMonthNumber)
{
	setMonthNumber(newMonthNumber);
}


// Copy Constructor
Month::Month(const Month& obj)
{
	monthNumber = obj.getMonthNumber();
	name = obj.getName();
}


// Condition: None
// Return the value of the private member name
string Month::getName() const
{
	return name;
}


// Condition: None
// Return the value of the private member month number
int Month::getMonthNumber() const
{
	return monthNumber;
}


// Pre-condition: a valid string
// Post-condition: Set the month name to the private member name
void Month::setName(string newName)
{

	// Loop to search if newName is a valid monthname
	for (int m = 0; m <= 12; m++)
	{
		if (newName == months[m])	// If found
		{
			monthNumber = m;		// Assign the index to the month number
			name = months[m];		// And set the name to the function
			return;					// Then, exit the function 
		}
	}

	// If not found
	monthNumber = 0;
	name = months[monthNumber];
	
}


// Pre-condition: a valid int
// Post-condition: Set the month number to the private member number
void Month::setMonthNumber(int newNumber)
{
	// Validate that the number is in the valid range 0 - 11
	if (newNumber >= 1 || newNumber <= 12)
		monthNumber = newNumber;		// Assign the value to the monthNumber
	else
		monthNumber = 0;				// Otherwise, set to 0

	name = months[monthNumber];			// Assign the month name corressponding with the month number
}


// Overload the prefix-increment to the month object
Month Month::operator++()
{

	monthNumber++;

	// If the value is not in the valid range, set the month number to 1
	if (monthNumber > 12)
		setMonthNumber(1);
	else
		setMonthNumber(monthNumber);

	return *this;
}

// Overload the postfix-increment to the month object
Month Month::operator++(int)
{
	Month temp(*this); // Copy constructor

	monthNumber++;	// Increment the month number

	// If the value is not in the valid range, set the month number to 1
	if (monthNumber > 12)
		setMonthNumber(1);
	else
		setMonthNumber(monthNumber);	

	return temp;
}

// Overload the operator << to the month object
ostream& operator<<(ostream& out, const Month& obj)
{
	out << "number: " << obj.getMonthNumber() << " - " << obj.getName();

	return out;
}

// Overload the operator >> to the month object
istream& operator>>(istream& in, Month& obj)
{	
	int temp = 0;
	cout << "\n\tMonth number: ";

	in >> temp;
	while (in.fail())
	{
		cout << "\n\tTry again and enter a numeric value";
		cout << "\n\tMonth number: ";
		in.clear();
		in.ignore(999, '\n');
		in >> temp;
	}

	if (temp >= 0 && temp <= 12)
		obj.monthNumber = temp;
	else
		obj.monthNumber = 0;

	obj.setMonthNumber(obj.getMonthNumber());

	return in;
}

// Overload the = operator
Month Month::operator=(const Month& obj)
{
	monthNumber = obj.getMonthNumber();
	name = obj.getName();

	return *this;
}




