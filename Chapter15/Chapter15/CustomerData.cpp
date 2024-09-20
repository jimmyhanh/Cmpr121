#include "CustomerData.h"

// Default Constructor
CustomerData::CustomerData() : PersonData(), customerNumber(0), mailingList(true) {};

// Pre-condition: A valid int
// Post-condition: Assign the value to member customerNumber
void CustomerData::setCustomerNumer(int number)
{
	customerNumber = number;
}

// Pre-condition: None
// Post-condition: Return the value of member customerNumber
int CustomerData::getCustomerNumber() const
{
	return customerNumber;
}


// Pre-condition: A valid bool
// Post-condition: Assign the value T or F to member malingList
void CustomerData::setMailingList(bool mailing)
{
	mailingList = mailing;
}


// Pre-condition: None
// Post-condition: Return the value of member mailList
bool CustomerData::getMailingList() const
{
	return mailingList;
}

// Operator Overloading <<
ostream& operator<< (ostream& out, const CustomerData& obj)
{
	out << "\n\tInformation of Customer";
	out << "\n\tLast Name : " << obj.getLastName();
	out << "\n\tFirst Name: " << obj.getFirstName();
	out << "\n\tAddress   : " << obj.getAddress();
	out << "\n\tCity      : " << obj.getCity();
	out << "\n\tState     : " << obj.getState();
	out << "\n\tZip       : " << obj.getZip();
	out << "\n\tPhone     : " << obj.getPhone();
	out << "\n\tID Number : " << obj.getCustomerNumber();
	out << ((obj.getMailingList()) ? "\n\tOn Mailing List" : "\n\tNot On Mailing List");

	return out;
}
