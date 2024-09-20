// Name: Hung Anh Ho
// Date: 10/31/2023
// Description: Chapter 15 - Assignment

#include <iostream>
#include "input.h"
#include "Employee.h"
#include "ProductionWorker.h"
#include "TeamLeader.h"
#include "MilTime.h"
#include "Essay.h"
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"
#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

int menuOption();
void Challenge3();
void Challenge4();
void Challenge6();
void Challenge7();
void Challenge8();
void Challenge12();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 3: Challenge3(); break;
        case 4: Challenge4(); break;
        case 6: Challenge6(); break;
        case 7: Challenge7(); break;
        case 8: Challenge8(); break;
        case 12: Challenge12(); break; // 10pts extra
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
    cout << "\n\tChapter 15 - assignments";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t0. exit";
    cout << "\n\t3. TeamLeader class";
    cout << "\n\t4. Time format";
    cout << "\n\t6. Essay class";
    cout << "\n\t7. PersonData and CustomerData class"; 
    cout << "\n\t8. Preferred Customer class";
    cout << "\n\t12.Ship, CruiseShip CargoShip Classes";
    cout << "\n\t" << string(60, char(196));
    return inputInteger("\n\tOption: ", 0, 12);
}

void Challenge3()
{
    // Instaniate the employee object
    Employee employee1;

    employee1.setName(inputString("\n\tEnter employee name: ", true));
    employee1.setEmployeeNumber(inputInteger("\n\tEnter employee number: ", true));
    employee1.setHireDate(inputString("\n\tEnter employee hire date: ", true));

    cout << "\n\tInformation of employee: ";
    cout << employee1 << "\n";

    //Instaniate the worker object
    ProductionWorker worker1;

    worker1.setName(inputString("\n\tEnter worker name: ", true));
    worker1.setEmployeeNumber(inputInteger("\n\tEnter worker number: ", true));
    worker1.setHireDate(inputString("\n\tEnter worker hire date: ", true));
    worker1.setHourlyPayRate(inputDouble("\n\tEnter worker pay rate: ", true));
    worker1.setShift(inputInteger("\n\tEnter worker shift (1 - Dayshift, 2 - Nightshift): ",1,2));

    cout << "\n\tInformation of worker: ";
    cout << worker1 << "\n";

    //Instaniatate the teamLeader object
    TeamLeader leader1;

    leader1.setName(inputString("\n\tEnter leader name: ", true));
    leader1.setEmployeeNumber(inputInteger("\n\tEnter leader number: ", true));
    leader1.setHireDate(inputString("\n\tEnter leader hire date: ", true));
    leader1.setHourlyPayRate(inputDouble("\n\tEnter leader pay rate: ", true));
    leader1.setShift(inputInteger("\n\tEnter working shift (1 - Dayshift, 2 - Nightshift): ",1,2));
    leader1.setBonusAmount(inputDouble("\n\tEnter bonus amount: ", true));
    leader1.setRequiredTrainingHours(inputInteger("\n\tEnter required training hour: ", true));
    leader1.setAttendedTrainingHours(inputInteger("\n\tEnter attendant training hour: ", leader1.getRequiredTrainingHours(), 1000));

    cout << "\n\tInformation of leader: ";
    cout << leader1 << "\n";
}

void Challenge4()
{
    //Create the MilTime object
    MilTime test1;

    //Validate the input
    int milHour = inputInteger("\n\tEnter the hour in military format (1.00pm - 1300):  ", 0, 2359);

    //If minute is invalid format, minute will become 0
    if (milHour % 100 > 59)
    {
        cout << "\n\tERROR: Invalid minute. Will convert the minute to 0\n" ;
        milHour = milHour - (milHour % 100);
    }

    int milSecond = inputInteger("\n\tEnter the seconds (0...59):  ", 0, 59);

    //Set the time
    test1.setTime(milHour, milSecond);

    cout << test1;
}

void Challenge6()
{
    Essay test1;

    test1.setGrammarScore(inputDouble("\n\tEnter the score for grammar: ", 0.0, 30.0));
    test1.setSpellingScore(inputDouble("\n\tEnter the score for spelling: ", 0.0, 20.0));
    test1.setLengthScore(inputDouble("\n\tEnter the score for length: ", 0.0, 20.0));
    test1.setContentScore(inputDouble("\n\tEnter the score for content: ", 0.0, 30.0));
    test1.setScore();
    cout << test1;
}

