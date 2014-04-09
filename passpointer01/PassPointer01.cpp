
/**************************************************
 *
 *      program name:
 *      Author:             Zack Lawton
 *      date due:           2/05/14
 *      remarks:            Pass two pointers into a function and return back to main()
 *
 *
 ***************************************************/

/******************************************
 *     library includes
 ******************************************/
#include <iostream>
#include <iomanip>
#include <cmath>

/******************************************
 *     pre-processor
 ******************************************/
#define PI 3.14159
using namespace std;


/****************************************
 *          function prototypes
 ****************************************/
void arithmetic(int, int, float*, float*);

/*****************************************
 *   main() - the function that executes
 *****************************************/
int main()
{
    /*******************************
     *        local variables
     *******************************/
    
    int inHeight;       //variable for height
    int inRadius;       //variable for Radius
    
    float* pArea = new float;       //pointer for the Area
    float* pVolume = new float;     //pointer for the Volume
    
    //input
    cout << "Please enter a height: ";
    cin >> inHeight;
    cout << "Please enter a radius: ";
    cin >> inRadius;
    
    //function call
    arithmetic(inHeight, inRadius, pVolume, pArea);
    
    //output
    cout << "**** using the pointers **** \n";
    cout << "area: " << *pArea << "\n";
    cout << "volume: " << *pVolume << "\n";
    
    
    
    system("pause");
    return 0;
}  // end main

void arithmetic(int inHeight, int inRadius, float* pArea, float* pVolume)
{
 
    //calculations
    *pArea = 2 * PI * pow(inRadius, 2.0) + inHeight * (2 * PI * inRadius);
    
    *pVolume = (inHeight * inRadius * inRadius * PI);
    
}

















