#pragma once
#include "Ship.h"
class CargoShip : public Ship
{
private:
	int maxCapacity;

public:
	CargoShip();		// Defaut Constructor

	void setMaxCapacity(int s);

	int getMaxCapacitys() const;

	virtual void print();
};

