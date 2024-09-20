//Hung Anh Ho
//9-15-2023
//Challenge 11

#include <iostream>
#include "input.h"
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

//Challenge 1, 2
struct MovieData
{
    char title[100] = "unknown";
    char director[100] = "unknown";
    int yearReleased = 0;
    int runningTime = 0;
    double cost = 0.0;
    double revenue = 0.0;
};

//Challenge 3
struct CompanyData
{
    char divisionName[10] = "unknown";
    double firstQuaterSale = 0.0;
    double secondQuaterSale = 0.0;
    double thirdQuaterSale = 0.0;
    double fourthQuaterSale = 0.0;
    double annualSales = 0.0;
    double averageSales = 0.0;
};
enum Division { EAST, WEST, NORTH, SOUTH };

//Challenge 4, 5
struct Weather
{
    double rainFall = 0.0;
    double highTemp = 0.0;
    double avgTemp = 0.0;
    double lowTemp = 0.0;
};
enum Month { JANUARY,FEBRUARY,MARCH,APRIL
    ,MAY,JUNE,JULY,AUGUST,SEPTEMBER,
    OCTOBER,NOVEMBER,DECEMBER};
//Challenge 6 
struct Player
{
    char name[100] = "unknown";
    double number = 0.0;
    double score = 0.0;
};

//Challenge 7, 8
struct Customer
{
    char name[100] = "unknown";
    char address[100] = "unknown";
    char city[30] = "unknown";
    char state[30] = "unknown";
    char zip[20] = "unknown";
    char telephone[20] = "unknown";
    int accountBalance = 0;
    char lastPaymentDate[20] = "unknown";
};

//Challenge 12
struct Student
{   
    char name[100] = "unknown";
    char ID[20] = "unknown";

    double* test = nullptr;

    double average = 0.00;
    char letter = 'N';
};


int menuOption();
int subMenuOption();

void Challenge1();
void Challenge2();
void inputMovie(MovieData&);
void displayMovie(MovieData);

void Challenge3();
void inputDivision(CompanyData&);
void displayDivision(CompanyData);
void DivisionName(Division);

void Challenge5();
void inputWeather(Weather&);
double findHighestTemp(Weather [], int, vector<int>&);
double findLowestTemp(Weather [], int, vector <int>&);
void MonthName(Month);

void Challenge6();
void inputPlayer(Player&);
double findHighestScore(Player[], int, vector<int>&);
void displayPlayer(Player);

void Challenge8();
void inputCustomer(Customer&);
void displayCustomer(Customer);
bool findOccurence(Customer, char[]);

void Challenge12();
void inputStudent(Student&, int);
void displayStudentInformation(Student);

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: Challenge1(); break;
        case 2: Challenge2(); break;
        case 3: Challenge3(); break;
        case 5: Challenge5(); break;
        case 6: Challenge6(); break;
        case 8: Challenge8(); break;
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
    cout << "\n\tCMPR121 - Chapter 11 by Hung Anh Ho";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t1. Movie Data";
    cout << "\n\t2. Movie Profit";
    cout << "\n\t3. Corporate Sales Data";
    cout << "\n\t5. Weather Statistics Modification";
    cout << "\n\t6. Soccer Scores";
    cout << "\n\t8. Search Function for Customer Account Program";
    cout << "\n\t12.Course Grade";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t0. exit";
    cout << "\n";

    return inputInteger("\n\tOption: ", 0, 12);
}

int subMenuOption()
{
    cout << "\n\t" + string(60, char(205));
    cout << "\n\t 1. Challenge";
    cout << "\n\t" + string(60, char(205));
    cout << "\n\t 0. return";
    cout << "\n\t" + string(60, char(205));

    return inputInteger("\n\tOption: ", 0, 1);
}

