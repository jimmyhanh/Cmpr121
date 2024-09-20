//Hung Anh Ho
//9-24-2023
//Chapter 12

#include <iostream>
#include "input.h"
#include <fstream>
#include <cstring>
#include <iomanip>
#include <vector>
using namespace std;

int menuOption();
int subMenuOption();

void Challenge7();
void toUpperFile();


void Challenge11();
void dataOutput();
//Struct for tempolary data store

struct Inventory
{
	char description[100] = "unknown";
	int quantity = 0;
	double wholeSalesCost = 0.0;
	double retailCost = 0.0;
	char dateAdded[13] = "unknown";
};

//Struc for company
struct company
{
	//Variable declaration
	char divisionName[19] = "unknown";
	int quarter = 0;
	double quarterlySales = 0.0;
};


void Challenge12();
//void readSales();
void readFile();
void inputDivisionInfo(company* , string);
void displayCompanyDivision(company*);
double getYearlySaleOfEachDivision(company*);

void Challenge13();

struct inventory
{
	char description[100] = "unknown";
	int quantity = 0;
	double wholeSalesCost = 0.0;
	double retailCost = 0.0;
	char dateAdded[13] = "unknown";
};

void addRecord();
void displayRecord();
void changeRecord();
int getNumberOfRecords(fstream&);

//Validate date
string inputDate(string);
string dateFormatValidation(string);
void split(const string&, char, vector<string>&);
bool isLeapYear(int);
int getMaxDaysInMonth(int, int);

void Challenge14();

