#include "Essay.h"

// Default Constructor
Essay::Essay() : GradedActivity(), grammarScore(0), spellingScore(0), lengthScore(0), contentScore(0)
{};	

// Pre-condition: A valid double
// Post-condition: Assign the value to member grammarScore
void Essay::setGrammarScore(double s)
{
	grammarScore = s;
}

// Pre-condition: None
// Post-condition: Return the value of member grammarScore
double Essay::getGrammarScore() const
{
	return grammarScore;
}


// Pre-condition: A valid double
// Post-condition: Assign the value to member spellingScore
void Essay::setSpellingScore(double s)
{
	spellingScore = s;
}


// Pre-condition: None
// Post-condition: Return the value of member spellingScore
double Essay::getSpellingScore() const
{
	return spellingScore;
}


// Pre-condition: A valid double
// Post-condition: Assign the value to member lengthScore
void Essay::setLengthScore(double s)
{
	lengthScore = s;
}


// Pre-condition: None
// Post-condition: Return the value of member lengthScore
double Essay::getLengthScore() const
{
	return lengthScore;
}


// Pre-condition: A valid double
// Post-condition: Assign the value to member contentScore
void Essay::setContentScore(double s)
{
	contentScore = s;
}


// Pre-condition: None
// Post-condition: Return the value of member contentScore
double Essay::getContentScore() const
{
	return contentScore;
}

// Pre-condition: None
// Post-condition: Assign the value to the score
void Essay::setScore()
{
	score = grammarScore + spellingScore + contentScore + lengthScore;
}


ostream& operator<<(ostream& out, const Essay& obj)
{
	out << "\n\tGrammar score : " << obj.getGrammarScore();
	out << "\n\tSpelling score: " << obj.getSpellingScore();
	out << "\n\tLength score  : " << obj.getLengthScore();
	out << "\n\tContent score : " << obj.getContentScore();

	out << "\n\tTotal score   : " << obj.getScore();
	out << "\n\tLetter Grade  : " << obj.getLetterGrade();

	return out;
}

