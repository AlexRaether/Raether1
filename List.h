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

#ifndef _LIST_H // Guard – start
#define _LIST_H

typedef float Element; // typedef <existing type> <new type>

// Define the class
class List {
    public: // exportable

    // default constructor
    List();
    
    // copy constructor
    List( const List & ); // reuse add
    
    // destructor
    ~List();

    // basic functions 
    /********************************************************************
    *** FUNCTION add ***
    *********************************************************************
    *** DESCRIPTION : adds a new node to the list ***
    *** INPUT ARGS : const Element ***
    *** OUTPUT ARGS : none ***
    *** IN/OUT ARGS : none ***
    *** RETURN : none ***
    ********************************************************************/
    void add( const Element );
    /********************************************************************
    *** FUNCTION remove ***
    *********************************************************************
    *** DESCRIPTION : deletes a specific node from the list ***
    *** INPUT ARGS : const Element ***
    *** OUTPUT ARGS : none ***
    *** IN/OUT ARGS : none ***
    *** RETURN : none ***
    ********************************************************************/
    void remove( const Element );
    /********************************************************************
    *** FUNCTION view ***
    *********************************************************************
    *** DESCRIPTION : view the full list of nodes ***
    *** INPUT ARGS : none ***
    *** OUTPUT ARGS : none ***
    *** IN/OUT ARGS : none ***
    *** RETURN : none ***
    ********************************************************************/
    void view() const;


    private: 
        struct Node;
    
        // Create a node for traversal
        typedef Node * NodePtr;

        // Node structure 
        struct Node {
            Element element;
            NodePtr next;
        };        
        
        // Initialize head pointer
        NodePtr front;
};

#endif