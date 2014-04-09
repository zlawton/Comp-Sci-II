/**************************************************
 *
 *      program name:       Date04
 *      Author:             Zack Lawton
 *      date due:           02/05/14
 *      remarks:            Write a C program using classes that decided if it is a leap year or not, also using constructors and pointers
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
    int* month;      //variable for month
    int* day;        //variable for day
    int* year;       //variable for the year
    
public:
    //constructors
    Date (int, int, int);
    
    //setters
    void setMonth(int x)    {*month = x;}
    void setDay(int x)      {*day = x;}
    void setYear(int x)     {*year = x;}
    
    //getters
    int getMonth()const          {return *month;}     //holds the month value
    int getDay()const            {return *day;}       //holds the day value
    int getYear()const           {return *year;}      //holds the year value
    
    bool calcLeapYear();     //contains leap year calculations
    
    void display();         //contains program output
    

    
    //Date03 Shit
    int calcDayOfYear();            //calculate the day of the year
    char* getDayOfWeek();           //calcuations for days of week
    string getMonthName();          //holds the month names
    
    //deconstructor
    ~Date();
    
};

/****************************************
 *         member functions
 ****************************************/
Date :: Date(int, int, int)
{
    month = new int;
    setMonth(*month);            //holds the month value
    
    day = new int;
    setDay(*day);                //holds the day value
    
    year = new int;
    setYear(*year);              //holds the year value
    
}

Date :: ~Date()
{
    //cout << "in destructor\n";
    
    delete month;
    delete day;
    delete year;
}

void Date :: display()
{
    
    char dayName[11];                     //used to show full day names
    strcpy(dayName, getDayOfWeek());
    
    cout << "\n" << "Day is: " << getDay();
    cout << "\n\n" << "Year is: " << getYear();
    cout << "\n\n" << "Day of year is: " << calcDayOfYear() << "\n\n";
    
    if (calcLeapYear() == true)
    {
        cout << getYear() << " is a leap year";
    }
    else                                                    //read out for leap year
    {
        cout << getYear() << " is not a leap year";
    }
    cout << "\n\n";
    cout << "Month is: " << getMonthName() << "\n\n";
    cout << "Day-of-week: " << dayName << "\n\n";
    
}

bool Date :: calcLeapYear()
{
    
    bool isLeapYear;       // variable for deciding leap year or not
    
    
    if (getYear() % 400 == 0)                        // evenly divisible by 400 years (true)
    {
        isLeapYear = true;
    }
    else if (getYear() % 100 == 0)               //year evenly divisible by 100 not a leap year(false)
    {
        isLeapYear = false;
    }
    else if (getYear() % 4 == 0)                 //year divisible by 4 (true)
    {
        isLeapYear = true;
    }
    else
    {
        isLeapYear = false;         //anything else
    }
    
    return isLeapYear;
}

/*********  Date04 ************
 ******************************/

int Date :: calcDayOfYear()
{
    int totalDays = 0;          //holds total number of days
    int numDays[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};             //array for the number of days in each month
    
    totalDays = numDays[getMonth() - 1] + getDay();
    
    return totalDays;
    
}

char* Date :: getDayOfWeek()
{
    
    Date leapCheck(1, 1, 1900);
    int totalDays = 0;              //holds the total number of days
    int i;                          //place holder
    int dayIndex = 0;               //holds the number for the day of the week
    char dayOfWeek[7][11] = {"Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"};
    
    for (i = 1900; i < getYear(); i++)
    {
        totalDays += 365;
        
        leapCheck.setYear(i);
        
        if (leapCheck.calcLeapYear())
        {
            totalDays++;
        }
    }
    
    totalDays += calcDayOfYear();
    
    dayIndex = totalDays % 7;
    
    return (&dayOfWeek[dayIndex][0]);    
}

string Date :: getMonthName()
{
    string monthName[12] = { "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};
       
    return monthName[getMonth()-1];
}

/****************************************
 *          function prototypes
 ****************************************/

void testDate04();
void testDeconstructor();

/*****************************************
 *   main() - the function that executes
 *****************************************/
int main()
{
    /*******************************
     *     local variables
     ******************************/
    
    testDate04();               //test function call
    testDeconstructor();
    
    system("PAUSE");               // causes the program to pause
    return 0;
    
}  // end main


/*****************************************
 *   Testing Function -  tests Date constructors
 *****************************************/
void testDate04()
{
    Date d1 (1, 1, 1900);
    
    //Constructor Test
    cout << "Constructor Test\n";
    d1.setDay(1);
    d1.setMonth(1);
    d1.setYear(1900);
    d1.display();
    
    cout << endl;
    //tests for leap year/day/month/year
    cout << "last day test(leap year) \n";
    d1.setDay(31);
    d1.setMonth(12);
    d1.setYear(2000);               //last day test(leap year)
    d1.display();
    
    cout << endl;
    cout << "last day test (non leap year) \n";
    d1.setDay(31);
    d1.setMonth(12);
    d1.setYear(1999);               //last day test (non leap year)
    d1.display();
    
    cout << endl;
    cout << "non-leap year test \n";
    d1.setDay(1);
    d1.setMonth(1);
    d1.setYear(2001);               //non-leap year test
    d1.display();
    
    cout << endl;
    cout << "leap year test \n";
    d1.setDay(1);
    d1.setMonth(1);                //leap year test
    d1.setYear(2000);
    d1.display();
    
    cout << "\n\n\n";
    
    //Test each day of the week
    cout << "Test through each day of the week \n";
    for (int x = 1; x <= 7; x++)
    {
        d1.setDay(x);
        d1.setMonth(1);
        d1.setYear(1900);
        d1.display();    
    }
    
    //test each month
    cout << endl;
    cout << "Test through each month day \n";
    for (int x = 1; x <= 12; x++)
    {
        d1.setDay(1);
        d1.setMonth(x);
        d1.setYear(1900);
        d1.display();
    }
}
//Test for deconstructor
void testDeconstructor()
{
    {
        cout << "in test destructor function\n";
        Date xx(4,4,4);
        cout << endl;
    }
}





