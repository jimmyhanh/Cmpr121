// Name: Hung Anh Ho
// Date: 11-26-2023
// Description: Exam 3 - STL Container

#include <iostream>
#include "input.h"
#include "Rational.h"
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <queue>

char menuOption();
int menuOptionV(vector<Rational>&);
int menuOptionL(list<Rational>&);
void displayAllStack(stack<Rational, vector<Rational>>);
void displayAllQueue(queue<Rational, list<Rational>>);

void CaseV();
void CaseL();
void CaseS();
void CaseQ();

Rational getRational();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 'X': exit(0); break;
        case 'V': CaseV(); break;
        case 'L': CaseL(); break;
        case 'S': CaseS(); break;
        case 'Q': CaseQ(); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}


// Display main menu option
char menuOption()
{
    system("cls");
    //cout << "                                                                    ║ in/out ║            ║   in   ║";
    //cout << "                                                                    ║ ┌────┐ ║            ║ ┌────┐ ║";
    //cout << "                                                                top»║ │ 1/2│ ║       rear»║ │ 5/6│ ║";
    //cout << "                                                                    ║ ├────┤ ║            ║ ├────┤ ║";
    //cout << "           ┌────┬────┬────┐         ┌────┐ ┌────┐ ┌────┐            ║ │ 3/4│ ║            ║ │ 3/4│ ║";
    //cout << "           │ 1/2│ 3/4│ 5/6│       ┌»│ 1/2│»│ 3/4│»│ 5/6│            ║ ├────┤ ║            ║ ├────┤ ║";
    //cout << "           └────┴────┴────┘       │ └────┘ └────┘ └────┘            ║ │ 5/6│ ║      front»║ │ 1/2│ ║";
    //cout << "           0    1    2            head                              ║ └────┘ ║            ║ └────┘ ║";
    //cout << "        (index)(pointer)                                            ╚════════╝            ║  out   ║";
    //cout << "\n";
    //cout << "            Vector(list array)        Linked List                      Stack                Queue";
    cout << "\n\t\033[97m" << "A container is a holder object that stores a collection of other objects (its elements). They";
    cout << "\n\t\033[97m" << "are implemented as class templates, which allows great flexibility in the types supported as";
    cout << "\n\t\033[97m" << "elements. The container manages the storage space for its elementsand provides member functions";
    cout << "\n\t\033[97m" << "to access them, either directly or through iterators(reference objects with similar properties";
    cout << "\n\t\033[97m" << "to pointers).";

    cout << "\n\033[0m";

    cout << "\n\tCMPR121 Exam3: STL (Standard Template Library) Containers and Container Adaptors by Hung Anh Ho (11/26/2023)";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\tV. Vector Container";
    cout << "\n\t\tL. List Container";
    cout << "\n\t\tS. Stack Container Adapter";
    cout << "\n\t\tQ. Queue Container Adapter";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\tX. Exit";
    cout << "\n\t" << string(100, char(205));

    return inputChar("\n\t\tOption: ", static_cast <string>("VLSQX"));
}


// Pre-condition: None
// Post-condition: Return the Rational data type by user input, will throw an exception if the input is invalid
Rational getRational()
{
    Rational temp;
    temp.setNumerator(inputInteger("\n\t\tEnter a numerator (-9...9): ", -9, 9));

    try
    {
        temp.setDenominator(inputInteger("\n\t\tEnter a denominator (-9...9): ", -9, 9));
    }
    catch (Rational::ZeroDenominator)
    {
        throw;  // Rethrow the exception
    }

    return temp;
}




