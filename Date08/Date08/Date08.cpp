
/**************************************************
 *
 *      program name:       Date08
 *      Author:             Zack Lawton
 *      date due:           03/24/14
 *      remarks:
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
    int* month;                 //variable for month
    int* day;                   //variable for day
    int* year;                  //variable for the year
    
public:
    //constructors
    Date();                     //default constructor
    Date(int, int);             //takes two integers
    Date(int, int, int);        //takes 3 integers
    Date (Date const &dx);      //copy constructor
    
    //setters
    void setMonth(int x)         {*month = x;}        //sets the month value
    void setDay(int x)           {*day = x;}          //sets the day value
    void setYear(int x)          {*year = x;}         //sets the year value
    
    //getters
    int getMonth()const          {return *month;}     //holds the month value
    int getDay()const            {return *day;}       //holds the day value
    int getYear()const           {return *year;}      //holds the year value
    
    //Member Function Prototypes
    void displayTwo();
    void display();                 //contains program output
    bool calcLeapYear();            //contains leap year calculations
    int calcDayOfYear();            //calculate the day of the year
    char* getDayOfWeek();           //calcuations for days of week
    string getMonthName();          //holds the month names
    
    //overloading operators (Date07)
    void operator = (const Date &right);        //overloading "=" operator
    bool operator < (const Date &right);        //overload "<" operator
    bool operator > (const Date &right);        //overload ">" operator
    Date operator + (int);                                      //overload addition operator
    Date operator - (int);                                      //overload subtraction operator
    Date operator ++ (int);                                     //overload ++ postfix operator
    Date operator ++ ();                                        //overload ++ prefix operator
    
    //deconstructor
    ~Date();
};

/****************************************
 *         member functions
 ****************************************/
Date::Date()
{
    //creates placeholder for the ints
    month = new int;
    day = new int;
    year = new int;
    
    //internal clock equations
    struct tm *ptr;
    time_t lt;
    lt = time(NULL);
    ptr = localtime (&lt);
    
    
    setMonth(ptr->tm_mon+1);
    setDay(ptr->tm_mday);
    setYear(ptr->tm_year+1900);
    
    
    
}

Date::Date(int doy, int y)
{
    //creates placeholder for the ints
    month = new int;
    day = new int;
    year = new int;
    
    int julianMonth[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};         //julian calender for each month
    int LeapYear[13] = {0,31,60,91,121,152,182,213,244,275,305,335,366};
    int x;          //place holder
    
    setYear(y);
    
    setMonth(x);
    
    setDay(doy - julianMonth[x]);
    
    
    //Get the month
    for(x=1; x<13 && doy>julianMonth[x]; x++)
    {
        
    }


    if (calcLeapYear())
    {
        for(x=1; x<13 && doy>LeapYear[x]; x++)
        {}
        setDay(doy - LeapYear[x]);
    }
    else
    {
        for(x=1; x<13 && doy>julianMonth[x]; x++)
        {}
        setDay(doy - julianMonth[x]);
    }
    

    
    
    for(x=1; x<13; x++)
    {
        //increment by 1 if a leap year
        if(calcLeapYear() && x>1)
        {
            julianMonth[x]++;
        }
        
        if(doy <= julianMonth[x])
        {
            setMonth(x);
            setDay(doy - julianMonth[x-1]);
            break;
        }
    }
}

Date :: Date(int m, int d, int y)
{
    month = new int;
    setMonth(m);            //holds the month value
    
    day = new int;
    setDay(d);                //holds the day value
    
    year = new int;
    setYear(y);              //holds the year value
}


