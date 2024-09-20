#pragma once

class Rational
{
private:
	int numerator;
	int denominator;

public:

	class ZeroDenominator {};	// Exeception class for handing zero denominator

	Rational();					// Default constructor
	Rational(int n, int d);		// Constructor#1

	// Accessor and Mutator
	void setNumerator(int NewNumerator);
	int getNumerator() const;

	void setDenominator(int NewDenominator);
	int getDenominator() const;

	string toString();
	void Normalize();

	// Overloading Operator
	bool operator< (const Rational& right);
	bool operator== (const Rational& right);
};


// Default constructor
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

// Constructor #1
// Pre-condition: A valid int
// Post-condition: Assign the first value to numerator and second value to denominator
Rational::Rational(int n, int d)
{
	if (d == 0)
		throw ZeroDenominator();
	else
	{
		numerator = n;
		denominator = d;
		Normalize();
	}
}

// Pre-condition: A valid int
// Post-condition: Assign the value to numerator
void Rational::setNumerator(int NewNumerator)
{
	numerator = NewNumerator;
}

// Pre-condition: None
// Post-condition: Return the value of member numerator
int Rational::getNumerator() const
{
	return numerator;
}

// Pre-condition: A valid int
// Post-condition: Assign the value to denominator
void Rational::setDenominator(int NewDenominator)
{
	if (NewDenominator == 0)
		throw ZeroDenominator();
	else
		denominator = NewDenominator;
}

// Pre-condition: None
// Post-condition: Return the value of member denominator
int Rational::getDenominator() const
{
	return denominator;
}

// Pre-condition: None
// Post-condition: Return the string expression of the rational
string Rational::toString()
{
	Normalize();
	return to_string(numerator) + "/" + to_string(denominator);
}

// Pre-conditon: None
// Post-condition: Return the GCD between 2 number
int GCD(int x, int y)
{
	// Base Case
	if (x % y == 0)
		return y;
	else
	{
		return GCD(y, x % y);	// Recursive Case
	}
}

// Pre-condition: None
// Post-condition: Reduce the rational and moving negative side to numerator
void Rational::Normalize()
{
	// Reduce the rational to their irreducable form
	int divisor = GCD(numerator, denominator);

	numerator = numerator / divisor;
	denominator = denominator / divisor;

	// Moving side 
	if (denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
}


// Compare two rational number 
bool Rational::operator< (const Rational& right)
{
	int d1 = this->denominator;
	int n1 = this->numerator;

	int d2 = right.denominator;
	int n2 = right.numerator;

	return (n1 * d2 < n2 * d1) ? true : false;
}

// Compare two rational number 
bool Rational::operator== (const Rational& right)
{
	int d1 = this->denominator;
	int n1 = this->numerator;

	int d2 = right.denominator;
	int n2 = right.numerator;

	return (n1 * d2 == n2 * d1) ? true : false;
}

