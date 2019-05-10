/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#include <iostream>

#include "autos.hpp"

using namespace std;

template <class T> Auto <T>::  Auto (string n, string c, T y)
{
      this->nameTaxi=n;
      this->colour=c;
      this->year=y;
}
template <class T> string Auto<T>:: getName ()
{
    return this->nameTaxi;
}

template <class T> string Auto<T>:: getColour ()
{
    return this->colour;
}
template <class T> short int Auto<T>:: getYear ()
{
    return this->year;
}

bool operator == (const Auto<short int> &auto1, const string Name)
{
    return (auto1.nameTaxi==Name);
}