//copy constructor
Date :: Date (Date const &dx)
{
    cout << "in copy constructor\n\n";
    month = new int;
    setMonth(dx.getMonth());            //holds the month value
    
    day = new int;
    setDay(dx.getDay());                //holds the day value
    
    year = new int;
    setYear(dx.getYear());              //holds the year value
    
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
    cout << "\n" << "Year is: " << getYear();
    cout << "\n" << "Day of year is: " << calcDayOfYear() << "\n";
    
    if (calcLeapYear() == true)
    {
        cout << getYear() << " is a leap year";
    }
    else                                                    //read out for leap year
    {
        cout << getYear() << " is not a leap year";
    }
    cout << "\n";
    cout << "Month is: " << getMonthName() << "\n";
    cout << "Day-of-week: " << dayName << "\n";
    
}

void Date :: displayTwo()
{
    cout << " " << getDay() << "," << getMonth() << "," << getYear() << endl;
    
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
    int NumDays[14]={0,0,31,59,90,120,151,181,212,243,273,304,334,365};
    int DayofYear;
    DayofYear = NumDays[getMonth()]+getDay();
    if (calcLeapYear() & getMonth() > 2)
    {
        DayofYear++;
    }
    return DayofYear;
    
}

char* Date :: getDayOfWeek()
{
    // declare the variables
    int totaldays=0;
    Date d1;
    int x;
    
    // initalize the array to get the day of the week
    char DayofWeek[7][11]={"Sunday",
                            "Monday",
                            "Tuesday",
                            "Wednesday",
                            "Thursday",
                            "Friday",
                            "Saturday"};
    
    // using the for loop to get the the array
    for(x =1900; x< getYear(); x++)
    {
        totaldays +=365;
        d1.setYear(x);
        if(d1.calcLeapYear())
            totaldays++;
    }
    totaldays = totaldays + calcDayOfYear();
    return &DayofWeek[totaldays%7][0];
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

/************* Date 07 ***********
 *********************************/

void Date :: operator = (Date const &right)
{
    month = new int (*right.month);
    day = new int (*right.day);
    year = new int (*right.year);
}

bool Date :: operator < (const Date &right)
{
    int trueFalse = 0;
    
    if (this->getYear() <= right.getYear())
    {
        trueFalse = 1;
    }
    
    else if (this->getYear() == right.getYear())
    {
        if (this->getMonth() < right.getMonth())
        {
            trueFalse = 1;
        }
        if (this->getDay() < right.getDay())
        {
            trueFalse = 1;
        }
    }
    
    return trueFalse;
}

bool Date :: operator > (const Date &right)
{
    int trueFalse = 0;
    
    if (this->getYear() >= right.getYear())
    {
        trueFalse = 1;
    }
    
    else if (this->getYear() == right.getYear())
    {
        if (this->getMonth() > right.getMonth())
        {
            trueFalse = 1;
        }
        if (this->getDay() > right.getDay())
        {
            trueFalse = 1;
        }
    }
    return trueFalse;
}


/*************** Date08 ****************
 ***************************************/
Date Date :: operator + (int addedNum)
{
    Date temp(getMonth(), getDay(), getYear());                                  //temporary Date object to add to
    int monthLength[12] { 31, 28, 31, 30, 31, 30,                                //days in each month
        31, 31, 30, 31, 30, 31};
    
    temp.setDay(temp.getDay() + addedNum);                                       //add to getDay
    
    while (temp.getDay() > monthLength[((temp.getMonth() - 1) % 12)])            //if days are > than they should, increment the months by 1
    {
        temp.setMonth(temp.getMonth() + 1);                                      //Add 1 to the month
        temp.setDay(temp.getDay() - monthLength[((temp.getMonth() - 1) % 12)]);  //remove however many days
        
        if (temp.getMonth() == 13)                                               //check if the month goes into a new year
        {
            temp.setYear(temp.getYear() + 1);                                    // Add 1 to the year
            temp.setMonth(1);                                                    // month resets to 1
        }
    }
    return temp;
}

Date Date :: operator - (int subNum)
{
    Date temp(getMonth(), getDay(), getYear());                         //temporary Date object to add to
    int monthLength[12] { 31, 28, 31, 30, 31, 30,                       //days in each month
        31, 31, 30, 31, 30, 31};
    
    temp.setDay(temp.getDay() - subNum);                                //add to the day
    
    while (temp.getDay() <= 0)                                          //if the days are > than it should be, increment the month by 1
    {
        temp.setMonth(temp.getMonth() - 1);                               //remove one month
        temp.setDay(temp.getDay() + monthLength[temp.getMonth()]);     //add proper amount of days
        
        if (temp.getMonth() == 0)                                       //see if the month goes down to the next year
        {
            temp.setMonth(12);                                          //set the month to 12
            temp.setYear(temp.getYear() - 1);                           //subtract 1 year
        }
    }
    return temp;
}

Date Date :: operator ++ (int)
{
    Date temp(getMonth(), getDay(), getYear());                           //temp Date object to add to
    temp.setDay(temp.getDay() + 1);
    
    int monthLength[12] { 31, 28, 31, 30, 31, 30,                         //days in each month
        31, 31, 30, 31, 30, 31};
    
    if (temp.getDay() > monthLength[temp.getMonth() - 1])                 //if days are > than should be in the month
    {
        temp.setDay(temp.getDay() - monthLength[temp.getMonth() - 1]);    //adjusting the days
        temp.setMonth(temp.getMonth() + 1);                               //add 1 month
        
    }
    
    if (temp.getMonth() == 13)                                            //if month is > than a year
    {
        temp.setMonth(1);                                                 //restart month at 1
        temp.setYear(temp.getYear() + 1);                                 //add 1 year
    }
    
    return temp;                                                          //returns temp
}

Date Date :: operator ++ ()
{
    Date temp(getMonth(), getDay(), getYear());                         //temp Date object to +
    
    temp.setDay(temp.getDay() + 1);
    
    int monthLengths[12] { 31, 28, 31, 30, 31, 30,                      //Days in the months
        31, 31, 30, 31, 30, 31};
    
    if (temp.getDay() > monthLengths[temp.getMonth()-1])                //if days are > in the month than should be
    {
        temp.setDay(temp.getDay() - monthLengths[temp.getMonth()-1]);   //adjusts the days
        temp.setMonth(temp.getMonth()+1);                               // Add one month
    }
    
    if (temp.getMonth() == 13)                                          //if month is > than a year
    {
        temp.setMonth(1);                                               //restarts month at 1
        temp.setYear(temp.getYear()+1);                                 //add 1 year
    }
    
    return temp;                                                        //returns temp
}



/****************************************
 *          function prototypes
 ****************************************/

void testDate03();
void testDate04();
void testDate05();
void testDate06(Date first);
void testDate07();
void testDate08();
void testDeconstructor();


/*****************************************
 *   main() - the function that executes
 *****************************************/
int main()
{
    
    //testDate03();
    //testDate04();                  // test function call
    //testDate05();
    //Date first(8,10,2000);          //hard-coded data
    //testDate06(first);              //input to the function
    //testDate07();
    //cout << "first display again\n";
    //first.display();                //display
    //testDeconstructor();
    
    
    testDate08();                    //readout Date08 test function
    
    //system("PAUSE");               // causes the program to pause
    return 0;
    
}  // end main


/*****************************************
 *   Testing Function -  tests Date constructors
 *****************************************/

void testDate03()
{
    Date d1 (1, 1, 1900);
    
    //Generic Readout test
    cout << "Generic Readout\n";
    d1.setDay(1);
    d1.setMonth(1);
    d1.setYear(1900);
    d1.display();
    cout << "\n\n\n\n";
    //Day Test 1
    cout << "********Day Test 1********* \n";
    d1.setDay(1);
    d1.setMonth(2);
    d1.setYear(1900);               //day test
    d1.display();
    cout << "\n\n\n\n";
    
    //Day Test 2
    cout << "********Day Test 2***** \n";
    d1.setDay(1);
    d1.setMonth(2);
    d1.setYear(1901);               //day test
    d1.display();
    cout << "\n\n\n\n";
    
    //Day Test 3
    cout << "********Leap Year 1***** \n";
    d1.setDay(30);
    d1.setMonth(2);
    d1.setYear(2000);               //leap year test
    d1.display();
    cout << "\n\n\n\n";
    
    //Day Test 4
    cout << "********Leap Year 2***** \n";
    d1.setDay(1);
    d1.setMonth(3);                //non- leap year test
    d1.setYear(2001);
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
        cout << "\n\n";
    }
    
    //test each month
    cout << "Test through each month day \n";
    for (int x = 1; x <= 12; x++)
    {
        d1.setDay(1);
        d1.setMonth(x);
        d1.setYear(1900);
        d1.display();
    }
    
}

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

