#include "Employee.h"


// Default Argument
Employee::Employee() : name("unknown"), employeeNumber(0), hireDate("unknown")
{}


// Pre-condition: A valid string
// Post-conditioin: Assign the string value to private member name
void Employee::setName(string newName)
{
    name = newName;
}

// Pre-condition: None
// Post-conditioin: Return the  value of private member name
string Employee::getName() const
{
    return name;
}

// Pre-condition: A valid int
// Post-conditioin: Assign the int value to private member employeeNumber
void Employee::setEmployeeNumber(int newNumber)
{
    employeeNumber = newNumber;
}

// Pre-condition: None
// Post-conditioin: Return the  value of private member employeeNumber
int Employee::getEmployeeNumber() const
{
    return employeeNumber;
}

// Pre-condition: A valid string
// Post-conditioin: Assign the string value to private member hireDate
void Employee::setHireDate(string newDate)
{
    hireDate = newDate;
}

// Pre-condition: None
// Post-conditioin: Return the  value of private member hireDate
string Employee::getHireDate() const
{
    return hireDate;
}

// Overload the operator <<
ostream& operator<< (ostream& out, const Employee& obj)
{
    out << "\n\tName           : " << obj.getName();
    out << "\n\tNumber         : " << obj.getEmployeeNumber();
    out << "\n\tHire date      : " << obj.getHireDate();
    return out;
}
