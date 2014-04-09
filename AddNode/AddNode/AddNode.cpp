/**************************************************
 *
 *      program name:       AddNode.cpp
 *      Author:             Zack Lawton
 *      date due:           02/24/2014
 *      remarks:            Create a linked list using classes and pointers
 *
 ***************************************************/

/******************************************
 *     library includes
 ******************************************/
#include <iostream>                // needed for I/O

/******************************************
 *     pre-processor
 ******************************************/
#define PI 3.14159
using namespace std;
/****************************************
 *         Class definitions
 ****************************************/
class Node
{
private:
    int* number;            //value of the node
    Node* prev;             //points to previous node
    Node* next;             //points to next node
    
public:
    //constructor
    Node();
    Node(int);
    
    //deconstructor
    ~Node();
    
    //setters
    void setPrev(Node* pp)      {prev = pp;}
    void setNext(Node* np)      {next = np;}
    void setNumber(int n)       {*number = n;}
    
    
    //getters
    Node* getPrev()      {return prev;}
    Node* getNext()      {return next;}
    int getNumber()      {return *number;}
    
    void display();
    
};
/****************************************
 *         member functions
 ****************************************/
//constructors
Node :: Node()
{
    //cout << "\n in constructor";
    number = new int(0);
    prev = NULL;
    next = NULL;
    
}

Node :: Node(int n)
{
    // cout << "\n in constructor";
    number = new int(n);
    prev = NULL;
    next = NULL;
    
}

//deconstructors
Node :: ~Node()
{
    cout << "\n in deconstructor";
    delete number;
}

//display function
void Node :: display()
{
    cout << "\n";
    cout << "node number   " << getNumber() << "\n";
    cout << "previous node " << getPrev()   << "\n";
    cout << "next node     " << getNext()   << "\n";
    cout << "current node  " << this        << "\n";
    cout << "\n";
    
}

/****************************************
 *          function prototypes
 ****************************************/

void loadLinkedList(Node** pps);
void traverseList (Node** start);
void addNode(Node** start, int addNum);
void delNode(Node** start, int delNum);


/*****************************************
 *   main() - the function that executes
 *****************************************/
int main()
{
    /*******************************
     *     local variables
     ******************************/
    Node* start;                            //start of the linked list
    //Node* temp;
    //Node* savePtr;                        //save the start of the linked list
    Node** ppStart;                         //pointer to a Node pointer
    ppStart = &start;                       //put the address of "Node* start" into ppStart
    
    //Node n1;
    //n1.display();                         //display function call
    
    loadLinkedList(ppStart);                //linked list fuction call
    
    //traverseList(ppStart);                  //displays the traverse list
    
    addNode(&start,5);          //duplicate
    addNode(&start,4);          //test in middle, in-between values
    addNode(&start,0);          //test one before the start
    addNode(&start,12);         //test right before the end
    addNode(&start,16);         //test after the end
    
    traverseList(&start);
    
    
    //delNode(&start, 7);
    
    
    //system("PAUSE");                      // causes the program to pause
	return 0;
}  // end main

void loadLinkedList(Node** pps)
{
    // we are basically just dealing with addresses of objects
    // we will store the address of the current object
    // and the address of the previous and next objects
    /*****************/
    Node* start;
    Node* temp;
    Node* savePtr;
    
    // create linked list (using new for each node)
    start = new Node(1);          // create the 1st (start) node
    savePtr = start;              // save address of CURRENT node in savePtr
    //savePtr->display();
    //system("pause");
    
    temp = new Node(3);         // create the next NEW node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS node using address of CURRENT node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT node using saved pointer
    savePtr = temp;             // save address of CURRENT node in savePtr to use with next node
    //savePtr->display();
    //system("pause");
    
    temp = new Node(5);         // create the next NEW node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS node using address of CURRENT node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT node using saved pointer
    savePtr = temp;             // save address of CURRENT node in savePtr to use with next node
    //savePtr->display();
    //system("pause");
    
    temp = new Node(7);         // create the next NEW node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS node using address of CURRENT node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT node using saved pointer
    savePtr = temp;             // save address of CURRENT node in savePtr to use with next node
    
    temp = new Node(9);         // create the next NEW node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS node using address of CURRENT node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT node using saved pointer
    savePtr = temp;             // save address of CURRENT node in savePtr to use with next node
    
    temp = new Node(11);        // create the next NEW node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS node using address of CURRENT node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT node using saved pointer
    savePtr = temp;             // save address of CURRENT node in savePtr to use with next node
    
    temp = new Node(13);        // create the next NEW node
    savePtr->setNext(temp);     // set setNext of the PREVIOUS node using address of CURRENT node
    temp->setPrev(savePtr);     // set setPrevious of CURRENT node using saved pointer
    savePtr = temp;             // save address of CURRENT node in savePtr to use with next node
    
    *pps = start;               //tells the function where to start
    
    //system ("pause");
}

void traverseList (Node** start)
{
    Node* current;                  //stores the current node
    current = *start;               //sets current equal to the address of start
    
    current ->display();            //puts the current node into the display function
    
    while(current->getNext() !=NULL)
    {
        current = current->getNext();
        current->display();
    }
    
}

void delNode(Node** start, int delNum)
{
    
    Node* current;                      //stores the current node
    current = *start;                   //sets current equal to the address of start
    
    while (delNum != current->getNumber() && current->getNext() != NULL)
    {
        current = current->getNext();
    }
 
    if (current->getNumber() == delNum)
    {
        if(current->getPrev() == NULL && current->getNext() == NULL);
        //first Node
        else if(current->getPrev() == NULL)
        {
            current->getNext()->getPrev();
            *start = current->getNext();
        }
        //Last Node
        else if(current -> getNext() == NULL)
        {
            current->getPrev()->setNext(NULL);
        }
        //middle Node
        else
        {
            current->getNext()->setPrev(current->getPrev());
            current->getPrev()->setNext(current->getNext());
        }
        
            
    }
    
    cout << "in *delete* node\n";
    current->display();                 //puts the current node into the display function
    
}


void addNode(Node** start, int addNum)
 {
 
     Node* current;              //stores the current node
     Node* add;
     current = *start;           //sets current equal to the address of start
     add = new Node (addNum);
 
     //Traversing the list
    while (current->getNext() != NULL && current->getNumber() < addNum)
    {
            current = current->getNext();
    }
    //Prints if the current node is the same as the add node
    if (current->getNumber() == add->getNumber())
    {
         cout << "duplicate add\n";
    }
 
    else if(current->getPrev() == NULL)
    {
        //cout << "add before start\n";
        current->setPrev(add);
        add->setNext(current);
        *start = add;
    }
     
    else if (current->getNext() == NULL)
    {
        if (addNum < current->getNumber())     // Add before last node
        {
            add->setNext(current);
            add->setPrev(current->getPrev());
            current->setPrev(add);
            current = add->getPrev();
            current->setNext(add);
        }
        else                                   // Add after last node
        {
            current->setNext(add);
            add->setPrev(current);
        }
             
    }
     
    else
    {
       // cout << "regular add\n";
        add->setNext(current);
        add->setPrev(current->getPrev());
        current->setPrev(add);
        current = add->getPrev();
        current->setNext(add);
    }
     
    //current->display();
     
     //cout << "add node";
 }














