
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

/*****************************************
 *   main() - the function that executes
 *****************************************/
int main()
{
    /*******************************
     *     local variables
     ******************************/
    Node* start;                        //start of the linked list
    //Node* temp;
    //Node* savePtr;                    //save the start of the linked list
    Node** ppStart;                     //pointer to a Node pointer
    ppStart = &start;                   //put the address of "Node* start" into ppStart
    
    loadLinkedList(ppStart);            //linked list fuction call
    
    traverseList(ppStart);               //displays the traverse list
    
    //system("PAUSE");                  // causes the program to pause
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

void traverseList(Node** start)
{
    Node* current;
    current = *start;
    
    current->display();
    
    while (current->getNext() != NULL)
    {
        current = current->getNext();
        current->display();
    }
    
}

