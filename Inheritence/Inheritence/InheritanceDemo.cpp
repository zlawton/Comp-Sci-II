/*************************************************************************
* 
*      program name:       Inheritance.cpp
*      Author:             Zack Lawton
*      date due:           04/08/14
*      remarks:
*
*************************************************************************/

/******************************************
*     library includes 
******************************************/
#include <iostream>                // needed for I/O

/******************************************
*     pre-processor
******************************************/
#define PI 3.14159
using namespace std;
class road_vehicle 
{
    private:
      int wheels;
      int passengers;
    public:
        road_vehicle()
        {
            cout << "in default road_vehicle" << endl;
            wheels = 0;
            passengers = 0;
        }
        road_vehicle(int w, int p)
        {
            cout << "in first road_vehicle construct" << endl;
            wheels = w;
            passengers = p;
        }
    
        //Setters
       void set_wheels(int num) { wheels = num; }
       void set_pass(int num)   { passengers = num; }
    
        //Getters
       int  get_wheels()        { return wheels; }
       int  get_pass()          { return passengers; }
    
       void show();
};

//****************************************//
//          Enumerated data types         //
//          for cars and motorcycles      //
//***************************************//
enum type {car, van, wagon, harley, triumph, BMW, otherType};

//**********************************//
//********** Truck Class ***********//
//**********************************//

class truck : public road_vehicle
{
    private:
      int cargo;
    public:
      //Constructors
      truck()
      {
        cargo = 0;
        cout << "in First Truck constructor" << endl;
      }
      truck(int t)
      {
        cargo = t;
        cout << "in Second Truck constructor" << endl;
      }

      void set_cargo(int size) { cargo = size; }
      int get_cargo()          { return cargo; }
      void show();
};

//************************************//
//******* Truck Member Function ******//
//************************************//

void truck :: show()
{
    cout << endl;
    cout << "-- Truck -- "  << endl;
    cout << "wheels:     "  << get_wheels() << endl;
    cout << "passengers: "  << get_pass() << endl;
    cout << "cargo room: "  << cargo << endl;
    cout << endl;
}

//**********************************//
//******** Motorcycle Class ********//
//**********************************//
class motorCycle : public road_vehicle
{
private:
    enum type motorcycle_type;
    
public:
    motorCycle()
    {
        motorcycle_type = otherType;
        cout << "in Motorcycle constructor default\n";
        
    }
    motorCycle(type m)
    {
        motorcycle_type = m;
        cout << "in Motorcycle constructor #1" << endl;
        
    }
    motorCycle(type m, int wheels, int passengers) : road_vehicle(wheels, passengers)
    {
        motorcycle_type = m;
        cout << "in Motorcycle constructor #2" << endl;
        
    }

    // member functions
    void set_type(type m)   { motorcycle_type = m; }
    enum type get_type()    { return motorcycle_type; }
    void show();
};

//************************************//
//**** Motorcycle Member Function ****//
//************************************//
void motorCycle :: show()
{
    cout << endl;
    cout << "-- Motorcycles --" << endl;
    cout << "wheels:     "  << get_wheels() << endl;
    cout << "passengers: "  << get_pass() << endl;
    cout << "type: ";
    
    switch(get_type())
    {
        case harley:      cout << "Harley" << endl;
            break;
        case triumph:     cout << "Triumph" << endl;
            break;
        case BMW:         cout << "BMW" << endl;
            break;
        case otherType:   cout << "Other Motorcycle Type" << endl;
    }
    
    cout << endl;
}

//****************************************//
//*********** Automobile Class **********//
//***************************************//
class automobile : public road_vehicle 
{
    private:
      enum type car_type;
    public:
        //Constructors
        automobile()
        {
            cout << "in Default Automobile constructor" << endl;
            car_type = otherType;
        }
        automobile(type t)
        {
            cout << "First Automobile constructor" << endl;
            car_type = t;
        }
        automobile(type t, int w, int p) : road_vehicle(w, p)
        {
            cout << "Second Automobile constructor" << endl;
            car_type = t;
        }

        //Setters
        void set_type(type c) { car_type = c; }
        //Getters
        enum type get_type()  { return car_type; }
        //Display
        void show();
};

