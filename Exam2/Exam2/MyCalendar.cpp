#include "MyCalendar.h"

// Default Constructor
MyCalendar::MyCalendar()
{
	currentYear = 0;
	currentDay = 0;
	currentMonth = 0;

	// Assign all type to U and all description to Unschedule
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 31; j++)
		{
			scheduleDay[i][j].setType('U');	
			scheduleDay[i][j].setDescription("unschedule");
		}
}

// Copy Constructor
MyCalendar::MyCalendar(const MyCalendar& obj)	
{
	currentDay = obj.getCurrentDay();
	currentMonth = obj.getCurrentMonth();
	currentYear = obj.getCurrentYear();

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 31; j++)
		{
			scheduleDay[i][j].setDescription(obj.scheduleDay[i][j].getDescription());
			scheduleDay[i][j].setType(obj.scheduleDay[i][j].getType());
		}
}

// Pre-condition: A valid int
// Post-condition: Assign a value to private member currentYear
void MyCalendar::setCurrentYear(int newCurrentYear)
{
	currentYear = newCurrentYear;
}

// Pre-condition: None
// Post-condition: Return a value of private member currentYear
int MyCalendar::getCurrentYear() const
{
	return currentYear;
}

// Pre-condition: A valid int
// Post-condition: Assign a value to private member currentMonth
void MyCalendar::setCurrentMonth(int newCurrentMonth)
{
	currentMonth = newCurrentMonth;
}

// Pre-condition: None
// Post-condition: Return a value of private member currentMonth
int MyCalendar::getCurrentMonth() const
{
	return currentMonth;
}



// Pre-condition: A valid int
// Post-condition: Assign a value to private member currentDay
void MyCalendar::setCurrentDay(int newCurrentDay)
{
	currentDay = newCurrentDay;
}



// Pre-condition: None
// Post-condition: Return a value of private member currentDay
int MyCalendar::getCurrentDay() const
{
	return currentDay;
}

// Pre-condition: A valid MyScheduleDay
// Post-condition: Assign a value to corresponding index in scheduleDay 2D array
void MyCalendar::setScheduleDay(const MyScheduleDay& ScheduleDay)
{
	scheduleDay[currentMonth - 1][currentDay - 1].setDescription(ScheduleDay.getDescription());
	scheduleDay[currentMonth - 1][currentDay - 1].setType(ScheduleDay.getType());
}

// Pre-condition: None
// Post-condition: Return a value of 2D array scheduleDay
MyScheduleDay MyCalendar::getScheduleDay() const
{	
	return scheduleDay[currentMonth - 1][currentDay - 1];
}


// Pre-condition: None
// Post-condition: Return the available maximum day of the month
int MyCalendar::maxDayOfTheMonth() const
{
	int answer = maxDay[this->getCurrentMonth()];

	// Change the max day to 29 if the year is leap and the month is 2
	if (this->isLeap() && this->getCurrentMonth() == 2)
		answer = 29;

	return answer;
}

// Pre-condition: None
// Post-condition: Return the name of the month (Januaray, February,...)
string MyCalendar::getMonthName() const
{
	return monthNames[getCurrentMonth()];
}


