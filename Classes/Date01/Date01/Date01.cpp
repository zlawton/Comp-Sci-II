/**************************************************
 *
 *      program name:       Dates01
 *      Author:             Zack Lawton
 *      date due:           02/05/14
 *      remarks:            Write a C program using classes that decided if it is a leap year or not, **Updated**
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
        //setters
    void setMonth(int x)    {month = x;}
    void setDay(int x)      {day = x;}
    void setYear(int x)     {year = x;}
    
        //getters
    int getMonth()          {return month;}     //holds the month value
    int getDay()            {return day;}       //holds the day value
    int getYear()           {return year;}      //holds the year value
    
    bool calcLeapYear(int year);        //contains leap year calculations
    
    void display();         //contains program output
};

/****************************************
 *         member functions
 ****************************************/

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


/*****************************************
 *   main() - the function that executes
 *****************************************/
int main()
{
    /*******************************
     *     local variables
     ******************************/
   
    Date d1;        //instantiating the class
    
    int month;      //variable for the month
    int day;        //variable for the day
    int year;       //variable for the year
    
    //input
    cout << "\n" << "please enter the month: ";
    cin >> month;
    cout << "\n" << "please enter the day: ";
    cin >> day;
    cout << "\n" << "please enter the year: ";
    cin >> year;
    
   
    //input to Date class
    d1.setMonth(month);
    d1.display();       //test
    
    d1.setDay(day);
    d1.display();       //test
    
    d1.setYear(year);
    d1.display();       //test
    
    //Getter tests
    
    cout << "\n\n"<< "****Getters Tests**** \n";
    cout << d1.getMonth() << endl;
    cout << d1.getDay() << endl;
    cout << d1.getYear() << endl;
    cout << "\n";
    
    //Leap year test
    
    cout << "****Leap Year Tests****" << endl;
    d1.setYear(1990);
    d1.display();
    d1.setYear(2000);
    d1.display();
    d1.setYear(1999);
    d1.display();
    d1.setYear(1996);
    d1.display();
    


   // system("PAUSE");               // causes the program to pause
    cout << endl;
	return 0;
}  // end main

















