#pragma once
#include <iostream>
#include <string>

using namespace std;

class PersonData
{
protected:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	string zip; 
	string phone;

public:
	PersonData();

	void setLastName(string s);
	string getLastName() const;

	void setFirstName(string s);
	string getFirstName() const;

	void setAddress(string s);
	string getAddress() const;

	void setCity(string s);
	string getCity() const;

	void setState(string s);
	string getState() const;

	void setZip(string s);
	string getZip() const;

	void setPhone(string s);
	string getPhone() const;

	friend ostream& operator<< (ostream& out, const PersonData& obj);
};

