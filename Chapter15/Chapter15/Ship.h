#pragma once

#include <iostream>
#include <string>
using namespace std;

class Ship
{
protected:
	string name;
	int year;

public:
	Ship();

	void setName(string s);

	string getName() const;

	void setYear(int s);

	int getYear() const;

	virtual void print();

};


