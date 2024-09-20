// Name: Hung Anh Ho
// Date: 10/19/2023
// Description: Chapter 14 - Assignment

#include <iostream>
#include "input.h"
#include "Month.h"
#include "Date.h"
#include "FeetInches.h"
#include "LandTract.h"

using namespace std;

int menuOption();
void Challenge7();
void Challenge8();
void Challenge9();
void Challenge11();
void Challenge12();

int main(){
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 7: Challenge7(); break; 
        case 8: Challenge8(); break;
        case 9: Challenge9(); break;
        case 11: Challenge11(); break;
        case 12: Challenge12(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

int menuOption()
{
    system("cls");
    cout << "\n\tChapter 14 - assignments";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t7. Month class";
    cout << "\n\t8. Date class modification";
    cout << "\n\t9. FeetInches modification";
    cout << "\n\t11.FeetInches class copy constructor and multiply function";
    cout << "\n\t12.LandTract Class";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t0. exit";
    cout << "\n\t" << string(60, char(205));

    return inputInteger("\n\tOption: ", 0, 12);
}

//Challenge7---------------------------------------------------------------------------
void Challenge7()
{
    // Instantiate the month object
    Month test;

    cin >> test;                    // Test the >> operator
    
    cout << "\tTest 1 information: \n";
    cout << "\t" << test << '\n';   // Test the << operator

    cout << "\t" << ++test << '\n'; // Prefix-mode 
    cout << "\t" << test++ << '\n'; // Postfix-mode
    cout << "\t" << test << '\n';   


    string monthName = inputString("\n\tEnter a month name: ", false);

    // Instantiate the month object with constructor#1
    Month test2(monthName);
    cout << "\tTest 2 informtation: \n";
    cout << "\t" << test2 << '\n';
    cout << "\t" << ++test2 << '\n';
    cout << "\t" << test2++ << '\n';
    cout << "\t" << test2 << '\n';

    int month = inputInteger("\n\tEnter a month number (0...12): ", 1, 12);

    // Instantiate the month object with constructor#2
    Month test3(month);
    cout << "\tTest 3 informtation: \n";
    cout << "\t" << test3 << '\n';
    cout << "\t" << ++test3 << '\n';
    cout << "\t" << test3++ << '\n';
    cout << "\t" << test3 << '\n';

    // Testing the assignment = operator
    Month test4 = test3;
    cout << "\n";
    cout << "\tTest 4 informtation: \n";
    cout << "\tTest assignment operator: \n" << test4 << '\n';
}

//Challenge8---------------------------------------------------------------------------
void Challenge8()
{
    // Instantiate the date object
    Date test1;

    cin >> test1;

    cout << "\tTest 1 information: \n";
    cout << "\tCurrent  : " << test1 << '\n';   // Test the << operator
    cout << "\tPrefix ++: " << ++test1 << '\n'; // Prefix-mode 
    cout << "\tPostfix++: " << test1++ << '\n'; // Postfix-mode
    cout << "\tCurrent  : " <<test1 << '\n';

    // Instantiate the date object
    Date test2;

    cin >> test2;
    cout << "\tTest 2 information: \n";
    cout << "\tCurrent  : " << test2 << '\n';   // Test the << operator
    cout << "\tPrefix --: " << --test2 << '\n'; // Prefix-mode 
    cout << "\tPostfix--: " << test2-- << '\n'; // Postfix-mode
    cout << "\tCurrent  : " << test2 << '\n';

    // Test the copy argument
    Date test3(test1);

    Date test4 = test2;

    // Test the - operator
    cout << "\n\tDate3: " << test3;
    cout << "\n\tDate4: " << test4;
    cout << "\n\tDate3 - Date4: " << test3 - test4 << " days";
}

//Challenge9---------------------------------------------------------------------------
void Challenge9()
{
    // Instaniate the FeetInches object
    FeetInches test1;
    cin >> test1;
    cout << "\tTest 1: " << test1 << '\n';

    // Instaniate the FeetInches object
    FeetInches test2;
    cin >> test2;
    cout << "\tTest 2: " << test2 << '\n';

    // Test the >=, <= and != reletion
    if (test1 >= test2)
        cout << "\n\tTest 1 >= Test 2";

    if (test1 <= test2)
        cout << "\n\tTest 1 <= Test 2";

    if (test1 != test2)
        cout << "\n\tTest 1 != Test 2";

}

//Challenge11---------------------------------------------------------------------------
void Challenge11()
{
    // Instaniate the FeetInches object
    FeetInches test1;
    cin >> test1;
    cout << "\tTest 1: " << test1 << '\n';

    // Instaniate the FeetInches object
    FeetInches test2;
    cin >> test2;
    cout << "\tTest 2: " << test2 << '\n';

    // Testing the copy constructor
    FeetInches test3(test1);
    cout << "\n\tTesting the copy constructor" << "\n";
    cout << "\tTest 3: " << test3 << '\n';
    
    // Testing the multiply function
    FeetInches test4 = test2.multiply(test3);
    cout << "\n\tTest 4 = Test2 * Test3" << "\n";
    cout << "\tTest 4: " << test4;


}

//Challenge12---------------------------------------------------------------------------
void Challenge12()
{
    // Instantiate the LandTract object
    LandTract land1;

    cout << "\n\tLandTract 1: ";
    cin >> land1;
    cout << "\t" << land1 << "\n";

    // Instantiate the LandTract object
    LandTract land2;

    cout << "\n\tLandTract 2: ";
    cin >> land2;
    cout << "\t" << land2 << "\n";

    if (land1 == land2)
        cout << "\n\tThe two landTract are equal";
    else
        cout << "\n\tThe two landTract are not equal";
}