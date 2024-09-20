#pragma once
#include "ProductionWorker.h"

class TeamLeader : public ProductionWorker
{
private:
	double bonusAmount;
	int requiredTrainingHours;
	int attendedTrainingHours;

public:
	TeamLeader();

	void setBonusAmount(double amount = 0);
	double getBonusAmount() const;

	void setRequiredTrainingHours(int hours = 0);
	int getRequiredTrainingHours() const;

	void setAttendedTrainingHours(int hours = 0);
	int getAttendedTrainingHours() const;

	friend ostream& operator << (ostream& out, const TeamLeader& obj);
};



