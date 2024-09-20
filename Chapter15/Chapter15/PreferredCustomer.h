#pragma once
#include "CustomerData.h"
class PreferredCustomer : public CustomerData
{
private:
	double purchaseAmount;
	double discountLevel;

public:
	PreferredCustomer();

	void setPurchaseAmount(double amount);
	double getPurchaseAmount() const;

	double getDiscountLevel() const;

	friend ostream& operator<< (ostream& out, const PreferredCustomer& obj);

};

