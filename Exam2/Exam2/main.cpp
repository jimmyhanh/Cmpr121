// Name: Hung Anh Ho
// Date: 11/15/2023
// Description: Exam 2

#include <iostream>
#include <ctime>
#include "MyUnit.h"
#include "MyScheduleDay.h"
#include "MyCalendar.h"
#include "input.h"
#include <fstream>

using namespace std;

// Function Prototype
char menuOption(const MyCalendar& obj);

void CaseA(MyCalendar& obj);    // Settings month
void CaseB(MyCalendar& obj);    // Settings year
void CaseC(MyCalendar& obj);    // Settings day
void CaseD(MyCalendar& obj);    // Settings calendar
void CaseE(MyCalendar& obj);    // Schedule and Report Date
void CaseF(MyCalendar& obj);    // Sync local time
void CaseG(MyCalendar& obj);    // Save calendar to the file
void CaseH(MyCalendar& obj);    // Restore calendar from the file

int main()
{
    MyCalendar calendar;    //MyCalendar object

    CaseF(calendar);        //Set MyCalendar object to local time
    
    do
    {
        switch (menuOption(calendar))
        {
        case 'X': exit(0); break;
        case 'A': CaseA(calendar); break;   
        case 'B': CaseB(calendar); break;
        case 'C': CaseC(calendar); break;
        case 'D': CaseD(calendar); break;
        case 'E': CaseE(calendar); break;
        case 'F': CaseF(calendar); break;
        case 'G': CaseG(calendar); break;
        case 'H': CaseH(calendar); break;
        
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
    
    return EXIT_SUCCESS;
}


// Display Graphical Board of calendar 
void displayGraphicalBoard(const MyCalendar& calendar)
{
    string leapIndicator = "";

    (calendar.isLeap()) ? leapIndicator = " (leap)" : leapIndicator = " (non-leap)";

    cout << "\n\t  Current year : \033[94m" << calendar.getCurrentYear()  << " - " << calendar.getYearName()  << leapIndicator << "\033[0m";
    cout << "\n\t  Current month: \033[94m" << calendar.getCurrentMonth() << " - " << calendar.getMonthName() << "\033[0m";
    cout << "\n\t  Awareness    : \033[94m" << calendar.getAwarenessMonth() << "\033[0m" ;
    cout << "\n\t  Current day  : \033[94m" << calendar.getOrdinalDay()   << " - " << calendar.dayOfTheWeek() << "\033[0m";
    cout << "\n\t               : " << (calendar.getScheduleDay()).getDescription();

    cout << "\n\n";
}

// Display main menu option
char menuOption(const MyCalendar& calendar)
{
    system("cls");
    displayGraphicalBoard(calendar);

    cout << "\n\tCMPR121 Exam2: MyCalendar - OOP implementations by Hung Anh Ho (11/15/2023)";
    cout << "\n\t" << string(85, char(205));
    cout << "\n\t\tA. Setting Current Year";
    cout << "\n\t\tB. Setting Current Month";
    cout << "\n\t\tC. Setting Current Day";
    cout << "\n\t\tD. Setting Current Calendar";
    cout << "\n\t\tE. Schedule and Report Dates";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t\tF. Sync to system's date";
    cout << "\n\t\tG. Save calendar to file";
    cout << "\n\t\tH. Restore calendar from file";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t\tX. Exit";
    cout << "\n\t" << string(85, char(205));

    return inputChar("\n\t\tOption: ", static_cast <string>("ABCDEFGHX"));
}

// Display menu of option A
int menuOptionA(const MyCalendar& calendar)
{
    system("cls");

    cout << "\n\tCurrent year : \033[94m" << calendar.getCurrentYear() << " - " << calendar.getYearName() << "\033[0m";

    cout << "\n\n\tCalendar - Current Year Menu";
    cout << "\n\t" << string(85, char(205));
    cout << "\n\t1. set current year";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t0. return";
    cout << "\n\t" << string(85, char(205));

    return inputInteger("\n\tOption: ", 0, 1);
}

// Set the year of MyCalendar 
void CaseA(MyCalendar& obj)
{
    do
    {
        switch (menuOptionA(obj))
        {
        case 0: return;
        case 1: 
            obj.setCurrentYear(inputInteger("\n\tEnter a year (1...9999): ", 1, 9999));
        break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

// Display menu of option B
int menuOptionB(const MyCalendar& calendar)
{
    system("cls");
    cout << "\n\tCurrent month: \033[94m" << calendar.getCurrentMonth() << " - " << calendar.getMonthName() << "\033[0m";

    cout << "\n\n\tCalendar - Current Month Menu";
    cout << "\n\t" << string(85, char(205));
    cout << "\n\t1. set current month";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t0. return";
    cout << "\n\t" << string(85, char(205));

    return inputInteger("\n\tOption: ", 0, 1);
}

// Set the month of MyCalendar object
void CaseB(MyCalendar& obj)
{
    do
    {
        switch (menuOptionB(obj))
        {
        case 0: return;
        case 1:
            obj.setCurrentMonth(inputInteger("\n\tEnter a month (1...12): ", 1, 12));
            break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

// Display menu of the option C
int menuOptionC(const MyCalendar& calendar)
{
    system("cls");
    cout << "\n\tCurrent day  : \033[94m" << calendar.getOrdinalDay() << " - " << calendar.dayOfTheWeek() << "\033[0m";

    cout << "\n\n\tCalendar - Current Day Menu";
    cout << "\n\t" << string(85, char(205));
    cout << "\n\t1. set current day";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t0. return";
    cout << "\n\t" << string(85, char(205));

    return inputInteger("\n\tOption: ", 0, 1);
}

// Set the day of MyCalendar object
void CaseC(MyCalendar& obj)
{
    do
    {
        switch (menuOptionC(obj))
        {
        case 0: return;
        case 1: // Set current day
        {           
            int MaxAllowedDay = obj.maxDayOfTheMonth();  // Set the max available day of the month

            obj.setCurrentDay(inputInteger("\n\tEnter a day (1..." + to_string(MaxAllowedDay) + "): ", 1, MaxAllowedDay));
        }
            break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

// Display the menu of option D
int menuOptionD(const MyCalendar& calendar)
{
    system("cls");
  
    calendar.displayDateFormat();
 
    cout << "\n\n\tMy Calendar Menu";
    cout << "\n\t" << string(85, char(205));
    cout << "\n\t 1. ++ (pre-increment)";
    cout << "\n\t 2. ++ (post-increment)";
    cout << "\n\t 3. jump forward (+n)";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t-1. -- (pre-decrement)";
    cout << "\n\t-2. -- (post-decrement)";
    cout << "\n\t-3. jump backward (-n)";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t 0. return";
    cout << "\n\t" << string(85, char(205));
    
    return inputInteger("\n\tOption: ", -3, 3);
}

// Setting currentCalendar
void CaseD(MyCalendar& obj)    
{
    do
    {
        switch (menuOptionD(obj))
        {
        case 0: return;
        case 1: // Pre-incrememnt
        {
            cout << "\n\n\tPre-increment:(++)\n";
            (++obj).displayDateFormat();
        }
        break;
        case 2: // Post-Increment
        {
            cout << "\n\n\tPost-increment:(++)\n";
            (obj++).displayDateFormat();
        }
        break;
        case 3: // Jump Forward
        {
            int JumpAmount = inputInteger("\n\tEnter an integer: ", true);

            obj.jumpforward(JumpAmount);
            cout << "\n\tJump forward(" << to_string(JumpAmount) << ")...";
        }
        break;
        case -1: // Pre-decrement
        {
            cout << "\n\n\tPre-decrement:(--)\n";
            (--obj).displayDateFormat();
        }
        break;
        case -2: // Post-decrement
        {
            cout << "\n\n\tPost-decrement:(--)\n";
            (obj--).displayDateFormat();
        }
        break;
        case -3: // Jump Backward
        {
            int JumpAmount = inputInteger("\n\tEnter an integer: ", true);

            obj.jumpbackward(JumpAmount);
            cout << "\n\tJump backward(" << to_string(JumpAmount) << ")...";
        }
        break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
}

int menuOptionE(const MyCalendar& calendar)
{
    system("cls");
  
    cout << calendar;

    cout << "\n\n\tScheduling Date";
    cout << "\n\t" << string(85, char(205));
    cout << "\n\t1. Schedule a date";
    cout << "\n\t2. Unschedule a date";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t3. display year schedules";
    cout << "\n\t4. display month schedules";
    cout << "\n\t5. display day schedule";
    cout << "\n\t" << string(85, char(196));
    cout << "\n\t0. return";
    cout << "\n\t" << string(85, char(205));
    return inputInteger("\n\tOption: ", 0, 5);

}

// Schedule and Report Date
void CaseE(MyCalendar& obj)    
{
    do
    {
        switch (menuOptionE(obj))
        {
        case 0: return;
        case 1: // Schedule a date
        {
            obj.setCurrentMonth(inputInteger("\n\tSpecify a month (1...12): ", 1, 12));

            int MaxAllowedDay = obj.maxDayOfTheMonth();  // Set the max available day of the month

            obj.setCurrentDay(inputInteger("\n\tSpecify a day (1..." + to_string(MaxAllowedDay) + ")  : ", 1, MaxAllowedDay));

            // Instaniate a MyScheduleDay object
            MyScheduleDay Schedule;
            
            // Create a temp variable to store the description and type
            string tempDescription = inputString("\n\tEnter a description     : ", true);
            char tempType = toupper(inputChar("\n\tSpecify a type (R-return, A-Awareness, H-holiday or P-personal) : ", static_cast <string>("RAHP")));

            // If the user not enter the R-Return option
            if (tempType != 'R')
            {
                // Set the description and type to schedule
                Schedule.setDescription(tempDescription);
                Schedule.setType(tempType);

                obj.setScheduleDay(Schedule);

                cout << "\n\tSUCCESS: Date has sucessfully been scheduled.";
            }
            else            
                cout << "\n\tDate has NOT been scheduled or rescheduled.";           
        }
        break;
        case 2: // Unschedule a date
        {
            obj.setCurrentMonth(inputInteger("\n\tSpecify a month (1...12): ", 1, 12));

            int MaxAllowedDay = obj.maxDayOfTheMonth();  // Set the max available day of the month

            obj.setCurrentDay(inputInteger("\n\tSpecify a day (1..." + to_string(MaxAllowedDay) + ")  : ", 1, MaxAllowedDay));

            MyScheduleDay Schedule;
            
            // To Unschedule a date, change the description to "unschedule" and type to 'U'
            Schedule.setDescription("unschedule");
            Schedule.setType('U');

            obj.setScheduleDay(Schedule);

            cout << "\n\tSUCCESS: Date has sucessfully been unscheduled.";
        }
        break;
        case 3: // Display year schedules
        {
            obj.displayYearSchedule();
        }
        break;
        case 4: // Display month schedules
        {
            int month = inputInteger("\n\tSpecify a month (1...12): ", 1, 12);
            obj.displayMonthSchedule(month);
        }
        break;
        case 5: // Display day schedule
        {            

            int month = inputInteger("\n\tSpecify a month (1...12): ", 1, 12);

            const int maxDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
            
            int MaxAllowedDay = maxDay[month];  // Set the max available day of the month

            if (obj.isLeap() && month == 2)
                MaxAllowedDay = 29;

            int day = inputInteger("\n\tSpecify a day (1..." + to_string(MaxAllowedDay) + ")  : ", 1, MaxAllowedDay);

            obj.displayDaySchedule(month, day);
        }
        break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

// Sync to system's date
void CaseF(MyCalendar& calendar)
{
    time_t currentTime = time(NULL);        // Data type represets time

    tm timeStruct;                          // Structure hold a calendar date and time

    localtime_s(&timeStruct, &currentTime); // Convert time_t to structure tm based on local time

    calendar.setCurrentMonth(timeStruct.tm_mon + 1);     // tm_mon: months since January
    calendar.setCurrentDay(timeStruct.tm_mday);          // tm_mday: day of the month
    calendar.setCurrentYear(timeStruct.tm_year + 1900);  // tm_year: years since 1900
}

// Write to the file
void CaseG(MyCalendar& obj)    
{
    fstream file;					// File for output
    string fileName;				// The file name

    // Open the file in binary for output mode
    fileName = inputString("\n\tEnter a binary (DAT) calendar file to write: ", true);

    file.open(fileName, ios::out | ios::binary);

    file.write(reinterpret_cast<char*>(&obj), sizeof(obj));

    file.close();
    cout << "\n\tSuccesfully write to the file, " << fileName;
}

// Restore from the file (read)
void CaseH(MyCalendar& obj)
{
    fstream file;					// File for input
    string fileName;				// The file name

    // Open the file in binary for input mode
    fileName = inputString("\n\tEnter a binary (DAT) calendar file name: ", true);
    file.open(fileName, ios::binary | ios::in);

    // Validate the binary file
    if (file.fail())
    {
        cout << "\n\tERROR: Binary data file, " << fileName << ", cannot be found.";
        return;
    }

    // Store the data from binary file into calendar 
    file.read(reinterpret_cast<char*>(&obj), sizeof(obj));

    file.close();
    cout << "\n\tSUCCESS: Restored calendar from " << fileName;
}