//***************************************//
//***** Automobile Member Function ******//
//***************************************//
void automobile :: show()
{
     cout << "-- Automobile --" << endl;
     cout << "wheels:     " << get_wheels() << endl;
     cout << "passengers: " << get_pass() << endl;
     cout << "type: ";
     switch(get_type()) 
     {
        case van:        cout << "van" << endl;
             break;
        case car:        cout << "car" << endl;
             break;
        case wagon:      cout << "wagon" << endl;
             break;
        case otherType:  cout << "Other Type of Automobile" << endl;
             break;
     }
    
    cout << endl;
}

//***************************************//
//******* Gas Car Derived Class *********//
//***************************************//
class gasCar : public virtual automobile
{
    private:
        int mpg = 0;
        int gasTankVol = 0;
    public:
        // constructors
        gasCar()
        {
            cout << "in Default Gas Car constructor" << endl;
            gasTankVol = 0;
            mpg = 0;
        }
        gasCar(int volume, int miles)
        {
            cout << "in First Gas Car constructor" << endl;
            gasTankVol = volume;
            mpg = miles;
        }
        gasCar(int volume, int miles, type at, int w, int p) : automobile(at, w, p)
        {
            cout << "in Second Gas Car Constructor" << endl;
            gasTankVol = volume;
            mpg = miles;
        }
    
        //Setters
        void set_gasTankVolume(int t)   {gasTankVol = t;}
        void set_mpg(int miles)         {mpg = miles;}
        //Getters
        int  get_gasTankVolume()        {return gasTankVol;}
        int  get_mpg()                  {return mpg;}
        //Display
        void show();
};

//***************************************//
//******* Gas Car Member Function *******//
//***************************************//

void gasCar :: show()
{
        cout << "-- Gas Car --" << endl;
        cout << "wheels:     " << get_wheels() << endl;
        cout << "passengers: " << get_pass() << endl;
        cout << "type: ";
        switch(get_type())
        {
            case van:        cout << "van" << endl;
                break;
            case car:        cout << "car" << endl;
                break;
            case wagon:      cout << "wagon" << endl;
                break;
            case otherType:  cout << "Other Type of Automobile" << endl;
                break;
        }
    
        cout << "Volume of Gas Tank:  "  << get_gasTankVolume() << endl;
        cout << "Miles Per Gallon:  "    << get_mpg() << endl;
        cout << endl;
}

//***************************************//
//**** Electric Car Derived Class *******//
//***************************************//
class electricCar : public virtual automobile
{
    private:
        int timeBatteryCharge;
        int milesBatteryCharge;
    
    public:
        // constructors
        electricCar()
        {
            cout << "in Default Electric Car constructor" << endl;
            timeBatteryCharge  = 0;
            milesBatteryCharge = 0;
        }
        electricCar(int tbc, int mbc)
        {
            cout << "in First Electric Car constructor" << endl;
            timeBatteryCharge  = tbc;
            milesBatteryCharge = mbc;
        }

    
        //Setters
        void set_timeBatteryCharge(int tbc)   { timeBatteryCharge = tbc; }
        void set_milesBatteryCharge(int mbc)  { milesBatteryCharge = mbc; }
        //Getters
        int  get_timeBatteryCharge()        { return timeBatteryCharge; }
        int  get_milesBatteryCharge()       { return milesBatteryCharge; }
        //Display
        void show();
};

//***************************************//
//***** Electric Car Member Function ****//
//***************************************//

void electricCar :: show()
{
    cout << "-- Electric Car --" << endl;
    cout << "wheels:     " << get_wheels() << endl;
    cout << "passengers: " << get_pass() << endl;
    cout << "type: ";
    switch(get_type())
    {
        case van:        cout << "van" << endl;
            break;
        case car:        cout << "car" << endl;
            break;
        case wagon:      cout << "wagon" << endl;
            break;
        case otherType:  cout << "Other Type of Automobile" << endl;
            break;
    }
    
    cout << "Battery Charge Time:  "  << get_timeBatteryCharge() << endl;
    cout << "Miles of Battery Charge:  " << get_milesBatteryCharge() << endl;
    cout << endl;
}

//***************************************//
//****** Hybrid Car Derived Class *******//
//***************************************//
class hybridCar : public electricCar, public gasCar
{
    
