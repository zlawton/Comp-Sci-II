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
/****************************************
*         Class definitions
****************************************/
class Coord
{
    private:
        int xCoord;
        int yCoord;
        int zCoord;
    
    public:
        //constructors
        Coord(int x, int y, int z);         //3 int constructor
        Coord();                            //example of a defult constructor
    
        //deconstructor
        ~Coord();
    
    
        // setters
        void setXCoord(int x)     {xCoord = x;}
        void setYCoord(int x)     {yCoord = x;}
        void setZCoord(int x)     {zCoord = x;}

        // getters
        int  getXCoord(int x)     {return xCoord;}
        int  getYCoord(int x)     {return yCoord;}       
        int  getZCoord(int x)     {return zCoord;}        
                        
        void display();     
};

/****************************************
*         member functions
****************************************/
    //constructors
Coord :: Coord()
{
    cout << "in default constructor \n";
    setXCoord(0);
    setYCoord(0);
    setZCoord(0);
}

Coord :: Coord(int x, int y, int z)
{
    cout << "in the 3 int constructor \n";
    setXCoord(x);
    setYCoord(y);
    setZCoord(z);
}

    //deconstructor
Coord :: ~Coord()
{
    cout << "in deconstructor \n\n";
}


void Coord :: display()
{
     cout << "\n";
     cout << "*** co-ordinate object ***\n";
     cout << "xCoord    " << xCoord << endl;
     cout << "yCoord    " << yCoord << endl;
     cout << "zCoord    " << zCoord << endl;
     cout << "\n";     
}

/****************************************
*          function prototypes
****************************************/
void testDestructor();

/*****************************************
*   main() - the function that executes
*****************************************/
int main()
{
    /*******************************
    *     local variables
    ******************************/
    
    
    Coord c1;
    Coord c2(1, 2, 3);
    
    c1.display();
    c2.display();
    
    testDestructor();
    
    //display();    
    //c1.xCoord = 44;           error - cannot access a provate data item
    //c1.display();
    //c1.setXCoord(44);
    //c1.display();
   
    //system("PAUSE");               // causes the program to pause
	return 0;
}  // end main

void testDestructor()
{
     cout << "in test destructor\n\n";
    Coord xx(4, 4, 4);
}

     
     
    











 

