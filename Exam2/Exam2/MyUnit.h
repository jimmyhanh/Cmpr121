#pragma once
#include <iostream>
#include <string>

using namespace std;

class MyUnit
{
private:
	unsigned short value;
	char description[100] = {0};

public:
	
	MyUnit();	// Default Constructor

	void setValue(int newValue);
	int getValue() const;

	void setDescription(string newDescription);
	string getDescription() const;

	friend ostream& operator<< (ostream& out, const MyUnit& obj);
};

