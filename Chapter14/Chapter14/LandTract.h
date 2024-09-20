#pragma once
#include "FeetInches.h"
#include <iostream>

using namespace std;

class LandTract
{
private:
	FeetInches length;
	FeetInches width;


public:
	LandTract();

	void setLength(FeetInches length);
	FeetInches getLength() const;

	void setWidth(FeetInches width);
	FeetInches getWidth() const;

	double tractArea() const;

	bool operator == (const LandTract& right);		// Overloaded ==


	friend ostream& operator<< (ostream& out, const LandTract& obj );
	friend istream& operator>> (istream& in, LandTract&obj);


};

