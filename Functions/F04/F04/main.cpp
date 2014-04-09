/********************************************************
 *  Name:           Functions04
 *  Author:         Zack Lawton
 *  Date due:       01/27/14
 *  Description:     write a function that has parameters and returns a value
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
float hasArgsHasRet(float length, float width);

/************************************
 *      global variables
 *************************************/
float acre;     //saves the amount of acres after calculation

int main()
{
    /************************************
     *      local variables
     *************************************/
    float length;          //saves user input for length
    float width;           //saves user input for width
    
    //input
    cout << "Please enter the length of the parcel of land (in feet): ";
    cin >> length;
    cout << "\n" << "Please enter the width of the parcel of land (in feet): ";
    cin >> width;
    cout << "\n";

    // function call
    hasArgsHasRet (length, width);
    
    //output
    cout << "A parcel with the land dimensions of" << "\n";
    cout << "\t" << "Length: " << length << " ft\n";
    cout << "\t" << "Width: " << width << " ft\n";
    cout << "Contains " << acre << " acres";
    cout << "\n";
    
    
    //system("pause");
    return 0;
}

/************************************
 *      non-member functions
 *************************************/
float hasArgsHasRet(float length, float width)
{
    /************************************
     *      local variables
     *************************************/
    
   // float acre;             //saves the calculation for acres
       
    //calculations
    acre = (length * width) / 43560.174;
    
    
    return acre;        //returns value of acre back to main()
    
}
