//Hung Anh Ho
//11-9-2023
//Chapter 17

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <set>
#include <unordered_map>
#include "input.h"


// Prototype:
int menuOption();
void Challenge3();
void Challenge4();
void Challenge6();
void Challenge7();
void Challenge8(); // 10 points Extra credit


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
		case 8: Challenge8(); break; // 10 points Extra credit
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
    cout << "\tAssignment Chapter 17 by Hung Anh Ho";
    cout << "\n\t" << string(80, char(196));
    cout << "\n\t3. Capital Quiz.";
    cout << "\n\t4. File Encryption and Decryption.";
    cout << "\n\t6. Word Frequency.";
    cout << "\n\t7. Word Index.";
    cout << "\n\t8. Prime Number Generation.     (10 points extra credit)";
    cout << "\n\t" << string(80, char(205));
    cout << "\n\t0.  Exit the program.";
    cout << "\n\t" << string(80, char(196));
	return inputInteger("\n\tOption: ", 0, 8);
}


//Challenge 3
void Challenge3()
{
	//Open states file
	fstream file;
	file.open("states.txt");
	if (file.fail())
	{
		cout << "\nERROR: Cannot read states.txt.\n";
		return;
	}

	map<string, string> USStates; //use map to associate one-to-one
	string name;
	string capital;

	//Insert in pair of states and their capital
	while (getline(file, name))
	{
		getline(file, capital);
		USStates.insert(pair<string, string>(name, capital));
	}

	file.close();
	int corrects = 0;
	int incorrects = 0;

	do
	{
		auto it = USStates.begin();
		advance(it, rand() % 50); //from algorithm library

		cout << "\nWhat is capital of " << it->first << "? ";
		getline(cin, capital);

		if (capital == it->second)
		{
			cout << "\nCorrect!\n";
			corrects++;
		}
		else
		{
			cout << "\nIncorrect. Please check your spelling.\n";
			incorrects++;
		}
		char ans = toupper(inputChar("\nDo you want to continue (Y-yes or N-no)?"));
			if (ans == 'N')
				break;
	} while (true);

	//Display total correct and incorrect answers
	cout << "\nCorrect answers : " << corrects << '\n';
	cout << "Incorrect answers: " << incorrects << '\n';
}



void Challenge4()
{
    system("cls");
    cout << "\n\t4. File Encryption and Decryption.";
    cout << "\n\t" << string(80, char(205));

    //Part 1: Encryption
    map<char, char> codes;

    int i = 33;

    // A -> Z
    for (char character = 'A'; character <= 'Z'; character++) // ASCII code
    {
        codes[character] = i;
        i++;
    }

    // a -> z
    i = 59;

    for (char character = 'a'; character <= 'z'; character++) // ASCII code
    {
        codes[character] = i;
        i++;
    }

    // Open and read file "input.txt"
    ifstream inputFile("input.txt");

    if (inputFile.fail())
    {
        cout << "\n\tERROR: file, input.txt, cannot be found.\n";
        return;
    }

    cout << "\n\tPart 1. Encrytion.\n";
    cout << "\n\tOur data: ";
    while (!inputFile.eof())
    {
        string line;
        getline(inputFile, line);
        cout << "\n\t" << line;
    }

    cout << "\n\n\tEncrypted data: ";


    //Open encryption
    ofstream outputFile("encrypted.txt");
    inputFile.seekg(0L, ios::beg);
    while (!inputFile.eof())
    {
        string line = "";
        getline(inputFile, line);
        cout << "\n\t";
        for (int i = 0; i < (int)line.length(); i++)
        {
            bool found = false;
            for (auto it = codes.begin(); it != codes.end(); it++)
            {
                if (line[i] == it->first)
                {
                    found = true;
                    cout << it->second;
                    outputFile << it->second;
                    break;
                }
            }
            if (found == false)
            {
                cout << line[i];
                outputFile << line[i];
            }
        }
        if (!inputFile.eof()) // Prevent writing an empty line at the end
            outputFile << "\n";
    }
    // Close the files:
    inputFile.close();
    outputFile.close();

    //Part 2: Decryption

    fstream file("encrypted.txt");
    cout << "\n\t" << string(60, char(196));
    cout << "\n\tPart 2: Decryption\n";

    cout << "\n\tEncrypted data: ";

    while (!file.eof())
    {
        string line = "";
        getline(file, line);
        if (file.eof() && line.empty()) break;
        cout << "\n\t" << line;
    }

    cout << "\n\n\tDecrypyted data: ";

    file.seekg(0L, ios::beg);
    while (!file.eof())
    {
        string line = "";
        getline(file, line);
        cout << "\n\t";
        for (int i = 0; i < (int)line.length(); i++)
        {
            bool found = false;
            for (auto it = codes.begin(); it != codes.end(); it++)
            {
                if (line[i] == it->second)
                {
                    found = true;
                    cout << it->first;
                    break;
                }
            }
            if (found == false)
            {
                cout << line[i];
            }
        }
        if (file.eof() && line.empty()) break;
    }
    cout << "\n\n";

    file.close();
}

