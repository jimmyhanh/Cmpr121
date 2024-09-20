//Hung Anh Ho
//5-24-2023
//Chapter 10

#include <iostream>
#include "input.h"
#include <cctype>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


void Challenge1();

void Challenge6();
int countConsonants(const char* str);
int countConsonants(const char* str);

void Challenge7();
char* nameArranger(char*, char* middleName, char*, int*);

void Challenge10();
string replaceSubstring(const string, const string, const string);
//void replaceSubstring(string&, string, string); // stopped working
string replaceSubstring(const char*, const char*, const char*);

void Challenge12();
bool isValidPassword(string&);
bool isValidPassword(char*);

void Challenge13();
bool checkDate(string);
string getMonths(const int);
void printDate(string, int, int);

void Challenge15();

void Challenge17();

int main()
{
    do
    {
        system("cls");
        cout << "\n\t\tChapter 10: Characters, C-strings and Strings by Hung Anh Ho";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t\t  1. String Length";
        cout << "\n\t\t  6. Vowels and Consonants";
        cout << "\n\t\t  7. Name Arranger             (required)"; //Done
        cout << "\n\t\t 10. ReplaceSubString Function (required)"; //Done
        cout << "\n\t\t 12. Password Verifier         (required)"; //Done
        cout << "\n\t\t 13. Date Printer              (required)"; //Done
        cout << "\n\t\t 15. Character Analysis";
        cout << "\n\t\t 17. Morse Code Converter      (required)"; //Done
        cout << "\n\t" + string(60, char(196));
        cout << "\n\t\t  0. Quit";
        cout << "\n\t" + string(60, char(205));
        cout << "\n";

        switch (inputInteger("\t\t  Option: ", 0, 17))
        {
        case 0: exit(1); break;
        case 1: Challenge1(); break;
        case 6: Challenge6(); break;
        case 7: Challenge7(); break;
        case 10: Challenge10(); break;
        case 12: Challenge12(); break;
        case 13: Challenge13(); break;
        case 15: Challenge15(); break;
        case 17: Challenge17(); break;
        default: cout << "\t\tERROR - Invalid option."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

void Challenge1()
{
    //c-string implementation
    char input[100];
    cout << "\nEnter a C-string: ";
    cin.getline(input, 100);

    cout << "\nLength of the c-string: " << strlen(input) << '\n';

    //string object implementation
    string input2;
    cout << "\nEnter a string object: ";
    getline(cin, input2, '\n');

    cout << "\nLength of the string object: " << input2.length() << '\n';

}

//countVowels get characters and return count for vowels
int countVowels(const char* str)
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
        if (isalpha(str[i]))
        {
            switch (toupper(str[i]))
            {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                count++;
                break;

            default:
                break;
            }
        }

    return count;
}

//countConsonants get characters and return count for consonsonants
int countConsonants(const char* str)
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
        if (isalpha(str[i]))
        {
            switch (toupper(str[i]))
            {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                break;
            default:
                count++;
                break;
            }
        }

    return count;
}


void Challenge6()
{
    char input[1000] = "";
    cout << "\n\tEnter a c-string: ";
    cin.getline(input, 1000);

    string input2;
    cout << "\n\tEnter a string: ";
    getline(cin, input2, '\n');


    do
    {
        cout << "\n\tA. Count the vowel(s)";
        cout << "\n\tB. Count the consonant(s)";
        cout << "\n\tC. Count both the vowel(s) and the consonant(s)";
        cout << "\n\tD. Enter a new c-string";
        cout << "\n\tE. Return";

        switch (toupper(inputChar("\nOption: ", static_cast<string>("ABCDE"))))
        {
        case 'A':
        {
            cout << "\t# of vowel(s) of c-string: " << countVowels(input) << "\n";
            cout << "\t# of vowel(s) of string: " << countVowels(input2.c_str()) << "\n";

        }
        break;

        case 'B':
        {
            cout << "\t# of consonant(s) of c-string: " << countConsonants(input) << "\n";
            cout << "\t# of consonant(s) of string: " << countConsonants(input2.c_str()) << "\n";
        }
        break;

        case 'C':
        {
            cout << "\t# of vowel(s) and consonant(s) of c-string: " << countVowels(input) + countConsonants(input) << "\n";
            cout << "\t# of vowel(s) and consonant(s) of string: " << countVowels(input2.c_str()) + countConsonants(input2.c_str()) << "\n";
        }
        break;

        case 'D':
            cout << "\nEnter a new c-string: ";
            cin.getline(input, 1000);

            break;

        case 'E':
            return;
        }

    } while (true);


}


void Challenge7()
{
    do
    {
        system("cls");
        cout << "\t Challenge7. Name Arranger\n";
        cout << "\t" + string(60, char(205));
        cout << "\n\t A. String object Implementation";
        cout << "\n\t B. C-string Implementation";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t R. return";
        cout << "\n\t" + string(60, char(205));

        switch (toupper(inputChar("\n\tOption: ", "ABR")))
        {

            case 'A':
            {
                system("cls");
                cout << "\t Challenge7. Name Arranger\n";
                cout << "\t" + string(60, char(205));

                // Ask for user's first, middle and last name.
                string first_name = inputString("\n\tEnter your first name: ", true);
                string middle_name = inputString("\n\tEnter your middle name (type ' '(space) if you don't have one): ", true);
                string last_name = inputString("\n\tEnter your last name: ", true);

                if (middle_name == "")
                {
                    cout << "\n\tYour full name is " + last_name + ", " + first_name + "\n";
                }
                else
                    cout << "\n\tYour full name is " + last_name + ", " + first_name + ' ' + middle_name + "\n";

                system("pause");
                break;
            }

            case 'B':
            {
                system("cls");
                cout << "\t Challenge10 - ReplaceSubString Function\n";
                cout << "\t" + string(60, char(205));

                int size = inputInteger("\n\tEnter size of the c-string: ", true);

                char* first_name = new char[size];
                char* middle_name = new char[size];
                char* last_name = new char[size];

                // Ask for user's first, middle and last name.
                /*
                cout << "\n\tEnter first name : ";
                cin.getline(first_name, size);

                cout << "\n\tEnter middle name (press Enter if you don't have one): ";
                cin.getline(middle_name, size);

                cout << "\n\tEnter last name : ";
                cin.getline(last_name, size);
                */

                do
                {
                    cout << "\n\tEnter first name : ";
                    cin.getline(first_name, size);

                    if (strstr(first_name, "") == nullptr)
                    {
                        cout << "\n\tInvalid input.";
                    }
                    else
                        break;

                } while (true);

                cout << "\n\tEnter middle name (press Enter if you don't have one): ";
                cin.getline(middle_name, size);

                do
                {
                    //Validate
                    cout << "\n\tEnter last name : ";
                    cin.getline(last_name, size);
                    if (strstr(last_name, "") == nullptr)
                    {
                        cout << "\n\tInvalid input.";
                    }
                    else
                        break;

                } while (true);

                int length = NULL;
                if (strlen(middle_name) <= 1)
                {
                   length = strlen(first_name) + strlen(last_name) + 3;
                }
                else
                   length = strlen(first_name) + strlen(middle_name) + strlen(last_name) + 3;

                char* fullname = new char[length + 1];

                //clear full name
                fullname[0] = '\0';

                //get full name
                strcat(fullname, last_name);
                strcat(fullname, ", ");
                strcat(fullname, first_name);

                if (strlen(middle_name) > 1)
                {
                    strcat(fullname, " ");
                    strcat(fullname, middle_name);

                }

                /*
                if (middle_name != "")
                {
                    strcat(fullname, " ");
                    strcat(fullname, middle_name);
                }
                */
                /*
                char* fullname = new char[size];

                strncat(fullname, last_name, size);
                strncat(fullname, ", ", size);
                strncat(fullname, first_name, size);
                strncat(fullname, " ", size);
                strncat(fullname, middle_name, size);
                */

                /*
                strcat(fullname, last_name);
                strcat(fullname, ", ");
                strcat(fullname, first_name);
                if (middle_name == NULL)
                {
                    strcat(fullname, " ");
                }
                else
                {
                    strcat(fullname, " ");
                    strcat(fullname, middle_name);
                }
                */

                //Display
                cout << "\n\tName : " << fullname << "\n";

                //Deallocate
                delete[] first_name;
                delete[] middle_name;
                delete[] last_name;
                delete[] fullname;

                system("pause");
                break;
            }
            case 'R': return;
        }
    } while (true);
}


//Challenge10
void Challenge10()
{
   do 
   {
       system("cls");
       cout << "\t Challenge10 - ReplaceSubString Function\n";
       cout << "\t" + string(60, char(205));
       cout << "\n\t A. String object Implementation";
       cout << "\n\t B. C-string Implementation";
       cout << "\n\t" + string(60, char(205));
       cout << "\n\t R. return";
       cout << "\n\t" + string(60, char(205));

       switch (toupper(inputChar("\n\tOption: ", "ABR")))
       {
        case 'A':
        {
            system("cls");
            cout << "\t Challenge10 - ReplaceSubString Function\n";
            cout << "\t" + string(60, char(205));

            cout << "\n\tExample: \n";
            string  string1 = "the dog jump over the fence";
            string  string2 = "the";
            string  string3 = "that";

            //Example
            cout << "\n\tString before change: ";
            cout << "\n\t" <<string1 << "\n";

            string1 = replaceSubstring(string1, string2, string3);

            cout << "\n\n\tString after change: ";
            cout << "\n\t" << string1 << "\n";

            //Execute
            string1 = inputString("\n\n\tInput your own string: ", true);

            do
            {
                string2 = inputString("\n\tInput your word to replace: ", true);
                if (string1.find(string2) == false)
                {
                    cout << "\n\tInvalid input. " << string2 << " was not found. Try again.\n";
                }
                else
                    break;

            } while (true);

            string3 = inputString("\n\tInput your replacing word: ", true);

            string1 = replaceSubstring(string1, string2, string3);

            cout << "\n\n\tString after change: ";
            cout << string1 << "\n";

            system("pause");
            break;
        }
       
        case 'B':
        {
            system("cls");
            cout << "\t Challenge10 - ReplaceSubString Function\n";
            cout << "\t" + string(60, char(205));

            cout << "\n\tExample: \n";
            const int SIZE = 100;
            char string1[SIZE] = "the dog jump over the fence";
            char string2[SIZE] = "the";
            char string3[SIZE] = "that";

            //Example
            cout << "\n\tString before change: ";
            cout << string1 << "\n";       

            //Display example
            cout << "\n\tString after change: ";
            cout << replaceSubstring(string1, string2, string3) << "\n";

            //Input string
            int size = inputInteger("\n\tEnter size of the c-string: ", true);

            char* input1 = new char[size];
            char* input2 = new char[size];
            char* input3 = new char[size];

            //Execute
            do
            {
                cout << "\n\tEnter a c-string to start: ";
                cin.getline(input1, size);

                if (strlen(input1) < 2)
                {
                    cout << "\n\tInvalid input. Try again.";
                }
                else
                    break;

            }while(true);
            
            //Word to replace
            do
            {
                cout << "\n\tEnter the word you want to replace: ";
                cin.getline(input2, size);

                //Validdate
                if (strstr(input2, "/"))
                {
                    cout << "\n\tInvalid input. " << input2 << " was not found. Try again.\n";
                }
                else
                    break;

            } while (true);

            //Replace with
            cout << "\n\tEnter word to replace with: ";
            cin.getline(input3, size);

            //Output
            cout << "\n\tYour updated string is: ";
            cout << replaceSubstring(input1, input2, input3) << "\n";

            //Deallocate
            delete[] input1;
            delete[] input2;
            delete[] input3;

            system("pause");
            break;
        }

        case 'R': return;
       }

   } while(true);
}

//replaceSubstring takes in string input, word to find and word to replace and return the string
string replaceSubstring(const string sentence, const string searchWord, const string replaceWord)
{
    string altered = sentence;  
    size_t findWord = altered.find(searchWord);
    static const size_t npos = -1;

    while (findWord != npos)
    {
        altered.replace(findWord, searchWord.size(), replaceWord);
        findWord = altered.find(searchWord, findWord + replaceWord.length());
    }
    return altered;
}

/*
//replaceSubstring takes in string input, word to find and word to replace and return the string
void replaceSubstring(string& string1, string string2, string string3)
{
    for (int i = 0; i < string1.length() - string2.length(); i++)
    {
        if (string1.substr(i, string2.length()) == string2)
        {
            string1.replace(string1.find(string2), string2.length(), string3);
        }
    }
}
*/

// function definition for replaceSubstring
string replaceSubstring(const char *string1, const char *string2, const char *string3)
{
    // declare variables
    char *startSearch = const_cast<char *>(string1);
    char *occurrence = strstr(startSearch, string2);
    // declare string to hold output
    string output = "";

    // while loop to find the occurrence of string1 in string2
    while (occurrence)
    {
        // append the string from startSearch to the occurrence of st2
        output.append(startSearch, occurrence - startSearch);
        output.append(string3);
        startSearch = occurrence + strlen(string2);
        occurrence = strstr(startSearch, string2);
    }

    // append the string from startSearch to the end of st1
    output.append(startSearch);

    // return the output
    return output;
}



//Challenge 12
void Challenge12()
{
    system("cls");
    cout << "\t Challenge13. Date Printer\n";
    cout << "\t" + string(60, char(205));
    cout << "\n\t A. String object Implementation";
    cout << "\n\t B. C-string Implementation";
    cout << "\n\t" + string(60, char(205));
    cout << "\n\t R. return";
    cout << "\n\t" + string(60, char(205));

    switch (toupper(inputChar("\n\tOption: ", "ABR")))
    {


        case 'A':
        {
            system("cls");
            cout << "\t Challenge12. Password Verifier\n";
            cout << "\t" + string(60, char(205));

            //input
            do
            {
                string password = inputString("\n\tEnter your password: ", true);

                //Validate
                if (isValidPassword(password))
                {
                    cout << "\n\tPassword is valid.\n";
                    return; //because break didn't worked
                }
                else
                {
                    cout << "\n\tPassword is not valid.\n";
                }

            } while (true);

            break;
        }

        case 'B':
        {
            system("cls");
            cout << "\t Challenge12. Password Verifier\n";
            cout << "\t" + string(60, char(205));

            int size = inputInteger("\n\tEnter your c-string's size: ", true);
            
            char* password = new char[size];
            //Input
            do
            {
                //Input
                cout << ("\n\tEnter your password: ");
                cin.getline(password, size);

                //Validate
                if (isValidPassword(password) == true)
                {
                    cout << "\n\tPassword is valid.\n";
                    delete[] password;
                    return; //because break didn't worked
                }
                else
                {
                    cout << "\n\tPassword is not valid.\n";
                }

            } while (true);

            break;           
        }

        case 'R': return;

    }while (true);
}

//isValidPassword check for password is valid to return true or false
bool isValidPassword(string& password) 
{
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasPunct = false;

    if (password.size() < 6) 
    {
        cout << "Password must be atleast 6 characters long.\n";
        return false;
    }

    for (char ch : password) 
    {
        if (isdigit(ch)) hasDigit = true;
        else if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        //else if (ispunct(ch)) hasPunct = true;
    }

    if (!hasDigit) 
    {
        cout << "Password must contain at least one digit.\n";
        return false;
    }

    if (!hasUpper) 
    {
        cout << "Password must contain at least one uppercase letter.\n";
        return false;
    }

    if (!hasLower) 
    {
        cout << "Password must contain at least one lowercase letter.\n";
        return false;
    }

    /*
    if (!hasPunct) 
    {
        cout << "Password must contain at least one special letter.\n";
        return false;
    }
    */
    return true;
}

//isValidPassword check for password is valid to return true or false
bool isValidPassword(char* password)
{
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasPunct = false;

    if (strlen(password) < 6) 
    {
        cout << "Password must be atleast 6 characters long.\n";
        return false;
    }

    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i])) hasDigit = true;
        else if (isupper(password[i])) hasUpper = true;
        else if (islower(password[i])) hasLower = true;
        //else if (ispunct(password[i])) hasPunct = true;
    }

    if (!hasDigit) 
    {
        cout << "Password must contain at least one digit.\n";
        return false;
    }

    if (!hasUpper) 
    {
        cout << "Password must contain at least one uppercase letter.\n";
        return false;
    }

    if (!hasLower) 
    {
        cout << "Password must contain at least one lowercase letter.\n";
        return false;
    }

    /*
    if (!hasPunct) 
    {
        cout << "Password must contain at least one special letter.\n";
        return false;
    }
    */

    return true;
}

