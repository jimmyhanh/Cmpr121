#pragma once
#include "GradedActivity.h"
#include "iostream"

using namespace std;

class Essay : public GradedActivity
{
private:
	double grammarScore;
	double spellingScore;
	double lengthScore;
	double contentScore;

public:
	Essay();	// Default Constructor
	
	void setGrammarScore(double s);
	double getGrammarScore() const;

	void setSpellingScore(double s);
	double getSpellingScore() const;

	void setLengthScore(double s);
	double getLengthScore() const;

	void setContentScore(double s);
	double getContentScore() const;

	void setScore();

	friend ostream& operator<<(ostream& out, const Essay& obj);
};