//Challenge 6
void Challenge6()
{
    system("cls");
    cout << "\n\t6. Word Frequency.";
    cout << "\n\t" << string(80, char(205)) << "\n\t";

    // create a map (associative container): string (key)  -  int (value)
    map <string, int> wordFrequency;

    // create and open input file "KENNEDY.txt"
    ifstream infile("KENNEDY.txt");

    if (infile.fail())
    {
        cout << "ERROR: File ,KENNEDY.txt, cannot be found.\n";
        return;
    }

    while (!infile.eof())
    {
        string inputline;
        getline(infile, inputline);
        if (infile.eof())
            break;
        cout << inputline << "\n\t";
        while (inputline.length() > 0)
        {
            string word;
            if (inputline.find(" ") != string::npos)
            {
                word = inputline.substr(0, inputline.find(" "));
                inputline = inputline.substr(inputline.find(" ") + 1);
            }
            else
            {
                word = inputline;
                inputline = "";
            }
            if (ispunct(word[word.length() - 1]))
                word = word.substr(0, word.length() - 1);
            transform(word.begin(), word.end(), word.begin(), ::tolower);


            if (wordFrequency.find(word) == wordFrequency.end()) // if not found --> return the iterator to the end of the map
                wordFrequency[word] = 1;

            else // if found
                wordFrequency[word] += 1;

        }
    }
    infile.close(); // close the file

    // Output to console and outfile
    cout << "\n" << setw(22) << "WORD" << setw(14) << "FREQUENCY" << "\n";
    for (auto element : wordFrequency)
    {
        cout << setw(20) << element.first << "    :     " << element.second << "\n";
    }
}

//Challenge 7
void Challenge7()
{
    system("cls");
    cout << "\n\t7. Word Index.";
    cout << "\n\t" << string(80, char(205)) << "\n\n\t";

    // create a set (associative container)
    set<int> index;

    // create a map (associative container): string (key)  -  set<int> (value)
    map <string, set<int>> wordIndex;

    int line = 1;

    // create and open input file "KENNEDY.txt"
    ifstream infile("KENNEDY.txt");

    if (infile.fail())
    {
        cout << "ERROR: File ,KENNEDY.txt, cannot be found.\n";
        return;
    }

    while (!infile.eof())
    {
        string inputline;
        getline(infile, inputline);
        if (infile.eof())
            break;
        cout << inputline << "\n\t";
        while (inputline.length() > 0)
        {
            string word;
            if (inputline.find(" ") != string::npos)
            {
                word = inputline.substr(0, inputline.find(" "));
                inputline = inputline.substr(inputline.find(" ") + 1);
            }
            else
            {
                word = inputline;
                inputline = "";
            }
            if (ispunct(word[word.length() - 1]))
                word = word.substr(0, word.length() - 1);
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (wordIndex.find(word) != wordIndex.end()) // if not found --> return the iterator to the end of the map
                wordIndex[word].insert(line);
            else
            {
                set<int> lines;
                lines.insert(line);
                wordIndex.insert(pair<string, set<int>>(word, lines));
            }
        }
        line++;
    }
    infile.close(); // close the file

    // create an output file "INDEX.txt"
    ofstream outfile("INDEX.TXT");

    // Output to console and outfile
    cout << "\n" << setw(20) << "WORD" << setw(7) << "INDEX" << "\n";
    for (auto element : wordIndex)
    {
        outfile << element.first << ": ";
        cout << setw(20) << element.first << ": ";
        for (auto l : element.second)
        {
            cout << l << ' ';
            outfile << l << ' ';
        }
        cout << '\n';
        outfile << '\n';
    }

    cout << "\n\tINDEX.TXT has been generated.\n";

    outfile.close(); // close the file
}

// Challenge 8
void Challenge8()
{
    system("cls");
    cout << "\n\t8. Prime Number Generation.     (10 points extra credit)";
    cout << "\n\t" << string(80, char(205)) << "\n\n\t";


    int maxNum = inputInteger("\n\tEnter an integer greater than 1: ", 2, 1000);


    //Create a vector of integers number
    //then insert numbers into it until the max number from user's input
    vector<int> numList;
    for (int i = 2; i <= maxNum; i++)
    {
        numList.push_back(i);
    }

    //Create a lambda expression for function object printPrime()
    //then assign it to auto isPrime
    auto printPrime = [](int num)
        {
            if (num == 2)
                cout << "\t" << num << "\n";
            else
            {
                for (int i = 2; i < num; i++)
                {
                    if (num % i == 0)
                        return;
                }
                cout << "\t" << num << "\n";
            }
        };


    // Output list of prime numbers
    cout << "\n\tThe prime numbers in range (2..." << maxNum << ") is: \n";
    for_each(numList.begin(), numList.end(), printPrime);
}