//Challenge 13
void Challenge13()
{
    do
    {
        system("cls");
        cout << "\t Challenge13. Date Printer\n";
        cout << "\t" + string(60, char(205));
        cout << "\n\t A. String object Implementation";
        cout << "\n\t B. C-string Implementation";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t R. return";
        cout << "\n\t" + string(60, char(205));

        switch (toupper(inputChar("\n\tOption: ", "ABR")))
        {           
            case 'A':
            {
                system("cls");
                cout << "\t Challenge13. Date Printer\n";
                cout << "\t" + string(60, char(205));

                int month = 0;
                int day = 0;
                int year = 0;

                string date = inputString("\n\tEnter your date in for of (mm/dd/yyyy): ", true);

                while (checkDate(date) == false)
                {
                    if (checkDate(date) == false)
                    {
                        date = inputString("\n\tYour date is invalid.\n\tEnter your date in for of (mm/dd/yyyy): ", true);
                    }
                }

                month = stoi(date.substr(0));
                day = stoi(date.substr(3));
                year = stoi(date.substr(6));

                date = getMonths(month);
                printDate(date, day, year);

                system("pause");
                break;
            }
        
        
            case 'B':
            {
                char date[11];  // Assuming the input date will be in mm/dd/yyyy format
                char month[20];
                int day = 0;
                int year = 0;

                const char* monthNames[] = { "January", "February", "March", "April", "May", "June", "July",
                                             "August", "September", "October", "November", "December"};

                do
                {
                    // Prompt user for input
                    system("cls");
                    cout << "\t Challenge13. Date Printer\n";
                    cout << "\t" + string(60, char(205));
                    cout << "\n\tEnter a date in mm/dd/yyyy format: ";
                    cin.getline(date, sizeof(date));

                    if (strstr(date, "/") != NULL)
                    {
                        //Validate the data
                        char* token = strtok(date, "/");
                        if (token != nullptr)
                        {
                            int monthNumber = atoi(token);
                            if (monthNumber < 1 || monthNumber > 12)
                            {
                                cout << "Invalid month. Please enter a valid month (1-12)." << "\n";
                                system("pause");
                            }
                            else
                            {
                                monthNumber = atoi(token);

                                month[0] = '\0';
                                strcat(month, monthNames[monthNumber - 1]);
                                token = strtok(nullptr, "/");
                            }                              
                        }
                        else
                        {
                            cout << "Invalid input. Try again.";
                            system("pause");
                        }

                        if (token != nullptr)
                        {
                            day = atoi(token);
                            if (day < 1 || day > 31)
                            {
                                cout << "Invalid day. Please enter a valid day (1-31)." << "\n";
                                system("pause");
                            }
                            else
                            {
                                day = atoi(token);
                                token = strtok(nullptr, "/");
                            }
                        }
                        else
                        {
                            cout << "Invalid input. Try again.";
                            system("pause");
                        }

                        if (token != nullptr)
                        {
                            year = atoi(token);
                            if (year < 1900 || year > 2100)
                            {
                                cout << "Invalid year. Please enter a valid year (1900-2100)." << "\n";
                                system("pause");
                            }
                            else
                            {
                                day = atoi(token);

                                // Print the formatted date
                                cout << "\n\t" << month << " " << day << ", " << year << "\n";
                                system("pause");
                                break;
                            }
                        }
                        else
                        {
                            cout << "Invalid input. Try again.";
                            system("pause");
                        }
                    }
                    else
                    {
                        cout << "\n\tInvalid format. Try again. \n";
                        system("pause");
                        break;
                    }

                } while (true);         
                break;
            }

            case 'R': return;
        }
    }while (true);
}

