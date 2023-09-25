/********************************************************************
*** NAME : Alex Raether
*** CLASS : CSc 300
*** ASSIGNMENT : 1
*** DUE DATE : 9/25/2023
*** INSTRUCTOR : GAMRADT ***
*********************************************************************
*** DESCRIPTION : The class of this file is called List, a list of 
nodes with the ability to add (insert a new node), remove 
(delete an existing node), or view all nodes in the list
********************************************************************/

// include libraries
#include "List.h"
#include <iostream>
#include <iomanip>
using namespace std;

// default constructor
List::List()
{
    front = nullptr;
}

// copy constructor
List::List(const List &object)
{
    front = nullptr;
}

/********************************************************************
*** FUNCTION add ***
*********************************************************************
*** DESCRIPTION : adds a new node to the list ***
*** INPUT ARGS : const Element ***
*** OUTPUT ARGS : none ***
*** IN/OUT ARGS : none ***
*** RETURN : none ***
********************************************************************/
void List::add(Element element)
{
    // Create two pointers, one for the node being appended
    // and one to point to values
    Node * newNode;
    Node * nodePtr;
    
    // allocate memory for the node being appended
    newNode = new Node;
    newNode->element = element;
    newNode->next = nullptr;
    
    // check if the list exists
    if (!front)
    {
        // if it doesn't, assign the new node to the front
        front = newNode;
    } else
    {
        // if it does, go through the list until nullptr is
        // reached and insert the new node there
        nodePtr = front;
        
        while(nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        
        nodePtr->next = newNode;
    }
}


/********************************************************************
*** FUNCTION remove ***
*********************************************************************
*** DESCRIPTION : deletes a specific node from the list ***
*** INPUT ARGS : const Element ***
*** OUTPUT ARGS : none ***
*** IN/OUT ARGS : none ***
*** RETURN : none ***
********************************************************************/
void List::remove(Element element)
{
    Node * nodePtr; // traversal pointer
    Node * prevNode; // previous node pointer
    
    // if the list is empty, end the function
    if (!front)
        return;
    
    // if the front is the value we're looking for, delete it
    if (front->element == element)
    {
        // save the value after the front
        nodePtr = front->next;
        // delete the front
        delete front;
        // replace the front
        front = nodePtr;
    } else
    {
        // start at the front and go through the list till the value is found
        nodePtr = front;
        
        while (nodePtr != nullptr && nodePtr->element != element)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        // if nodePtr isn't nullptr, delete the node found
        if (nodePtr)
        {
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
    
}

/********************************************************************
*** FUNCTION view ***
*********************************************************************
*** DESCRIPTION : view the full list of nodes ***
*** INPUT ARGS : none ***
*** OUTPUT ARGS : none ***
*** IN/OUT ARGS : none ***
*** RETURN : none ***
********************************************************************/
void List::view() const
{
    // traversal node
    Node * nodePtr;
    
    // start at the front
    nodePtr = front;
    
    cout << "FRONT-> ";
    
    // if nodePtr isn't nullptr, keep displaying values
    while (nodePtr)
    {
        cout << nodePtr->element << " -> ";
        nodePtr = nodePtr->next;
    }

    cout << "END" << endl;
}

// destructor
List::~List()
{
    Node * nodePtr; // traversal node
    Node * next; // node to move forward
    
    // start at the top
    nodePtr = front;
    
    cout << "Now releasing data..." << endl;
    
    // if nodePtr isn't nullptr, keep deleting nodes
    while (nodePtr != nullptr)
    {
        next = nodePtr->next;
        
        delete nodePtr;
        
        nodePtr = next;
    }
}
