#pragma once

#include "Employee.h"

class ProductionWorker : public Employee
{
private:
	int shift;
	double hourlyPayRate;

public:
	ProductionWorker();	// Default Constructor

	void setShift(int newShift = 1);
	int getShift() const;

	void setHourlyPayRate(double newHourlyPayRate = 0.0);
	double getHourlyPayRate() const;

	friend ostream& operator << (ostream& out, const ProductionWorker& obj);
};



