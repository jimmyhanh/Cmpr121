#include "TeamLeader.h"

// Default Constructor
TeamLeader::TeamLeader() : ProductionWorker(), bonusAmount(0.0), requiredTrainingHours(0), attendedTrainingHours(0)
{}

// Pre-condition: A valid double
// Post-condition: Assign the value to member bonus amount
void TeamLeader::setBonusAmount(double a)
{
	bonusAmount = a;
}

// Pre-condition: None
// Post-condition: Return the value of member bonus amount
double TeamLeader::getBonusAmount() const
{
	return bonusAmount;
}

// Pre-condition: A valid int
// Post-condition: Assign the value to member requiredTrainingHours
void TeamLeader::setRequiredTrainingHours(int hours)
{
	requiredTrainingHours = hours;
}

// Pre-condition: None
// Post-condition: Return the value of member requiredTrainingHours
int TeamLeader::getRequiredTrainingHours() const
{
	return requiredTrainingHours;
}


// Pre-condition: A valid int
// Post-condition: Assign the value to member attendedTrainingHours
void TeamLeader::setAttendedTrainingHours(int hours)
{
	attendedTrainingHours = hours;
}

// Pre-condition: A valid int
// Post-condition: Assign the value to member attendedTrainingHours
int TeamLeader::getAttendedTrainingHours() const
{
	return attendedTrainingHours;
}

ostream& operator<< (ostream& out, const TeamLeader& obj)
{
	out << static_cast<ProductionWorker>(obj);
	out << "\n\tMonthly bonus amount   : $" << obj.getBonusAmount();
	out << "\n\tRequired training hours: " << obj.getRequiredTrainingHours();
	out << "\n\tAttended training hours: " << obj.getAttendedTrainingHours();
	return out;
}
