/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#include <iostream>

#include "autos.hpp"

using namespace std;

template <class T> Autos <T>::  Autos (string n, string c, T y)
{
      this->nameTaxi=n;
      this->colour=c;
      this->year=y;
}
template <class T> string Autos<T>:: returnName ()
{
    return this->nameTaxi;
}

template <class T> string Autos<T>:: returnColour ()
{
    return this->colour;
}
template <class T> short int Autos<T>:: returnYear ()
{
    return this->year;
}
