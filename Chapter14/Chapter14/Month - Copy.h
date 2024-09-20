#pragma once
#include <string>
#include <iostream>



using namespace std;
class Month
{
	const string months[13] = { "unknown", "January", "February", "March" , "April", "May", "June", "July", "August", "September", "October" ,"November", "December" };

private:
	string name;
	int monthNumber;
public:
	//construtors
	Month();					//default
	Month(string newName);		//arg
	Month(int newMonthNumber);	//arg
	Month(const Month& obj);	//copy obj

	//getters (accessors)
	string getName() const;
	int getMonthNumber() const;

	//setter (mutators)
	void setName(string newName);
	void setMonthNumber(int newNumber);

	//overload the << operator -- VERY IMPORTANT for you to debug

	Month operator=(const Month& obj);
	Month operator++();	    // prefix(++)
	Month operator++(int);	// postfix(++)

	friend ostream& operator<<(ostream& out, const Month& obj);
	friend istream& operator>>(istream& in, Month& obj);

};



