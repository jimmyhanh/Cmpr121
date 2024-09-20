#include "CruiseShip.h"

// Default Constructor
CruiseShip::CruiseShip() : Ship(), maxPassengers(0)
{}

// Pre-conditoin: A valid int
// Post-condition: Assign the value to member maxPassengers
void CruiseShip::setMaxPassengers(int s)
{
	maxPassengers = s;
}

// Pre-condition: None
// Post-condition: Return the value of member maxOassengers
int CruiseShip::getMaxPassengers() const
{
	return maxPassengers;
}

// Pre-condition: None
// Post-condition: Print the information of cruise ship
void CruiseShip::print()
{
	cout << "\tCruise ship\n";
	cout << "\tname                         : " << name << '\n';
	cout << "\tYear built                   : " << year << '\n';
	cout << "\tMaximum number of passengers : " << maxPassengers << '\n';
}