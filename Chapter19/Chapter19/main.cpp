// Name: Hung Anh Ho
// Date: 11/25/2023
// Description: Chapter 19 - Assignment

#include <iostream>
#include "input.h"

#include "MyQueue.h"
#include "MyStack.h"
#include <stack>
#include <fstream>

using namespace std;


int menuOption();

void Challenge1();
void Challenge2();
void Challenge3();
void Challenge4();
void Challenge9();

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
        case 4: Challenge4(); break;
        case 9: Challenge9(); break;
        //case 12: Challenge12(); break; // 10pts Xtra
       // case 13: Challenge13(); break; // 10pts Xtra
       // case 14: Challenge14(); break; // 10pts Xtra
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
    cout << "\n\tChapter 19 - Assignment";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t0  exit";
    cout << "\n\t1  Static Stack Template";
    cout << "\n\t2  Dynamic Stack Template";
    cout << "\n\t3  Static Queue Template";
    cout << "\n\t4  Dynamic Queue Template";
    cout << "\n\t9  File Reverser";
    cout << "\n\t" << string(60, char(196));
    return inputInteger("\n\tOption: ", 0, 12);
}


void Challenge1()
{
    MyStack<int> testStack;

    cout << "\nPush value onto the stack: \n";
    testStack.push(666);
    testStack.push(12);
    testStack.push(-52);

    cout << "\nDisplay all value of the stack: \n";
    testStack.display();

    if (!testStack.isEmpty())
    {
       cout << "\nTop: " << testStack.top();
       cout << "\nPop:";
       testStack.pop();
    }

    if (!testStack.isEmpty())
    {
        cout << "\nTop: " << testStack.top();
        cout << "\nPop";
        testStack.pop();
    }

    if (!testStack.isEmpty())
    {

        cout << "\nTop: " << testStack.top();
        cout << "\nPop";
        testStack.pop();
    }

    if (!testStack.isEmpty())
    {
        cout << "\nTop: " << testStack.top();
        cout << "\nPop";
        testStack.pop();
    }


}

void Challenge2()
{
    MyStack<int> testStack;

    cout << "\nPush value onto the stack: \n";
    testStack.push(666);
    testStack.push(12);
    testStack.push(-52);

    cout << "\nDisplay all value of the stack: \n";
    testStack.display();

    if (!testStack.isEmpty())
    {
        cout << "\nTop: " << testStack.top();
        cout << "\nPop:";
        testStack.pop();
    }

    if (!testStack.isEmpty())
    {
        cout << "\nTop: " << testStack.top();
        cout << "\nPop";
        testStack.pop();
    }

    if (!testStack.isEmpty())
    {

        cout << "\nTop: " << testStack.top();
        cout << "\nPop";
        testStack.pop();
    }

    if (!testStack.isEmpty())
    {
        cout << "\nTop: " << testStack.top();
        cout << "\nPop";
        testStack.pop();
    }
}

void Challenge3()
{
    MyQueue<int> testQueue;

    cout << "\nPush value onto the queue: \n";
    testQueue.enqueue(4);
    testQueue.enqueue(12);
    testQueue.enqueue(47);

    cout << "\nDisplay all value of the queue: \n";
    testQueue.display();


    while (!testQueue.isEmpty())
    {
        cout << "\nTop: " << testQueue.front();
        cout << "\nEnqueue"; testQueue.dequeue();
    }

}

void Challenge4()
{
    MyQueue<int> testQueue;

    cout << "\nPush value onto the queue: \n";
    testQueue.enqueue(23);
    testQueue.enqueue(12);
    testQueue.enqueue(47);

    cout << "\nDisplay all value of the queue: \n";
    testQueue.display();


    while (!testQueue.isEmpty())
    {
        cout << "\nTop: " << testQueue.front();
        cout << "\nEnqueue"; testQueue.dequeue();
    }
}

void Challenge9()
{
    fstream File;

    File.open("Story.txt", ios::in);

    if (File.fail())
    {
        cout << "\n\tCannot open the txt file";
        return;
    }

    stack<char, vector<char>> testStack;
    char ch;

    cout << "\n\Content of normal file: \n";
    while (File.get(ch))
    {
        testStack.push(ch);
        cout << ch;
    }
    
    File.close();

    // Operatate the reverse file
    File.open("ReverseFile",ios::out | ios::in);

    while (!testStack.empty())
    {
        File << testStack.top();
        testStack.pop();
    }

    File.seekg(0, ios::beg);
    cout << "\n\nContent of reverse file: \n";
    while (File.get(ch))
    {
        cout << ch;
    }
    File.close();
}