//CheckDate  * Correct length of the date string (This is the only condition that immediately returns the result in case the validity check fails)
//Existence of delimiting characters '/'
//Correctness of month, day, year input
//Determins whether the year is a leap year. Based on
//the result, the month and day input is validated once more.
bool checkDate(string date)
{

    bool validDate = true;
    bool isLeapYear = false;
    int  month = 0;
    int day = 0;
    int year = 0;
    char delimiter = '/';

    if (date.length() < 10)
    {
        return validDate = false;
    }

    if (date.at(2) != delimiter || date.at(5) != delimiter)
    {
        validDate = false;
    }

    month = stoi(date.substr(0));

    if (month < 1 || month > 12)
    {
        validDate = false;
    }

    day = stoi(date.substr(3));

    if (day < 1 || day > 31)
    {
        validDate = false;
    }

    year = stoi(date.substr(6));

    if (year < 1 || year > 2100)
    {
        validDate = false;
    }

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        isLeapYear = true;
    }

    if (isLeapYear && month == 2 && day > 29)
    {
        validDate = false;
    }

    if (isLeapYear == false && month == 2 && day > 28)
    {
        validDate = false;
    }

    return validDate;
}

//months determines the name of a month, based on the integer value passed to it . Then return the month's name.
string getMonths(const int month)
{
    const string monthNames[12] = { "January", "February", "March",
                                    "April", "May", "June", "July",
                                    "August", "September", "October",
                                    "November", "December" };

    return monthNames[month-1];
}

