#include "PreferredCustomer.h"

// Default Constructor
PreferredCustomer::PreferredCustomer(): CustomerData(), purchaseAmount(0), discountLevel(0) 
{};


// Pre-condition: A valid double
// Post-condition: Assign the value to member purchaseAmount
void PreferredCustomer::setPurchaseAmount(double amount)
{
	purchaseAmount = amount;
}

// Pre-condition: None
// Post-condition: Return the value of member purchaseAmount
double PreferredCustomer::getPurchaseAmount() const
{
	return purchaseAmount;
}

// Pre-condition: None
// Post-condition: Return the discountLevel based on the cummulative purchaseAmount
double PreferredCustomer::getDiscountLevel() const
{
	if (purchaseAmount >= 2000)
		return 0.10;
	else if (purchaseAmount >= 1500)
		return 0.7;
	else if (purchaseAmount >= 1000)
		return 0.6;
	else if (purchaseAmount >= 500)
		return 0.5;
	else
		return 0;

}

ostream& operator<< (ostream& out, const PreferredCustomer& obj)
{
	out << "\n\tInformation of Preferred Customer";
	out << "\n\tLast Name : " << obj.getLastName();
	out << "\n\tFirst Name: " << obj.getFirstName();
	out << "\n\tAddress   : " << obj.getAddress();
	out << "\n\tCity      : " << obj.getCity();
	out << "\n\tState     : " << obj.getState();
	out << "\n\tZip       : " << obj.getZip();
	out << "\n\tPhone     : " << obj.getPhone();
	out << "\n\tID Number : " << obj.getCustomerNumber();
	out << ((obj.getMailingList()) ? "\n\tOn Mailing List" : "\n\tNot On Mailing List");
	out << "\n\tPurchase Amount: " << obj.getPurchaseAmount();
	out << "\n\tDiscount Level : " << obj.getDiscountLevel() * 100 << "%";
	
	return out;
}

