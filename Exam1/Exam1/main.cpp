//Hung Anh Ho
//09/29/2023
//Exam 1 - PERIODIC TABLE OF ELEMENTS BY SYMBOL

#include <Windows.h>
#include <iostream>
#include "input.h"
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct ChemistryElement
{
	int atomicNumber = 0;
	double atomicMass = 0.0;
	char symbol[3] = "no";
	char name[25] = "unknown";
	int standardState = 0; 
	int chemicalGroupBlock = 0;	
	double meltingPoint = 0.0;	// Hold K degrees
	double boilingPoint = 0.0;	// Hold K degrees
	int yearDiscovered = 0;		
	char Discoverers[100] = "unknown";
};

// Function Prototype
void displayTable();
char menuOption();

bool BinarySpecified(bool specified);
double KtoC(double);			// Convert K to C degree
void GroupBlockName(int);		// Convert int to corressponding Group Block
void StandardStateName(int );	// Convert int to corressponding Standard State
int EditmenuProperty();										// The menu of edit property
ChemistryElement changeElementProperty(ChemistryElement&);	// To change the element property

void swap();
void selectionSort(ChemistryElement* array, int size);

void ChallengeA();
int menuOptionA();
void displayElementA(ChemistryElement, int);

void ChallengeB();
int menuOptionB();
void displayElementB(ChemistryElement, int);

void ChallengeC();
int menuOptionC();
void displayElementC(ChemistryElement, int);