//Vector
void CaseV()
{
    // Instaniate the vector container of rational
    vector<Rational> Container;

    do
    {
        switch (menuOptionV(Container))
        {
        case 0: Container.clear();  return;
        case 1: // Add element to a back
        {
            try
            {
                cout << "\n\tInput a Rational number to be added...";
                Rational temp = getRational();

                // Push_back the element to the back
                cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be added to the back of the vector. ";
                cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

                Container.push_back(temp);
            }
            catch(Rational::ZeroDenominator)
            {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot add a Rational number with a zero denominator value.";
            }
        }
        break;
        case 2: // Insert an element at an index
        {
            try
            {
                cout << "\n\tInput a Rational number to be inserted...";
                Rational temp = getRational();
                
                int maxIndex = (Container.empty() ? 0 : Container.size() - 1);
                
                int index = inputInteger("\n\t\tInsert the element at index (0..." + to_string(maxIndex) + ") of the vector: ", 0, maxIndex);

                cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be inseted at index[" << to_string(index) << "] to the vector. ";
                cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

                Container.insert(Container.begin() + index, temp);
            }
            catch(Rational::ZeroDenominator)
            {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot insert a Rational number with a zero denominator value.";
            }
        }
        break;
        case 3: // Retrieve
        {
            if (Container.empty())
            {
                cout << "\n\t\tRetrieve operation cannot be performed on an empty vector.";
                break;
            }

            int maxIndex = Container.size() - 1;
            int index = inputInteger("\n\t\tEnter an index (0..." + to_string(maxIndex) + ") of Rational Number to be retrieved: ", 0, maxIndex);

            cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
            cout << "\n\t\t" << char(179) << setw(4) << right << Container[index].toString() << char(179) << " is located at index[" << to_string(index) << "] from the vector. ";
            cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
        }
        break;
        case 4: // Erase
        {
            if (Container.empty())
            {
                cout << "\n\t\tErase operation cannot be performed on an empty vector.";
                break;
            }

            try
            {
                cout << "\n\tInput a Rational number to be removed...";
                Rational temp = getRational();

                // Use the find algorithm to get the position of the value found
                auto it = find(Container.begin(), Container.end(), temp);

                // If cannot find the value, display the message
                if (it == Container.end())
                {
                    cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                    cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " cannot be found from the vector.";
                    cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
                    break;
                }

                // Otherwise, choose delete option 
                char choice = inputChar("\n\tDo you want to remove (O-one or A-all) element(s): ", static_cast <string>("OA"));

                cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be removed from the vector.";
                cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

                if (toupper(choice) == 'O')
                    Container.erase(it);
                else if (toupper(choice) == 'A')
                {
                    // Delete all the same value in the vector
                    while (it != Container.end())
                    {
                        Container.erase(it);
                        it = find(Container.begin(), Container.end(), temp);
                    }
                }
            }
            catch (Rational::ZeroDenominator)
            {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot remove a Rational number with a zero denominator value.";
            }
           
        }
        break;
        case 5: // Sort
        {
            if (Container.empty())
            {
                cout << "\n\t\tSort operation cannot be performed on an empty vector.";
                break;
            }

            cout << "\n\t\tThe vector will be sorted in ascending order.";
            sort(Container.begin(), Container.end());

        }
        break;
        case 6: // Clear
        {
            if (Container.empty())
            {
                cout << "\n\t\tClear operation cannot be performed on an empty vector.";
                break;
            }

            cout << "\n\t\tThe vector will be cleared of all elements.";
            Container.clear();

        }
        break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

}

// Pre-condition: the Rational- in Vector data type by user input
// Post-condition: Return the Rational data type by user input, will throw an exception if the input is invalid or vector is empty
int menuOptionV(vector<Rational>& Container)
{
    system("cls");

    cout << "\n\t\033[91m" << "Vectors are same as dynamic arrays with the ability to resize itself automatically when an";
    cout << "\n\t\033[91m" << "element is inserted or deleted, with their storage being handled automatically by the container.";
    cout << "\n\t\033[91m" << "Vector elements are placed in contiguous storage so that they can be accessed and traversed";
    cout << "\n\t\033[91m" << "using iterators or indexes.";
    cout << "\n\033[0m";

    // Display all element
    if (Container.empty())
        cout << "\n\tThe current vector is empty\n\n\n";
    else
    {
        int SIZE = Container.size();

        cout << "\n\tThe current vector contains " << to_string(SIZE) << " elements: ";

        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << char(218) << string(4, char(196)) << char(191);

        cout << "\n\t\t";
        for (auto i : Container)
            cout << char(179) << setw(4) << right << i.toString() << char(179);

        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << char(192) << string(4, char(196)) << char(217);

        cout << "\n\tIndex:\t";
        for (int i = 0; i < SIZE; i++)
            cout << i << string(5, char(' '));

        cout << "\n\tAddress: " << &Container[0];
    }

    cout << "\n";
    cout << "\n\t\tVector Menu Options";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\t1. Add an element to the back";
    cout << "\n\t\t2. Insert an element at an index";
    cout << "\n\t\t3. Retrieve an element at an index";
    cout << "\n\t\t4. Erase element(s)";
    cout << "\n\t\t5. Sort the elements in ascending order";
    cout << "\n\t\t6. Clear all elements";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0. Return";
    cout << "\n\t" << string(100, char(205));

    return inputInteger("\n\t\tOption: ", 0, 6);
}




//LinkList
void CaseL()
{
    // Instaniate the list container of rational
    list<Rational> Container;

    do
    {
        switch (menuOptionL(Container))
        {
        case 0: Container.clear();  return;
        case 1: // Add element to a list
        {
            try 
            {
                Rational temp = getRational();

                char choice = inputChar("\n\tAdd to the (F-front) or from the (B-back): ", static_cast <string>("FB"));

                if (toupper(choice) == 'F')
                {
                    cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                    cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be pushed to the front of the list.";
                    cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
                    Container.push_front(temp);
                }
                else
                {
                    cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                    cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be pushed to the back of the list.";
                    cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
                    Container.push_back(temp);
                }
            }
            catch (Rational::ZeroDenominator)
            {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot add a Rational number, with a zero denominator value.";
            }
            
        }
        break;
        
        case 2: // Insert an element
        {
            try
            {
                cout << "\n\tInput a Rational number to be inserted...";
                Rational temp = getRational();

                // Insert at the first index if vector is empty, otherwise insert at the spcified position
                if (Container.empty())
                {
                    cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                    cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be inseted to the empty list. ";
                    cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

                    Container.insert(Container.begin(), temp);
                    break;
                }

                cout << "\n\tInput an existing Rational number as the insert position to be added...";
                Rational searchValue = getRational();
               
                // Use the find algorithm to get the position of the value found
                auto it = find(Container.begin(), Container.end(), searchValue);

                // If cannot find the value, display the message
                if (it == Container.end())
                {
                    cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                    cout << "\n\t\t" << char(179) << setw(4) << right << searchValue.toString() << char(179) << " cannot be found from the list.";
                    cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
                    break;
                }


                // Otherwise, choose insert after or before the search value  
                char choice = inputChar("\n\tInsert (B-before) or (A-after) the existing element : ", static_cast <string>("AB"));

                if (toupper(choice) == 'A')
                {
                    cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                    cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be inserted after the existing element from the list.";
                    cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
                    Container.insert(++it,temp);
                }
                else
                {
                    cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                    cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be inserted before the existing element from the list.";
                    cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
                    Container.insert(it, temp);
                }                   
            }
            catch(Rational::ZeroDenominator)
            {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot insert a Rational number with a zero denominator value.";
            }
                    
        }
        break;
      
        case 3: // Erase
        {
            if (Container.empty())
            {
                cout << "\n\t\tErase operation cannot be performed on an empty list.";
                break;
            }

            try
            {
                cout << "\n\tInput a Rational number to be removed...";
                Rational temp = getRational();

                // Use the find algorithm to get the position of the value found
                auto it = find(Container.begin(), Container.end(), temp);

                // If cannot find the value, display the message
                if (it == Container.end())
                {
                    cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                    cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " cannot be found from the list.";
                    cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
                    break;
                }

                // Otherwise, choose delete option 
                char choice = inputChar("\n\tDo you want to remove (O-one or A-all) element(s): ", static_cast <string>("OA"));

                cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be removed from the list.";
                cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

                if (toupper(choice) == 'O')
                    Container.erase(it);
                else if (toupper(choice) == 'A')
                {
                    // Delete all the same value in the list
                    while (it != Container.end())
                    {
                        Container.erase(it);
                        it = find(Container.begin(), Container.end(), temp);
                    }
                }

            }
            catch (Rational::ZeroDenominator)
            {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot remove a Rational number with a zero denominator value.";
            }

        }
        break;

        case 4: // Sort
        {
            if (Container.empty())
            {
                cout << "\n\t\tSort operation cannot be performed on an empty vector.";
                break;
            }

            cout << "\n\t\tThe list will be sorted in ascending order.";
            Container.sort();
        }
        break;
        
        case 5: // Clear
        {
            if (Container.empty())
            {
                cout << "\n\t\tClear operation cannot be performed on an empty vector.";
                break;
            }

            cout << "\n\t\tThe list will be cleared of all elements.";
            Container.clear();

        }
        break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        
        }
        cout << "\n";
        system("pause");

    } while (true);
}

// Pre-condition: the Rational- in Linkedlist data type by user input
// Post-condition: Return the Rational data type by user input, will throw an exception if the input is invalid or list is empty
int menuOptionL(list<Rational>& Container)
{
    system("cls");

    cout << "\n\t\033[93m" << "Lists are sequence containers that allow non-contiguous memory allocation. As compared to";
    cout << "\n\t\033[93m" << "vector, the list has slow traversal, but once a position has been found, insertion and";
    cout << "\n\t\033[93m" << "deletion are quicker.";
    cout << "\n\033[0m";

    // Display all element
    if (Container.empty())
        cout << "\n\tThe current list is empty\n\n\n";
    else
    {
        int SIZE = Container.size();

        cout << "\n\tThe current list contains " << to_string(SIZE) << " elements: ";

        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << char(218) << string(4, char(196)) << char(191) << " ";

        cout << "\n\t\t";
        for (auto it = Container.begin(); it != Container.end(); it++)
        {
            cout << char(179) << setw(4) << right << it->toString() << char(179);

            if (it != --Container.end())
                cout << char(175);
        }

        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << char(192) << string(4, char(196)) << char(217) << " ";

        cout << "\n\tAddress: " << &Container;
    }

    cout << "\n";
    cout << "\n\t\tList Menu Options";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\t1. Add an element";
    cout << "\n\t\t2. Insert an element";
    cout << "\n\t\t3. Remove element(s)";
    cout << "\n\t\t4. Sort the elements in ascending order";
    cout << "\n\t\t5. Clear all elements";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0. Return";
    cout << "\n\t" << string(100, char(205));

    return inputInteger("\n\t\tOption: ", 0, 5);
}




//Stacks
int menuOptionS(stack<Rational, vector<Rational>> Container)
{
    system("cls");

    // Description
    cout << "\n\t\033[96m" << "Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where";
    cout << "\n\t\033[96m" << "a new element is added(push) at one end(top) and an element is removed(pop) from that end";
    cout << "\n\t\033[96m" << "only. Stack uses an encapsualted object of either vector or deque(by default) or list (sequential.";
    cout << "\n\t\033[96m" << "container class) as its underlying container,providing a specific set of member functions to";
    cout << "\n\t\033[96m" << "access it elements" << "\n\033[0m";

    // Display all element
    if (Container.empty())
        cout << "\n\tThe current stack is empty\n\n\n";
    else
    {
        int SIZE = Container.size();

        cout << "\n\tThe current stack contains " << to_string(SIZE) << " elements: ";

        cout << "\n\t\t\033[96m";

        // The first line
        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << string(6, char(205));
        cout << char(187) << "\033[0m";

        // The second line
        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << char(218) << string(4, char(196)) << char(191);

        cout << "\033[96m" << char(186) << "\033[0m";

        // The third line
        cout << "\n\t\033[96m" << "top " << char(175) << "\t\033[0m";
        displayAllStack(Container); // Using recurrence to display its content
        cout << "\033[96m" << char(186) << "\033[0m";

        // The fourth line
        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << char(192) << string(4, char(196)) << char(217);
        cout << "\033[96m" << char(186) << "\033[0m";

        // The fifth line
        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << "\033[96m" << string(6, char(205));
        cout << "\033[96m" << char(188) << "\033[0m";
    }

    // Display menu
    cout << "\n";
    cout << "\n\t\tStack Menu Options";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\t1. Push";
    cout << "\n\t\t2. Top";
    cout << "\n\t\t3. Pop";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0. Return";
    cout << "\n\t" << string(100, char(205));

    return inputInteger("\n\t\tOption: ", 0, 3);
}

// Pre-condition: the Rational- in Stacked data type by user input
// Post-condition: Return the Rational data type by user input, will throw an exception if the input is invalid or stack is empty
void CaseS()
{
    stack<Rational, vector<Rational>> Container;

    do
    {
        switch (menuOptionS(Container))
        {
        case 0:
        {
            while (Container.size() != 0){Container.pop();}

            return;
        }
        case 1: // Push
        {
            try
            {
                cout << "\n\tInput a Rational number to be pushed...";
                Rational temp = getRational();

                // Push_back the element to the back
                cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be pushed onto the stack. ";
                cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

                Container.push(temp);
            }
            catch (Rational::ZeroDenominator)
            {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot push a Rational number with a zero denominator value.";
            }
        }
        break;
        case 2: // Top
        {
            if (Container.empty())
            {
                cout << "\n\t\tNo top element can be retrieved from an empty stack.";
                break;
            }

            Rational top = Container.top();

            cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
            cout << "\n\t\t" << char(179) << setw(4) << right << top.toString() << char(179) << " is at the top of the stack. ";
            cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
        }
        break;
        case 3: // Pop
        {
            if (Container.empty())
            {
                cout << "\n\t\No pop operation can be performed from an empty stack.";
                break;
            }

            Rational top = Container.top();

            cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
            cout << "\n\t\t" << char(179) << setw(4) << right << top.toString() << char(179) << " will be popped from the stack ";
            cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

            Container.pop();
        }
        break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}

//Dispaly Stack
void displayAllStack(stack<Rational, vector<Rational>> Container)
{
    // If stack is empty
    if (Container.empty())
        return;

    // Extract top of the stack
    Rational x = Container.top();

    // Pop the top element
    Container.pop();

    // Print the current top of the stack 
    cout << char(179) << setw(4) << right << x.toString() << char(179);

    // Proceed to print remaining stack
    displayAllStack(Container);

    // Push the element back
    Container.push(x);

}




//Queues
int menuOptionQ(queue<Rational, list<Rational>> Container)
{
    system("cls");

    // Description
    cout << "\n\t\033[92m" << "Queues are a type of container adaptors that operate in a first in first out (FIFO) type of";
    cout << "\n\t\033[92m" << "arrangement. Elements are inserted(enqueued) at the back and are deleted (dequeued) from the";
    cout << "\n\t\033[92m" << "front. Queues use an encapsulated object of deque or list(sequential container class) as its";
    cout << "\n\t\033[92m" << "underlying container, providing a specific set of member functions to access elements." << "\n\033[0m";

    // Display all element
    if (Container.empty())
        cout << "\n\tThe current queue is empty\n\n\n";
    else
    {
        int SIZE = Container.size();

        cout << "\n\tThe current queue contains " << to_string(SIZE) << " elements: ";

        cout << "\n\t\t\033[92m";

        // The first line
        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << string(6, char(205));

        cout << "\033[0m";

        // The second line
        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << char(218) << string(4, char(196)) << char(191);

        // The third line
        cout << "\n\t\033[92m" << "back " << char(175) << "\t\033[0m";
        displayAllQueue(Container); // Using recurrence to display its content
        cout << "\033[92m  " << char(174) << "  front" << "\033[0m";

        // The fourth line
        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << char(192) << string(4, char(196)) << char(217);

        // The fifth line
        cout << "\n\t\t";
        for (int i = 0; i < SIZE; i++)
            cout << "\033[92m" << string(6, char(205));
        
        cout << "\033[0m";
    }

    // Display menu
    cout << "\n";
    cout << "\n\t\tQueue Menu Options";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t\t1. Enqueue (Push in from the back)";
    cout << "\n\t\t2. Front";
    cout << "\n\t\t3. Back";
    cout << "\n\t\t4. Dequeue (Pop from the front)";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t\t0. Return";
    cout << "\n\t" << string(100, char(205));

    return inputInteger("\n\t\tOption: ", 0, 4);
}

// Pre-condition: the Rational- in Queues data type by user input
// Post-condition: Return the Rational data type by user input, will throw an exception if the input is invalid or queue is empty
void CaseQ()
{
    queue<Rational, list<Rational>> Container;

    do
    {
        switch (menuOptionQ(Container))
        {
        case 0:
        {
            // Pop all the queue
            while (Container.size() != 0) { Container.pop(); }
            return;
        }
        case 1: // Enqueue
        {
            try
            {
                cout << "\n\tInput a Rational number to be enqueued...";
                Rational temp = getRational();

                // Push_back the element to the back
                cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
                cout << "\n\t\t" << char(179) << setw(4) << right << temp.toString() << char(179) << " will be enqueued (pushed) onto the queue.";
                cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
                
                Container.push(temp);
            }
            catch (Rational::ZeroDenominator)
            {
                cout << "\n\tEXCEPTIONAL ERROR: Cannot enqueue a Rational number with a zero denominator value.";
            }
        }
        break;
        case 2: // Front
        {
            if (Container.empty())
            {
                cout << "\n\t\tNo front element can be retrieved from an empty queue.";
                break;
            }

            // Display the front of the queue
            cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
            cout << "\n\t\t" << char(179) << setw(4) << right << Container.front().toString() << char(179) << " is at the front of the queue. ";
            cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
            
        }
        break;
        case 3: // Back
        {
            if (Container.empty())
            {
                cout << "\n\t\tNo back element can be retrieved from an empty queue.";
                break;
            }

            // Display the back of the queue
            cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
            cout << "\n\t\t" << char(179) << setw(4) << right << Container.back().toString() << char(179) << " is at the back of the queue. ";
            cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);
        }
        break;
        case 4: // Pop
        {
            if (Container.empty())
            {
                cout << "\n\t\No dequeue (pop) operation can be performed on an empty queue.";
                break;
            }

            // Pop the front of the queue
            cout << "\n\t\t" << char(218) << string(4, char(196)) << char(191);
            cout << "\n\t\t" << char(179) << setw(4) << right << Container.front().toString() << char(179) << " will be popped from the queue ";
            cout << "\n\t\t" << char(192) << string(4, char(196)) << char(217);

            Container.pop();
            
        }
        break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

//Display Queue
void displayAllQueue(queue<Rational, list<Rational>> Container)
{
    if (Container.size() == 0)
        return;

    // Store the front of the queue
    Rational x = Container.front();

    // Pop the front
    Container.pop();

    // Display the remaining queue
    displayAllQueue(Container);

    // Push the element to the back
    Container.push(x);

    // Print the bottom of the queue
    cout << char(179) << setw(4) << right << x.toString() << char(179);
}