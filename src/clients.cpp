/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#include <iostream>

#include "clients.hpp"

using namespace std;

Client::Client (string s, string n, double d)
{
  this-> cliSur=s;
  this-> cliName=n;
  this-> discount=d;
}

string Client:: getCSur ()
{
    return this->cliSur;
}

string Client:: getCName ()
{
    return this->cliName;
}

double Client:: getDis ()
{
    return this->discount;
}

void Client:: getDis (double discount2)
{
    this->discount=discount2;
}
