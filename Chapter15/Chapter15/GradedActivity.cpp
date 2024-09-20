#include "GradedActivity.h"

// Default Constructor
GradedActivity::GradedActivity() : score(0) {};

// Constructor #1
GradedActivity::GradedActivity(int s) : score(s) {};	

// Pre-condition: A valid double
// Post-condition: Assign a value to member score
void GradedActivity::setScore(double s)
{
	score = s;
}

// Pre-condition: None
// Post-condition: Return a value of member score
double GradedActivity::getScore() const
{
	return score;
}

// Pre-condition: None
// Post-condition: Return a letter based on the score (A,B,C,D,F)
char GradedActivity::getLetterGrade() const
{
	if (score > 89)
		return 'A';
	else if (score > 79)
		return 'B';
	else if (score > 69)
		return 'C';
	else if (score > 59)
		return 'D';
	else
		return 'F';
}
