/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#include <iostream>

#include "drivers.hpp"

using namespace std;

Driver::Driver(string c, string d,  short int e)
{
     this->drivSur=d;
     this->code=c;
     this->exp=e;
}
string Driver::getDSur ()
{
    return this->drivSur;
}
string Driver:: getCode ()
{
    return this->code;
}
short int Driver:: getExp ()
{
    return this->exp;
}

bool operator == (const Driver &driv1, const string Code)
{
    return (driv1.code==Code);
}