void Challenge1()
{
    do
    {
        system("cls");
        cout << "\n\t Challenge1. Movie Data\n";

        switch (subMenuOption())
        {
            case 1:
            {
                // Allocate the movie array
                int size = inputInteger("\n\tEnter the number of movies: ", true);
                MovieData* movies = new MovieData[size];

                // Enter the information for each element in the movie array
                for (int i = 0; i < size; i++)
                {
                    cout << "\nEnter the information for movie #" << i + 1;
                    inputMovie(*(movies + i));
                    cout << "\n";
                }

                // Display the information of each element in the movie array
                for (int i = 0; i < size; i++)
                {
                    cout << "\n\tThe information of movie #" << i + 1;
                    displayMovie(movies[i]);
                    cout << "\n";
                }

                system("pause");
                delete[] movies;
                break;
            }

            case 0:
                return;
        }

    } while (true);

}

void Challenge2()
{
    system("cls");
    cout << "\n\tChallenge 2. Movie Profit";
    cout << "\n\t" << string(60, char(205));

    switch (subMenuOption())
    {
    case 1:
    {
        int size = inputInteger("\n\tEnter the number of movies: ", true);
        MovieData* movies = new MovieData[size];

        for (int i = 0; i < size; i++)
        {
            cout << "\n\tEnter the information for movie #" << i + 1;
            inputMovie(*(movies + i));
            cout << "\n";
        }

        for (int i = 0; i < size; i++)
        {
            cout << "\n\tThe information of movie #" << i + 1;
            displayMovie(movies[i]);
            cout << "\n";
        }

        delete[] movies;
    }
    case 0:
        return;
    }
    system("pause");
}

//Input the values for the movie
void inputMovie(MovieData& m)
{
    strcpy_s(m.title, inputString("\n\tEnter the movie name            : ", true).c_str());
    strcpy_s(m.director, inputString("\n\tEnter the director name         : ", true).c_str());
    m.yearReleased = inputInteger("\n\tEnter the year released         : ", 1900, 2023);
    m.runningTime = inputInteger("\n\tEnter the running time (minutes): ", 60, 180);
    m.revenue = inputDouble("\n\tEnter the movie revenue         : ", true);
    m.cost = inputDouble("\n\tEnter the movie production cost : ", true);
}

//Output the movie information
void displayMovie(MovieData m)
{
    cout << "\n\tTitle        : " << m.title;
    cout << "\n\tDirector name: " << m.director;
    cout << "\n\tYear released: " << m.yearReleased;
    cout << "\n\tRunning time : " << m.runningTime << " minutes";

    double profit = m.revenue - m.cost;

    cout << fixed << setprecision(2) << showpoint;
    cout << "\n\tRevenue      : " << m.revenue ;
    cout << "\n\tCost         : " << m.cost;

    profit > 0 ? 
        cout << "\n\tProfit       : " << profit :
        cout << "\n\tLoss         : " << abs(profit);
}



void Challenge3()
{
    const int size = 4;
    CompanyData company[size];

    do
    {
        system("cls");
        cout << "\n\tChallenge 3. Corporate Sales Data\n";

        switch (subMenuOption())
        {
        case 1:
        {
            for (int i = 0; i < size; i++)
            {
                cout << "\nEnter the information for division "; DivisionName(static_cast<Division>(i));
                inputDivision(company[i]);
                cout << "\n";
            }

            for (int i = 0; i < size; i++)
            {
                cout << "\nThe sale of division "; DivisionName(static_cast<Division>(i));
                displayDivision(company[i]);
                cout << "\n";
            }
            break;
        }
        case 0:
            return;
        }

    } while (true);

}

//inputDivision take in CompanyData object's information for quarter sales
void inputDivision(CompanyData& s)
{
    s.firstQuaterSale = inputDouble("\n\tEnter the first quater sale : ", true);
    s.secondQuaterSale = inputDouble("\n\tEnter the second quater sale : ", true);
    s.thirdQuaterSale = inputDouble("\n\tEnter the third quater sale : ", true);
    s.fourthQuaterSale = inputDouble("\n\tEnter the fourth quater sale: ", true);

    s.annualSales = s.firstQuaterSale + s.secondQuaterSale + s.thirdQuaterSale + s.fourthQuaterSale;
    s.averageSales = s.annualSales / 4.0;
}

