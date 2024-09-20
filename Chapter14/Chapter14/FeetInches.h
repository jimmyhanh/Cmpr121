#pragma once
#include <math.h>
#include <iostream>
#include "input.h"

using namespace std;

class FeetInches
{
private: 
	int feet;
	int inches;
	void simplify();

public:
	FeetInches();
	FeetInches(int f, int i);
	FeetInches(const FeetInches& obj);	// Copy Constructor

	void setFeet(int f);
	void setInches(int i);

	int getFeet() const;
	int getInches() const;
	
	FeetInches multiply(const FeetInches&);

	// Overloaded operator functions
	FeetInches operator + (const FeetInches&);  // Overloaded +
	FeetInches operator - (const FeetInches&);  // Overloaded -
	FeetInches operator ++ ();					// Prefix ++
	FeetInches operator ++ (int);				// Postfix ++


	bool operator > (const FeetInches&);		// Overloaded >
	bool operator < (const FeetInches&);		// Overloaded <
	bool operator == (const FeetInches&);		// Overloaded ==

	bool operator >= (const FeetInches&);		// Overloaded >=
	bool operator <= (const FeetInches&);		// Overloaded <=
	bool operator != (const FeetInches&);		// Overloaded !=

	friend ostream& operator << (ostream&, const FeetInches&);
	friend istream& operator >> (istream&, FeetInches&);

};

