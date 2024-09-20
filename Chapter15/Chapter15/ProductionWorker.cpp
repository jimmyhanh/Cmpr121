#include "ProductionWorker.h"

// Default Constructor
ProductionWorker::ProductionWorker() : Employee(), shift(1), hourlyPayRate(0.0)
{}

// Pre-condition: A valid int (1, 2)
// Post-conditioin: Assign the int value to private member shift (1 - Dayshift) (2 - Nightshift)
void ProductionWorker::setShift(int newShift)
{
	shift = newShift;
}

// Pre-condition: None
// Post-condition: Return the value of private member shift
int ProductionWorker::getShift() const
{
	return shift;
}

// Pre-condition: A valid double 
// Post-conditioin: Assign the double value to private member hourlyPayRate 
void ProductionWorker::setHourlyPayRate(double newHourlyPayRate)
{
	hourlyPayRate = newHourlyPayRate;
}

// Pre-condition: None
// Post-condition: Return the value of private member hourlyPayRate
double ProductionWorker::getHourlyPayRate() const
{
	return hourlyPayRate;
}


// Overload the Production Worker object
ostream& operator<< (ostream& out, const ProductionWorker& obj)
{
	out << static_cast<Employee>(obj);
	out << "\n\tShift          : " << (obj.getShift() == 1 ? "day" : "night");
	out << "\n\tHourly pay rate: $" << obj.getHourlyPayRate();
	return out;
}

