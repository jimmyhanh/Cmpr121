#include "PersonData.h"

// Defualt Constructor
PersonData::PersonData()
{
	lastName = "unknown";
	firstName = "unknown";
	address = "unknown";
	city = "unknown";
	state = "unknown";
	zip = "unknown";
	phone = "unknown";
}

// Pre-condition: A valid string
// Post-condition: Assign the value to member lastName
void PersonData::setLastName(string s)
{
	lastName = s;
}

// Pre-condition: None
// Post-condition: Return the value of member lastName
string PersonData::getLastName() const
{
	return lastName;
}


// Pre-condition: A valid string
// Post-condition: Assign the value to member firstName
void PersonData::setFirstName(string s)
{
	firstName = s;
}

// Pre-condition: None
// Post-condition: Return the value of member firstName
string PersonData::getFirstName() const
{
	return firstName;
}


// Pre-condition: A valid string
// Post-condition: Assign the value to member address
void PersonData::setAddress(string s)
{
	address = s;
}

// Pre-condition: None
// Post-condition: Return the value of member address
string PersonData::getAddress() const
{
	return address;
}

// Pre-condition: A valid string
// Post-condition: Assign the value to member city
void PersonData::setCity(string s)
{
	city = s;
}


// Pre-condition: None
// Post-condition: Return the value of member city
string PersonData::getCity() const
{
	return city;
}

// Pre-condition: A valid string
// Post-condition: Assign the value to member state
void PersonData::setState(string s)
{
	state = s;
}

// Pre-condition: None
// Post-condition: Return the value of member state
string PersonData::getState() const
{
	return state;
}

// Pre-condition: A valid string
// Post-condition: Assign the value to member zip
void PersonData::setZip(string s)
{
	zip = s;
}

// Pre-condition: None
// Post-condition: Return the value of member zip
string PersonData::getZip() const
{
	return zip;
}

// Pre-condition: A valid string
// Post-condition: Assign the value to member phone
void PersonData::setPhone(string s)
{
	phone = s;
}

// Pre-condition: None
// Post-condition: Return the value of member phone
string PersonData::getPhone() const
{
	return phone;
}


// Overload the operator <<
ostream& operator<< (ostream& out, const PersonData& obj)
{
	out << "\n\tInformation of Person";
	out << "\n\tLast Name : " << obj.getLastName();
	out << "\n\tFirst Name: " << obj.getFirstName();
	out << "\n\tAddress   : " << obj.getAddress();
	out << "\n\tCity      : " << obj.getCity();
	out << "\n\tState     : " << obj.getState();
	out << "\n\tZip       : " << obj.getZip();
	out << "\n\tPhone     : " << obj.getPhone();

	return out;
}