void displayDivision(CompanyData s)
{
    cout << fixed << setprecision(2) << showpoint;
    cout << "\n\tFirst Quater Sales : " << s.firstQuaterSale;
    cout << "\n\tSecond Quater Sales: " << s.secondQuaterSale;
    cout << "\n\tThird Quater Sales : " << s.thirdQuaterSale;
    cout << "\n\tFourth Quater Sales: " << s.fourthQuaterSale;
    cout << "\n\tTotal Sales        : " << s.annualSales;
    cout << "\n\tAverage Sales      : " << s.averageSales;
}

// Display corresponding name of the enum Division
void DivisionName(Division name)
{
    switch (name)
    {
    case EAST: cout << "East"; break;
    case WEST: cout << "West"; break;
    case NORTH: cout << "North"; break;
    case SOUTH: cout << "South"; break;
    }
}



void Challenge5()
{
    const int size = 12;
    Weather weather[size];

    Month month;

    do
    {
        system("cls");
        cout << "\n\t Challenge 5. Weather Statistics Modification\n";

        switch (subMenuOption())
        {
        case 1:
        {
            for (month = JANUARY; month <= DECEMBER; month = static_cast<Month> (month + 1))
            {
                cout << "\nEnter the following information for "; MonthName(month);
                inputWeather(weather[static_cast<int>(month)]);
            }

            // The vector will store the index of the months occur highest temp
            vector <int> MonthHighTemp;

            double highestTemp = findHighestTemp(weather, size, MonthHighTemp);

            cout << "\nThe highest temperature for the year: " << highestTemp << " which occured in ";

            for (int i = 0; i < MonthHighTemp.size(); i++)
            {
                MonthName(static_cast<Month>(MonthHighTemp[i])); cout << " ";
            }
            cout << "\n";

            // The vector will store the index of the months occur lowest temp
            vector <int> MonthLowTemp;

            double lowestTemp = findLowestTemp(weather, size, MonthLowTemp);

            cout << "\nThe lowest temperature for the year: " << lowestTemp << " which occured in ";

            for (int i = 0; i < MonthLowTemp.size(); i++)
            {
                MonthName(static_cast<Month>(MonthLowTemp[i])); cout << " ";
            }
            cout << "\n";

            // Display the total and average rainfall
            double totalRainfall = 0.0;
            double avgRainfall = 0.0;
            double avgTemp = 0.0;

            for (int i = 0; i < size; i++)
            {
                totalRainfall += weather[i].rainFall;
                avgTemp += weather[i].avgTemp;
            }

            avgTemp = avgTemp / size;

            avgRainfall = totalRainfall / size;

            //Display
            cout << "\nThe total rainfall             : " << totalRainfall;
            cout << "\nThe monthly rainfall           : " << avgRainfall;
            cout << "\nThe monthly average temperature: " << avgTemp;
            break;
        }
        case 0:
            return;
    }
    } while (true);
}

void inputWeather(Weather& s)
{
    s.highTemp= inputDouble("\n\tEnter the highest temperature: ", -100.0, 140.0);
    s.lowTemp = inputDouble("\n\tEnter the lowest temperature: ", -100.0,s.highTemp);
    s.rainFall = inputDouble("\n\tEnter the rainfall: ", true);
    s.avgTemp = (s.highTemp + s.lowTemp) / 2.0;
}

// Find the highest temperature in the array and the position
double findHighestTemp(Weather s[], int size, vector<int>& index)
{
    double highest = s[0].highTemp;

    for (int i = 0; i < size; i++)
    {
        if (s[i].highTemp > highest)
        {
            highest = s[i].highTemp;
            index.clear();          // Clear the value of vector each time the new highest value is found
            index.push_back(i);     // Store the index of the highest temperature 
        }
        else if (s[i].highTemp == highest)
        {
            index.push_back(i);
        }
    }

    return highest;
}

// Find the lowest temperature in the array and the position
double findLowestTemp(Weather s[], int size, vector <int>& index)
{
    double lowest = s[0].lowTemp;

    for (int i = 0; i < size; i++)
    {
        if (s[i].lowTemp < lowest)
        {
            lowest = s[i].lowTemp;
            index.clear();          // Clear the value of vector each time the new lowest value is found
            index.push_back(i);     // Store the index of the highest temperature 
        }
        else if (s[i].lowTemp == lowest)
        {
            index.push_back(i);
        }
    }

    return lowest;
}

