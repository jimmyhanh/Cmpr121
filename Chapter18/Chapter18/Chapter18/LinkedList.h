// A class template for holding a linked list.
// The node type is also a class template.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
//*********************************************
template<class T>
class ListNode
{
public:
    T value;           // Node value
    ListNode* next; // Pointer to the next node

    // Constructor
    ListNode(T nodeValue)
    {
        value = nodeValue;
        next = nullptr;
    }
};

//*********************************************
// LinkedList class                           *
//*********************************************

template<class T>
class LinkedList
{
private:
    ListNode<T> * head;   // List head pointer

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;
    }

    // Copy Constructor by Prof Q
    LinkedList(const LinkedList<T>& link)
    {
        ListNode<T>* nodePtr;  // To move through the list

         // Position nodePtr at the head of the list.
        nodePtr = link.head;

        // While nodePtr points to a node, traverse
        // the list.
        while (nodePtr)
        {
            appendNode(nodePtr->value);

            // Move to the next node.
            nodePtr = nodePtr->next;
        }
    }

    // Destructor
    ~LinkedList()
    {
        ListNode<T>* nodePtr;   // To traverse the list
        ListNode<T>* nextNode;  // To point to the next node

        // Position nodePtr at the head of the list.
        nodePtr = head;

        // While nodePtr is not at the end of the list...
        while (nodePtr != nullptr)
        {
            // Save a pointer to the next node.
            nextNode = nodePtr->next;

            // Delete the current node.
            delete nodePtr;

            // Position nodePtr at the next node.
            nodePtr = nextNode;
        }
    }

    // Linked list operations
    void appendNode(T newValue)
    {
        ListNode<T>* newNode;  // To point to a new node
        ListNode<T>* nodePtr;  // To move through the list

        // Allocate a new node and store newValue there.
        newNode = new ListNode<T>(newValue);

        // If there are no nodes in the list
        // make newNode the first node.
        if (!head)
            head = newNode;
        else  // Otherwise, insert newNode at end.
        {
            // Initialize nodePtr to head of list.
            nodePtr = head;

            // Find the last node in the list.
            while (nodePtr->next)
                nodePtr = nodePtr->next;

            // Insert newNode as the last node.
            nodePtr->next = newNode;
        }

    }
    void insertNode(T newValue)
    {
        ListNode<T>* newNode;				// A new node
        ListNode<T>* nodePtr;				// To traverse the list
        ListNode<T>* previousNode = nullptr; // The previous node

        // Allocate a new node and store newValue there.
        newNode = new ListNode<T>(newValue);

        // If there are no nodes in the list
        // make newNode the first node
        if (!head)
        {
            head = newNode;
            newNode->next = nullptr;
        }
        else  // Otherwise, insert newNode
        {
            // Position nodePtr at the head of list.
            nodePtr = head;

            // Initialize previousNode to nullptr.
            previousNode = nullptr;

            // Skip all nodes whose value is less than newValue.
            while (nodePtr != nullptr && nodePtr->value < newValue)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            // If the new node is to be the 1st in the list,
            // insert it before all other nodes.
            if (previousNode == nullptr)
            {
                head = newNode;
                newNode->next = nodePtr;
            }
            else  // Otherwise insert after the previous node.
            {
                previousNode->next = newNode;
                newNode->next = nodePtr;
            }
        }
    }

    void deleteNode(T searchValue)
    {
        ListNode* nodePtr;       // To traverse the list
        ListNode* previousNode = nullptr;  // To point to the previous node

        // If the list is empty, do nothing.
        if (!head)
            return;

        // Determine if the first node is the one.
        if (head->value == searchValue)
        {
            nodePtr = head->next;
            delete head;
            head = nodePtr;
        }
        else
        {
            // Initialize nodePtr to head of list
            nodePtr = head;

            // Skip all nodes whose value member is 
            // not equal to num.
            while (nodePtr != nullptr && nodePtr->value != searchValue)
            {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            // If nodePtr is not at the end of the list, 
            // link the previous node to the node after
            // nodePtr, then delete nodePtr.
            if (nodePtr)
            {
                previousNode->next = nodePtr->next;
                delete nodePtr;
            }
        }
    }

    void displayList() const
    {
        ListNode<T>* nodePtr;  // To move through the list

        // Position nodePtr at the head of the list.
        nodePtr = head;

        // While nodePtr points to a node, traverse
        // the list.
        while (nodePtr)
        {
            // Display the value in this node.
            cout << nodePtr->value << endl;

            // Move to the next node.
            nodePtr = nodePtr->next;
        }
    }

    void removalPosition(int n)
    {
        ListNode<T>* nodePtr;                   // To move through the list
        ListNode<T>* previousNode = nullptr;    // To point to the previous node

        // If the list is empty do nothing
        if (!head)
            return;

        // If the number passed by is negative, do nothing
        if (n < 0)
            return;

        // If the position is 0, remove the head list
        if (n == 0)
        {
            nodePtr = head->next;         // Initialize nodePtr to the next node
            delete head;                  // Delete head
            head = nodePtr;               // Made nodePtr the head list
        }

        // Initialize nodePtr to the head of list
        nodePtr = head;

        // Move to the next node n times 
        for (int i = 0; i < n; i++)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;

            // If nodePtr is at the end of list, do nothing
            if (!nodePtr)
                return;
        }

        // After traversing the node, delete the node
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
       
    void mergeArray(T array[], int size)
    {
        for (int i = 0; i < size; i++)
            this->insertNode(array[i]);
    }
};

#endif