//printDate accepts a string and two int values as arguments. It inserts day and year into the date string, and displays the date.
void printDate(string date, int day, int year)
{
    date.insert(date.length(), " " + to_string(day) + ", " + to_string(year));

    cout << "\n\tYour date is: " << date << "\n";
}

//Challenge15
void Challenge15()
{
    system("cls");
    
    ifstream inputFile;
    string fileName = inputString("\n\tEnter a data file name (text.txt): ", true);

    //open file to read
    inputFile.open(fileName);

    while (!inputFile)
    {
        cout << "\n\t " << fileName << ", was found. Enter the correct file name.\n";
        fileName = inputString("\n\tEnter a data file name (text.txt): ", true);

        inputFile.open(fileName);
    }

    int uppercaseCount = 0, lowercaseCount = 0, digitCount = 0;
    char ch;


    while (inputFile.get(ch)) 
    {
        if (isupper(ch)) uppercaseCount++;
        else if (islower(ch)) lowercaseCount++;
        else if (isdigit(ch)) digitCount++;
    }

    cout << "\n\tNumber of uppercase letters: " << uppercaseCount << '\n';
    cout << "\n\tNumber of lowercase letters: " << lowercaseCount << '\n';
    cout << "\n\tNumber of digits: " << digitCount << '\n';

    inputFile.close();
}

