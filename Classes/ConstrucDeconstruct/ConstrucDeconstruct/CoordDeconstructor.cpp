/**************************************************
* 
*      program name:       Skeleton
*      Author:             Captain Kirk
*      date due:            
*      remarks:            Skeleton C code 
*                          Start with this format    
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

/******************************************
*     function prototypes
******************************************/
void testDestructor();

/****************************************
*         Class definitions
****************************************/
class Coord
{
    private:
        int* xCoord;
        int* yCoord;
        int* zCoord;
    public:
        // constructors
        Coord();
        Coord(int x, int y, int z);
        
        // setters
        void setXCoord(int x)     {*xCoord = x;}
        void setYCoord(int y)     {*yCoord = y;}
        void setZCoord(int z)     {*zCoord = z;}

        // getters
        int  getXCoord()const      {return *xCoord;}
        int  getYCoord()const      {return *yCoord;}
        int  getZCoord()const      {return *zCoord;}
        
        // destructor
        ~Coord();
        
        void display();     
};

/****************************************
*         member functions
****************************************/
// Constructors
Coord :: Coord ()
{
      cout << "in default constructor\n";
      xCoord = new int;
      yCoord = new int;
      zCoord = new int;
    
      setXCoord(0);
      setYCoord(0);
      setZCoord(0);
}
Coord :: Coord (int x, int y, int z)
{
      cout << "in constructor with 3 ints\n";
    
    xCoord = new int;
    setXCoord(x);
    
    yCoord = new int;
    setYCoord(y);
    
    zCoord = new int;
    setZCoord(z);
}

// Destructor
Coord :: ~Coord()
{
    cout << "in destructor\n";
    
    delete xCoord;
    delete yCoord;
    delete zCoord;
}

// Function: Display()
void Coord :: display()
{
     cout << "\n";
     cout << "*** co-ordinate object ***\n";
     cout << "xCoord    " << getXCoord() << endl;
     cout << "yCoord    " << getYCoord() << endl;
     cout << "zCoord    " << getZCoord() << endl;
     cout << "\n";     
}

/****************************************
*          function prototypes
****************************************/
void display();

/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
    // int x;
    //int* px;
    
    
    Coord c3(1, 2, 3);
    
    Coord c1;
    c1.display();
    c3.display();
    
    testDestructor();
    
    //system("PAUSE");               // causes the program to pause
	return 0;
}  // end main

/*****************************************
*   display function
*****************************************/
void testDestructor()
{
     cout << "in test destructor function\n";
     Coord xx(4,4,4);
}

















