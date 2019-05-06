/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#include <iostream>

#include "clients.hpp"

using namespace std;

Clients::Clients (string s, string n, double d)
{
  this-> cliSur=s;
  this-> cliName=n;
  this-> discount=d;
}

string Clients:: returnCSur ()
{
    return this->cliSur;
}

string Clients:: returnCName ()
{
    return this->cliName;
}

double Clients:: returnDis ()
{
    return this->discount;
}

void Clients:: returnDis (double discount2)
{
    this->discount=discount2;
}
