/**************************************************
 *
 *      program name:       Date02
 *      Author:             Zack Lawton
 *      date due:           02/05/14
 *      remarks:            Write a C program using classes that decided if it is a leap year or not, also using constructors
 *
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

class Date
{
    private:
        int month;      //variable for month
        int day;        //variable for day
        int year;       //variable for the year
    
    public:
        //constructors
        Date();
        Date (int month, int day, int year);
    
        //setters
        void setMonth(int x)    {month = x;}
        void setDay(int x)      {day = x;}
        void setYear(int x)     {year = x;}
    
        //getters
        int getMonth()          {return month;}     //holds the month value
        int getDay()            {return day;}       //holds the day value
        int getYear()           {return year;}      //holds the year value
    
        bool calcLeapYear(int year);                //contains leap year calculations
    
        void display();         //contains program output
    
};

/****************************************
 *         member functions
 ****************************************/
Date :: Date()
{
    setMonth(0);
    setDay(0);
    setYear(0000);
    
}

Date :: Date(int month, int day, int year)
{
    setMonth(1);
    setDay(1);
    setYear(1900);
}

void Date :: display()
{
    
    cout << "\n";
    cout << "Month is " << getMonth();
    cout << "\n" << "Day is " << getDay();
    cout << "\n" << "Year is " << getYear();
    cout << "\n";
   
    
    //read out for leap year
    if (calcLeapYear(year) == true)
    {
         cout << getYear() << " is a leap year";
    }
    else
    {
        cout << getYear() << " is not a leap year";
    }
    
    cout << "\n\n";
}


bool Date :: calcLeapYear(int year)
{
   
    bool isLeapYear;       // variable for deciding leap year or not
    
    
        if (year % 400 == 0)                        // evenly divisible by 400 years (true)
        {
            isLeapYear = true;
        }
            else if (year % 100 == 0)               //year evenly divisible by 100 not a leap year(false)
                {
                    isLeapYear = false;
                }
            else if (year % 4 == 0)                 //year divisible by 4 (true)
                {
                    isLeapYear = true;
                }
        else
            {
            isLeapYear = false;         //anything else
            }
  
   return isLeapYear;
}

/****************************************
 *          function prototypes
 ****************************************/

void testDate02();

/*****************************************
 *   main() - the function that executes
 *****************************************/
int main()
{
    /*******************************
     *     local variables
     ******************************/
    
    Date d1;            //calls Date()
    Date d2(1,2,3);     //calls Date(int, int, int)
    
    
    //function call
    testDate02();


    system("PAUSE");               // causes the program to pause
    cout << endl;                  //line break
	return 0;
}  // end main

/*****************************************
 *   Testing Function -  tests Date constructors
 *****************************************/
void testDate02()
{

    Date d1;            //First class function
    d1.setDay(6);
    d1.setMonth(6);
    d1.setYear(6668);
    d1.display();
    
    Date d2 (01,01,1990);           //second class function
    d2.display();

}