    public:
        // constructors
        hybridCar()
        {
            cout << "in Default HybridCar constructor" << endl;
            cout << endl;
        }
    hybridCar(int tbc, int mbc)
        {
            cout << "in First Hybrid Car constructor" << endl;
        }
    
        //Display
        void show();
    
};

//***************************************//
//***** Hybrid Car Member Function ****//
//***************************************//

void hybridCar :: show()
{
    cout << "-- Hybrid Car --" << endl;
    cout << "wheels: "         << get_wheels() << endl;
    cout << "passengers: "     << get_pass() << endl;
    cout << "type: ";
    switch(get_type())
    {
        case van:        cout << "van" << endl;
            break;
        case car:        cout << "car" << endl;
            break;
        case wagon:      cout << "wagon" << endl;
            break;
        case otherType:  cout << "Other Type of Automobile" << endl;
            break;
    }
    
    cout << "Volume of Gas Tank:  "        << get_gasTankVolume() << endl;
    cout << "Miles Per Gallon:  "          << get_mpg() << endl;
    cout << "Battery Charge Time:  "       << get_timeBatteryCharge() << endl;
    cout << "Miles of Battery Charge:  "   << get_milesBatteryCharge() << endl;
    cout << endl;
}

//***************************//
//*** Function Prototypes ***//
//***************************//
void testTruck();
void testMotorcycle();
void testAutomobile();
void testElectricCar();
void testGasCar();
void testHybridCar();

//************************//
//***** Main Function ****//
//************************//
int main()
{
    
    //testTruck();
    //testMotorcycle();
    //testAutomobile();
    //testElectricCar();
    //testGasCar();
    testHybridCar();
    

    system("pause");
    return 0;
}

/***********************************/
/******** Test Functions ***********/
/***********************************/
void testTruck()
{
    truck t1;
    truck t2;
    
    t1.set_wheels(18);
    t1.set_pass(4);
    t1.set_cargo(18000);
    
    t2.set_wheels(16);
    t2.set_pass(2);
    t2.set_cargo(1000);
    
    t1.show();
    cout << endl;
    
    t2.show();
    cout << endl;
}

void testMotorcycle()
{
    //Test the default constructor
    motorCycle mc;
    mc.show();
    cout << endl;
    
    motorCycle mcH;
    mcH.set_wheels(2);
    mcH.set_pass(3);        //sidecar ;)
    mcH.set_type(harley);
    mcH.show();
    cout << endl;
    
    motorCycle mcBMW(BMW);
    mcBMW.show();
    cout << endl;
    
    motorCycle mcT(triumph, 2, 2);
    mcT.show();
    cout << endl;
}

void testAutomobile()
{
    automobile a;
    
    a.set_wheels(4);
    a.set_pass(8);
    a.set_type(car);
    a.show();
    cout << endl;
}
void testElectricCar()
{
    electricCar eCar;
    
    eCar.set_wheels(4);
    eCar.set_pass(3);
    eCar.set_type(wagon);
    eCar.set_timeBatteryCharge(9);
    eCar.set_milesBatteryCharge(425);
    eCar.show();
    cout << "\n";
}
void testGasCar()
{
    gasCar gCar(20, 45, car, 4, 5);
    gCar.set_wheels(4);
    gCar.set_pass(4);
    gCar.set_type(car);
    gCar.set_gasTankVolume(12);
    gCar.set_mpg(31);
    gCar.show();
    cout << "\n";
}

void testHybridCar()
{
    
    hybridCar hCar1;
    hCar1.set_wheels(4);
    hCar1.set_pass(4);
    hCar1.set_type(car);
    hCar1.set_gasTankVolume(12);
    hCar1.set_mpg(31);
    hCar1.set_timeBatteryCharge(9);
    hCar1.set_milesBatteryCharge(425);
    hCar1.show();
    
    hybridCar hCar2;
    hCar2.set_wheels(3);
    hCar2.set_pass(1);
    hCar2.set_type(van);
    hCar2.set_gasTankVolume(4);
    hCar2.set_mpg(80);
    hCar2.set_timeBatteryCharge(12);
    hCar2.set_milesBatteryCharge(360);
    hCar2.show();

}