void testDate05()
{
    Date d01(1, 2000);
    d01.display();
    Date d02(1, 2001);
    d02.display();
    Date d03(59, 2000);
    d03.display();
    Date d04(59, 2001);
    d04.display();
    Date d05(60, 2000);
    d05.display();
    Date d06(60, 2001);
    d06.display();
    Date d07(61, 2000);
    d07.display();
    Date d08(61, 2001);
    d08.display();
    Date d09(366, 2000);
    d09.display();
    Date d10(365, 2001);
    d10.display();
}

void testDate06(Date first)
{
    //local variables
    Date copy(first);                   // Copy of original
    cout << "\n**original display**\n";
    copy.display();                     // Display copy
    cout << "\n**copy display**\n";
    first.display();                    // Display original
    
    Date xx(first);                     // Delete copy
}

void testDate07()
{
    Date d1(2, 5, 2000);
    Date d2(6, 6, 1999);
    Date d3(4, 6, 2000);
    
    //displaying original values
    d1.display();
    d2.display();
    
    cout << "\n\n";
    
    //testing the "<" and ">" operators
    cout << "testing the '<' and '>' operators\n";
    cout << "Date 01: ";
    d1.displayTwo();
    cout << "Date 02: ";
    d2.displayTwo();
    cout << endl;
    
    if (d1 < d2)
    {
        cout << "Date01 is less than Date02 \n";
    }
    else
    {
        cout << "Date02 is less than Date01 \n";
    }
    
    if (d2 > d1)
    {
        cout << "Date02 is greater than Date01 \n";
    }
    else
    {
        cout << "Date01 is greater than Date02 \n";
    }
    
    //testing the "=" operator
    d1 = d2;             //setting d1 = to d2
    d1.display();        //display after d2 is equal to d1
    
    Date xx(0,0,0);      //deconstructor
}