void Challenge7()
{
    PersonData person;

    person.setFirstName(inputString("\n\tEnter the person first name: ", true));
    person.setLastName(inputString("\n\tEnter the person last name: ", true));
    person.setAddress(inputString("\n\tEnter the person address: ", true));
    person.setCity(inputString("\n\tEnter the person city: ", true));
    person.setState(inputString("\n\tEnter the person state: ", true));
    person.setZip(inputString("\n\tEnter the person zip: ", true));
    person.setPhone(inputString("\n\tEnter the person phone: ", true));

    cout << person << "\n\n";

    CustomerData customer;
 
    customer.setFirstName(inputString("\n\tEnter the customer first name: ", true));
    customer.setLastName(inputString("\n\tEnter the customer last name: ", true));
    customer.setAddress(inputString("\n\tEnter the customer address: ", true));
    customer.setCity(inputString("\n\tEnter the customer city: ", true));
    customer.setState(inputString("\n\tEnter the customer state: ", true));
    customer.setZip(inputString("\n\tEnter the customer zip: ", true));
    customer.setPhone(inputString("\n\tEnter the customer phone: ", true));
    customer.setCustomerNumer(inputInteger("\n\tEnter the customer number: ", true ));

    char choice = toupper(inputChar("\n\tEnter T if customer want to be on Mailing List or F if customer did not: ", static_cast <string>("TF")));

    choice == 'T' ? customer.setMailingList(true) : customer.setMailingList(false);

    cout << customer << "\n";

}

void Challenge8()
{
    PreferredCustomer customer;

    //Input
    customer.setFirstName(inputString("\n\tEnter the customer first name: ", true));
    customer.setLastName(inputString("\n\tEnter the customer last name: ", true));
    customer.setAddress(inputString("\n\tEnter the customer address: ", true));
    customer.setCity(inputString("\n\tEnter the customer city: ", true));
    customer.setState(inputString("\n\tEnter the customer state: ", true));
    customer.setZip(inputString("\n\tEnter the customer zip: ", true));
    customer.setPhone(inputString("\n\tEnter the customer phone: ", true));
    customer.setCustomerNumer(inputInteger("\n\tEnter the customer number: ", true));

    char choice = toupper(inputChar("\n\tEnter T if customer want to be on Mailing List or F if customer did not: ", static_cast <string>("TF")));
    choice == 'T' ? customer.setMailingList(true) : customer.setMailingList(false);

    customer.setPurchaseAmount(inputDouble("\n\tEnter the purchase amount: ", true));

    //output
    cout << customer << "\n";
}

void Challenge12()
{
    Ship* ships[3] = { new Ship(), new CruiseShip(), new CargoShip() };

    //Input
    ships[0]->setName(inputString("\tEnter ship's name (Ex: Nautilus) : ", true));
    ships[0]->setYear(inputInteger("\tEnter ship's make (Ex: 1999) : ", 1000, 3000));

    dynamic_cast<CruiseShip*>(ships[1])->setName(inputString("\tEnter ship's name (Ex: Tiatanic) : ", true));
    dynamic_cast<CruiseShip*>(ships[1])->setYear(inputInteger("\tEnter ship's make (Ex: 1911) : ", 1000, 3000));
    dynamic_cast<CruiseShip*>(ships[1])->setMaxPassengers(inputInteger("\tEnter ship's passengers (Ex: 2700) : ", 0, 5000));

    dynamic_cast<CargoShip*>(ships[2])->setName(inputString("\tEnter ship's name (Ex: Madrid Maersk) : ", true));
    dynamic_cast<CargoShip*>(ships[2])->setYear(inputInteger("\tEnter ship's make (Ex: 2017) : ", 1000, 3000));
    dynamic_cast<CargoShip*>(ships[2])->setMaxCapacity(inputInteger("\tEnter ship's capacity (Ex: 20,568) : ", 0, 99999));

    //output
    for (int s = 0; s < 3; s++)
    {
        cout << '\n';
        ships[s]->print();
    }
}