#include "CargoShip.h"

CargoShip::CargoShip() : Ship(), maxCapacity(0) {};		// Defaut Constructor

// Pre-conditoin: A valid int
// Post-condition: Assign the value to member maxCapacity
void CargoShip::setMaxCapacity(int s)
{
	maxCapacity = s;
}

// Pre-condition: None
// Post-condition: Return the value of member maxCapacity
int CargoShip::getMaxCapacitys() const
{
	return maxCapacity;
}

// Pre-condition: None
// Post-condition: Print the information of cargo ship
void CargoShip::print()
{
	cout << "\tCargo ship\n";
	cout << "\tname                         : " << name << '\n';
	cout << "\tYear built                   : " << year << '\n';
	cout << "\tMaximum number of passengers : " << maxCapacity << '\n';
}