// Display corresponding name of the enum Month
void MonthName(Month name)
{
    switch (name)
    {
    case JANUARY:   cout << "January"; break;
    case FEBRUARY:  cout << "February"; break;
    case MARCH:     cout << "March"; break;
    case APRIL:     cout << "April"; break;
    case MAY:       cout << "May"; break;
    case JUNE:      cout << "June"; break;
    case JULY:      cout << "July"; break;
    case AUGUST:    cout << "August"; break;
    case SEPTEMBER: cout << "September"; break;
    case OCTOBER:   cout << "October"; break;
    case NOVEMBER:  cout << "November"; break;
    case DECEMBER:  cout << "December"; break;
    }
}



void Challenge6()
{
    const int size = 12;
    Player player[12];
    double totalScore = 0.0;

    system("cls");
    cout << "\n\tChallenge 6. Soccer Scores";

    switch (subMenuOption())
    {
    case 1:
    {
        for (int i = 0; i < size; i++)
        {
            cout << "\n\tEnter the following information for player[" << (i + 1) << "]";
            inputPlayer(player[i]);
            totalScore += player[i].score;
        }
        cout << "\n";

        // The vector that stores players has highest pointed score 
        vector<int> index;

        double highestScore = findHighestScore(player, size, index);

        // Display the table information of player
        for (int i = 0; i < size; i++)
        {
            cout << "\nThe information of player[" << (i + 1) << "]";
            displayPlayer(player[i]);
        }

        cout << "\n";
        cout << "\n\tThe total team score  :" << totalScore;

        // Display player whose achived highest score
        cout << "\n\tThe highest score     :" << highestScore << " earned by ";
        for (int i = 0; i < index.size(); i++)
        {
            cout << "\n\tPlayer[" << index[i] + 1 << "]: " << player[i].name << " " << player[i].number;
            cout << "\n";
        }
        cout << "\n";
        break;
    }
    case 0:
        return;
    }
}

//inputPlayer input player's information
void inputPlayer(Player& s)
{
    strcpy_s(s.name, inputString("\n\tEnter the player name: ", true).c_str());

    s.number = inputDouble("\n\tEnter the player number: ", true);

    s.score = inputDouble("\n\tEnter the pointed score by player: ", true);
}

//findHighestScore find the highest score and return the highest
double findHighestScore(Player s[], int size, vector<int>& index)
{
    double highest = s[0].score;

    for (int i = 0; i < size; i++)
    {
        if (s[i].score > highest)
        {
            highest = s[i].score;
            index.clear();          // Clear the value of vector each time the new highest value is found
            index.push_back(i);     // Store the index of the highest temperature 
        }
        else if (s[i].score == highest) 
        {
            index.push_back(i);     // Store the additional index of the highest temperature
        }
    }

    return highest;
}

//displayPlayer display the player's name, score and number
void displayPlayer(Player s)
{
    cout << "\n\tThe player name   :" << s.name;
    cout << "\n\tThe player number :" << s.number;
    cout << "\n\tThe player score  :" << s.score;
}



