#include "Ship.h"

// Default Constructor
Ship::Ship() : name("unknown"), year(0)
{}

// Pre-condition: A valid string
// Post-condition: Assign the string to the member name
void Ship::setName(string s)
{
	name = s;
}

// Pre-condition: None
// Post-condition: Return the value of the member name
string Ship::getName() const
{
	return name;
}

// Pre-condition: A valid string
// Post-condition: Assign the string to the member year
void Ship::setYear(int newYear)
{
	year = newYear;
}

// Pre-condition: None
// Post-condition: Return the value of the member name
int Ship::getYear() const
{
	return year;
}

// Pre-condition: None
// Post-condition: Print the information of the ship
void Ship::print()
{
	cout << "\tShip\n";
	cout << "\tName       : " << name << '\n';
	cout << "\tYear built : " << year << '\n';
}
