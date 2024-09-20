// Name: Hung Anh Ho
// Date: 11/18/2023
// Description: Chapter 18 - Assignment


#include <iostream>
#include <fstream>
#include "input.h"
#include "LinkedList.h"
using namespace std;


int menuOption();

void Challenge1();
void Challenge2();
void Challenge3();
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
        case 1: Challenge1(); break;
        case 2: Challenge2(); break;
        case 3: Challenge3(); break;
        case 7: Challenge7(); break;
        case 8: Challenge8(); break;
        case 12: Challenge12(); break; // 10 points extra credit
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
    cout << "\n\tChapter 18 - Assignment";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t1  Your Own Linked List";
    cout << "\n\t2  List Print";
    cout << "\n\t3  List Copy Constructor";
    cout << "\n\t7  Member Removal by Position";
    cout << "\n\t8  List Template";
    cout << "\n\t12 Double Merge";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t0  exit";
    cout << "\n\t" << string(60, char(196));
    return inputInteger("\n\tOption: ", 0, 12);
}


void Challenge1()
{
    LinkedList<int> mylist;

    srand(time(0));

    cout << "\nAppends:\n";
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 200;
        mylist.appendNode(temp);
        cout << temp << '\n';
    }


    cout << "\nInserts:\n";
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 200;
        mylist.insertNode(temp);
        cout << temp << '\n';
    }

    cout << "\nDipslay my list:\n";
    mylist.displayList();

}

void Challenge2()
{
    LinkedList<int> mylist;

    srand(time(0));

    cout << "\nappends:\n";
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 200;
        mylist.appendNode(temp);
        cout << temp << '\n';
    }

    cout << "\ninserts:\n";
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 200;
        mylist.insertNode(temp);
        cout << temp << '\n';
    }

    ofstream fileout;

    string filename = inputString("\nEnter a file name to write: ", true);

    fileout.open(filename);
    cout << "\ndisplay my linked list:\n";
    mylist.displayList();
    cout << "\nFile, " << filename << ", has been printed/saved.\n";

    fileout.close();
}

void Challenge3()
{
    LinkedList<int> mylist;

    srand(time(0));

    cout << "\nappends:\n";
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 200;
        mylist.appendNode(temp);
        cout << temp << '\n';
    }

    cout << "\ninserts:\n";
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 200;
        mylist.insertNode(temp);
        cout << temp << '\n';
    }

    //1st List
    cout << "\ndisplay my first linked list:\n";
    mylist.displayList();

    //2nd list
    LinkedList<int> mySecondList(mylist);

    cout << "\nDisplay my second linked list (copy from my first linked list):\n";
    mySecondList.displayList();


}

void Challenge7()
{
    LinkedList<int> mylist;

    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 200;
        mylist.appendNode(temp);
    }

    cout << "\n\tThe current linked list: \n";
    mylist.displayList();

    int position = inputInteger("\n\tEnter the position to delete a node: ");

    mylist.removalPosition(position);

    cout << "\n\tAfter deleting specified position of node: \n";
    mylist.displayList();
}

void Challenge8()
{
    // Integer Linked List
    LinkedList<int> myIntList;

    srand(time(0));

    cout << "\nAppends int list:\n";
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 200;
        myIntList.appendNode(temp);
        cout << temp << '\n';
    }

    cout << "\nInserts int list:\n";
    for (int i = 0; i < 10; i++)
    {
        int temp = rand() % 200;
        myIntList.insertNode(temp);
        cout << temp << '\n';
    }

    cout << "\nDisplay int linked list:\n";
    myIntList.displayList();


    // Double linked list
    cout << "\n----------------------------------------";
    LinkedList<double> myDoubleList;

    srand(time(0));

    cout << "\nAppends double linked list:\n";
    for (int i = 0; i < 10; i++)
    {
        double temp = (rand() % 2000 + 100) * 0.1;
        myDoubleList.appendNode(temp);
        cout << temp << '\n';
    }

    cout << "\nInserts double linked list:\n";
    for (int i = 0; i < 10; i++)
    {
        double temp = (rand() % 2000 + 100) * 0.1;
        myDoubleList.insertNode(temp);
        cout << temp << '\n';
    }

    cout << "\nDisplay double linked list:\n";
    myDoubleList.displayList();

}

void Challenge12()
{
    // Create a linked list with sorted data first
    LinkedList<double> myDoubleList;

    srand(time(0));

    // Append the linked list
    for (int i = 0; i < 5; i++)
    {
        double temp = (i + 1) * 4 + rand() % 3;
        myDoubleList.appendNode(temp);
    }

    // Insert the linked list
    for (int i = 0; i < 5; i++)
    {
        double temp = (rand() % 2000 + 100) * 0.1;
        myDoubleList.insertNode(temp);
    }

    cout << "\nThe sorted double linked list:\n";
    myDoubleList.displayList();

    // Create a fixed-size double array 
    const int SIZE = 10;
    double array[SIZE];

    // Assign random value to each element
    for (auto& i : array)
        i = (rand() % 2000 + 100) * 0.1;

    // Display the value of the array
    cout << "\n----------------------------------------";
    cout << "\nThe content of the double array";
    for (const auto &i : array)
        cout << "\n" << i;
    
    // Merging the array into the linked list
    cout << "\n\n----------------------------------------";
    cout << "\nAfter merging: \n";
    myDoubleList.mergeArray(array, SIZE);
    myDoubleList.displayList();

}