void Challenge8()
{
    Customer* ptr = nullptr;
    int size = 0;
    int Option = -1;

    do {
        system("cls");
        cout << "\n\tChallenge 8. Search Function for Customer Account Program";
        cout << "\n\t" << string(60, char(205));
        cout << "\n\t1. Enter the data into the array";
        cout << "\n\t2. Change the content";
        cout << "\n\t3. Display Data Stored";
        cout << "\n\t4. Search customer information by name";
        cout << "\n\t" << string(60, char(205));
        cout << "\n\t0. Return";
        switch (inputInteger("\nOption: ", 0, 4))
        {
        case 0: // Return to the main menu, also free the allocated memory
        {
           delete[] ptr;
           return;
        }

        case 1:
        {
            // Ask for the size for dynamically array
            size = inputInteger("\n\tEnter the number of customer: ", true);
            ptr = new Customer[size];

            // Got the input
            for (int i = 0; i < size; i++)
            {
                cout << "\n\tEnter the information for customer[" << i + 1 << "]: ";
                inputCustomer(ptr[i]);
                cout << "\n";
            }

            // Prompt the succesfful message
            cout << "\n\tAll the data are stored successfully";
            cout << "\n";
            system("pause");
        }
        break;
        case 2:
        {
            // In case the ptr are empty, return to the main menu
            if (ptr == nullptr)
            {
                cout << "\n\tThe data is empty";
                return;
            }

            int choice = -1;

            do
            {
                system("cls");

                int number = inputInteger("\n\tChoose the customer[] that you want to change information: ", 1, size);

                // The index that we deal with an array
                int index = number - 1;

                cout << "\n\tThe current information of customer#" << number;
                displayCustomer(ptr[index]);
                cout << "\n\t" << string(60, char(205));
                cout << "\n\tSelect the element that you want to change";
                cout << "\n\t1. Name";
                cout << "\n\t2. Address";
                cout << "\n\t3. City";
                cout << "\n\t4. State";
                cout << "\n\t5. Zip";
                cout << "\n\t6. Telephone";
                cout << "\n\t7. Account Balance";
                cout << "\n\t8. Last Payment Date";
                cout << "\n\t" << string(60, char(205));
                cout << "\n\t0. Return";

                switch (inputInteger("\n\tEnter your option: ", 0, 8))
                {
                case 0: return;
                case 1:
                    strcpy_s(ptr[index].name, inputString("\n\tEnter the customer name   : ", true).c_str()); 
                    break;
                case 2:
                    strcpy_s(ptr[index].address, inputString("\n\tEnter the customer address: ", true).c_str());
                    break;
                case 3:
                    strcpy_s(ptr[index].city, inputString("\n\tEnter the city            : ", true).c_str());
                    break;
                case 4:
                    strcpy_s(ptr[index].state, inputString("\n\tEnter the state           : ", true).c_str());
                    break;
                case 5:
                    strcpy_s(ptr[index].zip, inputString("\n\tEnter the zip             : ", true).c_str());
                    break;
                case 6:
                    strcpy_s(ptr[index].telephone, inputString("\n\tEnter the telephone       : ", true).c_str());
                    break;
                case 7:
                    ptr[index].accountBalance = inputDouble("\n\tEnter the account balance : ");
                    break;
                case 8:
                    strcpy_s(ptr[index].lastPaymentDate, inputString("\n\tEnter the lastPaymentDate : ", true).c_str());
                    break;
                }

                cout << "\n\tThe Customer Information after updated";
                displayCustomer(ptr[index]);

                cout << "\n";
                system("pause");

            } while (true);


            cout << "\n";
            system("pause");
        }
        break;
        case 3:
        {
            if (ptr == nullptr)
            {
                cout << "\n\tThe data is empty";
                return;
            }

            // Display all stored information
            for (int i = 0; i < size; i++)
            {
                cout << "\n\tThe information of customer[" << i + 1 << "] ";
                displayCustomer(ptr[i]);
                cout << "\n";
            }

            cout << "\n";
            system("pause");
        }
        break;
        case 4:
        {
            if (ptr == nullptr)
            {
                cout << "\n\tThe data is empty";
                return;
            }

            char nameSearch[100] = "unknown";

            strcpy_s(nameSearch,inputString("\n\tEnter the name to search: ", true).c_str());

            int count = 0;  // Count how many customer have the same name searched

            for (int i = 0; i < size; i++)
            {
                if (findOccurence(ptr[i], nameSearch))
                {
                    cout << "\n\tThe information of customer[" << i + 1 << "] ";
                    displayCustomer(ptr[i]);
                    cout << "\n";
                    count++;
                }

            }

            if (count == 0)
                cout << "\n\tThere are no customer who have the name " << nameSearch << " in array";

            cout << "\n";
            system("pause");

            break;
        }
        default: cout << "\n\tNot a valid option"; break;
        }
    } while (true);
}

