#pragma once
#include "PersonData.h"
class CustomerData : public PersonData
{
protected:
	int customerNumber;
	bool mailingList;

public:
	CustomerData();

	void setCustomerNumer(int number);
	int getCustomerNumber() const;

	void setMailingList(bool mailing);
	bool getMailingList() const;

	friend ostream& operator<< (ostream& out, const CustomerData& obj);
};

