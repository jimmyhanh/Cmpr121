#include "LandTract.h"

// Constructor
// Post-condition: Assign each private membet to -
LandTract::LandTract()
{
	length = FeetInches(0, 0);
	width  = FeetInches(0, 0);
}

// Pre-condition: A FeetInches object
// Post-condition: Assign the value to private member length
void LandTract::setLength(FeetInches newLength)
{
	length = newLength;
}


// Pre-condition: None
// Post-condition: Return the value of private member length
FeetInches LandTract::getLength() const
{
	return length;
}


// Pre-condition: A FeetInches object
// Post-condition: Assign the value to private member width
void LandTract::setWidth(FeetInches newWidth)
{
	width = newWidth;
}


// Pre-condition: None
// Post-condition: Return the value of private member width
FeetInches LandTract::getWidth() const
{
	return width;
}

// Return tractArea in ft^2
double LandTract::tractArea() const
{
	return (length.getFeet() + (length.getInches() / 12.0)) * (width.getFeet() + (width.getInches() / 12.0));
}


// Pre-condition: A valid LandTract object
// Post-condition: Return true if two object's area are equal
bool LandTract::operator == (const LandTract& right)
{
	if (this->tractArea() == right.tractArea())
		return true;
	else
		return false;
}


// Post-Condition: Overload the << operator
ostream& operator<< (ostream& out, const LandTract& obj)
{
	out << "\nTract Length: " << obj.getLength();
	out	<< "\nTract Width : " << obj.getWidth();
	out << "\nTract Area  : " << obj.tractArea() << " square feet";
	return out;
}

// Post-Condition: Overload the >> operator
istream& operator>> (istream& in, LandTract& obj)
{
	FeetInches tempLength;
	FeetInches tempWidth;

	// Enter the value for tempLength and tempWidth
	cout << "\n\tEnter the length: ";
	cin >> tempLength;

	cout << "\n\tEnter the width: ";
	cin >> tempWidth;

	obj.setLength(tempLength);
	obj.setWidth(tempWidth);

	return in;
}




