/********************************************************
*  Name:           Struct01
*  Author:         Zack Lawton
*  Date due:       01/27/14
*  Description:
*
*
**********************************************************/

/***************************
*     libraries
****************************/
#include <iostream>            // needed for Cin and Cout
#include <string>              // needed for string class
using namespace std;

/************************************
*     defines
*************************************/
#define  PI  3.14159

/*************************************
*     function prototype
*************************************/


/************************************
*      global variables
*************************************/
 struct StarTrekPersonel
    {
        string ID;
        string name;
        string address;
        string city;
        string state;
        string zip;
        string planet;
        
    };

int main()
{
    /************************************
    *      local variables
    *************************************/
    
    StarTrekPersonel stpSample;
    
    //input
    cout << "Please enter your ID: ";
    cin >> stpSample.ID;
    
    cout << "\n" << "Please enter your name: ";
    cin.ignore( );
    getline(cin, stpSample.name);
    
    cout << "\n" << "Please enter your street address: ";
    getline(cin, stpSample.address);
    
    cout << "\n" << "Please enter the city: ";
    getline(cin, stpSample.city);
    
    cout << "\n" << "Please enter the state: ";
    getline(cin, stpSample.state);
    
    cout << "\n" << "Please enter the zip code: ";
    cin >> stpSample.zip;
    
    cout << "\n" << "Please enter the planet: ";
    cin >> stpSample.planet;
    
    //output
    cout << "**** The stpSample Field *** \n";
    cout << "ID" << "\t\t" << stpSample.ID << endl;
    cout << "Name" << "\t\t" << stpSample.name << endl;
    cout << "Address" << "\t\t" << stpSample.address << endl;
    cout << "City" << "\t\t" << stpSample.city << endl;
    cout << "State" << "\t\t" << stpSample.state << endl;
    cout << "Zip Code" << "\t" << stpSample.zip << endl;
    cout << "Planet" << "\t\t" << stpSample.planet << endl;
    
     system("pause");
     return 0;
}









