#pragma once
#include <string>
#include <iostream>
using namespace std;
class Employee
{
private:
	string name;
	int employeeNumber;
	string hireDate;

public:
	Employee();			// Default Argument

	void setName(string newName);
	string getName() const;

	void setEmployeeNumber(int newNumber);
	int getEmployeeNumber() const;

	void setHireDate(string newDate);
	string getHireDate() const;

	friend ostream& operator<< (ostream& out, const Employee& obj);
};


