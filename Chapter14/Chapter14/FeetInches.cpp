#include "FeetInches.h"

// Default Constructor
FeetInches::FeetInches()
{
	feet = 0;
	inches = 0;
}

// Arg Constructor
FeetInches::FeetInches(int f, int i)
{
	feet = f;
	inches = i;
	simplify();
}

// Copy Constructor
FeetInches::FeetInches(const FeetInches& obj)
{
	feet = obj.feet;
	inches = obj.inches;
	simplify();
}

// condition: none
void FeetInches::simplify()
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - ((abs(inches) % 12));
	}
}

// Pre-condition: a valid int;
// Post-condition: assign a value to private member feet
void FeetInches::setFeet(int f)
{
	feet = f;
}

// Pre-condition: a valid int;
// Post-condition: assign a value to private member inches
void FeetInches::setInches(int i)
{
	inches = i;
	simplify();
}


// Return the value of private member feet
int FeetInches::getFeet() const
{
	return feet;
}

// Return the value of private member inches
int FeetInches::getInches() const
{
	return inches;
}

// Pre-condition: FeetInches object
// Post-condition: Return the feetinches object that result from multiplication
FeetInches FeetInches::multiply(const FeetInches& obj)
{
	FeetInches temp;

	// Convert to total inches
	int totalInches1 = 12 * this->getFeet() + this->getInches();
	int totalInches2 = 12 * obj.getFeet() + obj.getInches();

	// Store the result of multiplicatioin to inches member of the temp
	temp.inches = totalInches1 * totalInches2;
	temp.inches /= 12;

	// simplify the temp
	temp.simplify();

	return temp;
}


// Overloaded + operator.               *
FeetInches FeetInches::operator + (const FeetInches& right)
{
	FeetInches temp;

	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}


// Overloaded - operator.               *
FeetInches FeetInches::operator - (const FeetInches& right)
{
	FeetInches temp;

	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();
	return temp;
}


// Overloaded prefix ++ operator.
FeetInches FeetInches::operator ++ ()
{
	++inches;
	simplify();
	return *this;
}


// Overloaded postfix ++ operator.
FeetInches FeetInches::operator ++ (int)
{
	FeetInches temp(feet, inches);

	inches++;
	simplify();
	return temp;
}


// Overloaded > operator. 
bool FeetInches::operator > (const FeetInches& right)
{
	bool status;

	if (feet > right.feet)
		status = true;
	else if (feet == right.feet && inches > right.inches)
		status = true;
	else
		status = false;

	return status;
}


// Overloaded < operator
bool FeetInches::operator < (const FeetInches& right)
{
	bool status;

	if (feet < right.feet)
		status = true;
	else if (feet == right.feet && inches < right.inches)
		status = true;
	else
		status = false;

	return status;
}


// Overloaded == operator
bool FeetInches::operator == (const FeetInches& right)
{
	bool status;

	if (feet == right.feet && inches == right.inches)
		status = true;
	else
		status = false;

	return status;
}

bool FeetInches::operator >= (const FeetInches& right)
{
	bool status;

	if (feet > right.feet)
		status = true;
	else if (feet == right.feet && inches >= right.inches)
		status = true;
	else
		status = false;

	return status;
}


bool FeetInches::operator <= (const FeetInches& right)
{
	bool status;

	if (feet < right.feet)
		status = true;
	else if (feet == right.feet && inches <= right.inches)
		status = true;
	else
		status = false;

	return status;
}

// Overload the != operator
bool FeetInches::operator != (const FeetInches& right)
{
	bool status;

	// If both feet and inches are equal, change status to false 
	if (feet == right.feet && inches == right.inches)
		status = false;
	else
		status = true;

	return status;
}

// Overloaded << operator.
ostream& operator<<(ostream& strm, const FeetInches& obj)
{
	strm << obj.feet << " feet, " << obj.inches << " inches";
	return strm;
}


// Overloaded >> operator.
istream& operator >> (istream& strm, FeetInches& obj)
{
	int Feet = 0;
	int Inches = 0;

	// Prompt the user for the feet.
	cout << "\n";
	Feet = inputInteger("\tFeet  : ", 0,10000);
	Inches = inputInteger("\tInches: ", 0,10000);

	obj.inches = Inches;
	obj.feet = Feet;

	// Normalize the values.
	obj.simplify();

	return strm;
}