int main()
{
	do
	{
		switch (menuOption())
		{
		case 'X': exit(0); break;
		case 'A': ChallengeA(); break;
		case 'B': ChallengeB(); break;
		case 'C': ChallengeC(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

//Display table
// Pre-condition: N/A
// Post-condition: N/A
void displayTable()
{
	cout << "\n                        PERIODIC TABLE OF ELEMENTS BY SYMBOL";
	cout << "\n";
	cout << "\n\t" << "\033[93m[  H]" << string(80, ' ') << "\033[91m[ He]";
	cout << "\n\t" << "\033[96m[ Li]" << "\033[91m[ Be]" << string(50, ' ') << "\033[94m[  B]" << "\033[93m[  C][  N][  O]" << "\033[0m[  F]" << "\033[91m[ Ne]";
	cout << "\n\t" << "\033[96m[ Na]" << "\033[91m[ Mg]" << string(50, ' ') << "\033[92m[ Al]" << "\033[94m[ Si]" << "\033[93m[  P][  S]" << "\033[0m[ Cl]" << "\033[91m[ Ar]";
	cout << "\n\t" << "\033[96m[  K]" << "\033[91m[ Ca]" << "\033[95m[ Sc][ Ti][  V][ Cr][ Mn][ Fe][ Co][ Ni][ Cu][ Zn]" << "\033[92m[ Ga]"      << "\033[94m[ Ge][ As]" <<"\033[93m[ Se]" << "\033[0m[ Br]"<<"\033[91m[ Kr]";
	cout << "\n\t" << "\033[96m[ Rb]" << "\033[91m[ Sr]" << "\033[95m[  Y][ Zr][ Nb][ Mo][ Tc][ Ru][ Rh][ Pd][ Ag][ Cd]" << "\033[92m[ In][ Sn]" << "\033[94m[ Sb][ Te]" << "\033[0m[  I]" << "\033[91m[ Xe]";;
	cout << "\n\t" << "\033[96m[ Cs]" << "\033[91m[ Ba]" << "\033[0m  *  " << "\033[95m[ Hf][ Ta][  W][ Re][ Os][ Ir][ Pt][ Au][ Hg]" << "\033[92m[ Tl][ Pb][ Bi][ Po][ At]" << "\033[91m[ Rn]";
	cout << "\n\t" << "\033[96m[ Fr]" << "\033[91m[ Ra]" << "\033[0m  ** " << "\033[95m[ Rf][ Db][ Sg][ Bh][ Hs]" << "\033[90m[ Mt][ Ds][ Rg][ Cn][ Nh][ Fl][ Mc][ Lv][ Ts][ Og]";
	cout << "\n";
	cout << "\n\t" << string(10, ' ') <<                    "\033[0m  *  " << "\033[94m[ La][ Ce][ Pr][ Nd][ Pm][ Sm][ Eu][ Gd][ Tb][ Dy][ Ho][ Er][ Tm][ Yb][ Lu]";
	cout << "\n\t" << string(10, ' ') <<                    "\033[0m  ** " << "\033[33m[ Ac][ Th][ Pa][  U][ Np][ Pu][ Am][ Cm][ Bk][ Cf][ Es][ Fm][ Md][ No][ Lr]";

	cout << "\033[0m\n";
}

//display menu
// Pre-condition: N/A
// Post-condition: N/A
char menuOption()
{
	system("cls");
	displayTable();
	cout << "\n        CMPR121 - Exam1 (Chapter 12...1) by Hung Anh Ho (9/29/2023)";
	cout << "\n        " << string(90, char(205));
	cout << "\n        A. Advanced Binary File Opertions (chapter 12)";
	cout << "\n        B. Dynamic Allocated Array        (chapter  9)";
	cout << "\n        C. Vector (array)                 (chapter  7)";
	cout << "\n        " << string(90, char(196));        
	cout << "\n        X. Exit";
	cout << "\n        " << string(90, char(205));

	return inputChar("\n\tOption: ", static_cast <string>("ABCX"));
}

//Swap swap variables
// Pre-condition: int variable a and int varaible b
// Post-condition: swap the what they holds with each other
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//selectionSort function that sort the array of structure based on atomic number
// Pre-condition: ChemistryElement array, size- int type
// Post-condition: sort min to max
void selectionSort(ChemistryElement* array, int size)
{
	int minIndex;
	int minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start].atomicNumber;

		for (int index = start + 1; index < size; index++)
		{
			if (array[index].atomicNumber < minValue)
			{
				minValue = array[index].atomicNumber;
				minIndex = index;
			}
		}

		swap(array[minIndex], array[start]);
	}
}

//ChallengeA
// Pre-condition: N/A
// Post-condition: N/A
void ChallengeA()
{
	fstream file;
	bool fileRead = false;
	string fileName;

	do {
		switch (menuOptionA())
		{
		case 0: file.close(); return;
		case 1:
		{
			// Open the file in binary for output and input mode
			fileName = inputString("\n\tEnter the binary data file name: ", true);
			file.open(fileName, ios::out | ios::binary | ios::in);

			// Validate the binary file
			if (file.fail())
			{
				cout << "\n\tERROR: Binary data file, " << fileName << ", cannot be found.\n\t";
				system("pause");
				break;
			}

			ChemistryElement record;	// Hold a record for the structure
			int count = 0;

			// Read until not succesful
			while (file.read(reinterpret_cast<char*>(&record), sizeof(record)))
			{
				displayElementA(record, count);
				count++;
			}

			//Close the file
			fileRead = true;
			file.close();
			cout << "\n\t";
			system("pause");
		}
		break;
		case 2:
		{
			if (BinarySpecified(fileRead))
				break;

			// Open the file but clear all the flag
			file.open(fileName, ios::out | ios::binary | ios::in);
			file.clear();	

			// Prompt for the element to search
			char ElementSearch[100] = "no";
			strcpy_s(ElementSearch, inputString("\n\tEnter an Element Symbol to search and update: ", true).c_str());

			ChemistryElement record;	// Hold the record for the structure
			bool Found = false;			// Flag for if the searched element is found

			// Process the file
			int count = 0;
			while (file.read(reinterpret_cast<char*>(&record), sizeof(record)))
			{		
				if (strcmp(ElementSearch, record.symbol) == 0)
				{
					displayElementA(record, count);		// Display the element
					Found = true;						// Change the flag to true
					break;								// Break the loop immediately
				}

				count++;
			}

			// Display Error Message if the element cannot be found
			if (!Found)
			{
				cout << "\n\tERROR: Element cannot be found from binary file.";
				cout << "\n\t";
				system("pause");
				break;
			}

			// Otherwise, edit the property from the file and Writing it to the file
			record = changeElementProperty(record);

			// Move the write position and write the file
			file.seekp(count * sizeof(record), ios::beg);
			file.write(reinterpret_cast<char*>(&record), sizeof(record));

			// Close the file
			file.close();
		}
		break;
		}
	} while (true);

	// Close the file
	file.close();
}

//MenuOptionA function for menu option A
// Pre-condition: N/A
// Post-condition: N/A
int menuOptionA()
{
	system("cls");
	cout << "\n        Advanced Binary File Opertions Menu";
	cout << "\n        " << string(90, char(205));
	cout << "\n        1. Read and Display ALL elements from binary data file";
	cout << "\n        2. Search and update an element by Symbol from binary file";
	cout << "\n        " << string(90, char(196));
	cout << "\n        0. Return to main menu";
	cout << "\n        " << string(90, char(205));
	return inputInteger("\n\tOption: ", 0,2);
}

//BinarySpecified function takes in readFile bool
//pre-condition: the bool value that check if the step 1 has been processed
//post-condition: return true if it is not specifed, otherwise return false
bool BinarySpecified(bool specified)
{
	if (!specified)
	{
		cout << "\n\tNo Binary File has been specified from step#1\n\t";
		system("pause");
		return true;
	}

	return false;
}


// Convert K to C degree
double KtoC(double s)
{
	return s - 273.15;
}

// Display Group Block corresponing to the integer value
void GroupBlockName(int s)
{
	switch (s)
	{
	case 1: cout << "Nonmedal"; break;
	case 2: cout << "Noble Gas"; break;
	case 3: cout << "Alkali Metal"; break;
	case 4: cout << "Alkali Earth Metal"; break;
	case 5: cout << "Transition Metal"; break;
	case 6: cout << "Post-Transition Metal"; break;
	case 7: cout << "Metaloid"; break;
	case 8: cout << "Halogen"; break;
	case 9: cout << "Lanthanide"; break; 
	case 10: cout << "Actinide"; break;
	default: cout << "unknown"; break;
	}
}

// Display Stadard state corresponing to the integer value
void StandardStateName(int s)
{
	switch (s)
	{
	case 1: cout << "Gas"; break;
	case 2: cout << "Liquid"; break;
	case 3: cout << "Solid"; break;
	default: cout << "unknown"; break;
	}
}

//Display information of the element
void displayElementA(ChemistryElement s, int number)
{
	//Melting and Boiling in C and K degree
	double MeltK = s.meltingPoint;
	double BoilK = s.boilingPoint;
	double MeltC = KtoC(MeltK);
	double BoilC = KtoC(BoilK);

	//Display the information
	cout << "\n        Element (struct) #" << number + 1 << " - " << sizeof(s) << " Bytes";
	cout << "\n        " << string(90, char(196));
	cout << "\n        Atomic Number                     : " << s.atomicNumber;
	cout << "\n        Symbol                            : " << s.symbol;
	cout << "\n        Name                              : " << s.name;
	cout << fixed << showpoint << setprecision(4);
	cout << "\n        Atomic Mass                       : " << s.atomicMass << " u";
	cout << "\n        Chemical Group Block              : "; GroupBlockName(s.chemicalGroupBlock);
	cout << "\n        Standard State                    : "; StandardStateName(s.standardState);
	cout << fixed << showpoint << setprecision(2);
	cout << "\n        Melting Point                     : " << MeltC << char(248) << "C (" << MeltK << " K)";
	cout << "\n        Boiling Point                     : " << BoilC << char(248) << "C (" << BoilK << " K)";
	cout << "\n        Year Discovered                   : " << s.yearDiscovered;
	cout << "\n        Discover by                       : " << s.Discoverers;
	cout << "\n";
}

//Display the Edit Menu for the property
int EditmenuProperty()
{
	cout << "\n\tEdit Element Properties Menu";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\t 1. Atomic Number";
	cout << "\n\t 2. Symbol";
	cout << "\n\t 3. Name";
	cout << "\n\t 4. Atomic Mass";
	cout << "\n\t 5. Chemical Group Block";
	cout << "\n\t 6. Standard State";
	cout << "\n\t 7. Melting Point";
	cout << "\n\t 8. Boiling Point";
	cout << "\n\t 9. Discovered Year";
	cout << "\n\t10. Discovered By";
	cout << "\n\t" << string(90, char(196));
	cout << "\n\t-1. return without committing the updates";
	cout << "\n\t 0. Committing the updates and return";
	cout << "\n\t" << string(90, char(205));
	return inputInteger("\n\tOption: ", -1, 10);
}

//ChemistryElement function change elements of the ChemistryElement struct
// Pre-condition: A valid ChemistryElement structue and valid int count
// Post-condition: Return an updated property to a structure
ChemistryElement changeElementProperty(ChemistryElement& s)
{
	// Temperary variable to hold before commiting changing
	int tempAtomicNumber = s.atomicNumber;
	double tempAtomicMass = s.atomicMass;

	char tempSymbol[3];
	strcpy_s(tempSymbol, s.symbol);

	char tempName[25] = "unknown";
	strcpy_s(tempName, s.name);

	int tempStandardState = s.standardState;
	int tempChemicalGroupBlock = s.chemicalGroupBlock;
	double tempMeltingPoint = s.meltingPoint;	// Hold K degrees
	double tempBoilingPoint = s.boilingPoint;	// Hold K degrees
	int tempyearDiscovered = s.yearDiscovered;
	char tempDiscoverers[100] = "unknown";
	strcpy_s(tempDiscoverers, s.Discoverers);

	do {
		string input = "unknown";
		switch (EditmenuProperty())
		{
		case 1: // Atomic number
			tempAtomicNumber = inputInteger("\n\tEnter the Atomic Number: ", 1, 118);
			break;

		case 2: // Symbol
			do
			{
				input = inputString("\n\tEnter the symbol      : ", false);

				if (input.length() > 2)
					cout << "\n\tERROR: invalid input. Symbol's length can not exceed 2 characters.\n";
				else
					break;
			} while (true);

			input[0] = toupper(input[0]);
			for (int i = 1; i < (int) input.length(); i++)
			{
				input[i] = tolower(input[i]);
			}
			strncpy_s(tempSymbol, input.c_str(), sizeof(s.symbol) - 1);
			break;

		case 3: // Name
		{
			do
			{
				input = inputString("\n\tEnter the name        : ", false);

				if (input.length() > 24)
					cout << "\n\tERROR: invalid input. Symbol's name can not exceed 24 characters.\n";
				else
					break;
			} while (true);
			strncpy_s(tempName, input.c_str(), sizeof(s.name) - 1);
			break;
		}

		case 4: // Atomic Mass
		{
			tempAtomicMass = inputDouble("\n\tEnter the Atomic Mass (u): ", true);
			break;
		}

		case 5: // Group Block
		{
			cout << "\n\tAtomic's Type Options";
			cout << "\n\t" << string(30, char(196));
			cout << "\n\t0  - Unknown";
			cout << "\n\t1  - Actinide";
			cout << "\n\t2  - Alkali Metal";
			cout << "\n\t3  - Alkaline Earth Metal";
			cout << "\n\t4  - Halogen";
			cout << "\n\t5  - Lanthanide";
			cout << "\n\t6  - Metalloid";
			cout << "\n\t7  - Noble Gas";
			cout << "\n\t8  - Reactive Nonmetal";
			cout << "\n\t9  - Post-Transition Metal";
			cout << "\n\t10 - Transition Metal";
			cout << "\n\t" << string(30, char(196));
			tempChemicalGroupBlock = inputInteger("\n\tEnter your choice: ", 0, 10);
			break;
		}

		case 6: // Standard State
		{
			cout << "\n\tAtomic's State Options";
			cout << "\n\t" << string(30, char(196));
			cout << "\n\t0 - Unknown" << "\n\t1 - Solid" << "\n\t2 - Liquid" << "\n\t3 - Gas";
			cout << "\n\t" << string(30, char(196));
			tempStandardState = inputInteger("\n\tEnter your choice: ", 0, 3);
		}
			break;
		case 7: // Melting Point
			tempMeltingPoint = inputDouble("\n\tEnter the Melting Point (K): ");
			break;

		case 8: // Boiling Point
			tempBoilingPoint = inputDouble("\n\tEnter the Boiling Point (K): ");
			break;

		case 9: // Discoverted year
			tempyearDiscovered = inputInteger("\n\tEnter the Year Discovered: ", 0, 3000);
			break;

		case 10: // Discovered by
		{
			do
			{
				input = inputString("\n\tEnter the discorever(s)'s name(s): ", true);

				if (input.length() > 99)
					cout << "\n\tERROR: invalid input. Symbol's discorevers can not exceed 99 characters.\n";
				else
					break;
			} while (true);

			strncpy_s(tempDiscoverers, input.c_str(), sizeof(s.Discoverers) - 1);
			break;
		}

		case 0:	// committing the updates
		{
			// Assign the temp variable to structure and return it
			s.atomicMass = tempAtomicMass;
			s.atomicNumber = tempAtomicNumber;
			s.boilingPoint = tempBoilingPoint;
			s.meltingPoint = tempMeltingPoint;
			s.chemicalGroupBlock = tempChemicalGroupBlock;
			s.standardState = tempStandardState;
			s.yearDiscovered = tempyearDiscovered;
			strcpy_s(s.name, tempName);
			strcpy_s(s.Discoverers, tempDiscoverers);
			strcpy_s(s.symbol, tempSymbol);

			cout << "\n\tElement has been successfully updated.\n";
			system("pause");
			return s;
		}
		break;

		case -1: // Without committing the updates"
		{
			cout << "\n\tElement has NOT been updated.\n";
			system("pause");
			return s;
		}
		break;
		}
	} while (true);
}

//menuOptionB display
int menuOptionB()
{
	system("cls");
	displayTable();

	cout << "\n        Dynamic Allocated Array Menu";
	cout << "\n        " << string(90, char(205));
	cout << "\n        1. Read, store ALL elements from binary file into the sorted array";
	cout << "\n        2. Display ALL elements from the array";
	cout << "\n        3. Search and update an element by Atomic Number from the array";
	cout << "\n        4. Write ALL elements from the array into the binary file";
	cout << "\n        " << string(90, char(196));
	cout << "\n        0. return to main menu";
	cout << "\n        " << string(90, char(205));

	return inputInteger("\n\tOption: ", 0, 4);
}

//ChallengeB----------------------------------------------------------------------------------------------------
void ChallengeB()
{
	fstream file;					// File for input and output
	bool fileRead = false;   // Flag for if binary file in step 1 before other step
	string fileName;				// The file name
	ChemistryElement* array = nullptr;	// Dynamically array
	int size = 0;						// Sizee of the dynamically array

	do
	{
		switch (menuOptionB())
		{
		case 0: file.close(); return;
		case 1: // Read store from binary file into the sorted array
		{
			// Open the file in binary for output and input mode
			fileName = inputString("\n\tEnter the binary data file name: ", true);
			file.open(fileName, ios::out | ios::binary | ios::in);

			// Validate the binary file
			if (file.fail())
			{
				cout << "\n\tERROR: Binary data file, " << fileName << ", cannot be found.";
				cout << "\n\t";
				system("pause");
				break;
			}

			file.seekg(0L, ios::end);							// Set the read to the EOF
			size = file.tellg() / sizeof(ChemistryElement);     // Calculate how many struct in the binary file
			file.seekg(0L, ios::beg);							// Reset the position;

			// An dynamically array of structure
			array = new ChemistryElement[size];

			fileRead = true;		// The binary file has been specified

			int index = 0;

			// Read the content of the file
			while (file.read(reinterpret_cast<char*>(&array[index]), sizeof(array[index])))
			{
				index++;
			}

			// Sort the array based on the atomic number 
			selectionSort(array, size);

			// Prompt the user succesful message
			file.close();

			cout << "\n\tSUCCESS: " << index << " (struct) data from " << fileName << " have been stored into dynamic allocated array and sorted by Atomic Number";
			cout << "\n\t";
			system("pause");
		}
		break;
		case 2: // Display All Element from the array
		{
			if (BinarySpecified(fileRead))			
				break;

			// Display element from the array
			for (int i = 0; i < size; i++)
				displayElementB(array[i], i);

			cout << "\n\t";
			system("pause");
		}
		break;
		case 3: // Search and update an element by Atomic Number from the array
		{
			if (BinarySpecified(fileRead))
				break;

			// Prompt the user for atomic number the element to search
			int atomicSearch = inputInteger("\n\tEnter an Atomic Number (1..." + to_string(size) + ") to search and update: ", 1, size);
			int indexFound = atomicSearch -1;// The array is sorted, thus index = atomic number - 1		

			displayElementB(array[indexFound], indexFound);
			changeElementProperty(array[indexFound]);
		}
		break;
		case 4: // Write ALL elements from the array into the binary file
		{
			if (BinarySpecified(fileRead))
				break;

			// Open the output file to write the data
			string outputName = inputString("\n\tEnter the binary data file name: ", true);
			fstream outputFile(outputName, ios::out | ios::binary);

			for (int i = 0; i < size; i++)
			{
				// Move the write position and write the file
				outputFile.seekp(i * sizeof(array[0]), ios::beg);
				outputFile.write(reinterpret_cast<char*>(&array[i]), sizeof(array[i]));
			}

			// Promt the user succesful message
			cout << "\n\tSUCCESS: " << size << " (struct) from array have been written to the binary data file, " << outputName << ".\n\t";
			// Close the file
			outputFile.close();
			system("pause");
		}
		break;
		}
	} while (true);

	// Delete the dynamically array
	delete[] array;
	array = nullptr;
}

//displayElements display the infomations of the elements
void displayElementB(ChemistryElement s, int index)
{
	// Melting and Boiling in C and K degree
	double MeltK = s.meltingPoint;
	double BoilK = s.boilingPoint;
	double MeltC = KtoC(MeltK);
	double BoilC = KtoC(BoilK);

	// Display the information
	cout << "\n        array element[" << index << "]";
	cout << "\n        " << string(90, char(196));
	cout << "\n        Atomic Number                     : " << s.atomicNumber;
	cout << "\n        Symbol                            : " << s.symbol;
	cout << "\n        Name                              : " << s.name;
	cout << fixed << showpoint << setprecision(4);
	cout << "\n        Atomic Mass                       : " << s.atomicMass << " u";
	cout << "\n        Chemical Group Block              : "; GroupBlockName(s.chemicalGroupBlock);
	cout << "\n        Standard State                    : "; StandardStateName(s.standardState);
	cout << fixed << showpoint << setprecision(2);
	cout << "\n        Melting Point                     : " << MeltC << char(248) << "C (" << MeltK << " K)";
	cout << "\n        Boiling Point                     : " << BoilC << char(248) << "C (" << BoilK << " K)";
	cout << "\n        Year Discovered                   : " << s.yearDiscovered;
	cout << "\n        Discover by                       : " << s.Discoverers;
	cout << "\n";
}



//ChallengeC----------------------------------------------------------------------------------------------------
void ChallengeC()
{
	fstream file;
	bool fileRead = false; 

	vector <ChemistryElement> vector;

	do
	{
		switch (menuOptionC())
		{
		case 0: file.close(); return;
		case 1:
		{
			// Open the file in binary for output and input mode
			string fileName = inputString("\n\tEnter the binary data file name: ", true);
			file.open(fileName, ios::out | ios::binary | ios::in);

			// Validate the binary file
			if (file.fail())
			{
				cout << "\n\tERROR: Binary data file, " << fileName << ", cannot be found.\n\t";
				system("pause");
				break;
			}

			fileRead = true;
			ChemistryElement record;

			int count = 0;

			//Read until the end of the file
			while (file.read(reinterpret_cast<char*>(&record), sizeof(record)))
			{
				vector.push_back(record); // Push back the data into the vector
				count++;
			}

			//Prompt the user succesful message
			file.close();
			cout << "\n\tSUCCESS: " << vector.size() << " (struct) data from " << fileName << " have been stored into into unsorted vector";
			cout << "\n\t";
			system("pause");
		}
		break;
		case 2: // Display all Element from the vector
		{
			if (BinarySpecified(fileRead))
				break;

			// Display element from the array
			for (int i = 0; i < vector.size(); i++)
				displayElementC(vector[i], i);

			cout << "\n\t";
			system("pause");
		}
		break;
		case 3:  // Search and update an element by Atomic Number from the array
		{
			if (BinarySpecified(fileRead))
				break;

			int size = vector.size();

			// Prompt the user for the element name to search
			// Prompt for the element to search
			char NameSearch[100] = "unknown";
			strncpy_s(NameSearch, inputString("\n\tEnter an Element's Name to search and update:  ", true).c_str(), sizeof(NameSearch) - 1);

			bool Found = false;
			int indexFound = -1;

			// Search if the atomic number is there
			for (int i = 0; i < vector.size(); i++)
			{
				if (strcmp(vector[i].name, NameSearch) == 0)
				{
					Found = true;		// Set the found flag to true
					indexFound = i;		// Store the position of the element
					break;				// Exit the loop 
				}
			}

			// Display Error Message if the element cannot be found
			if (!Found)
			{
				cout << "\n\tERROR: Element cannot be found from binary file.\n\t";
				system("pause");
				break;
			}

			displayElementC(vector[indexFound], indexFound);
			changeElementProperty(vector[indexFound]);
		}
		break;
		case 4: // Write ALL elements from the array into the binary file
		{
			if (BinarySpecified(fileRead))
				break;

			// Open the output file to write the data
			string outputName = inputString("\n\tEnter the binary data file name: ", true);
			fstream outputFile(outputName, ios::out | ios::binary);

			for (int i = 0; i < vector.size(); i++)
			{
				// Move the write position and write the file
				outputFile.seekp(i * sizeof(vector[0]), ios::beg);
				outputFile.write(reinterpret_cast<char*>(&vector[i]), sizeof(vector[i]));
			}

			// Promt the user succesful message
			cout << "\n\tSUCCESS: " << vector.size() << " (struct) from vector have been written to the binary data file," << outputName << ".\n\t";
			// Close the file
			outputFile.close();
			system("pause");
		}
		break;
		}
	} while (true);
}

//menuOptionC display
int menuOptionC()
{
	system("cls");
	displayTable();

	cout << "\033[0m\n";
	cout << "\n        Vector (array) Menu";
	cout << "\n        " << string(90, char(205));
	cout << "\n        1. Read and store ALL elements from binary file into the unsorted vector (array)";
	cout << "\n        2. Display ALL elements from the vector";
	cout << "\n        3. Search and update an element by Name from the vector";
	cout << "\n        4. Write ALL elements from the vector into the binary file";
	cout << "\n        " << string(90, char(196));
	cout << "\n        0. return to main menu";
	cout << "\n        " << string(90, char(205));
	return inputInteger("\n\tOption: ", 0, 4);
}

//displayElements display the infomations of the elements
void displayElementC(ChemistryElement s, int index)
{
	// Melting and Boiling in C and K degree
	double MeltK = s.meltingPoint;
	double BoilK = s.boilingPoint;
	double MeltC = KtoC(MeltK);
	double BoilC = KtoC(BoilK);

	// Display the information
	cout << "\n        vector element[" << index << "]";
	cout << "\n        " << string(90, char(196));
	cout << "\n        Atomic Number                     : " << s.atomicNumber;
	cout << "\n        Symbol                            : " << s.symbol;
	cout << "\n        Name                              : " << s.name;
	cout << fixed << showpoint << setprecision(4);
	cout << "\n        Atomic Mass                       : " << s.atomicMass << " u";
	cout << "\n        Chemical Group Block              : "; GroupBlockName(s.chemicalGroupBlock);
	cout << "\n        Standard State                    : "; StandardStateName(s.standardState);
	cout << fixed << showpoint << setprecision(2);
	cout << "\n        Melting Point                     : " << MeltC << char(248) << "C (" << MeltK << " K)";
	cout << "\n        Boiling Point                     : " << BoilC << char(248) << "C (" << BoilK << " K)";
	cout << "\n        Year Discovered                   : " << s.yearDiscovered;
	cout << "\n        Discover by                       : " << s.Discoverers;
	cout << "\n";
}
