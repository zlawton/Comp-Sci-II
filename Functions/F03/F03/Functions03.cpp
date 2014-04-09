/********************************************************
 *  Name:           Functions03
 *  Author:         Zack Lawton
 *  Date due:       01/27/14
 *  Description:    write a function that receives no parameters but returns a value
 *                   - given the length and width (in feet) of a square parcel of
 *                     land, convert that parcel of land from square feet to acres.
 **********************************************************/

/***************************
 *     libraries
 ****************************/
#include <iostream>            // needed for Cin and Cout
using namespace std;

/************************************
 *     defines
 *************************************/
#define  PI  3.14159            //globablly defines PI

/*************************************
 *     function prototype
 *************************************/
float noArgsHasRet();

/************************************
 *      global variables
 *************************************/

int main()
{
    /************************************
     *      local variables
     *************************************/
    float acre;
    
    // function call
    acre = noArgsHasRet();
    
    cout << "Contains " << acre << " acres";
    cout << "\n";
    
    //system("pause");
    return 0;
}

/************************************
 *      non-member functions
 *************************************/
float noArgsHasRet()
{
    /************************************
     *      local variables
     *************************************/
    
    float acre;             //saves the calculation for acres
    float length;          //saves user input for length
    float width;           //saves user input for width
    
    //input
    cout << "Please enter the length of the parcel of land (in feet): ";
    cin >> length;
    cout << "\n" << "Please enter the width of the parcel of land (in feet): ";
    cin >> width;
    cout << "\n";
    
    //calculations
    acre = (length * width) / 43560.174;
    
    //output
    cout << "A parcel with the land dimensions of" << "\n";
    cout << "\t" << "Length: " << length << " ft\n";
    cout << "\t" << "Width: " << width << " ft\n";
   
    
    return acre;        //returns value of acre back to main()
    
}
