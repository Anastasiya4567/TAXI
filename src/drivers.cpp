/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#include <iostream>

#include "drivers.hpp"

using namespace std;

Drivers::Drivers(string d, string c, short int e)
{
     this->drivSur=d;
     this->code=c;
     this->exp=e;
}
string Drivers::returnDSur ()
{
    return this->drivSur;
}
string Drivers:: returnCode ()
{
    return this->code;
}
short int Drivers:: returnExp ()
{
    return this->exp;
}

bool operator == (Drivers &driv1, string Code)
{
    return (driv1.returnCode()==Code);
}