//Challenge 17
void Challenge17()
{
    do
    {
        system("cls");
        cout << "\t Challenge117. Morse Code Converter\n";
        cout << "\t" + string(60, char(205));
        cout << "\n\t A. String object Implementation";
        cout << "\n\t B. C-string Implementation";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t R. return";
        cout << "\n\t" + string(60, char(205));

        switch (toupper(inputChar("\n\tOption: ", "ABR")))
        {
        case 'A':
        {
            system("cls");
            cout << "\t Challenge17. Morse Code Converter\n";
            cout << "\t" + string(60, char(205));

            string digits[10] = 
            { "-----", // 0
                ".----", // 1
                "..---", // 2
                "...--", // 3
                "....-", // 4
                ".....", // 5
                "-....", // 6
                "--...", // 7
                "---..", // 8
                "----.", // 9
            };

            string alphabets[26] = { ".-",   // A
                "-...", //B
                "-.-.", //C
                "-..", //D
                ".", //E
                "..-.", //F
                "--.", //G
                "--...", //H
                "..", //I
                ".---", //J
                "-.-", //K
                ".-..", //L
                "--", //M
                "-.", //N
                "---", //O
                ".--.", //P
                "--.-", //Q
                ".-.", //R
                "...", //S
                "-", //T
                "..-", //U
                "...-", //V
                ".--", //W
                "-..-", //X
                "-.--", //Y
                "--..", //Z
            };

            string comma = "--..--";
            string period = ".-.-.-";
            string questionMark = "..--..";

            //Input
            string input = inputString("\n\tEnter a string to convert to morse code: ", true);

            //Output
            cout << "\n\tMorsecode: \n";
            for (int i = 0; i < input.length(); i++)
            {
                if (isdigit(input[i]))
                    cout << digits[input[i] - '0'] << "|";

                if (isalpha(input[i]))
                    cout << alphabets[toupper(input[i]) - 'A'] << "|";

                if (isspace(input[i]))
                    cout << "space|";

                if (ispunct(input[i]))
                {
                    if (input[i] == ',')
                        cout << comma << "|";
                    else if (input[i] == '.')
                        cout << period << "|";
                    else if (input[i] == '?')
                        cout << questionMark << "|";
                    else
                        cout << "unknown";
                }
            }

            cout << "\n";

            system("pause");
            break;
        }
        
        case 'B':
        {
            system("cls");
            cout << "\t Challenge17. Morse Code Converter\n";
            cout << "\t" + string(60, char(205));

            string digits[10] = 
            { "-----", // 0
                ".----", // 1
                "..---", // 2
                "...--", // 3
                "....-", // 4
                ".....", // 5
                "-....", // 6
                "--...", // 7
                "---..", // 8
                "----.", // 9
            };

            string alphabets[26] = { ".-",   // A
                "-...", //B
                "-.-.", //C
                "-..", //D
                ".", //E
                "..-.", //F
                "--.", //G
                "--...", //H
                "..", //I
                ".---", //J
                "-.-", //K
                ".-..", //L
                "--", //M
                "-.", //N
                "---", //O
                ".--.", //P
                "--.-", //Q
                ".-.", //R
                "...", //S
                "-", //T
                "..-", //U
                "...-", //V
                ".--", //W
                "-..-", //X
                "-.--", //Y
                "--..", //Z
            };

            string comma = "--..--";
            string period = ".-.-.-";
            string questionMark = "..--..";

            //Input string
            int size = inputInteger("\n\tEnter size of the c-string: ", true);

            char* input = new char[size];

            //Output
            cout << "\n\tEnter a c-string to convert to morse code: ";
            cin.getline(input, size);


            cout << "\n\tMorsecode: \n";
            for (int i = 0; i < strlen(input); i++)
            {
                if (isdigit(input[i]))
                    cout << digits[input[i] - '0'] << "|";

                if (isalpha(input[i]))
                    cout << alphabets[toupper(input[i]) - 'A'] << "|";

                if (isspace(input[i]))
                    cout << "space|";

                if (ispunct(input[i]))
                {
                    if (input[i] == ',')
                        cout << comma << "|";
                    else if (input[i] == '.')
                        cout << period << "|";
                    else if (input[i] == '?')
                        cout << questionMark << "|";
                    else
                        cout << "unknown";
                }
            }
            cout << "\n";

            delete[] input;

        system("pause");
        break;
        }

        case 'R': return;
        }

    }while (true);
    
} 