void testDate08()
{
    Date d01(1,1,1234);                 //to test +
    Date d02(12,31,1234);               //to test -
    Date d03(5,30,1999);                //test ++ (pre and post)
    
    //test "+"
    cout << "Test '+' \n";
    d01 = d01 + 10;                      //add to d01 within 1 month
    d01.display();                      //display
    
    d01 = d01 + 50;                     //add to d01 more than 1 month
    d01.display();                      //display
    
    d01 = d01 + 375;                    //add to d01 more than 1 year
    d01.display();                      //display
    
    cout << "\n";
    //test "-"
    cout << "TEST '-' \n";
    d02 = d02 - 5;                      //subtract from d02 < one month
    d02.display();                      //display
    
    d02 = d02 - 50;                     //subtract from d02 more than one month
    d02.display();                      //display
    
    d02 = d02 - 375;                    //subtract from d02 more than one year
    d02.display();                      //display
    
    cout << "\n";
    //test "++" (post)
    cout << "Test '++' (post) \n";
    d03 = d03++;                        //add 1 to d03
    d03.display();                      //display
    
    cout << "\n";
    //test "++" (pre)
    cout << "test '++' (pre) \n";
    d03 = ++d03;                        // + 1 to d03 again
    d03.display();                      //display
}



//Test for deconstructor
void testDeconstructor()
{
    {
        cout << "in test destructor function\n";
        Date xx(4,1,1992);
        cout << endl;
    }
}



