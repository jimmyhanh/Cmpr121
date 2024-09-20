#pragma once
class GradedActivity
{
protected:
	double score;

public:
	GradedActivity();			// Default Constructor
	GradedActivity(int s);	// Constructor #1

	void setScore(double s);
	double getScore() const;

	char getLetterGrade() const;
};

