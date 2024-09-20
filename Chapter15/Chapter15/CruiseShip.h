#pragma once

#include <iostream>
#include <string>
#include "Ship.h"
using namespace std;

class CruiseShip : public Ship
{
private:
	int maxPassengers;

public:
	CruiseShip();

	void setMaxPassengers(int s);

	int getMaxPassengers() const;

	virtual void print();
};