//inputCustomer takes in customer object's data
void inputCustomer(Customer& s)
{
    strcpy_s(s.name,     inputString("\n\tEnter the customer name   : ", true).c_str());
    strcpy_s(s.address,  inputString("\n\tEnter the customer address: ", true).c_str());
    strcpy_s(s.city,     inputString("\n\tEnter the city            : ", true).c_str());
    strcpy_s(s.state,    inputString("\n\tEnter the state           : ", true).c_str());
    strcpy_s(s.zip,      inputString("\n\tEnter the zip             : ", true).c_str());
    strcpy_s(s.telephone,inputString("\n\tEnter the telephone       : ", true).c_str());

    s.accountBalance =   inputDouble("\nEnter the account balance : ");

    strcpy_s(s.lastPaymentDate,inputString("\nEnter the lastPaymentDate : ", true).c_str());
}

//displayCustomer display customer's information
void displayCustomer(Customer s)
{
    cout << "\n\tThe customer name     :" << s.name;
    cout << "\n\tThe customer address  :" << s.address;
    cout << "\n\tThe customer city     :" << s.city;
    cout << "\n\tThe customer state    :" << s.state;
    cout << "\n\tThe customer zip      :" << s.zip;
    cout << "\n\tThe customer phone    :" << s.telephone;
    cout << "\n\tThe customer balance  :" << s.accountBalance;
    cout << "\n\tThe customer pay date :" << s.lastPaymentDate;
}

//findOccurence find the cstring and return true or false to count
bool findOccurence(Customer s, char searched[])
{
    char* find = nullptr;

    // Searches for the first occurence, return a pointer to it, otherwise nullptr if not found
    find = strstr(s.name, searched);

    return (find != nullptr) ?  true : false;

}



void Challenge12()
{

    do
    {
        system("cls");
        cout << "\n\tChallenge 12.Course Grade\n";

        switch (subMenuOption())
        {
        case 1:
        {
            // Prompt the user the size of student and test for dynamically array
            int sizeStudent = inputInteger("\n\tEnter the number of the student: ", true);

            int sizeTest = inputInteger("\n\tEnter the number of the test: ", true);

            // An array of student 
            Student* student = new Student[sizeStudent];

            // An array of double that store test score for each student
            for (int i = 0; i < sizeStudent; i++)
            {
                student[i].test = new double[sizeTest];
            }

            // Enter the information for each student
            for (int i = 0; i < sizeStudent; i++)
            {
                cout << "\n\tEnter the information for student #" << i + 1;
                cout << "\n";
                inputStudent(student[i], sizeTest);
                cout << "\n";
            }

            // Display the information of each student
            for (int i = 0; i < sizeStudent; i++)
            {
                cout << "\n\tThe information of student #" << i + 1;
                displayStudentInformation(student[i]);
                cout << "\n";
            }

            delete[] student;
            break;
        }
        case 0:
            return;
        }
    } while (true);
}

//inputStudent input Student infomations
void inputStudent(Student& s, int sizeTest)
{

    strcpy_s(s.name, inputString("\n\tEnter the student name : ", true).c_str());
    strcpy_s(s.ID, inputString(  "\n\tEnter the student ID   : ", true).c_str());

    // Enter the grade for the number of test
    for (int i = 0; i < sizeTest; i++)
        s.test[i] = inputDouble("\n\tEnter the grade of test #" + to_string(i + 1) + ": ", 0.0, 100.0);

    double total = 0.0;

    for (int i = 0; i < sizeTest; i++)
        total += s.test[i];

    s.average = total / sizeTest;   // Calculate the average grade of the student

    if (s.average > 90)
        s.letter = 'A';
    else if (s.average > 81 && s.average <= 90)
        s.letter = 'B';
    else if (s.average > 71 && s.average <= 80)
        s.letter = 'C';
    else if (s.average > 61 && s.average <= 70)
        s.letter = 'D';
    else
        s.letter = 'F';

}

//displayStudentInformation display Student informations
void displayStudentInformation(Student s)
{
    // Display each information for the Student object
    cout << "\n\tStudent name : " << s.name;
    cout << "\n\tStudent ID   : " << s.ID;
    cout << "\n\tAerage score : " << s.average;
    cout << "\n\tCourse Grade : " << s.letter;
}
