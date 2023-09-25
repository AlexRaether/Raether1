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
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "List.h"
using namespace std;

// define constants
const float num1 = 7.7;
const float num2 = 2.34;
const float num3 = 32.03;

int main()
{
    // define user input variables
    float del;
    float num;
    int choice;
    
    List List1;
   
    // test append function
    List1.add(num1);
    List1.add(num2);
    List1.add(num3);
    

    do {
    
        cout << "Current List: ";
        // test display function
        List1.view();

        cout << "*** Menu ***" << endl << "1. Add" << endl << "2. Remove" << endl << "3. Exit" << endl << "Select from the options above" << endl;

        cin >> choice;

        switch (choice)
        {
            // add function
            case 1: 
                    // ask for the user to put in a node
                    cout << "Enter a node to add to the list: ";
                    cin >> num;
                    cout << "Now adding node " << num << endl;
                    
                    // delete node
                    List1.add(num);

                    break;
            case 2: 
                    // ask for the user to delete a node
                    cout << "From the list above, enter a node to delete in the list: ";
                    cin >> del;
                    cout << "Now deleting node " << del << endl;

                    List1.remove(del);

                    break;
        }

    } while (choice != 3);
    
    return 0;
}