// Pre-condition: None
// Post-condition: Return the words spelling of the year from 1 - 9999
string MyCalendar::getYearName() const
{

	string first_twenty[20] = { 
						"", "One", "Two", "Three", "Four", 
						"Five", "Six", "Seven", "Eight", "Nine", "Ten", 
						"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", 
						"Sixteen", "Seventeen", "Eighteen", "Nineteen" };

	string tens[10] = { "", "", "Twenty", "Thirty", "Forty",
						"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

	if (currentYear < 20)		// If the number is less than 20
		return first_twenty[currentYear];

	string answer = "";

	// Example number: ABCD
	// Get the thousand place digit A
	int digit1 = currentYear / 1000;	  

	// If digit 1 is [1,9], append the first_twenty and thousand
	if (digit1 > 0)
		answer += first_twenty[digit1] + " Thousand ";

	// Get the current number to hundred places BCD
	int currentNumber = currentYear % 1000;		

	// If BCD > 99, appends the first_twenty + hundred
	if (currentNumber > 99)
		answer += (first_twenty[currentNumber / 100]	+ " Hundred ");

	// Get the current hundred to tens places CD
	currentNumber = currentNumber % 100;

	// If the value in tens belongs to [0,19], using the first_twenty
	if (currentNumber >= 0 && currentNumber < 20)
		answer += first_twenty[currentNumber];
	else  	// If the value in tens belong to [20,99]
	{
		if (currentNumber % 10 != 0)  // but not in multiples of 10s, appends tens + first_twenty 
			answer += tens[currentNumber / 10] + " " + first_twenty[currentNumber % 10];
		else  // otherwise, only appends tens
			answer += tens[currentNumber / 10];
	}
	return answer;
}

// Pre-condition: None
// Post-condition: Return the ordinal form of the day
string MyCalendar::getOrdinalDay() const
{
	string answer = "";

	// If the last dight is 1 but the number is not 11, append st
	if (currentDay % 10 == 1 && currentDay != 11)
		answer = to_string(currentDay) + "st";
	else if (currentDay % 10 == 2 && currentDay != 12)
		answer = to_string(currentDay) + "nd";
	else if (currentDay % 10 == 3 && currentDay != 13)
		answer = to_string(currentDay) + "rd";
	else
		answer = to_string(currentDay) + "th";

	return answer;
}

// Pre-condition: None
// Post-condition: Return the day of the week based on the given day, month, year
string MyCalendar::dayOfTheWeek() const
{
	int day = currentDay;
	int month = currentMonth;
	int year = currentYear;

	// Geeks for Geeks Zeller’s Congruence
	string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	if (month < 3) 
	{
		month += 12;
		year -= 1;
	}

	int c = year / 100;

	year = year % 100;

	int h = (c / 4 - 2 * c + year + year / 4 + 13 * (month + 1) / 5 + day - 1) % 7;

	return days[(h + 7) % 7];
}

// Pre-condition: None:
// Post-condition: Return the month awareness
string MyCalendar::getAwarenessMonth() const
{
	string awareMonth[13] = { "unknown", "Thyroid Month", "Heart Failure Month",
							"Multiple Sclerosis Month", "Oral Cancer Month", "Mental Health Month",
							"Migrane and Headache Month", "Juvenile Arthrisis Month", "Immunization Month",
							"Ovarian Cancer Month", "Breast Cancer Month", "Lung Cancer Month",
							"HIV Aids Month" };

	return awareMonth[currentMonth];
}



// Pre-condition: None
// Post-condition: Return true if the years is leap, otherwise return false
bool MyCalendar::isLeap() const
{

	// If the year divisible by 4
	if (currentYear % 4 == 0)
	{
		// And if it's divisible by 100, it should also be divisible by 400 to be a leap year
		if (currentYear % 100 == 0)
		{
			return (currentYear % 400 == 0) ? true : false;
		}
		else
			return true;
	}

	return false;
}


// Pre-conditin: None
// Post-condition: Return date in format Friday, October 27th, 2023 (Example)
string MyCalendar::dateFormat1() const
{
	return dayOfTheWeek() + ", " + getMonthName() + " " + getOrdinalDay() + ", " + to_string(currentYear);
}


// Pre-conditin: None
// Post-condition: Return date in format MM/DD/YYY
string MyCalendar::dateFormat2() const
{
	return to_string(currentMonth) + "/" + to_string(currentDay) + "/" + to_string(currentYear);
}


// Pre-conditin: None
// Post-condition: Display date in both format
void MyCalendar::displayDateFormat() const
{
	cout << "\n\t" << dateFormat1();
	cout << "\n\t" << dateFormat2();
}

// Overload the Prefix Incrememnt 
MyCalendar MyCalendar::operator++()		
{
	currentDay++;

	int maxAllowedDay = maxDayOfTheMonth();

	// If the day before increment is 12/31/9999
	if (currentDay == 32 && currentMonth == 12 && currentYear == 9999)
	{
		currentDay = 1;
		currentMonth = 1;
		currentYear = 1;
		return *this;
	}

	// Otherwise, if the increment make the day exceed the max day each month
	if (currentDay > maxAllowedDay)
	{
		currentDay = 1;	// Change the day to 1
		currentMonth++;	// Change the month to next month

		if (currentMonth > 12)	// If the increment make the month > 12
		{
			currentMonth = 1;	// Change the month to 1
			currentYear++;		// And forward the following year
		}
	}

	return *this;
}

// Overload the Postfix Incrememnt 
MyCalendar MyCalendar::operator++(int)
{

	MyCalendar temp(*this); // Copy constructor

	currentDay++;

	int maxAllowedDay = maxDayOfTheMonth();

	// If the day before increment is 12/31/9999
	if (currentDay == 32 && currentMonth == 12 && currentYear == 9999)
	{
		currentDay = 1;
		currentMonth = 1;
		currentYear = 1;
		return temp;
	}

	// If the increment cause the day exceed the max day of the month
	if (currentDay > maxAllowedDay)
	{
		currentDay = 1;	// Change the day to 1
		currentMonth++;	// And change the month to next month

		if (currentMonth > 12)	// If the increment cause the day > 12
		{
			currentMonth = 1;	// Change the month to 1
			currentYear++;		// And forward the following year
		}
	}

	return temp;
}

// Pre-Condition: A valid int
// Post-Condition: Using operator++ up to the jump amount
MyCalendar MyCalendar::jumpforward(int jump)
{
	for (int i = 0; i < jump; i++)
		(*this)++;

	return *this;
}

// Overload the prefix decrement
MyCalendar MyCalendar::operator--()
{
	currentDay--;	// Decrement the day

	// If the date before decrememnt is 1/1/1
	if (currentDay == 0 && currentMonth == 1 && currentYear == 1)
	{
		currentDay = 31;
		currentMonth = 12;
		currentYear = 9999;
		return *this;
	}

	// If the decrement cause the day lower than 1
	if (currentDay < 1)
	{
		currentMonth--;	// Decrease the month by 1

		// If this is leap year and the month after decrement become 2
		if (isLeap() && currentMonth == 2)
		{
			currentDay = 29;
			return *this;
		}

		// If the dereament make the month lower than 0
		if (currentMonth < 1)
		{
			currentMonth = 12;	// Set it back to 12
			currentDay = 31;	// Set the day to 31
			currentYear--;		// And Subtract the year
			return *this;
		}

		currentDay = maxDay[currentMonth];	// Set the day to the highest day of the month
	}

	return *this;
}


// Overload the postfix decremement
MyCalendar MyCalendar::operator--(int)		
{
	MyCalendar temp(*this); // Copy constructor

	currentDay--;	// Decrement the day

	// If the date before decrememnt is 1/1/1
	if (currentDay == 0 && currentMonth == 1 && currentYear == 1)
	{
		currentDay = 31;
		currentMonth = 12;
		currentYear = 9999;
		return temp;
	}

	// If the decrement cause the day lower than 1
	if (currentDay < 1)
	{
		currentMonth--;	// Decrease the month by 1

		// If this is leap year and the month after decrement become 2
		if (isLeap() && currentMonth == 2)
		{
			currentDay = 29;
			return temp;
		}

		// If the dereament make the month lower than 0
		if (currentMonth < 1)
		{
			currentMonth = 12;	// Set it back to 12
			currentDay = 31;	// Set the day to 31
			currentYear--;		// And Subtract the year
			return temp;
		}

		currentDay = maxDay[currentMonth];	// Set the day to the highest day of the month
	}

	return temp;
}

// Pre-Condition: A valid int
// Post-Condition: Using operator-- to the jump amount
MyCalendar MyCalendar::jumpbackward(int jump)
{
	for (int i = 0; i < jump; i++)
		(*this)--;

	return *this;
}

// Overload the << operator
ostream& operator<<(ostream& out, const MyCalendar& obj)
{
	out << "\n\tMonth      : " << obj.getCurrentMonth();
	out << "\n\tDay        : " << obj.getCurrentDay();
	out << obj.getScheduleDay();

	return out;
}

// Function return the ordinal representative based on the given integer
string OrdinalNumber(int i)
{
	string answer = "";

	if (i % 10 == 1 && i != 11)
		answer = to_string(i) + "st";
	else if (i % 10 == 2 && i != 12)
		answer = to_string(i) + "nd";
	else if (i % 10 == 3 && i != 13)
		answer = to_string(i) + "rd";
	else
		answer = to_string(i) + "th";

	return answer;
}

// Pre-condition: None
// Post-Condtion: Display the schedule of the whole year
void MyCalendar::displayYearSchedule() const
{
	bool ScheduleInThisYear = false;	// Keep track if the year has schedule date or not

	cout << "\n";

	for (int i = 0; i < 12; i++)
	{
		bool ScheduleInThisMonth = false;

		cout << "\t" << setw(9) << left << monthNames[i + 1] << ": ";

		for (int j = 0; j < 31; j++)
		{

			if (scheduleDay[i][j].getType() == 'H')	//Green Background
			{
				cout << "\033[42m\n\t\t" << OrdinalNumber(j + 1) << " - " << scheduleDay[i][j].getDescription() << "\033[0m";
				ScheduleInThisMonth = true;
				ScheduleInThisYear = true;
			}

			if (scheduleDay[i][j].getType() == 'P')	//Cyan Background
			{
				cout << "\033[36m\n\t\t" << OrdinalNumber(j + 1) << " - " << scheduleDay[i][j].getDescription() << "\033[0m";
				ScheduleInThisMonth = true;
				ScheduleInThisYear = true;
			}

			if (scheduleDay[i][j].getType() == 'A')	//No Color
			{
				cout << "\n\t\t" << OrdinalNumber(j + 1) << " - " << scheduleDay[i][j].getDescription() << "\033[0m";
				ScheduleInThisMonth = true;
				ScheduleInThisYear = true;
			}

			if (j == 30 && !ScheduleInThisMonth)
				cout << "No scheduled dates for the month.";
		}

		if (i == 11 && !ScheduleInThisYear)
			cout << "\n\n\t* No scheduled dates for the current year.";

		cout << "\n\n";
	}
}

// Post-Condition: Display the schedule of a whole month
void MyCalendar::displayMonthSchedule(int month) const
{
	bool IsThereSchedule = false;	// Keep track if the month has schedule date or not
	
	cout << "\n\t" << setw(9) << left << monthNames[month] << ": ";

	int i = month - 1;		

	for (int j = 0; j < 31; j++)
	{

		if (scheduleDay[i][j].getType() == 'H')	// Green Background
		{
			cout << "\033[42m\n\t\t" << OrdinalNumber(j + 1) << " - " << scheduleDay[i][j].getDescription() << "\033[0m";
			IsThereSchedule = true;
		}

		if (scheduleDay[i][j].getType() == 'P')	// Pink Background
		{
			cout << "\033[41m\n\t\t" << OrdinalNumber(j + 1) << " - " << scheduleDay[i][j].getDescription() << "\033[0m";
			IsThereSchedule = true;
		}

		if (scheduleDay[i][j].getType() == 'A')	// No Color
		{
			cout << "\n\t\t" << OrdinalNumber(j + 1) << " - " << scheduleDay[i][j].getDescription() << "\033[0m";
			IsThereSchedule = true;
		}

		if (j == 30 && (!IsThereSchedule))
			cout << "No scheduled dates for the month.";
	}
}

// Post-Condition: Display the schedule of the specific day
void MyCalendar::displayDaySchedule(int month, int day) const
{
	int i = month - 1;
	int j = day - 1;

	cout << "\n\t" << setw(9) << left << monthNames[month] << ": ";

	if (scheduleDay[i][j].getType() == 'H')	// Green Background
		cout << "\033[42m\n\t\t" << OrdinalNumber(j + 1) << " - " << scheduleDay[i][j].getDescription() << "\033[0m";

	if (scheduleDay[i][j].getType() == 'P')	// Pink Background
		cout << "\033[41m\n\t\t" << OrdinalNumber(j + 1) << " - " << scheduleDay[i][j].getDescription() << "\033[0m";
		
	if (scheduleDay[i][j].getType() == 'A')	// No Color
		cout << "\n\t\t" << OrdinalNumber(j + 1) << " - " << scheduleDay[i][j].getDescription() << "\033[0m";
		
	if (scheduleDay[i][j].getType() == 'U')
		cout << "\n\t\t" << OrdinalNumber(day) << " - " << "unschedule";
}