int main()
{
	do
	{
		system("cls");
		switch (menuOption())
		{
		case 0: exit(1); break;
		case 7: Challenge7(); break;
		case 11: Challenge11(); break;
		case 12: Challenge12(); break;
		case 13: Challenge13(); break;
		case 14: Challenge14(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return EXIT_SUCCESS;
}

//Menu
int menuOption()
{
	int n = 60;
	cout << "\n\tChapter 12 - assignments by Hung Anh Ho";
	cout << "\n\t" << string(n, char(205));
	cout << "\n\t7. Sentence Filter";
	cout << "\n\t11. Coperate Sales Data Output";
	cout << "\n\t12. Coperate Sales Data Input";
	cout << "\n\t13. Inventory Program";
	cout << "\n\t14. Inventory Screen Report";
	cout << "\n\t" << string(n, char(196));
	cout << "\n\t0. exit";
	cout << "\n\t" << string(n, char(205));
	cout << "\n";
	return inputInteger("\n\tOption: ", 0, 14);
}

//Sub menu options
int subMenuOption()
{
	cout << "\n\t" + string(60, char(205));
	cout << "\n\t1. Challenge";
	cout << "\n\t2. Size of structure for challenge";
	cout << "\n\t0. return";
	cout << "\n\t" + string(60, char(205));

	return inputInteger("\n\tOption: ", 0, 2);
}




//Challenge 7--------------------------------------------------------------------------------------------------------------------------------------
void Challenge7()
{
	do
	{
		system("cls");
		cout << "\n\t7. Sentence Filter";

		if (subMenuOption() == 1)
		{
			toUpperFile();
		}
		else if(subMenuOption() == 1)
		{
			cout << "\n\tDon't have a structure for this one.\n";
		}
		else
			break;

	} while (true);
}

//Change the first letter uppercase in every sentence
void toUpperFile()
{
	char ch = ' ';

	// Display message to enter input filename
	string inputName = inputString("\n\tEnter input file name: ", true);

	// Display message to enter output filename
	string outputName = inputString("\n\tEnter output file name: ", true);

	// Define input/output files and open
	ifstream inputFile;
	inputFile.open(inputName, ios::in);

	ofstream outputFile;
	outputFile.open(outputName, ios::out);


	// Only convert, if the input and output file could be opened
	bool newSentence = true;

	if (inputFile) 
	{
		char ch;
		while (inputFile.get(ch)) 
		{
			//Recognise the delimiter
			if (ispunct(ch) || ch == '\n' && ch != ',')
			{
				newSentence = true;
			}
			if (isalpha(ch)) 
			{
				if (newSentence) 
				{
					ch = toupper(ch);
					newSentence = false;
				}

				else 
				{
					ch = tolower(ch);
				}
			}
			outputFile.put(ch);
		}
		cout << "\n\tFile conversion program complete\n";
	}

	else 
	{
		cout << "\n\tCannot open file\n";
	}

	// Close files
	inputFile.close();
	outputFile.close();
}




//Challenge 11--------------------------------------------------------------------------------------------------------------------------------------
void Challenge11()
{
	do
	{
		system("cls");
		cout << "\n\t11. Corporate Sales Data Output";
		if (subMenuOption() == 1)
		{
			dataOutput();
		}
		else if (subMenuOption() == 2)
		{
			cout << "Size of company structure: " << sizeof(company) << "\n";
		}
		else
			break;

	} while (true);
}

//dataOutput get input for output sales.dat
void dataOutput()
{
	system("cls");
	cout << "\n\t11. Corporate Sales Data Output.";
	cout << "\n\t" << string(80, char(205));

	// Create 4 array objects of CompanyDivision, each one has 4 elements for each quaters:
	company divisionEast[4];
	company divisionWest[4];
	company divisionSouth[4];
	company divisionNorth[4];


	// Prompt the users to input data for each divison
	inputDivisionInfo(divisionEast , "East");
	inputDivisionInfo(divisionWest , "West");
	inputDivisionInfo(divisionSouth , "South");
	inputDivisionInfo(divisionNorth , "North");

	//Validate and create a binary output File
	fstream outputFile("Sales.dat", ios::out | ios::binary);

	// Writing Data to binary file:
	outputFile.write(reinterpret_cast<char*>(divisionEast), sizeof(divisionEast));
	outputFile.write(reinterpret_cast<char*>(divisionWest), sizeof(divisionWest));
	outputFile.write(reinterpret_cast<char*>(divisionSouth), sizeof(divisionSouth));
	outputFile.write(reinterpret_cast<char*>(divisionNorth), sizeof(divisionNorth));

	//Output successful message
	cout << "\n\tData has been written to Sales.dat.\n\n";

	//Close to save
	outputFile.close();
}

//inputDivisionInfo function prompts the user to input information for company divisions
void inputDivisionInfo(company* division, string divisionName)
{
	const string numQuarter[4] = { "1st", "2nd", "3rd", "4th" };

	cout << "\n\tDivision " << divisionName << "\n";
	for (int i = 0; i < 4; i++)
	{
		strcpy_s(division[i].divisionName, divisionName.c_str());
		division[i].quarter = i + 1;
		division[i].quarterlySales = inputDouble("\tEnter the sale of the " + numQuarter[i] + " quater (0 - 99999): $ ", 0.0, 99999.0);
	}
	cout << "\t" << string(80, char(196));
}


//Challenge 12--------------------------------------------------------------------------------------------------------------------------------------
void Challenge12()
{
	do
	{
		system("cls");
		cout << "\n\t12. Coperate Sales Data Input";
		if (subMenuOption() == 1)
		{
			readFile();
		}
		else if (subMenuOption() == 2)
		{
			cout << "Size of company structure: " << sizeof(company) << "\n";
		}
		else
			break;

	} while (true);
}

//readSales read file from challenge 11 and return the sales
/* Failed test
void readSales()
{
	company Sales;
	double TotalCorporateSalesQuarterly[4] = {0,0,0,0}; // Total corporate sales for each quarter
	double TotalYearlyPerDivision[4] = {0,0,0,0}; // Total yearly sales for each division
	double TotalYearlyCoporate = 0.0; // Total yearly corporate sales
	double Highest = 0.0;
	double Lowest = 0.0;

	system("cls");
	cout << "\n\t12. Coperate Sales Data Input";

	//Open file
	string filename = inputString("\n\tEnter a file name (Sales.dat) : ", true);
	fstream inputFile(filename.c_str(), ios::in | ios::binary);

	//Validate
	inputFile.read(reinterpret_cast<char*>(&Sales), sizeof(Sales));
	if (!inputFile)
	{
		cout << "\n\tError opening file. Program aborting.\n";
		return;
	}

	// Display sales figures.
	cout << fixed << showpoint << setprecision(2);
	cout << "\n\tCorporate Sales Data Report"
		<< "\n\t---------------------------";
	cout << "\n\tTotal sales by division:\n";


	// Until the end of the file
	//while (!inputFile.eof())
	//{
		//Display sales for each division
		for (int d = 0; d < 4; d++)
		{
			inputFile.read(reinterpret_cast<char*>(&Sales), sizeof(Sales));
			cout << "\n\t" << Sales.DivisionName[d] << ":";
			//Display yearly sales for each division
			for (int q = 0; q < 4; q++)
			{
				TotalYearlyPerDivision[d] += Sales.quarterlySales[q];
				TotalCorporateSalesQuarterly[q] += Sales.quarterlytSales[q];
			}

			cout << "\n\tTotal yearly sales per division: $" << TotalYearlyPerDivision[d] << "\n";


			//Display the average quarterly sales for each division
			cout << "\tAverage quarterly sales : $" << TotalYearlyPerDivision[d] / 4 << "\n";
			TotalYearlyCoporate += TotalYearlyPerDivision[d];
		}
	//}
		//Display the corporate quarterly sales
		cout << "\n\tTotal corporate sales for each quarter:";
		for (int i = 0; i < 4; i++)
		{
			cout << "\n\tQuarter " << (i + 1) << ": $" << TotalCorporateSalesQuarterly[i];
		}

		cout << "\n\tTotal yearly corporate sales: $" << TotalYearlyCoporate;

		//The display highest and lowest corporate quarter
		Highest = TotalCorporateSalesQuarterly[0];
		Lowest = TotalCorporateSalesQuarterly[0];
		for (int i = 1; i < 4; i++)
		{
			//Highest
			if (TotalCorporateSalesQuarterly[i] > Highest)
				Highest = TotalCorporateSalesQuarterly[i];

			//Lowest
			if (TotalCorporateSalesQuarterly[i] < Lowest)
				Lowest = TotalCorporateSalesQuarterly[i];
		}

		//Display the highest and lowest
		cout << "\n\tThe highest quarter for the corporation: " << Highest;
		cout << "\n\tThe lowest quarter for the corporation: " << Lowest << "\n";

	inputFile.close();
}
*/

//readFile read file from challenge 11 and return the sales
void readFile()
{
	system("cls");
	cout << "\n\t12. Corporate Sales Data Input.";
	cout << "\n\t" << string(80, char(205));

	//Open a binary input file:
	cout << "\n\n\tData from Sales.dat file.\n";

	fstream inputFile("Sales.dat", ios::in, ios::binary);

	//Create 4 array objects of CompanyDivision and 4 elements for each quaters:
	company divisionEast[4];
	company divisionWest[4];
	company divisionSouth[4];
	company divisionNorth[4];

	// Read Data from binary file to each Companydivison pointers :
	inputFile.read(reinterpret_cast<char*>(divisionEast), sizeof(divisionEast));
	inputFile.read(reinterpret_cast<char*>(divisionWest), sizeof(divisionWest));
	inputFile.read(reinterpret_cast<char*>(divisionSouth), sizeof(divisionSouth));
	inputFile.read(reinterpret_cast<char*>(divisionNorth), sizeof(divisionNorth));

	// Calculate the total quarterly sale of each quarter:
	double quarterSaleOfEachQuarter[4]{};
	for (int i = 0; i < 4; i++)
	{
		quarterSaleOfEachQuarter[i] = divisionEast[i].quarterlySales + divisionWest[i].quarterlySales
			+ divisionSouth[i].quarterlySales + divisionNorth[i].quarterlySales;
	}

	double lowestQuarter = quarterSaleOfEachQuarter[0];
	int indexLowestQuarter = 0;
	double highestQuater = quarterSaleOfEachQuarter[0];
	int indexHighestQuarter = 0;
	for (int i = 0; i < 4; i++)
	{
		if (quarterSaleOfEachQuarter[i] <= lowestQuarter)
		{
			lowestQuarter = quarterSaleOfEachQuarter[i];
			indexLowestQuarter = i + 1;
		}

		if (quarterSaleOfEachQuarter[i] >= lowestQuarter)
		{
			highestQuater = quarterSaleOfEachQuarter[i];
			indexHighestQuarter = i + 1;
		}
	}

	double totalYearlySalesOfTheCorporate = getYearlySaleOfEachDivision(divisionEast) + getYearlySaleOfEachDivision(divisionWest)
		+ getYearlySaleOfEachDivision(divisionSouth) + getYearlySaleOfEachDivision(divisionNorth);

	cout << fixed << setprecision(4);

	cout << "\n\tAnnual report: \n";
	cout << "\tDivision\t\tQuarter\t\tSales\n";
	displayCompanyDivision(divisionEast);
	displayCompanyDivision(divisionWest);
	displayCompanyDivision(divisionSouth);
	displayCompanyDivision(divisionNorth);
	cout << "\t" << string(80, char(205)) << "\n\n";

	cout << "\tDetail: ";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\tTotal coporate sale of each quater: ";
	cout << "\n\tFirst Quarter : $ " << quarterSaleOfEachQuarter[0];
	cout << "\n\tSecond Quarter: $ " << quarterSaleOfEachQuarter[1];
	cout << "\n\tThird Quarter : $ " << quarterSaleOfEachQuarter[2];
	cout << "\n\tForth Quater  : $ " << quarterSaleOfEachQuarter[3];
	cout << "\n\t" << string(80, char(205));

	cout << "\n\tTotal yearly sale of each division: ";
	cout << "\n\tEast : $ " << getYearlySaleOfEachDivision(divisionEast);
	cout << "\n\tWest : $ " << getYearlySaleOfEachDivision(divisionWest);
	cout << "\n\tSouth: $ " << getYearlySaleOfEachDivision(divisionSouth);
	cout << "\n\tNorth: $ " << getYearlySaleOfEachDivision(divisionNorth);
	cout << "\n\t" << string(80, char(205));

	cout << "\n\tThe average sales of each division: ";
	cout << "\n\tEast : $ " << getYearlySaleOfEachDivision(divisionEast) / 4;
	cout << "\n\tWest : $ " << getYearlySaleOfEachDivision(divisionWest) / 4;
	cout << "\n\tSouth: $ " << getYearlySaleOfEachDivision(divisionSouth) / 4;
	cout << "\n\tNorth: $ " << getYearlySaleOfEachDivision(divisionNorth) / 4;
	cout << "\n\t" << string(80, char(205));

	cout << "\n\tTotal yearly sale of the corporate: $ " << totalYearlySalesOfTheCorporate;
	cout << "\n\tThe average sales of the corporate: $ " << totalYearlySalesOfTheCorporate / 4.0;
	cout << "\n\t" << string(80, char(205));

	cout << "\n\tThe quarter with a higest sale is Q" << indexHighestQuarter << " $ " << highestQuater << "";
	cout << "\n\tThe quarter with a lowest sale is Q" << indexLowestQuarter  << " $ " << lowestQuarter << "";
	cout << "\n\t" << string(80, char(205)) << "\n\n";

	//Close to save
	inputFile.close();
	//system("pause");
}

//displayCompanyDivision function display company divisions
void displayCompanyDivision(company division[])
{
	cout << "\t" << string(80, char(196)) << "\n";
	for (int i = 0; i < 4 ; i++) 
	{
		cout << "\t" << division[i].divisionName << "\t\t\t" << division[i].quarter << "\t\t$" << division[i].quarterlySales << "\n";
	}
}

//getYearlySaleOfEachDivisio function returns a total yearly sale of a given division
double getYearlySaleOfEachDivision(company* division)
{
	double yearlySales = 0;
	for (int i = 0; i < 4; i++)
	{
		yearlySales += division[i].quarterlySales;
	}
	return yearlySales;
}

//Tried and Failed
/*
void Challenge12()
{
	salesInfo eastDivision[4];
	salesInfo westDivision[4];
	salesInfo northDivision[4];
	salesInfo southDivision[4];

	system("cls");
	cout << "\n\t12. Coperate Sales Data Input\n";

	//Buffer used for reading
	salesInfo division;
	//Create and open file for writing
	fstream inputFile;
	inputFile.open("Sales.dat", ios::in|ios::binary);

	if (inputFile)
	{
		// Until the end of the file
		while (!inputFile.eof())
		{
			inputFile.seekp(0L, ios::beg);
			for (int count = 0; count < 4; count++)
			{
				inputFile.read(reinterpret_cast<char*>(&division[count]), sizeof(division[count]));
			}

			//Move pointer to beginning of file (data for EAST division)
			inputFile.seekg(0L, ios::beg);
			//Read data from file into array
			readFromFile(inputFile, eastDivision);
			//Get position is before data for West division
			readFromFile(inputFile, westDivision);
			//Get position is before data for North division
			readFromFile(inputFile, northDivision);
			//Get position is before data for South division
			readFromFile(inputFile, southDivision);
			//Display the corporate quarterly sales
			quarterlyTotal(eastDivision, westDivision, northDivision, southDivision);

			//Display yearly sales for each division
			cout << "\nTotal Yearly Sales\n";
			cout << "East Division: $"<<yearlySales(eastDivision) << "\n";
			cout << "West Division: $"<<yearlySales(westDivision) << "\n";
			cout << "North Division: $"<<yearlySales(northDivision) << "\n";
			cout << "South Division: $"<<yearlySales(southDivision) << "\n";

			//Display the total corporate yearly sales
			cout<<"Total Yearly Corporate Sales:\n";
			cout<<"$" << yearlySales(eastDivision) + yearlySales(westDivision) + yearlySales(northDivision) + yearlySales(southDivision) << "\n";
			//Display the average quarterly sales for each division
			cout<<"\nAverage quarterly sales:\n";
			cout<<"East division: $"<<averageQuarterlySales(eastDivision) << "\n";
			cout<<"West division: $"<<averageQuarterlySales(westDivision) << "\n";
			cout<<"North division: $"<<averageQuarterlySales(northDivision) << "\n"
			cout<<"South division: $"<<averageQuarterlySales(southDivision) << "\n";

			file.close();
			system("pause");
		}
	}
}

void quarterlyTotal(salesInfo east[], salesInfo west[], salesInfo north[], salesInfo south[])
{
	double quarterTotal = 0;
	//Variables to store highest and lowest sales per quarter
	double highest = 0;
	double lowest = 9999999999;

	//Variables to store highest/lowest quarters
	int high = 1, low =1;
	for(int count = 0; count < 4; count++)
	{
		cout << "Corporate total for Quarter " << count + 1<<": "; 
		quarterTotal += east[count].quarterlySales + west[count].quarterlySales + north[count].quarterlySales + south[count].quarterlySales;
		//Update highest and lowest sales values
		if(highest <quarterTotal)
		{
			highest = quarterTotal;
			high = count + 1;
		}
		if(lowest >quarterTotal)
		{
			lowest = quarterTotal;
			low = count + 1;
		}
		cout<<"$"<<quarterTotal<<endl;
		//Reset to 0
		quarterTotal = 0;
	}
	highestLowest(high, low);
}
//The function calculates the yearly sales
double yearlySales(company divison[])
{
	double yearly = 0;
	for(int count = 0; count < 4; count++)
	{
		yearly += divison[count].quarterlySales;
	}
	return yearly;
}

//The averageQuarterlySales function calculates the average quarterly sales
double averageQuarterlySales(company divisionNames[])
{
	double totalSales = 0;
	for(int count = 0; count < 4; count++)
	{
		totalSales += divisionNames[count].QuarterlytSales;
	}

	//Typecast to prevent integer division
	totalSales = (double)totalSales/4;
	return totalSales;
}

//The highestLowest function to display highest and lowest corporate quarter
void highestLowest(int high, int low)
{
	cout<<"\n\tHighest Corporate Quarter was Quarter " << high;
	cout<<"\n\tLowest Corporate Quarter was Quarter" << low << "\n";
}
*/




//Challenge 13--------------------------------------------------------------------------------------------------------------------------------------
void Challenge13()
{
	fstream file;
	Inventory item;
	do
	{
		system("cls");
		cout << "\n\tInventory Menu";
		cout << "\n\t" << string(60, char(196));
		cout << "\n\t0. return";
		cout << "\n\t1. get sizeof(structure)";
		cout << "\n\t2. Add new record the file";
		cout << "\n\t3. Display any record in the file";
		cout << "\n\t4. Change any record in the file";
		cout << "\n\t" << string(60, char(196));
		cout << "\n";

		switch((inputInteger("\n\toption: ", 0, 4)))
		{
			case 0: return;
			case 1:
			{
				cout << "\nsizeof(Inventory): " << sizeof(Inventory) << '\n';
				break;
			}

			case 2:
			{
				addRecord();
				break;
			}

			case 3:
			{
				displayRecord();
			}

			case 4:
			{
				changeRecord();
				break;
			}

			break;
			}
		cout << "\n";
		system("pause");

	} while (true);
}

//addRecord function adds record to the destinated output file
void addRecord()
{
	system("cls");
	cout << "\n\t13. Inventory Program.";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t1. Add Record: \n";

	Inventory inventory;
	// Prompting
	strcpy_s(inventory.description, inputString("\n\tEnter the item description: ", true).c_str());
	inventory.quantity = inputInteger("\tEnter the quantity of the item (0...100): ", 0, 100);
	inventory.wholeSalesCost = inputDouble("\tEnter the wholesales cost (0...10000): $", 0.0, 10000.00);
	inventory.retailCost = inputDouble("\tEnter the retail cost: $", 0.0, 10000.00);
	strcpy_s(inventory.dateAdded, inputDate("\tEnter the date added: ").c_str());

	// Create and open an output File
	fstream outFile("inventory.dat", ios::out | ios::binary | ios::app);

	// Write data into output file
	outFile.write(reinterpret_cast<char*>(&inventory), sizeof(inventory));

	cout << "\n\tData has been written to inventory.dat succesfully\n\n";

	// Close the file:
	outFile.close();
}

//CheckDate function check length of the date string (This is the only condition that immediately returns the result in case the validity check fails)
string inputDate(string prompt)
{
	string date = "";
	do
	{
		cout << prompt;
		getline(cin, date);
		if (dateFormatValidation(date) != "") // Validate date format.
			cout << dateFormatValidation(date);
		else
			break;
	} while (true);

	return date;
}

//dateFormatValidation function validates the user's input for date in form mm/dd/yyyy
string dateFormatValidation(string date)
{
	if (date.length() != 10) // Because mm / dd / yyyy has 10 characters
		return "\tERROR: your date has to be in form mm/dd/yyyy\n";
	else if (date[2] != '/' && date[5] != '/')
		return "\tERROR: your date has to be in form mm/dd/yyyy\n";
	// Check if "mm", "dd", and "yyyy" is all digit
	else if (!isdigit(date[0]) || !isdigit(date[1]) || !isdigit(date[3]) || !isdigit(date[4]) ||
		!isdigit(date[6]) || !isdigit(date[7]) || !isdigit(date[8]) || !isdigit(date[9]))
		return "\tERROR: your date has to be in form mm/dd/yyyy\n";
	else
	{
		// Vector to hold the tokens
		vector<string> tokens;

		split(date, '/', tokens);
		// Now the vector must contain {"mm", "dd", "yyyy"}
		// We need to validate those element: month (1-12), day (1-29,30, or 31), year(1930, 2030)
		int month = stoi(tokens.at(0));
		int day = stoi(tokens.at(1));

		int year = stoi(tokens.at(2));

		// validate year:
		if (year < 1930 || year > 2022)
			return "\tERROR: year has to be from range 1930 to 2022\n";

		// validate month:
		if (month < 1 || month > 12)
			return "\tERROR: month has to be from range 01 to 12\n";

		// validate day:
		if (day <1 || day > getMaxDaysInMonth(month, year))
			return "\tERROR: day has to be from range 01 to " + to_string(getMaxDaysInMonth(month, year)) + "\n";

		else
			return "";
	}
}

//split function splits a string in parts based on given delimiter, and put them into a string vector
void split(const string& myString, char delim, vector<string>& tokensVector)
{
	int tokenStart = 0; //Starting position of the next token

	// Find the first occurent of the delimiter
	int delimPosition = myString.find(delim);

	// While we haven't run out of delimiters...
	while (delimPosition != string::npos)
	{
		// Extract the token
		string token = myString.substr(tokenStart, (int)delimPosition - (int)tokenStart);

		// Push the token onto the tokens vector
		tokensVector.push_back(token);

		// Move the delimPosition to the next character position
		delimPosition++;

		// Move tokenStart to delimPosition
		tokenStart = delimPosition;

		// Find the next occurrence of the delimiter
		delimPosition = myString.find(delim, delimPosition);

		// If no more delimiter, extract the last token
		if (delimPosition == string::npos)
		{
			// Extract the token
			string token = myString.substr(tokenStart, (int)delimPosition - (int)tokenStart);

			// Push the token onto the vector
			tokensVector.push_back(token);
		}
	}
}

//isLeapYear function determines if a given year is a leap year: true if it's a leap year, false if it's not a leap year
bool isLeapYear(int year)
{
	return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
}

//getMaxDaysInMonth function returns a maximum number of days in a month
int getMaxDaysInMonth(int month, int year)
{
	if (month == 2)
	{
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else
		return 31;
}

//displayRecord display recorded information
void displayRecord()
{
	system("cls");
	cout << "\n\t13. Inventory Program.";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t2. Display Record: \n";

	// Create an input binary file
	fstream inputFile("inventory.dat", ios::in, ios::binary);

	// File validation:
	if (inputFile.fail()) // If the file does not exist
	{
		cout << "\n\tError: file inventory.dat does not exist. Please choose option 1. Add Records.\n";
		inputFile.close();
		return;
	}

	// Get the number of records:
	int numberOfRecords = getNumberOfRecords(inputFile);
	// Validation:
	if (numberOfRecords == 0)
	{
		cout << "\n\tError: the file is empty. Please choose option 1 to Add Records.\n";
		inputFile.close();
		return;
	}

	cout << "\n\tThe number of records is: " << numberOfRecords << "\n";

	// Output the records information:
	// Reset the buffer
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	Inventory inventory;
	for (int i = 0; i < numberOfRecords; i++)
	{
		inputFile.read(reinterpret_cast<char*>(&inventory), sizeof(inventory));
		cout << "\n\tRecord: #" << i + 1;
		cout << "\n\tItem's description: " << inventory.description;
		cout << "\n\tItem's quantity: " << inventory.quantity;
		cout << "\n\tItem's wholesale cost: $ " << inventory.wholeSalesCost;
		cout << "\n\tItem's retail cost: $ " << inventory.retailCost;
		cout << "\n\tItem's date added: " << inventory.dateAdded;
		cout << "\n\t" << string(80, char(196));
	}
	inputFile.close();
}

//getNumberOfRecords functions counts the number of records (structures) from a given binary file
int getNumberOfRecords(fstream &inputFile)
{
	Inventory inventory;
	int count = 0;
	while (!inputFile.eof())
	{
		count++;
		inputFile.read(reinterpret_cast<char*>(&inventory), sizeof(inventory));
	}

	return count - 1;
}

//The function to update/change the existing record
void changeRecord()
{
	system("cls");
	cout << "\n\t\t13. Inventory Program.";
	cout << "\n\t" << string(80, char(205));
	cout << "\n\t3. Change Record: \n";

	// Create an input binary file
	fstream file("inventory.dat", ios::in | ios::out | ios::binary);

	// File validation:
	if (file.fail()) // If the file does not exist
	{
		cout << "\n\tERROR: file inventory.dat does not exist. Please choose option 1.Add Record first to create that file.\n";
		file.close();
		return;
	}

	// Get the number of records:
	int numberOfRecords = getNumberOfRecords(file);

	// Validation:
	if (numberOfRecords == 0)
	{
		cout << "\n\tError: the file is empty. Please choose option 1.\n";
		file.close();
		return;
	}

	cout << "\n\tThere is " << numberOfRecords << " number of records in the inventory.dat file." << "\n";

	Inventory inventory;

	int chosenRecord = inputInteger("\tEnter record #number you want to adjust: ", 1, numberOfRecords);

	file.clear();
	file.seekg(static_cast<long>( (long long) sizeof(inventory) * (chosenRecord - 1)), ios::beg);
	file.read(reinterpret_cast<char*>(&inventory), sizeof(inventory));

	cout << "\n\tRecord: #" << chosenRecord;
	strcpy_s(inventory.description, inputString("\n\tEnter the item description: ", true).c_str());
	inventory.quantity = inputInteger("\tEnter the quantity of the item in range (0...100): ", 0, 100);
	inventory.wholeSalesCost = inputDouble("\tEnter the wholesales cost in range (0...50000): $", 0.0, 50000.00);
	inventory.retailCost = inputDouble("\tEnter the retail cost: $", 0.0, 50000.00);
	strcpy_s(inventory.dateAdded, inputDate("\tEnter the date added: ").c_str());

	file.seekg(static_cast<long>( (long long) sizeof(inventory) * (chosenRecord - 1)), ios::beg);
	file.write(reinterpret_cast<char*>(&inventory), sizeof(inventory));

	cout << "\t"<< string(80, char(196));
	cout << "\n\tThe record has been edited succesfully.";
	cout << "\n\tThe inventory.dat file has been updated.\n\n";

	// Close the file:
	file.close();
}



//Challenge 14--------------------------------------------------------------------------------------------------------------------------------------
void Challenge14()
{
	system("cls");
	cout << "\n\t\t14. Inventory Screen Report.";
	cout << "\n\t" << string(80, char(205));

	//Create an input binary file
	fstream inputFile("inventory.dat", ios::in | ios::binary);

	//File validation:
	if (inputFile.fail()) // If the file does not exist
	{
		cout << "\n\Error: file inventory.dat does not exist. Please choose option 13 to create one.\n";
		inputFile.close();
		return;
	}

	//Get the number of records:
	int numberOfRecords = getNumberOfRecords(inputFile);
	//Validation:
	if (numberOfRecords == 0)
	{
		cout << "\n\tError: the file is empty. Please choose option 13 to add new records.\n";
		inputFile.close();
		return;
	}

	//Reset the buffer
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);

	//Calculating the total quantity, wholesales and retail cost of the whole inventory
	Inventory inventory;
	int totalQuantity = 0;
	double totalWholesalesCost = 0.0;
	double totalRetailCost = 0.0;
	for (int i = 0; i < numberOfRecords; i++)
	{
		inputFile.read(reinterpret_cast<char*>(&inventory), sizeof(inventory));
		totalQuantity += inventory.quantity;
		totalWholesalesCost += inventory.wholeSalesCost;
		totalRetailCost += inventory.retailCost;
	}

	//Output the inventory report:
	cout << "\n\tInventory Report: ";
	cout << "\n\t" << string(60, char(196));
	cout << "\n\tThe total wholesale value in the inventory: $ " << totalWholesalesCost;
	cout << "\n\tThe total retail value in the inventory   : $ " << totalRetailCost;
	cout << "\n\tThe quantity of all items in the inventory: " << totalQuantity;
	cout << "\n\t" << string(60, char(196));

	//Close the file:
	inputFile.close();
}

